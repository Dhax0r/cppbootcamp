#include <iostream>
#include <random>

int main() {

    unsigned int input_value;
     size_t rows;
     size_t cols;
     size_t depth;
    //unsigned int result_array[rows][cols][depth];
    
    std::cout << "Enter size of array (row col depth): ";
    std::cin >> rows;
    std::cin >> cols;
    std::cin >> depth;
    unsigned int ***result_array = new unsigned int **[rows];
    for (size_t i = 0; i < rows; i++) {
        result_array[i] = new unsigned int * [cols];
    
        for (size_t j = 0; j < cols; j++) {
            result_array[i][j] = new unsigned int [depth];
        }
    }
    std::cout << "Enter a number: ";
    std::cin >> input_value;
    int random_number;
    for (size_t i = 0; i < depth; i++) {
        std::cout << "Layer: " << i + 1 << std::endl;
        for (size_t j = 0; j < cols; j++) {
            for (size_t k = 0; k < rows; k++) {
                random_number = rand() % input_value;
                result_array[i][j][k] = random_number;
                std::cout << "[" << random_number << "]";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    } 
     for (size_t i = 0; i < cols; i++){
         for (size_t j = 0; j < rows; j++) {
             delete[] result_array[i][j];
         }
         delete[] result_array[i];
     }
     delete[] result_array;
    return 0;
}