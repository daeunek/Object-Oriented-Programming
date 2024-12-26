// #include<iostream>
// using namespace std;

// int main()
// {
//     int ftemp;
//     cout << "Enter the fahrenhet temp: ";
//     cin >> ftemp;

//     int ctemp = (ftemp - 32) * (5.0/9.0);
//     cout << "Celsius is "<< ctemp << endl;

//     return 0;
// }

// ----------------------------------------------------------------------------------------//

// // circle area calculation
// #include <iostream>
// using namespace std;

// int main() {
//     float rad;
//     const float PI = 3.14159F;
//     cout << "Enter the radius of circle: ";
//     cin >> rad;
//     float area = PI * rad  * rad;
//     cout << "Area is " << area << endl;
//     return 0;
// }

// -------------------------------------------------------------------------------//

// // Display town and its population
// #include <iostream>
// #include <iomanip>    // to use setw and setw is used to add spaces but setw does not work for long spaces
// using namespace std;

// int main() {
//     long pop1 = 2425785, pop2 = 47, pop3 = 9761;
//     cout << setw(8) << "lOCATION " << setw(12) << " POP" << endl;
//     cout << setw(8) << "Koreamissutoooabc " << setw(12) << pop1 << endl;
//     cout << setw(8) << "India " << setw(12) << pop2 << endl;
//     cout << setw(8) << "China " << setw(12) << pop3 << endl;

//     return 0;

// }

// ------------------------------------------------------------------------------------------- //

// // mixed data types
// #include <iostream> 
// using namespace std;

// int main() {
//     int count = 7;
//     float avgWeight = 155.5F;
//     double totWeight = count * avgWeight; //accept integer * float , mixed data types calculation
//     cout << "Total weight = " << totWeight << endl;
//     char aChar = static_cast<char>(count); // will not see output and use to convert data types
//     cout << " achar " << aChar << endl;

//     return 0;
// }

// --------------------------------------------------------------------------------------------------------//

// // sqrt usage
// #include <iostream>
// #include <cmath>

// using namespace std;

// int main() {
//     double number, answer; // sqrt needs double data type
//     cout << "Enter a number: ";
//     cin >> number ;
//     answer = sqrt(number);
//     cout << "square root is " << answer << endl;

//     return 0;

// }

// ----------------------------------------------------------------------------------------//

/* Practice Problem 1:
Modify the "Display town and its population" code to format the population numbers
 with commas for better readability. For example, instead of displaying "2425785", 
 display "2,425,785". You can achieve this by using the std::setw and std::setfill 
 manipulators along with the std::fixed and std::setprecision manipulators for formatting.*/
//fixed will use not to display scientific notation.

#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

struct standardform : numpunct<char> {
    char do_thousands_sep() const override {        
        return ',';
    }

    string do_grouping() const override {
        return "\04";
    }
};

int main() {
    locale mylocale(locale(), new standardform);
    cout.imbue(mylocale);
    double pop1 = 1234567.09;
    long double pop2 = 4567890.165, pop3 = 657894561.345;
    cout << setw(20) << "location" << setw(20) << "pop" << endl;
    cout << setw(20) << "Koreamissutoooabc " << setw(20) << fixed << setprecision(2) <<  pop1 << endl; //set precision is to show decimal numbers (1) will show 1 decimal number 
    cout << setw(20) << "India " << setw(20) << fixed << setprecision(2) << pop2 << endl;
    cout << setw(20) << "China " << setw(20) << pop3 << fixed << setprecision(2) << endl;

    return 0;
}