#ifndef DAAA_IHW_2_DAAA_IHW_2_LIBRARY_TEST_H_
#define DAAA_IHW_2_DAAA_IHW_2_LIBRARY_TEST_H_

#include <fstream>

/// Вывод в файл сгенерированных исходных текстов.
void launchTextViewer(const std::string &initial_text, std::ofstream *output, const std::string &info);

/// Вывод в файл замеров времени работы всех сортировок заголовка \b searching_algorithms.h .
void launchTimeChecker(const std::string &initial_text, int pattern_size, int count_of_extra_symbols, std::ofstream *output, const std::string &info);

#endif //DAAA_IHW_2_DAAA_IHW_2_LIBRARY_TEST_H_
