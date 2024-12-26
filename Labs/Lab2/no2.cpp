#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void draw_triangle(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void draw_arrow(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

int main(){
    string size;
    cout << "Enter the size: ";
    cin >> size;
    int n = stoi(size);
    draw_triangle(n);
    // draw_arrow(n);
    return 0;
}