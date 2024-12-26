#include <iostream>
#include <vector>

using namespace std;

int smallest_int(vector<int> v1) {
    int min = v1[0];
    for (auto i: v1) {
        if (i < min) {
            min = i;
        }
    }
    return min;
}

int main() {
    int num;
    cout << "Enter the number of integers: ";
    cin >> num ;

    if (num <= 0) {
        cout << "The number must be positive or greater than 0" << endl;
        return 1; 
    }
    cout << "Enter integers: " << endl;
    vector<int> integers;

    for (int i =0; i < num; i++) {
        int temp; cin >> temp;
        integers.push_back(temp);
    }

    cout << "Smallest integer is " << smallest_int(integers);
    return 0;
}