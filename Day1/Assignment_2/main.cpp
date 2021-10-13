#include <iostream>

int main() {
    int key;
    std::string cipher;
    std::cout << "Enter a key (0-26): ";
    std::cin >> key;
    std::cout << "Enter Cipher: ";
    std::cin >> cipher;


    for (char c : cipher) {
        char a = c - key;
        if (a < 'A') {
            std::cout << char(a + ('Z'-'A') + 1);
        } else {
            std::cout << a;
        }
    }
    std::cout << std::endl;
    return 0;
}