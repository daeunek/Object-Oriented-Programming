#include<iostream>
#include<vector>
#include <limits>
#include <string>

using namespace std;

//if not virtual const = 0 it will give error
class CarbonSystem {
public:
    CarbonSystem(){}
    virtual ~CarbonSystem() {}

    virtual double calculateCarbon() const= 0;
    virtual void display() const =0;
};

class Factory : public CarbonSystem{
private:
    int proHr, eneCom, wasteHr;
public:
    Factory(int p, int e, int w) {
        proHr = p;
        eneCom = e;
        wasteHr = w;
    }
    double calculateCarbon () const override{
        return (proHr*eneCom + wasteHr*proHr);
    }

    void display() const override {
        cout << "Factory carbon foorprint: " << calculateCarbon() << "tons of Co2\n";
    }
};

class Car : public CarbonSystem{
protected:
    int eneConsu;
    double fuel_eff;
public:
    Car(int p): eneConsu(p){}
    Car (int p, double fuel): eneConsu(p),fuel_eff(fuel) {}
    double calculateCarbon() const override{
        return(eneConsu * fuel_eff);
    }
    
    void display() const override {
        cout << "Car carbon foorprint: " << calculateCarbon() << "tons of Co2\n";
    }
};

class ElectricCar : public Car{
private:
    int battery, charge_eff;
public:
    ElectricCar(int p, int b, int charge) : Car(p) {
        battery = b;
        charge_eff = charge;
    }
    double calculateCarbon() const override{
        return (charge_eff * eneConsu);
    }
    
    void display() const override {
        cout << "ElectricCar carbon foorprint: " << calculateCarbon() << "tons of Co2\n";
    }
};

class Building : public CarbonSystem{
private:
    int no_occu; double eneCo;
public:
    Building(int no, double ene): no_occu(no), eneCo(ene){}
    
    double calculateCarbon() const override{
        return (eneCo*no_occu);
    }
    
    void display() const override {
        cout << "Building carbon foorprint: " << calculateCarbon() << "tons of Co2\n";
    }
};

class Bicycle : public CarbonSystem{
private:
    int manuHr; double emissions;
public:
    Bicycle(int manu, double em): manuHr(manu),emissions(em){}

    double calculateCarbon() const override{
        return (manuHr * emissions);
    }

    void display() const override {
        cout << "Bicycle carbon foorprint: " << calculateCarbon() << "tons of Co2\n";
    }
};

class AllCarbonFootprint{
private:
    vector<CarbonSystem*>system;
public:
    void addObjs(CarbonSystem& obj){
        system.push_back(&obj);
    }

    double totalFootprint() const{
        int total = 0;
        for (const auto* obj: system){
            total += obj->calculateCarbon();
        }
        return total;
    }

    void displayInfo() const{
        for (const auto* obj: system){
            obj->display();
        }
        cout << "toatal " << totalFootprint();

    }

};

double getUserInput(){
    double input;
    while(!(cin >> input) || input <= 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid Input";
    }

    return input;
}

int main(){
    AllCarbonFootprint all;
    //for car
    int eneconsu; double eff;
    cout << "Enter car's fuel consumption (liters) and fuel efficiency (km/liter): ";
    cin >> eneconsu >> eff;
    // eneconsu = getUserInput();
    // eff = getUserInput();

    //for building
    int no_occu; double eneB;
    cout << "Enter building's energy consumption (kWh) and number of occupants: ";
    eneB = getUserInput();
    no_occu = getUserInput();


    //for electric car
    int charge_eff; double eneE;
    cout << "Enter electric car's energy consumption (kWh) and charge efficiency (ratio): ";
    eneE = getUserInput();
    charge_eff = getUserInput();

    Car car(eneconsu, eff);
    Building building(no_occu, eneB);
    ElectricCar ecar(eneE, 0, charge_eff);

    all.addObjs(car);
    all.addObjs(building);
    all.addObjs(ecar);

    all.displayInfo();
    return 0;
}

// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     int num1, num2;
    
//     cout << "Enter two numbers separated by space: ";
//     cin >> num1 >> num2;

//     cout << "You entered: " << num1 << " and " << num2 << endl;

//     return 0;
// }
