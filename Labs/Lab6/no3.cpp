// // /*
// // The main problem is when user inputs the negative value for b, it will not reach the base case.
// // */

// // #include <iostream>

// // using namespace std;

// // int mystery(int, int);

// // int main() {
// //     int num1 =0, num2 =0;

// //     cout << "Enter two integers: ";
// //     cin >> num1 >> num2;
// //     cout << "The result is " << mystery(num1,num2) << endl;

// //     return 0;
// // }


// // int mystery(int a, int b){
// //     if(b == 1) {
// //         return a;
// //     } 
// //     else if (b == 0) {
// //         return 0;
// //     }
// //     else if (b < 0) {
// //         b = abs(b);
// //         a = -a;
// //         return a + mystery(a, b-1);
// //     }
// //     else {
// //         return a + mystery(a, b-1);
// //     }
// // }

// // -----------------------------------------------------------------//
// #include <iostream>

// using namespace std;

// // int mystery(int, int);

// int main() {
//     int num1 = 0, num2 = 0;
//     cout << "Enter two integers (enter 'a' to exit): ";
//     cin >> num1 >> num2;
//     if (num2 >= 0) {
//         cout << "The result is " << mystery(num1, num2) << endl;
//     }
//     else if (num2 < 0) {
//         cout << "Please enter positive numbers." << endl;
//     }
// }

// // int mystery(int a, int b){
// //     if(b == 1) {
// //         return a;
// //     }
// //     else if (b == 0) {
// //         return 0;
// //     }
// //     else {
// //         return a + mystery(a, b-1);
// //     }
// // }

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double num = 123.450;
    cout << "Fixed: " << fixed << num << endl;
    cout << "scientific: " << scientific << num << endl;
    cout << "set precision and sci: " << setprecision(2) << scientific << num << endl;
    cout << "scientific and set precision: " << scientific << setprecision(2) << num << endl;
    cout << "set precision and fixed: " << setprecision(2) << fixed << num << endl;
    cout << "fix + set precision: " << fixed <<setprecision(4) << num << endl;
    return 0;

}