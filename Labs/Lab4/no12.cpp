#include <iostream>
#include <vector>
#include <list>
using namespace std;

void remove_negative_vec(vector<double>& vec){
   cout << "Original Vector:";
   for ( double x : vec ) {
        cout << x << " ";
   }

   int i = 0;
   while ( i < vec.size()) {
        if ( vec[i] < 0 ) {
            vec.erase( vec.begin() + i, vec.begin() + i + 1 );
        }else {
            i++;
        }                   
   }

   cout << "\n" << "Vector after removing negative numbers: ";
   for ( double x : vec ) cout <<  x << " ";
   cout << endl;
}

void remove_negative_list(list<float>& lst){
    cout << "Original List: ";
    for (float x: lst) cout << x << " ";

    auto i = lst.begin();
    while ( i != lst.end()){
        if ( *i < 0){
           i = lst.erase(i);
        }else{
            i++;
        }
    }
    cout << "\n" << "List after removing negative numbers: ";
    for (double x: lst) cout << x << " ";

}

int main(){
    vector<double> vec {-0.8, -5.1, -1.6, -6.5, -10.5};   
    list<float> lst {0.8, 5.1, 1.6, 6.5, 10.5};

    remove_negative_vec(vec);
    remove_negative_list(lst);

    return 0;
}
