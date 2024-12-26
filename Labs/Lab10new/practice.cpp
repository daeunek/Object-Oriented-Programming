
#include <iostream>
#include <vector>
#include <algorithm>


//greater than phit tae kg ko shrr
using namespace std;

struct vec {
    int a, b;
};

int main() {
    vector<vec> air = { {1, 2}, {-4, 3} };
    auto it = find_if(air.begin(), air.end(), [&](vec& v) {
        return v.a > v.b;
    });

    if (it != air.end()) {
        cout << "found\n";
        cout << it->a << ": " << it->b;
    }

    sort(air.begin(),air.end(),[](vec& a, vec& b){return a.a < b.a;});
    for (const auto n: air){
        cout << n.a << "," << n.b << endl;
    }
    return 0;
}
