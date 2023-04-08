#ifndef DAAA_IHW_2_DAAA_IHW_2_LIBRARY_TEXT_GENERATOR_H_
#define DAAA_IHW_2_DAAA_IHW_2_LIBRARY_TEXT_GENERATOR_H_

#include <string>

/// Создаёт текст заданного размера \b size, сгенерированный из символов '0' и '1'.
std::string generateRandomizedBinaryText(int size);

/// Создаёт текст заданного размера \b size, сгенерированный из символов 'a', 'b', 'c', 'd'.
std::string generateRandomizedQuartetText(int size);

#endif //DAAA_IHW_2_DAAA_IHW_2_LIBRARY_TEXT_GENERATOR_H_
