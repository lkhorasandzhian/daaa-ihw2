#ifndef DAAA_IHW_2_DAAA_IHW_2_LIBRARY_ELEMENTARY_COUNTER_H_
#define DAAA_IHW_2_DAAA_IHW_2_LIBRARY_ELEMENTARY_COUNTER_H_

#include <string>
#include <vector>

/// Счётчик посимвольных сравнений в функциях из заголовка \b searching_algorithms.h .
extern unsigned long long global_counter;

/// Наивный алгоритм с использованием простого посимвольного сравнения.
std::vector<int> simpleSearchCounter(const std::string &text, const std::string &pattern);

/// Набор стандартных функций.
namespace count_std {
    /// Алгоритм Кнута-Морриса-Прата с применением стандартных граней.
    std::vector<int> launchKnuthMorrisPrattCounter(const std::string &text, const std::string &pattern);
}

/// Набор модифицированных функций.
namespace count_mod {
    /// Алгоритм Кнута-Морриса-Прата с применением уточненных граней.
    std::vector<int> launchKnuthMorrisPrattCount(const std::string &text, const std::string &pattern);
}

/// Дополнительный алгоритм с использованием Z-функции.
std::vector<int> zSearchCount(const std::string &text, const std::string &pattern);

#endif //DAAA_IHW_2_DAAA_IHW_2_LIBRARY_ELEMENTARY_COUNTER_H_
