// // #include <iostream>
// // #include <string>
// // #include <algorithm>

// // using namespace std;

// // void together(string p1, string p2){
// //     const int padding = 1;
// //     const int rows = padding * 2 + 3;

// //     const string::size_type cols = p1.size() + p2.size() + padding * 2 + 5;

// //     cout << endl;

// //     for (int r = 0; r < rows; r++){
// //         string::size_type c = 0;

// //         while(c < cols){
// //             if (r == padding + 1 && c == padding + 1){
// //                 cout << p1;
// //                 c += p1.size();
// //             }
// //             else if(r == padding + 1 && c == padding + 3 + p1.size() + padding){
// //                 cout << p2;
// //                 c += p2.size();
// //             }
// //             else if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1 || c == padding + 2 + p1.size()) {
// //                 cout << "*";
// //                 c++;
// //             }
// //             else{
// //                 cout << " ";
// //                 c++;
// //             }
// //         }
// //         cout << endl;
// //     }
// // }
        
// // void frame(string p1,string p2) {
// //     const int pad = 1;
// //     const int rows = pad * 4 +5;
// //     const string :: size_type cols = max(p1.size(), p2.size()) + pad + 3;
// //     cout << endl;
// //     for (int r = 0; r < rows; ++r) {
// //         string::size_type c = 0;
// //         while (c < cols){
// //             if (r == pad + 1 && c == pad + 1) {
// //                 cout << p1;
// //                 c += p1.size();
// //             }
// //             else if (r == pad + 5 && c == pad + 1){
// //                 cout << p2;
// //                 c += p2.size();
// //             }
// //             else if (r == 0 || r == rows - 1 || r == pad + 3 || c==0 || c == cols-1){
// //                 cout << "*";
// //                 c++;
// //             }
// //             else{
// //                 cout << " ";
// //                 c++;
// //             }
// //         }
// //         cout << endl;
// //     }
// // };

// // void frame_dash(string p1,string p2) {
// //     const int pad = 1;
// //     const int rows = pad * 4 +5;
// //     const string :: size_type cols = max(p1.size(), p2.size()) + pad + 3;
// //     cout << endl;
// //     for (int r = 0; r < rows; ++r) {
// //         string::size_type c = 0;
// //         while (c!= cols){
// //             if (r == pad + 1 && c == pad + 1) {
// //                 cout << p1;
// //                 c += p1.size();
// //             }
// //             else if (r == pad + 5 && c == pad + 1){
// //                 cout << p2;
// //                 c += p2.size();
// //             }
// //             else{
// //                 if (r == 0 || r == rows - 1 || r == pad + 3){
// //                     if (c == 0  || c == cols -1){
// //                         cout << "+";
// //                         c++;
// //                     }
// //                     else{
// //                         cout << "-";
// //                         c++;
// //                     }
// //                 }
// //                 else{
// //                     if (c== 0 || c == cols-1){
// //                         cout << "|";
// //                         c++;
// //                     }
// //                     else {
// //                         cout << " ";
// //                         ++c;
// //                     }
                    
// //                 }
// //             }
            
// //         }
// //         cout << endl;
// //     }
// // };

// // void frame_eq(string p1,string p2) {
// //     const int pad = 1;
// //     const int rows = pad * 4 +5;
// //     const string :: size_type cols = max(p1.size(), p2.size()) + pad + 3;
// //     cout << endl;
// //     for (int r = 0; r < rows; ++r) {
// //         string::size_type c = 0;
// //         while (c!= cols){
// //             if (r == pad + 1 && c == pad + 1) {
// //                 cout << p1;
// //                 c += p1.size();
// //             }
// //             else if (r == pad + 5 && c == pad + 1){
// //                 cout << p2;
// //                 c += p2.size();
// //             }
// //             else if (r == 0 || r == rows - 1 || r == pad + 3){
// //                 if (c == 0  || c == cols -1){
// //                     cout << "+";
// //                     c++;
// //                 }
// //                 else if (r == 0 || r == rows-1){
// //                     cout << "=";
// //                     c++;
// //                 }
// //                 else {
// //                     cout << "-";
// //                     ++c;
// //                 }
// //             }
// //             else{
// //                 if (c== 0 || c == cols-1){
// //                     cout << "|";
// //                     c++;
// //                 }
// //                 else {
// //                     cout << " ";
// //                     ++c;
// //                 }
                
// //             }
// //         }
// //         cout << endl;        
// //     }
// // }


// // int main()
// // {   
// //     cout << "Please enter person1 name: "; string p1name;
// //     getline(cin, p1name);
// //     cout << "Please enter person2 name: "; string p2name;
// //     getline(cin, p2name);

// //     string p1 = "Player 1 " + p1name;
// //     string p2 = "Plyer 2 " + p2name;
// //     together(p1, p2);
// //     frame(p1,p2);
// //     frame_dash(p1,p2);
// //     frame_eq(p1,p2);

// //     return 0;
// // }
// //--------------------------------------------------------------------------------------//
// // #include<iostream>
// // using namespace std;

// // void triangle(int size){
// //     for (int i = 0; i < size; i++){
// //         for (int j = 0; j < i+1 ; j++){
// //             cout << "*";
// //         }
// //         cout << endl;
// //     }
// // };

// // void arrow(int size){
// //     for(int i = 0; i < size; i++){
// //         for (int j = 0; j < i+1; j++){
// //             cout << "*";
// //         }
// //         cout << endl;
// //     }
// //     for (int i = 1; i < size; i++){
// //         for (int j = size-i; j>0 ; j--){
// //             cout << "*";
// //         }
// //         cout << endl;
// //     }
// // };

// // int main() {
// //     int n;
// //     cout << "Output size = "; cin >> n;
// //     triangle(n);
// //     cout << endl;
// //     arrow(n);
// //     return 0;
// // }
// //---------------------------------------------------------------------//
// #include<random>
// #include<iostream>
// #include<iomanip>
// #include<cmath>
// using namespace std;

// class Rand_double{
//     public:
//         Rand_double(double low, double high) : dist(low, high){
//             random_device rd;
//             re.seed(rd());
//         }
//         double operator()() {
//             return dist(re);
//         }
//     private:
//         default_random_engine re;
//         uniform_real_distribution<double> dist;
// };
// int main(){
//     const double rnd_min = -1.0, rnd_max = 1.0;
//     Rand_double rnd(rnd_min, rnd_max);

//     int N; cout << "Enter N: "; cin >> N;
//     int points_inside = 0;
//     for (int i =0; i < N; ++i){
//         double x = rnd();
//         double y = rnd();
//          if (x*x + y*y <=1){
//             ++points_inside;
//          }
//     }
//     double pi_estimate = 4.0 * points_inside/N;
//     cout << fixed << setprecision(4) << "Estimated Pi:" << pi_estimate << endl;

//     return 0;
// }

