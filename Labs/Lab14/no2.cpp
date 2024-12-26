#include <iostream>
#include <vector>

double customSqrt(double num) {
    if (num == 0) return 0;
    double x = num / 2;
    double temp = 0;
    while (x != temp) {
        temp = x;
        x = (x + num / x) / 2;
    }
    return x;
}

void customSort(std::vector<double>& numbers) {
    bool swapped;
    size_t n = numbers.size();
    do {
        swapped = false;
        for (size_t i = 1; i < n; ++i) {
            if (numbers[i - 1] > numbers[i]) {
                std::swap(numbers[i - 1], numbers[i]);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
}


int main() {
    std::vector<double> numbers;
    double num;

    // Input loop
    std::cout << "Enter numbers (enter any non-numeric value to stop):" << std::endl;
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    // Check if any numbers were entered
    if (numbers.empty()) {
        std::cout << "No numbers entered. Exiting program." << std::endl;
        return 0;
    }

    // Calculate mean
    double sum = 0;
    for (double n : numbers) {
        sum += n;
    }
    double mean = sum / numbers.size();

    // Calculate median
    double median;
    size_t size = numbers.size();

    customSort(numbers);
    
    if (size % 2 == 0) {
        median = (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
    } else {
        median = numbers[size / 2];
    }

    // Calculate standard deviation
    double sum_squared_diff = 0;
    for (double n : numbers) {
        sum_squared_diff += (n - mean) * (n - mean);
    }
    double std_deviation = customSqrt(sum_squared_diff / numbers.size());

    // Calculate minimum and maximum
    double minimum = numbers[0];
    double maximum = numbers[0];
    for (double n : numbers) {
        if (n < minimum) {
            minimum = n;
        }
        if (n > maximum) {
            maximum = n;
        }
    }

    // Output results with two digits of precision
    std::cout.precision(2);
    std::cout << std::fixed;
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << "Standard Deviation: " << std_deviation << std::endl;
    std::cout << "Minimum: " << minimum << std::endl;
    std::cout << "Maximum: " << maximum << std::endl;

    return 0;
}
