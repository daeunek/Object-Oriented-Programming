#include <iostream>
#include <vector>

class MyClass {
public:
    MyClass(int a, double b) : x(a), y(b) {}

    void print() const {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }

private:
    int x;
    double y;
};

int main() {
    std::vector<MyClass> myVector;

    // Using push_back
    myVector.push_back(MyClass(10, 3.14)); // This requires a copy of the MyClass object

    // Using emplace_back
    myVector.emplace_back(20, 6.28); // This constructs the MyClass object directly in the vector

    std::cout << "Vector contents after emplace_back:" << std::endl;
    for (const auto& obj : myVector) {
        obj.print();
    }

    return 0;
}
