#include<iostream>
using namespace std;
#include<cstring>

void mystery1(char *, const char *);
bool mystery2(char *, const char *);


int main() {
    char string1[20];
    char string2[20];

    // Test Case 1: Concatenate and print
    cout << "Enter two strings for mystery1: ";
    cin >> string1 >> string2;
    mystery1(string1, string2);
    if (string1[0] != '\0'){
        cout << "Concatenated string: " << string1 << endl;
    
    }

    //Test Case 2: Substring
    cout << "Enter two strings: ";
    cin >> string1 >> string2;
    cout << "Is string2 a substing of string1? ";
    if (mystery2(string1, string2)) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

void mystery1(char *s1, const char *s2) {
    int len_s1 = 0;
    while (s1[len_s1] != '\0'){
        ++len_s1;
    }
    int len_s2 = 0;
    while (s2[len_s2] != '\0'){
        ++len_s2;
    }

    if (len_s1 + len_s2 <= 80) {
        while (*s1 != '\0') ++s1;
        for (; (*s1 = *s2); ++s1, ++s2);
    }
    else{
        s1[0] = '\0';
        cout << "Error: Insufficient space for concatenation." << endl;
    }
}

bool mystery2(char *s1, const char *s2){
    
    return strstr(s1, s2) != nullptr;
}

//purpose is to combine 2nd string after writing the first string. increment s1 pointer until it reaches the null terminator.
//It positions s1 at the end of the content in s1. For loop copies chars from s2 to s1 until '\0' in s2. It increments both s1 and s2 after each copy.
//(*s1=*s2) is a checkpoint for null terminator. in main, string1 will contain the content of both string1 and string2.


