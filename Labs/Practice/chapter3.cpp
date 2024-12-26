// //Structures
// #include<iostream>
// #include<cmath>
// using namespace std;

// struct Distance{
//     int feet;
//     float inches;
// };

// int main() {
//     Distance d1, d3;
//     Distance d2 = {11, 6.25};
//     cout << "Enter feet: "; cin >> d1.feet;
//     cout << "enter inches:"; cin >> d1.inches;
//     d3.inches = d1.inches + d2.inches;
//     d3.feet = 0;
//     if (d3.inches >= 12.0) {
//         d3.feet = d3.inches/12.0;
//         d3.inches = fmod(d3.inches, 12);
//     }
//     d3.feet += d1.feet + d2.feet;
//     cout << d1.feet << "\'-" << d1.inches << "\"+";
//     cout << d2.feet << "\'-" << d2.inches << "\"=";
//     cout << d3.feet << "\'-" << d3.inches << "\"\n";
//     return 0;
// }
//-----------------------------------------------------------------------------//
// #include<iostream>
// using namespace std;
// const int clubs = 0;
// const int diamonds = 1;
// const int hearts = 2;
// const int spades = 3;
// const int jack = 11;
// const int queen = 12;
// const int king = 13;
// const int ace = 14;

// struct card{
//     int number;
//     int suit;
// };

// int main() {
//     card temp, chosen, prize;
//     int position;
//     card card1 = {7, clubs};
//     cout << "card 1 is the 7 of clubs\n";
//     card card2 = {jack, hearts};
//     cout << "card  is the jack of hearts\n";
//     card card3 = {ace, spades};
//     cout << "card is the ace of spades\n";
//     prize = card3;
//     cout << "I am swapping card1 and card3 \n";
//     temp = card3; card3 = card1; card1 = temp;
//     cout << "I am swapping card2 and card3\n";
//     temp = card3; card3 = card2 ; card2 = temp;
//     cout << "I am swapping card1 and card2\n";
//     temp = card2; card2 = card1; card1 = temp;
//     cout << "Where (1, 2, 3) is the ace of spades? "; cin >> position;
//     switch (position){
//         case 1: chosen = card1;break;
//         case 2: chosen = card2;break;
//         case 3: chosen = card3;break;
//     }
//     if (chosen.number == prize.number && chosen.suit == prize.suit){
//         cout << "Win\n";
//     }else {
//         cout << "Lose";
//     }
//     return 0;
// }
//---------------------------------------------------------------------------//
// #include<iostream>
// using namespace std;

// enum days {Sun, Mon, Tue, Wed, Thur, Fri, Sat};
// int main() {
//     days day1, day2;
//     day1 = Mon;
//     day2 = Thur;
//     int diff = day2 - day1;
//     cout << diff << endl;
//     if (day1 < day2) {
//         cout << "day1 comes before day2" << endl;
//     }
//     return 0;
// }
//-----------------------------------------------------------------------//
#include<iostream>
#include<string>
using namespace std;

enum isword{NO, YES};

int main() {
    string a;
    isword ques = NO;
    int wordcount = 0;
    char ch;
    cout << "Enter a phrase: ";getline(cin, a);
    for (auto ch : a) {
        if (ch == ' ' || ch == '\r' || ch == '\n' || ch == '\t') {
            if(ques == YES){
                wordcount++;
                ques = NO;
            }
        }
        else{
            if (ques == NO) {
                ques = YES;

            }
        }
    }
    if (ques == YES){       //for last element
        wordcount++;
    }
    cout << "\n word cout is " << wordcount << endl;
    return 0;
}
