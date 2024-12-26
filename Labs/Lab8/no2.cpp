#include<iostream>
#include <tuple>
#include<string>
using namespace std;

tuple<int, int> mystery3(const char*);

int main(){
    char string1[80];
    cout << "Enter a string: ";
    cin.getline(string1, sizeof(string1));
    tuple<int, int> len_count = mystery3(string1);
    cout << "Length of the string: " << get<0>(len_count) << endl;
    cout << "Vowel count: " << get<1>(len_count) << endl;
}

tuple<int, int> mystery3(const char *s){
    int length = 0;
    int vowel_count =0;
    for (int x=0; *s != '\0'; ++x){
        ++length;
        char ans = tolower(*s);
        if(ans == 'a' || ans =='e' || ans == 'i' || ans == 'o' || ans == 'u'){
            ++vowel_count;
        }
        ++s;
    }    
    return make_tuple(length, vowel_count);
}

void 