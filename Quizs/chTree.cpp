#include <iostream>

int main() {
    int height;

    // Input the height of the tree
    std::cout << "Enter the height of the Christmas tree: ";
    std::cin >> height;

    // Print the tree
    for (int i = 0; i < height; ++i) {
        // Print spaces before the stars
        for (int j = 0; j < height - i - 1; ++j) {
            std::cout << " ";
        }
        // Print stars
        for (int k = 0; k < 2 * i + 1; ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    // Print the trunk of the tree
    for (int i = 0; i < height / 3; ++i) {
        for (int j = 0; j < height - 1; ++j) {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }

    return 0;
}
