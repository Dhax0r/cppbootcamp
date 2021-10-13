#include <iostream>
#include <random>

int main() {

    unsigned int input_value;
    const size_t rows = 8;
    const size_t cols = 9;
    const size_t depth = 11;
    unsigned int result_array[rows][cols][depth];

    std::cout << "Enter a number: ";
    std::cin >> input_value;
    int random_number;
    for (size_t i = 0; i < depth; i++) {
        std::cout << "Layer: " << i + 1 << std::endl;
        for (size_t j = 0; j < cols; j++) {
            for (size_t k = 0; k < rows; k++) {
                random_number = rand() % input_value;
                result_array[k][j][i] = random_number;
                std::cout << "[" << random_number << "]";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }


    return 0;
}