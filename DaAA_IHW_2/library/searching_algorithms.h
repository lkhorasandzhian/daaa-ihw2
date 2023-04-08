#ifndef DAAA_IHW_2_DAAA_IHW_2_LIBRARY_SEARCHING_ALGORITHMS_H_
#define DAAA_IHW_2_DAAA_IHW_2_LIBRARY_SEARCHING_ALGORITHMS_H_

#include <string>
#include <vector>

/// Наивный алгоритм с использованием простого посимвольного сравнения.
std::vector<int> simpleSearch(const std::string &text, const std::string &pattern);

/// Набор стандартных функций.
namespace lib_std {
    /// Алгоритм Кнута-Морриса-Прата с применением стандартных граней.
    std::vector<int> launchKnuthMorrisPratt(const std::string &text, const std::string &pattern);
}

/// Набор модифицированных функций.
namespace lib_mod {
    /// Алгоритм Кнута-Морриса-Прата с применением уточненных граней.
    std::vector<int> launchKnuthMorrisPratt(const std::string &text, const std::string &pattern);
}

#endif //DAAA_IHW_2_DAAA_IHW_2_LIBRARY_SEARCHING_ALGORITHMS_H_
