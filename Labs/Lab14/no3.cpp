#include <iostream>

class Point {
private:
    int xCoordinate, yCoordinate;

public:
    // Constructor
    Point(int x = 0, int y = 0) : xCoordinate(x), yCoordinate(y) {}

    // Getter functions
    int getXCoordinate() const { return xCoordinate; }
    int getYCoordinate() const { return yCoordinate; }

    // Stream insertion operator overload (friend function)
    friend std::ostream& operator<<(std::ostream& out, const Point& point) {
        out << "(" << point.xCoordinate << ", " << point.yCoordinate << ")";
        return out;
    }

    // Stream extraction operator overload (friend function)
    friend std::istream& operator>>(std::istream& in, Point& point) {
        int x, y;
        if (!(in >> x >> y)){
            // If input conversion fails
            in.setstate(std::ios::failbit); // Set the fail bit on the stream
            return in;
        }
        // Input conversion succeeded
        point.xCoordinate = x;
        point.yCoordinate = y;
        return in;
    }
};

int main() {
    Point point;
    // Input from the user
    std::cout << "Enter the coordinates of the point:" << std::endl;
    std::cin >> point;
    // Check if input was successful
    if (!std::cin.fail()) {
        // Output the point
        std::cout << "The point is: " << point << std::endl;
    } else {
        // Input was invalid
        std::cerr << "Error: Invalid input." << std::endl;
    }
    return 0;
}
