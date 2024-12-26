#include<iostream>
#include <string>


using namespace std;

const int currentyear = 2023;
const int currentdate = 28;
const int currentm = 12;

class HeartRateMonitor{
    private:
        string firstname;
        string lastname;
        int birthyear;
        int birthmonth;
        int birthday;
        int age;
        int maxHeartrate;
        int targetMin;
        int targetMax;

    public:
        HeartRateMonitor(string fname,string lname, int bYear, int bMonth,int bday)
        : firstname(fname), lastname(lname), birthyear(bYear), birthmonth(bMonth), birthday(bday) {
            calculateAge();
            calculateHeartRates();
        }

    void calculateAge() {

        if (currentm < birthmonth || currentm == birthmonth && currentdate < birthday){
            age = currentyear - birthyear -1;
        }
        else{
            age = currentyear - birthyear;
        }
        // return age;
    }

    void calculateHeartRates() {
         maxHeartrate = 220 - age;
         targetMax = static_cast<int> (0.85 * maxHeartrate);
         targetMin = static_cast<int> (0.5 * maxHeartrate);

    
    }

    void DisplayInfo() {
        cout << "\nHello, "<< age << " years old " << firstname << lastname << "."<< endl;
        cout << "Your max heart rate should be " << maxHeartrate << "beats per min." << endl;
        cout << "Your target heart rate range is " << targetMin << "-" << targetMax << " beats per min.";
    }
};

int main() {
    string firstname, lastname;
    int birthyear, birthmonth, birthday;

    cout<<"Enter your first name: ";
    cin >> firstname;

    cout<<"Ente your last name: ";
    cin >> lastname;

    cout <<"Enter your birth month: ";
    cin >> birthmonth;

    cout <<"Enter your birthyear: ";
    cin >> birthyear;

    cout << "Enter your birthdy: ";
    cin >> birthday;

    HeartRateMonitor userMonitor(firstname, lastname, birthyear, birthmonth, birthday);
    userMonitor.DisplayInfo();

    return 0;
}