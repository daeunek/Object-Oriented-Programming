// #include<iostream>
// using namespace std;

// int main() {
//     int pennies, nickles, dimes, quarters;
//     cout << "Enter them:";
//     cin >> pennies >> nickles >> dimes >> quarters;
//     cout << pennies << nickles << dimes  ;
//     return 0;
// }
//-------------------------------------------------------------------------------//
// //set precison
// #include <iostream>
// #include<iomanip>
// using namespace std;

// int main() {
//     for (int i = 1; i < 7; i++){
//         cout << "precision " << i << ":\t" << setprecision(i) << 12.3456 << endl;
//     }
//     cout << "with no show point " << noshowpoint << 10.13 << endl;
//     cout << "with show point " << showpoint << 10.13 << endl;
//     return 0;
// }
//--------------------------------------------------------------------------------//
// #include<iostream>
// #include<string>
// using namespace std;

// int main() {
//     string name;
//     cout << "Please enter your first name: "; cin >> name;
//     const string greeting = "Hello " + name;
//     const int pad = 1;
//     const int rows = pad * 2 + 3;
//     const string:: size_type cols = greeting.size() + pad * 4;
//     cout << endl;
//     for (int r = 0; r!= rows; ++r){
//         string::size_type c = 0;
//         while (c!= cols) {
//             if (r == pad +1 && c == pad +1 ) {
//                 cout << greeting;
//                 c += greeting.size();
//             }
//             else{
//                 if ( r == 0 || r == rows-1 || c == 0 || c == cols -1) {
//                     cout << "*";
//                 }
//                 else{
//                     cout << " ";
//                 }
//                 ++c;
//             }
//         }
//         cout << endl;
//     }
//     return 0;
// }
//---------------------------------------------------------------------//
// size_type, typedef , auto , cout.precision(); ae drr brr loe 3 mhnn m thi
#include<algorithm>
#include<iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cout << "Please enter your first name:"; 
    string name; cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final exam grades:";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades, " "followed by end-of-file: ";
    vector<double> homework;
    double x;
    while (cin >> x){
        homework.push_back(x);    
    }
    cout << "Homework size: " << homework.size() << endl; 
    // typedef vector<double>:: size_type vec_sz;
    // vec_sz size = homework.size();
    if (homework.size() == 0) {
        cout << endl << "You must enter your grades. " "Please try again." << endl;
        return 1;
    }
    sort(homework.begin(), homework.end());
    for (auto i: homework){
        cout << i << endl;
    }
    auto mid = homework.size()/2;
    double median;
    median = homework.size()%2 == 0? (homework[mid] + homework[mid-1]) /2 : homework[mid];
    // auto prec = cout.precision();
    cout << "Grade is" << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * median << endl;
    return 0;
}