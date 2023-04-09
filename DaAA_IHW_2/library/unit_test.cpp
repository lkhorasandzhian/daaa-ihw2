#include <iostream>
#include "searching_algorithms.h"
#include "text_generator.h"

void binaryEasyUnitTest() {
    auto text = "1011111010111101000010";

    auto res_1 = simpleSearch(text, "101");
    auto res_2 = lib_std::launchKnuthMorrisPratt(text, "101");
    auto res_3 = lib_mod::launchKnuthMorrisPratt(text, "101");
    auto res_4 = zSearch(text, "101");

    if (res_1.size() != res_2.size() || res_2.size() != res_3.size() || res_3.size() != res_4.size()) {
        std::cout << res_1.size() << " " << res_2.size() << " " << res_3.size() << " " << res_4.size() << "\n";
        std::cout << "incorrect size\n";
        exit(-1);
    }

    int init_size = static_cast<int>(res_1.size());

    for (int i = 0; i < init_size; ++i) {
        if (res_1[i] != res_2[i]) {
            std::cout << "res_1 && res_2\n";
            exit(-1);
        }
    }

    for (int i = 0; i < init_size; ++i) {
        if (res_2[i] != res_3[i]) {
            std::cout << "res_2 && res_3\n";
            exit(-1);
        }
    }

    for (int i = 0; i < init_size; ++i) {
        if (res_3[i] != res_4[i]) {
            std::cout << "res_3 && res_4\n";
            exit(-1);
        }
    }
}

void binaryHardUnitTest() {
    auto text = generateRandomizedBinaryText(100'000);

    auto res_1 = simpleSearch(text, "101");
    auto res_2 = lib_std::launchKnuthMorrisPratt(text, "101");
    auto res_3 = lib_mod::launchKnuthMorrisPratt(text, "101");
    auto res_4 = zSearch(text, "101");

    if (res_1.size() != res_2.size() || res_2.size() != res_3.size() || res_3.size() != res_4.size()) {
        std::cout << res_1.size() << " " << res_2.size() << " " << res_3.size() << " " << res_4.size() << "\n";
        std::cout << "incorrect size";
        exit(-1);
    }

    int init_size = static_cast<int>(res_1.size());

    for (int i = 0; i < init_size; ++i) {
        if (res_1[i] != res_2[i]) {
            std::cout << "res_1 && res_2\n";
            exit(-1);
        }
    }

    for (int i = 0; i < init_size; ++i) {
        if (res_2[i] != res_3[i]) {
            std::cout << "res_2 && res_3\n";
            exit(-1);
        }
    }

    for (int i = 0; i < init_size; ++i) {
        if (res_3[i] != res_4[i]) {
            std::cout << "res_3 && res_4\n";
            exit(-1);
        }
    }
}
