#include <iostream>
#include <vector>
using namespace std;

void lshift(vector<int>& vec, int num) {
    if (num >= vec.size()){
        vec.clear();
    }
    else{
        vec.erase(vec.begin(), vec.begin() +num);
    }
}

void rshift(vector<int>& vec, int num) {
    vec.insert(vec.begin(), num, 0);
}

int main() {
    vector<int> myvec = {1,2,3,4,5};

    lshift(myvec, 2);
    cout << "Left shift: ";
    for (int x: myvec) {
        cout << x << " ";
    }
    cout << endl;

    rshift(myvec, 3);
    cout << "Right shift: ";
    for (int x: myvec) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}
//------------------------------------------------------------------------//
// #include<iostream>
// #include<algorithm>
// #include<vector>

// using namespace std;

// void remove_neg(vector<double> &vec) {
//     vec.erase(remove_if(vec.begin(),vec.end(),[](double value){return value < 0;}), vec.end());   
// }

// int main(){
//     vector<double> vec{0.8, -5.1, 1.6, -6.5, 10.5};
//     cout << "Original vector: ";
//     for (double num : vec) {
//         cout << num << " ";
//     }
//     cout << "\n";
//     remove_neg(vec);

//     cout << "Vector after removing negative numbers: ";
//     for (double num : vec) {
//         cout << num << " ";
//     }
//     cout << "\n";

//     return 0;
// }
//--------------------------------------------------------------------------//
// #include <iostream>
// #include <list>
// #include <algorithm>
// using namespace std;

// void remove_negative(list<double> &lst) {
//     lst.remove_if([](double value) {
//         return value < 0;
//     });
// }

// int main() {
//     list<double> lst= {0.8, -5.1, 1.6, -6.5, 10.5};

//     cout << "\nOriginal list: ";
//     for (double num : lst) {
//         cout << num << " ";
//     }
//     remove_negative(lst);
//     cout << "\nList after removing negative numbers: ";
//     for (double num : lst) {
//         cout << num << " ";
//     }
//     cout << "\n";

//     return 0;
// }
//-------------------------------------------------------------------------//
// #include<iostream>
// #include<string>
// #include<vector>
// #include<limits>
// using namespace std;

// class Book{
// public:
//     string title, author;
//     int quantity;

//     Book(string t, string a, int q) : title(t), author(a), quantity(q) {}

//     string getTitle() const { return title; }
//     string getAuthor() const { return author; }
//     int getQuantity() const { return quantity; }

//     void setTitle(string t) { title = t; }
//     void setAuthor(string a) { author = a; }
//     void setQuantity(int q) { quantity = q; }
// };

// class Inventory {
//     public:
//         vector<Book> books;
//         void addBook(const Book &b) {
//             books.push_back(b);
//         }

//         void removeBook(const string &title) {
//             for(int i = 0; i < books.size(); ++i) {
//                 if (books[i].getTitle() == title) {
//                 books.erase(books.begin() + i);
//                 } else {
//                     continue;
//                 }
//             }
//         }
    
//         string findBook(string findTitle) {
//             for(const auto &book : books) {
//                 if (book.getTitle() == findTitle) {
//                     return "Title: " + book.getTitle() 
//                         + ", Author: " + book.getAuthor()
//                         + ", Quantity: " + to_string(book.getQuantity());
//                 }
//             }
//             return "Not found.";
//         }

//         void printInventory() {
//             if (books.empty()) {
//                 cout << "There is no book";
//             }
//             for (int i = 0; i < books.size(); ++i) {
//                 cout <<  "Book No." + to_string(i+1)
//                         + "\nTitle: " + books[i].getTitle() 
//                         + "\nAuthor: " + books[i].getAuthor()
//                         + "\nQuantity: " + to_string(books[i].getQuantity());
//             }
//         } 
// };

// int main(){
//     Inventory ek;
//     char command;
//     string title, author;
//     int quantity;

//     while(true){
//         cout << "Enter command (a: add, r: remove, s: search, l: list, q: quit): ";
//         cin >> command;

//         if (command == 'a' || command == 'A') {
//             cout << "Enter title: ";
//             cin.ignore(); 
//             getline(cin, title);
//             cout << "Enter author: ";
//             getline(cin, author);
//             cout << "Enter quantity: ";

//             if(!(cin>> quantity)){
//                 cin.clear();
//                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             }
//             ek.addBook(Book(title, author, quantity));
//         }
//         else if (command == 'r') {
//             cout << "Enter title to remove: ";
//             cin.ignore();
//             getline(cin, title);
//             ek.removeBook(title);
//             cout << "Book removed (if it existed)." << endl;
//         }
//         else if(command == 's'){
//             cout << "Enter title to find: ";
//             cin.ignore();
//             getline(cin, title);
//             string result = ek.findBook(title);
//             cout << result << endl;  
//         }
//         else if (command == 'l'){
//             ek.printInventory();
//         }
//         else if(command == 'q'){
//             break;
//         }
//         else{
//             cout << "Invalid " << endl;
//         }
//     }
//     return 0;
// }