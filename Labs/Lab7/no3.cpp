#include<iostream>
#include<string>

using namespace std;

string Reverse(const string& a, int index){
    if (index == 0) {
        return string(1, a[index]);
    }
    else{
        return a[index] + Reverse(a, index -1);
    }
}

int main() {
    string user_input;
    cout << "Ente a string: "; getline(cin, user_input);

    string result = Reverse(user_input, user_input.length()-1);
    cout << result;

    return 0;
}
