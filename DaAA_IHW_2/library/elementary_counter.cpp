#include "elementary_counter.h"

using namespace count_std;
using namespace count_mod;

unsigned long long global_counter = 0;

namespace private_count_std {
    bool isEqual(char a, char b) {
        return (a == b || a == '?' || b == '?');
    }

    std::vector<int> getPrefixesCounter(const std::string &pattern) {
        int m = static_cast<int>(pattern.size());

        std::vector<int> br(m);

        br[0] = 0;

        int k = 0;
        for (int i = 1; i < m; ++i) {
            while (k > 0 && pattern[i] != pattern[k]) {
                k = br[k - 1];
                ++global_counter;
            }
            ++global_counter;

            ++global_counter;
            if (pattern[i] == pattern[k]) {
                ++k;
            }

            br[i] = k;
        }

        return br;
    }
}

namespace private_count_mod {
    std::vector<int> getPrefixesCount(const std::string &pattern) {
        int m = static_cast<int>(pattern.size());

        std::vector<int> br(m);

        br[0] = 0;

        int k = 0;
        for (int i = 1; i < m; ++i) {
            while (k > 0 && pattern[i] != pattern[k]) {
                k = br[k - 1];
                ++global_counter;
            }
            ++global_counter;

            ++global_counter;
            if (pattern[i] == pattern[k]) {
                ++k;
            }

            br[i] = k;
        }

        std::vector<int> brs(m);

        brs[0] = 0;

        for (int i = 1; i < m; ++i) {
            ++global_counter;
            if (pattern[br[i]] != pattern[i + 1]) {
                brs[i] = br[i];
            } else {
                brs[i] = brs[br[i]];
            }
        }

        return brs;
    }
}


std::vector<int> simpleSearchCounter(const std::string &text, const std::string &pattern) {
    std::vector<int> positions;
    positions.reserve(text.length());

    for (int i = 0; i < text.length() - pattern.length() + 1; ++i) {
        bool flag = true;

        for (int j = 0; j < pattern.length(); ++j) {
            ++global_counter;
            if (!private_count_std::isEqual(text[i + j], pattern[j])) {
                flag = false;
                break;
            }
        }

        if (flag) {
            positions.push_back(i);
        }
    }

    return positions;
}

std::vector<int> count_std::launchKnuthMorrisPrattCounter(const std::string &text, const std::string &pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());

    auto prefixes = private_count_std::getPrefixesCounter(pattern);

    int count_of_equal = 0;

    std::vector<int> positions;
    positions.reserve(n);
    for (int i = 0; i < n; ++i) {
        while (count_of_equal > 0 && pattern[count_of_equal] != text[i] &&
            pattern[count_of_equal] != count_of_equal) {
            count_of_equal = prefixes[count_of_equal - 1];
            ++global_counter;
        }
        ++global_counter;

        ++global_counter;
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

std::vector<int> count_mod::launchKnuthMorrisPrattCount(const std::string &text, const std::string &pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());

    auto prefixes = private_count_mod::getPrefixesCount(pattern);

    int count_of_equal = 0;

    std::vector<int> positions;
    positions.reserve(n);
    for (int i = 0; i < n; ++i) {
        while (count_of_equal > 0 && pattern[count_of_equal] != text[i] &&
            pattern[count_of_equal] != count_of_equal) {
            count_of_equal = prefixes[count_of_equal - 1];
            ++global_counter;
        }
        ++global_counter;

        ++global_counter;
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

std::vector<int> zFunctionCount(const std::string &text) {
    int n = static_cast<int>(text.size());
    std::vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }

        while (i + z[i] < n && text[z[i]] == text[i + z[i]]) {
            ++z[i];
            ++global_counter;
        }
        ++global_counter;

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

std::vector<int> zSearchCount(const std::string &text, const std::string &pattern) {
    int pattern_size = static_cast<int>(pattern.size());

    auto z_func = zFunctionCount(pattern + "#" + text);

    std::vector<int> positions;

    for (int i = pattern_size + 1; i < z_func.size(); ++i) {
        if (z_func[i] == pattern_size) {
            positions.push_back(i - (pattern_size + 1));
        }
    }

    return positions;
}
