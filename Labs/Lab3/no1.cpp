#include <iostream>
#include <limits>

using namespace std;

class TemperatureConverter {
public:
    float cels;
    float fahr;

    void tofah(float cels) {
        fahr = cels * (9.0 / 5.0) + 32.0;
    }

    void tocel(float fahr) {
        cels = (fahr - 32.0) * (5.0 / 9.0);
    }
};

int main() {
    TemperatureConverter TempC;
    float temp;
    char choice;
    char exit;

    while (true) {
        cout << "Enter temperature: ";

        if (!(cin >> temp)) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Convert to cel or fah? Enter C or F: ";
        cin >> choice;

        if (choice == 'C') {
            TempC.tocel(temp);
            cout << temp << " Fahrenheit is " << TempC.cels << " Celsius" << endl;
        } else {
            TempC.tofah(temp);
            cout << temp << " Celsius is " << TempC.fahr << " Fahrenheit" << endl;
        }

        cout << "Do you want to exit? Enter Y/N: ";
        cin >> exit;

        if (exit == 'Y') {
            break;
        }
    }

    return 0;
}}
