// #include <iostream>
// using namespace std;

// void starline();
// int main() {
//     starline();
//     cout << "\nData type range" << endl;
//     starline();
//     return 0;
// }

// void starline() {
//     for (int j = 0; j < 45; j++) {
//         cout << "*";
//     }
// }
//--------------------------------------------------------------------------------------//
// //Passing a stucture
// #include<iostream>
// using namespace std;
// struct Distance{
//     int feet;
//     float inches;
// };

// void engldisp(Distance);

// int main() {
//     Distance d1, d2;
//     cout << "Enter feet: "; cin >> d1.feet;
//     cout << "Enter inches: "; cin >> d1.inches;
//     cout << "\nEnter feet: "; cin >> d2.feet;
//     cout << "Enter inches: "; cin >> d2.inches;
//     cout << "\nd1 =";
//     engldisp(d1);
//     cout << "\nd2=";
//     engldisp(d2);

// }

// void engldisp(Distance dd){
//     cout << dd.feet << "\'- " << dd.inches << "\"" << endl;
// }
//------------------------------------------------------------------------------------//
// //Passing by reference
// #include<iostream>
// using namespace std;

// int main() {
//     void intfrac(float, float&, float&);
//     float number, intpart, fracpart;
//     do {
//         cout << "Enter a real number: ";cin >> number;
//         intfrac(number, intpart, fracpart);
//         cout << "Integer part is " <<intpart;
//         cout << " fraction part is " << fracpart << endl;
//     }
//     while(number != 0.0);
//     return 0;
// }

// void intfrac(float n , float& intp, float& fracp) {
//     long temp = static_cast<long>(n);      //change it to long
//     intp = static_cast<float>(temp);         //back to float
//     fracp = n-intp;
// }
//--------------------------------------------------------------------------//
