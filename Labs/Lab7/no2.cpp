#include<iostream>
#include<ctime>
#include<array>
#include<iomanip>
using namespace std;

void generateRandom(int arr[], int size) {
    for (int i = 0; i < size; ++i){
        arr[i] = rand() % 100 + 1;
    }
}

int findMax(const int arr[],int size,int currentIndex, int currentMax) {
    if (currentIndex == size){
        return currentMax;
    }
    if (arr[currentIndex] > currentMax) {
        return findMax(arr, size, currentIndex + 1, arr[currentIndex]);
    }
    else {
        return findMax(arr, size, currentIndex +1, currentMax);
    }
}

int main() {
    const int arraySize = 10;
    int randomArray[arraySize];

    srand(static_cast<unsigned>(time(0)));
    generateRandom(randomArray, arraySize);

    cout << "Generated Numbers: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << randomArray[i] << " ";
    }
    int maxNum = findMax(randomArray, arraySize, 0,randomArray[0]);
    cout << "\nMax number = " << maxNum << endl;

    return 0;
  
}