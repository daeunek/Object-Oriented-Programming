#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
class GuessNumberGame{
public:
    // srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomNumber;
    int count=0;
    bool win= false;
    int guessnum;

    GuessNumberGame(): randomNumber{ std::rand() % 100 + 1} {};

    void play() {
        cout << randomNumber;

        while (true) {
            cout << "enter a num: "; 
            if (!(cin >> guessnum)) {
                cout <<"Invalid input"<<endl;
                break;
            }

            if (count == 10) {
                cout << "You lose!"<<endl;
                break;
            }else {

                if( guessnum < randomNumber) {
                    cout<<"greater than" << endl;
                    count = count + 1;

                }else if (guessnum > randomNumber) {
                    cout <<"less than " << endl;
                    count = count + 1;

                }else {
                    cout<<"Congratulations";
                    break;
                }
            }
        }
    }
};



int main() {
    // srand(static_cast<unsigned int>(std::time(nullptr)));
    srand(time(NULL));
    GuessNumberGame gg;

    gg.play();

    return 0;
}