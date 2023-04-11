#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <set>
#include <vector>
#include "test.h"
#include "searching_algorithms.h"
#include "elementary_counter.h"

std::vector<std::string> generatePatterns(const std::string &substr, int count_of_extra_symbols) {
    std::vector<std::string> patterns;

    std::vector<char> alphabet;
    if (substr[0] == '0' || substr[0] == '1') {
        alphabet.emplace_back('0');
        alphabet.emplace_back('1');
    } else {
        alphabet.emplace_back('a');
        alphabet.emplace_back('b');
        alphabet.emplace_back('c');
        alphabet.emplace_back('d');
    }

    std::string copy_pattern;
    copy_pattern.resize(substr.size());
    std::copy(substr.begin(), substr.end(), copy_pattern.begin());
    int first_pos, second_pos, third_pos, fourth_pos;
    if (count_of_extra_symbols >= 1) {
        first_pos = static_cast<int>(copy_pattern.find('?'));
        copy_pattern[first_pos] = '-';
    }
    if (count_of_extra_symbols >= 2) {
        second_pos = static_cast<int>(copy_pattern.find('?'));
        copy_pattern[second_pos] = '-';
    }
    if (count_of_extra_symbols >= 3) {
        third_pos = static_cast<int>(copy_pattern.find('?'));
        copy_pattern[third_pos] = '-';
    }
    if (count_of_extra_symbols >= 4) {
        fourth_pos = static_cast<int>(copy_pattern.find('?'));
        copy_pattern[fourth_pos] = '-';
    }

    if (count_of_extra_symbols == 1) {
        for (char i : alphabet) {
            copy_pattern[first_pos] = i;
            patterns.push_back(copy_pattern);
        }
    } else if (count_of_extra_symbols == 2) {
        for (char i : alphabet) {
            copy_pattern[first_pos] = i;
            for (char j : alphabet) {
                copy_pattern[second_pos] = j;
                patterns.push_back(copy_pattern);
            }
        }
    } else if (count_of_extra_symbols == 3) {
        for (char i : alphabet) {
            copy_pattern[first_pos] = i;
            for (char j : alphabet) {
                copy_pattern[second_pos] = j;
                for (char k : alphabet) {
                    copy_pattern[third_pos] = k;
                    patterns.push_back(copy_pattern);
                }
            }
        }
    } else if (count_of_extra_symbols == 4) {
        for (char i : alphabet) {
            copy_pattern[first_pos] = i;
            for (char j : alphabet) {
                copy_pattern[second_pos] = j;
                for (char k : alphabet) {
                    copy_pattern[third_pos] = k;
                    for (char l : alphabet) {
                        copy_pattern[fourth_pos] = l;
                        patterns.push_back(copy_pattern);
                    }
                }
            }
        }
    } else {
        patterns.push_back(substr);
    }

    return patterns;
}

void launchTextViewer(const std::string &initial_text, std::ofstream *output, const std::string &info) {
    int text_size = static_cast<int>(initial_text.size());

    *output << info << ":\n";
    for (int i = 0; i < text_size; ++i) {
        *output << initial_text[i] << " ";
    }
    *output << "\n\n";
}

void launchTimeChecker(const std::string &initial_text, int pattern_size, int count_of_extra_symbols, std::ofstream *output, const std::string &info) {
    const int count_of_repeats = 10;
    const int count_of_tests = 4;
    const std::string tests[count_of_tests] { "Simple",     // Brute-force search algo.
                                              "Standard",   // Standard KMP search algo.
                                              "Modified",   // Modified KMP search algo.
                                              "Z-func"
    };
    int current_test = 0;

    long long nanoseconds;

    int pos = rand() % (static_cast<int>(initial_text.size()) - pattern_size);
    std::string substr = initial_text.substr(pos, pos + pattern_size);
    std::set<int> used_positions;
    for (int i = 0; i < count_of_extra_symbols; ++i) {
        do {
            pos = rand() % pattern_size;
        } while (used_positions.find(pos) != used_positions.end());
        used_positions.insert(pos);
        substr.insert(pos, "?");
    }
    auto patterns = generatePatterns(substr, count_of_extra_symbols);



    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (int i = 0; i < count_of_repeats; ++i) {
        auto start_time_point =  std::chrono::high_resolution_clock::now();
        auto _ = simpleSearch(initial_text, substr);
        auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
        nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
    }
    *output << nanoseconds / (count_of_repeats * static_cast<int>(patterns.size())) << "\n";



    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (const std::string &pattern : patterns) {
        for (int i = 0; i < count_of_repeats; ++i) {
            auto start_time_point =  std::chrono::high_resolution_clock::now();
            auto _ = lib_std::launchKnuthMorrisPratt(initial_text, pattern);
            auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
            nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
        }
    }
    *output << nanoseconds / (count_of_repeats * static_cast<int>(patterns.size())) << "\n";



    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (const std::string &pattern : patterns) {
        for (int i = 0; i < count_of_repeats; ++i) {
            auto start_time_point =  std::chrono::high_resolution_clock::now();
            auto _ = lib_mod::launchKnuthMorrisPratt(initial_text, pattern);
            auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
            nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
        }
    }
    *output << nanoseconds / (count_of_repeats * static_cast<int>(patterns.size())) << "\n";



    *output << info << tests[current_test++] << ";";
    nanoseconds = 0;
    for (const std::string &pattern : patterns) {
        for (int i = 0; i < count_of_repeats; ++i) {
            auto start_time_point =  std::chrono::high_resolution_clock::now();
            auto _ = zSearch(initial_text, pattern);
            auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time_point;
            nanoseconds += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();
        }
    }
    *output << nanoseconds / (count_of_repeats * static_cast<int>(patterns.size())) << "\n";
}

void launchCounterChecker(const std::string &initial_text, int pattern_size, int count_of_extra_symbols, std::ofstream *output, const std::string &info) {
    const int count_of_tests = 4;
    const std::string tests[count_of_tests] { "Simple",     // Brute-force search algo.
                                              "Standard",   // Standard KMP search algo.
                                              "Modified",   // Modified KMP search algo.
                                              "Z-func"
    };
    int current_test = 0;

    int pos = rand() % (static_cast<int>(initial_text.size()) - pattern_size);
    std::string substr = initial_text.substr(pos, pos + pattern_size);
    std::set<int> used_positions;
    for (int i = 0; i < count_of_extra_symbols; ++i) {
        do {
            pos = rand() % pattern_size;
        } while (used_positions.find(pos) != used_positions.end());
        used_positions.insert(pos);
        substr.insert(pos, "?");
    }
    auto patterns = generatePatterns(substr, count_of_extra_symbols);



    *output << info << tests[current_test++] << ";";
    global_counter = 0;
    auto __ = simpleSearchCounter(initial_text, substr);
    *output << global_counter / patterns.size() << "\n";



    *output << info << tests[current_test++] << ";";
    global_counter = 0;
    for (const std::string &pattern : patterns) {
        auto _ = count_std::launchKnuthMorrisPrattCounter(initial_text, pattern);
    }
    *output << global_counter / patterns.size() << "\n";



    *output << info << tests[current_test++] << ";";
    global_counter = 0;
    for (const std::string &pattern : patterns) {
        auto _ = count_mod::launchKnuthMorrisPrattCount(initial_text, pattern);
    }
    *output << global_counter / patterns.size() << "\n";



    *output << info << tests[current_test++] << ";";
    global_counter = 0;
    for (const std::string &pattern : patterns) {
        auto _ = zSearchCount(initial_text, pattern);
    }
    *output << global_counter / patterns.size() << "\n";
}
