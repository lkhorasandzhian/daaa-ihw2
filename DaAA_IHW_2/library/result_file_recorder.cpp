#include <fstream>
#include "result_file_recorder.h"
#include "text_generator.h"
#include "test.h"

void startProcess() {
    srand(time(NULL));

    std::ofstream viewer_output;
    std::string initial_texts[4];

    viewer_output.open("../../../test_view.txt");
    for (int i = 0; i < 4; ++i) {
        switch (i) {
            case 0:
                initial_texts[i] = generateRandomizedBinaryText(10'000);
                launchTextViewer(initial_texts[i], &viewer_output, "Randomized binary 10.000");
                break;
            case 1:
                initial_texts[i] = generateRandomizedBinaryText(100'000);
                launchTextViewer(initial_texts[i], &viewer_output, "Randomized binary 100.000");
                break;
            case 2:
                initial_texts[i] = generateRandomizedQuartetText(10'000);
                launchTextViewer(initial_texts[i], &viewer_output, "Randomized quartet 10.000");
                break;
            case 3:
                initial_texts[i] = generateRandomizedQuartetText(100'000);
                launchTextViewer(initial_texts[i], &viewer_output, "Randomized quartet 100.000");
                break;
            default:break;
        }
    }
    viewer_output.close();

    std::ofstream time_output, counter_output;
    for (int count_of_extra_symbols = 0; count_of_extra_symbols <= 4; ++count_of_extra_symbols) {
        time_output.open("../../../test_time_" + std::to_string(count_of_extra_symbols) + ".csv");
        counter_output.open("../../../test_counter_" + std::to_string(count_of_extra_symbols) + ".csv");
        for (int size = 100; size <= 3000; size += 100) {
            // Binary randomized 10'000.
            launchTimeChecker(initial_texts[0], size, count_of_extra_symbols, &time_output, "Binary 10'000;" + std::to_string(size) + ";");
            launchCounterChecker(initial_texts[0], size, count_of_extra_symbols, &counter_output, "Binary 10'000;" + std::to_string(size) + ";");

            // Binary randomized 100'000.
            launchTimeChecker(initial_texts[1], size, count_of_extra_symbols, &time_output, "Binary 100'000;" + std::to_string(size) + ";");
            launchCounterChecker(initial_texts[1], size, count_of_extra_symbols, &counter_output, "Binary 100'000;" + std::to_string(size) + ";");

            // Quartet randomized 10'000.
            launchTimeChecker(initial_texts[2], size, count_of_extra_symbols, &time_output, "Quartet 10'000;" + std::to_string(size) + ";");
            launchCounterChecker(initial_texts[2], size, count_of_extra_symbols, &counter_output, "Quartet 10'000;" + std::to_string(size) + ";");

            // Quartet randomized 100'000.
            launchTimeChecker(initial_texts[3], size, count_of_extra_symbols, &time_output, "Quartet 100'000;" + std::to_string(size) + ";");
            launchCounterChecker(initial_texts[3], size, count_of_extra_symbols, &counter_output, "Quartet 100'000;" + std::to_string(size) + ";");
        }
        counter_output.close();
        time_output.close();
    }
}
