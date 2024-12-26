// //Square
// #include<iostream>

// using namespace std;

// int main() {
//    for (int j = 0; j<15; j++) {
//     cout << (j*j)<< endl; 
//    }
//    return 0;

// }
// ________________________________________________________________________________________//

// //cube list
// #include<iostream>
// #include <iomanip>

// using namespace std;

// int main() {
//    for (int i =0; i < 11; i++) {
//       cout << i << setw(10) << (i * i * i) <<  endl;
//    }
//    return 0;
// }
// --------------------------------------------------------------------------------//

// //Factorial Calculation
// #include<iostream>

// using namespace std;

// int main() {
//    int num;
//    cout << "Enter a number: "; cin >> num;

//    int factorial = 1;

//    for (int i = num; i > 0; i--){
//       factorial *= i;
//    }
//    cout << "Factorial " << factorial << endl;

//    return 0;
// }

//---------------------------------------------------------------------------------//
// //Demonstrate While loop
// #include<iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//    int n = 0;
//    int fourth = 0;
//    while (fourth < 10000){
//       cout << n << setw(10) << fourth << endl;
//       n++;
//       fourth = n *n*n*n;
//    }
//    return 0;
// }

// ------------------------------------------------------------------------------//

//Fibonacci Numbers Calculation
// #include<iostream>

// using namespace std;

// int main() {
//    int a = 0;
//    long b = 1;
//    while (b < 100 ){
//       cout << b << endl;
//       int sum = a + b;
//       a = b;
//       b = sum;
//    }
//    return 0;
// }

// -------------------------------------------------------------------------------//
// //Do Loop
// #include <iostream>
// #include<cctype>

// using namespace std;
// int main() {
//    long a, b;
//    char ch;
//    do {
//       cout << "enter a: "; cin >> a;
//       cout << "enter b: "; cin >> b;
//       cout << "Quotient is " << a/b << " " << "Remainder is " << a%b << endl;
//       cout << "do another? (y/n): ";cin >> ch;
//    }
//    while (tolower(ch) != 'n');
//    return 0;
// }

//------------------------------------------------------------------------------------------//
// #include<iostream>
// using namespace std;
// bool isPrime(int numb) {
//    if (numb <= 1) {
//       return false;
//    }

//    for (int i =2; i <= numb/2; i++){
//       if (numb%i == 0){
//          return false;
//       }
//    }
//    return true;
// }

// int main() {
//    int numb;
//    cout << "Enter a number: "; cin >> numb;
//    if (isPrime(numb)){
//       cout << numb << " is a prime number." << endl;
//    } else {
//       cout << numb << " is not a prime number." << endl;
//    }
//    return 0;
// }
// --------------------------------------------------------------------------------------//
// #include<iostream>
// using namespace std;

// int main(){
//    int n,j;
//    cout << "Enter a number: ";cin >> n;
//    for (j=2; j <= n/2; j++){
//       if (n%j == 0){
//          cout << "not prime ";
//          exit(0);
//       }
//    }
//    cout << "Prime\n";
//    return 0;
// }

//-------------------------------------------------------------------------------//
// #include<iostream>
// using namespace std;

// int main(){
//    int n,j = 2;
//    cout << "Enter a number: ";cin >> n;
//    while (j <= n/2){
//       if (n%j == 0){
//          cout << "not prime ";
//          exit(0);
//       }
//       j++;
//    }
//    cout << "Prime\n";
//    return 0;
// }

//-----------------------------------------------------------------------------//
// #include<iostream>
// #include<string>

// using namespace std;

// int main() {
//     int charCount = 0, wordCount = 1;
//     string a;

//     cout << "Enter a phrase: "; 
//     getline(cin, a);

//     for (auto i : a) {
//         if (i == ' ') {
//             wordCount++;
//         } else {
//             charCount++;
//         }
//     }
//     cout << "Words: " << wordCount << endl;
//     cout << "Characters: " << charCount << endl;

//     return 0;
// }

// -----------------------------------------------------------------------------------------------------------//
// #include<iostream>
// #include<conio.h>
// using namespace std;

// int main() {
//     char dir = 'a';
//     int x = 10, y =10;
//     cout << "Type Enter to exit: ";
//     while (dir != '\r') {
//         cout << "\nYour location is " << x << "," << y << endl;
//         cout << "\nPress direction key(n,s,e,w): ";
//         dir = getche();
//         if (dir == 'n'){
//             y++;
//         }
//         else if (dir == 's'){
//             y--;
//         }
//     }
//     return 0;
// }

//--------------------------------------------------------------------------//
// // Demonstrate Switch Statement
// #include<iostream>
// using namespace std;

// int main() {
//     int speed;
//     cout << "\nEnter 33,45 or 78: ";cin >> speed;
//     switch(speed) {
//         case 33:
//             cout << "LP\n";
//             break;
//         case 45:
//             cout << "Single\n";
//             break;
//         case 78:
//             cout << "Obso\n";
//             break;
//     }
//     return 0;
// }

//==============================================================================//

// // conditional operator
// #include<iostream>
// using namespace std;

// int main() {
//     for (int j = 0; j < 80; j++){
//         char ch = (j%8) ? ' ':'x';
//         cout << ch;
//     }
//     return 0;
// }
//-----------------------------------------------------------------------------//

#include<iostream>
using namespace std;
int main() {
    long divideend, divisor;
    char ch;
    do {
        cout << "Enter dividend: ";cin >> divideend;
        cout << "enter divisor: "; cin >> divisor;
        if (divisor == 0){
            cout << "Invalid \n";
            continue;
        }
        cout << "Quotient is " << divideend/divisor;
        cout << ", Remainder is" << divideend%divisor;
        cout << "\n do another?(y/n)";        cin >> ch;
    }
    while (ch != 'n');
    return 0;
}