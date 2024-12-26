// #include<iostream>
// #include<limits>
// using namespace std;

// class TemperatureConverter{
//     public:
//         float cel2fah(float celsius){
//             return (celsius * 9.0 / 5.0) + 32.0;
//         }
//         float Fahr2Cel(float fahrenheit) {
//             return (fahrenheit - 32.0) * 5.0 / 9.0;
//     }
// };

// int main() {
//     while (true) {
//         cout << "Please enter a temp: ";
//         float temp; cin >> temp;
//         if (!cin) {
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(),'\n');//newline characters + remain ingnore
//             cout << "Invalid. Please enter a numeric integer.\n";
//             continue;
//         }
//         cout << "Plese enter your converted (C)for celsius and (F): ";
//         char choice; cin >> choice;

//         TemperatureConverter tc;
//         if (choice == 'C' || choice =='c'){
//             cout << temp << "Fahr is " << tc.Fahr2Cel(temp) << "Celsius." << endl;
//         }
//         else if (choice == 'F' || choice == 'f'){
//             cout << temp << "Cels is " << tc.cel2fah(temp) << "Fahr." << endl;
//         }
//         else{
//             cout << "Invalid choice." << endl;
//             continue;
//         }
//         cout << "Do you want to perform another conversion? (Y/N): ";
//         char ans; cin >> ans;

//         if (ans == 'N' || ans == 'n'){
//             break;
//         }        
//     }
//     return 0;
// }
//-----------------------------------------------------------------------//
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class GuessNumberGame {
    private:
        int chance, random_num, count;
    public:
        GuessNumberGame() : chance(10), count(0) {
            srand(time(nullptr));
            random_num = rand() % 101; //5 to 50 rand() % 46 + 5; 8 to 70 rand() % 63+8;
        }
        void play(){
            cout << "Enter your guess: ";
            int guess;
            while (count < chance){
                cin >> guess;
                count++;
                if(guess == random_num){
                    cout << "win\n";
                }
                else if(guess > random_num){
                    cout << "Random is lower than your number, Try again: ";
                }
                else {
                    cout << "random is higher than your num, Try again: ";
                }             
            }
            cout << "Lose the number is " << random_num << endl;;
        }
};

int main(){
    GuessNumberGame a;
    a.play();
    return 0;
}