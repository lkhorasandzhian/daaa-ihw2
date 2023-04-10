#include "searching_algorithms.h"

using namespace lib_std;
using namespace lib_mod;

std::vector<int> simpleSearch(const std::string &text, const std::string &pattern) {
    int text_size = static_cast<int>(text.size());
    int pattern_size = static_cast<int>(pattern.size());

    std::vector<int> positions;

    bool is_equals;
    for (int i = 0; i + pattern_size <= text_size; ++i) {
        is_equals = true;

        for (int j = 0; j < pattern_size; ++j) {
            if (pattern[j] != text[i + j]) {
                is_equals = false;
                break;
            }
        }

        if (is_equals) {
            positions.push_back(i);
        }
    }

    return positions;
}

namespace private_lib_std {
    std::vector<int> getPrefixes(const std::string &pattern) {
        int m = static_cast<int>(pattern.size());

        std::vector<int> br(m);

        br[0] = 0;

        int k = 0;
        for (int i = 1; i < m; ++i) {
            while (k > 0 && pattern[i] != pattern[k]) {
                k = br[k - 1];
            }

            if (pattern[i] == pattern[k]) {
                ++k;
            }

            br[i] = k;
        }

        return br;
    }
}

std::vector<int> lib_std::launchKnuthMorrisPratt(const std::string &text, const std::string &pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());

    auto prefixes = private_lib_std::getPrefixes(pattern);

    int count_of_equal = 0;

    std::vector<int> positions;
    positions.reserve(n);
    for (int i = 0; i < n; ++i) {
        while (count_of_equal > 0 && pattern[count_of_equal] != text[i] &&
            pattern[count_of_equal] != count_of_equal) {
            count_of_equal = prefixes[count_of_equal - 1];
        }

        if (text[i] == pattern[count_of_equal]) {
            ++count_of_equal;
        }

        if (count_of_equal == m) {
            positions.push_back(i - m + 1);
            count_of_equal = prefixes[count_of_equal - 1];
        }
    }

    return positions;
}

namespace private_lib_mod {
    std::vector<int> getPrefixes(const std::string &pattern) {
        int m = static_cast<int>(pattern.size());

        std::vector<int> br(m);

        br[0] = 0;

        int k = 0;
        for (int i = 1; i < m; ++i) {
            while (k > 0 && pattern[i] != pattern[k]) {
                k = br[k - 1];
            }

            if (pattern[i] == pattern[k]) {
                ++k;
            }

            br[i] = k;
        }

        std::vector<int> brs(m);

        brs[0] = 0;

        for (int i = 1; i < m; ++i) {
            if (pattern[br[i]] != pattern[i + 1]) {
                brs[i] = br[i];
            } else {
                brs[i] = brs[br[i]];
            }
        }

        return brs;
    }
}

std::vector<int> lib_mod::launchKnuthMorrisPratt(const std::string &text, const std::string &pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());

    auto prefixes = private_lib_mod::getPrefixes(pattern);

    int count_of_equal = 0;

    std::vector<int> positions;
    positions.reserve(n);
    for (int i = 0; i < n; ++i) {
        while (count_of_equal > 0 && pattern[count_of_equal] != text[i] &&
            pattern[count_of_equal] != count_of_equal) {
            count_of_equal = prefixes[count_of_equal - 1];
        }

        if (text[i] == pattern[count_of_equal]) {
            ++count_of_equal;
        }

        if (count_of_equal == m) {
            positions.push_back(i - m + 1);
            count_of_equal = prefixes[count_of_equal - 1];
        }
    }

    return positions;
}

std::vector<int> zFunction(const std::string &text) {
    int n = static_cast<int>(text.size());
    std::vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }

        while (i + z[i] < n && text[z[i]] == text[i + z[i]]) {
            ++z[i];
        }

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

std::vector<int> zSearch(const std::string &text, const std::string &pattern) {
    int pattern_size = static_cast<int>(pattern.size());

    auto z_func = zFunction(pattern + "#" + text);

    std::vector<int> positions;

    for (int i = pattern_size + 1; i < z_func.size(); ++i) {
        if (z_func[i] == pattern_size) {
            positions.push_back(i - (pattern_size + 1));
        }
    }

    return positions;
}
