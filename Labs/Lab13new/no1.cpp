#include<iostream>
#include <vector>
#include <string>

using namespace std;

class SpaceObject{
protected:
    string type, color, shape;
public:
    SpaceObject(const string& t, const string& c, const string& s) : type(t), color(c), shape(s){}
    virtual ~SpaceObject() {}

    // virtual void draw() const{
    //     cout << "Drawing a generic shape\n";
    // }

    virtual void draw() const = 0;
};

class Martian : public SpaceObject{
public:
    Martian(const string& t, const string& c, const string& s) : SpaceObject(t, c, s){}
    void draw() const override{
        cout << "Drawing " << type <<  " with " << color << " color.\n";
    }
};

class Venutian : public SpaceObject{
public:
    Venutian(const string& t, const string& c, const string& s) : SpaceObject(t, c, s){}
    void draw() const override{
        cout << "Drawing " << type <<  " with " << color << " color.\n";
    }
};

class Plutonian : public SpaceObject{
public:
    Plutonian(const string& t, const string& c, const string& s) : SpaceObject(t, c, s){}
    void draw() const override{
        cout << "Drawing " << type <<  " with " << color << " color.\n";
    }
};

class Spaceship : public SpaceObject{
public:
    Spaceship(const string& t, const string& c, const string& s) : SpaceObject(t, c, s){}
    void draw() const override{
        cout << "Drawing " << type <<  " with " << color << " color.\n";
    }
};

class LaserBeam : public SpaceObject{
public:
    LaserBeam(const string& t, const string& c, const string& s) : SpaceObject(t, c, s){}
    void draw() const override{
        cout << "Drawing " << type <<  " with " << color << " color.\n";
    }
};

class Mercuian : public SpaceObject{
public:
    Mercuian(const string& t, const string& c, const string& s) : SpaceObject(t, c, s) {}
    void draw() const override{
        cout << "Drawing " << type << " with " << color << " color.\n";
    }   
};

class ScreenManager {
private:
    vector<SpaceObject*> space;
public:
    void add_objs(SpaceObject& obj){
        space.push_back(&obj);
    }
    void refreshScreen(){
        for (const auto* a: space) {
            a-> draw();
        }
    }
};

int main() {
    ScreenManager sm;
    Martian m("Martian", "blue", "s");
    Venutian n ("Venutian", "red", "s");
    Plutonian p("Pluto", "white","s");
    Spaceship s("ship", "yellow", "s");
    LaserBeam l("leaser", "green", "s");
    Mercuian me("Mercuian", "cyan", "c");
     
    sm.add_objs(m);
    sm.add_objs(n);
    sm.add_objs(p);
    sm.add_objs(s);
    sm.add_objs(l);
    sm.add_objs(me);

    sm.refreshScreen();
    return 0;
}