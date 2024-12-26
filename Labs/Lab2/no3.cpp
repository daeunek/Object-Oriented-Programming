#include <random>
#include <iostream>
#include <iomanip>
#include <cmath>

class Rand_double {
public:
    Rand_double(double low, double high) : dist(low, high) {
        std::random_device rd;
        re.seed(rd());
    }

    double operator()() {
        return dist(re);
    }

private:
    std::default_random_engine re;
    std::uniform_real_distribution<double> dist;
};

int main() {
    const double rnd_min = -1.0, rnd_max = 1.0;
    Rand_double rnd(rnd_min, rnd_max);

    int N;
    std::cout << "Enter the number of points (N): ";
    std::cin >> N;

    int points_inside = 0;
    for (int i = 0; i < N; ++i) {
        double x = rnd();
        double y = rnd();
        if (x * x + y * y <= 1) {
            ++points_inside;
        }
    }

    double pi_estimate = 4.0 * points_inside / N;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Estimated Pi: " << pi_estimate << std::endl;

    return 0;
}
