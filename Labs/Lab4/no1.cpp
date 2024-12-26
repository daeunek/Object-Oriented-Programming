#include <iostream>
#include <vector>
using namespace std;

void lshift(vector<int>& vec, int num) {
    if (num >= vec.size()){
        vec.clear();
    }
    else{
        vec.erase(vec.begin(), vec.begin() +num);
    }
}

void rshift(vector<int>& vec, int num) {
    vec.insert(vec.begin(), num, 0);
}

int main() {
    vector<int> myvec = {1,2,3,4,5};

    lshift(myvec, 6);
    cout << "Left shift: ";
    for (int x: myvec) {
        cout << x << " ";
    }
    cout << endl;

    rshift(myvec, 3);
    cout << "Right shift: ";
    for (int x: myvec) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}