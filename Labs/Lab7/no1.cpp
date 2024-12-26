#include<iostream>
#include<array>
#include<iomanip>

using namespace std;

array<string, 5> dishes = {"Pad Thai", "Som Tam", "Mango Sticky Rice", "Tom Yum Goong", "Green Curry"};
array<array<int, 5>,10> responses;

void collectRatings() {
    for (int poll = 0; poll < 5; poll++){
        cout << "\nPoll " << poll+1 << endl;
        for (int dish = 0; dish < 5; dish++) {
            cout << "rate" << dishes[dish] << "on a scale of 1 to 10: ";
            do {
                cin >> responses[dish][poll];
                if (responses[dish][poll] < 1 || responses[dish][poll] > 10) {
                    cout << "Invalid rating" << endl;
                }
            }while (responses[dish][poll] < 1 || responses[dish][poll] > 10);
        }
    
    }
}

void displayResults() {
    cout << "\nSurvey Results: " << endl;
    cout << setw(20) << left <<  "Dish" << right;

    for (int i =0; i < 10; i++) {
        cout << i+1 << setw(5);
    }
    cout << setw(10) << "Average" << endl;
    int highestTotal = 0, lowestTotal = 5 *5 , highestIndex = 0, lowestIndex = 0;

    for (int dish =0; dish < 5; dish++) {
        cout << left << setw(20) << dishes[dish] << right;
        double total = 0.0;
        for (int rate = 0; rate < 10; rate++){
            cout << responses[dish][rate] << setw(5);
            total += (rate + 1) * responses[dish][rate];
        }
        double avg = total/(5*1.0);
        cout << setw(10) << avg << endl;

        if (total > highestTotal) {
            highestTotal = total;
            highestIndex = dish;
        }
        if (total < lowestTotal) {
            lowestTotal = total;
            lowestIndex = dish;
        }

    }
    cout << "Most popular dish: " << dishes [highestIndex] << "(" << highestTotal << " points)\n";
    cout << "Least Popular Dish: " << dishes[lowestIndex] << " (" << lowestTotal << " points)\n"; 

}

int main() {
    collectRatings();
    displayResults();
    return 0;
}