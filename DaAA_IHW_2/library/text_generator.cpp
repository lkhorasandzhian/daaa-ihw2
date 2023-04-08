#include "text_generator.h"

std::string generateRandomizedBinaryText(int size) {
    std::string text;
    text.reserve(size);

    for (int i = 0; i < size; ++i) {
        text += std::to_string(rand() % 2);
    }

    return text;
}

std::string generateRandomizedQuartetText(int size) {
    std::string text;
    text.reserve(size);

    std::string quartet = "abcd";

    for (int i = 0; i < size; ++i) {
        text += quartet[rand() % 4];
    }

    return text;
}
