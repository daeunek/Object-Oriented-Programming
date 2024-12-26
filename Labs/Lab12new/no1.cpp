#include <iostream>
#include <vector>
#include <cstdlib>
#include<algorithm>

using namespace std;

class Pokemon {
protected:
    string name, sound, type;  //not constant needed
    int power, speed;
public:
    Pokemon(const string& n, const string& s, const string& t, int pow, int sped)
            : sound(s), type(t), power(pow), speed(sped){
                name = n;
    }

    string getName() const{return name;}
    string getSound() const{return sound;}
    string getType() const{return type;}
    int getPower() const {return power;}
    int getSpeed() const{return speed;}
};

class WildPoke : public Pokemon{

private:
    int catchRate;
public:
    WildPoke(const string& n, const string& s, const string& t, int pow, int sped, int catchr)
        :Pokemon(n,s,t,pow,sped){
            catchRate = catchr;
    }

    int getCatch() const{return catchRate;}

    void attemptEscape() {
        int escapeChance = getPower() + speed;
        if (escapeChance > 100) {
            cout << "Escaped" << getName();}
    }
};

class PalPoke: public Pokemon{
public:
    PalPoke(const string& n, const string& s, const string& t, int pow, int sped):Pokemon(n,s,t,pow,sped){}
};

class Pokeball {
private:
    string name;
    int efficiency;
public:
    Pokeball(const string& n, int eff){
        name = n;
        efficiency = eff;}

    bool catchPoke(WildPoke wildpoke){
        return efficiency > wildpoke.getCatch();}
    
    string getName() const{return name;}
    int getEff() const{return efficiency;}
    
};

class Berry{
private:
    string name;
    int effectiveness;

public:
    Berry(const string& p_name, int eff) {
        name = p_name;
        effectiveness = eff;
    }

    void effect(Pokeball& ball){
        int ballEff = ball.getEff();
        if (ballEff < 20) {
            ballEff += 20;
            effectiveness = 0;
        }
    }
};

class Player{
private:
    vector<Pokeball> balls;
    vector<PalPoke> fris;
    Berry berry;
public:

    Player(Berry &b):berry(b){}

    void addBalls(Pokeball ball){
        balls.push_back(ball);
        cout << "Added balls to collection.\n";
    }
    bool catchPoke(WildPoke &poke){
        if (balls.size() > 0) {
            if (balls[balls.size()-1].catchPoke(poke)){
                cout << "caught " << poke.getName();
                /// Remove elements greater than 3
                //vec.erase(remove_if(vec.begin(), vec.end(), [](int x){ return x > 3; }), vec.end());
                //it doesn't work now                wilds.erase(std::remove_if(wilds.begin(), wilds.end(), [a](const WildPoke &obj) { return obj.getName() == a; }), wilds.end());
                PalPoke fri(poke.getName(),poke.getSound(),poke.getType(), poke.getPower(),poke.getSpeed());
                fris.emplace_back(fri); // u can use push_back too
                balls.pop_back();
                return true; 
            }
            balls.pop_back();
        }

        return false;             
    }

    vector<Pokeball> getBalls(){
        return balls;
    }

    vector<PalPoke> getfriends(){
        return fris;
    }
};

class World{
private:
    vector<WildPoke> wilds;
    Player& player;
public:
    World(Player &p_player):player(p_player){}
    void addwilds(WildPoke &wild){
        wilds.push_back(wild);
    }

    void explore() {
        int index = rand() % 5 +0;
        cout << "Index " << index << "no of pokemons " << wilds.size() << endl;
        if (index < wilds.size()){
            cout << "encountered" << wilds[index].getName()<< endl;
            if (player.catchPoke(wilds[index])){
                string b = wilds[index].getName();
                wilds.erase(std::remove_if(wilds.begin(), wilds.end(), [b](const WildPoke &obj) {return obj.getName() == b;}), wilds.end());
            };
        }
        cout << " not encountered a wild pokemon./n";
    }

};

class GameTester {
public:
    void static testCatch() {
        cout << "Testing Catch Mechanics:\n";
        WildPoke poke("elf", "zz","ohio", 45, 20, 10);
        WildPoke poe("hj", "zz","ohio", 45, 20, 0);
        WildPoke pok("kkkk", "zz","ohio", 45, 20, 0);

        Pokeball ball("fire", 70);
        Pokeball ball1("water", 39);
        Berry ber("Hi", 50);
        Player ek(ber);

        World pokeworld(ek);
        pokeworld.addwilds(poke);
        pokeworld.addwilds(poe);
        pokeworld.addwilds(pok);

        ek.addBalls(ball);
        ek.addBalls(ball1);

        pokeworld.explore();

    }
};

int main(){
    WildPoke poke("elf", "zz","ohio", 45, 20, 10);
    WildPoke poe("hj", "zz","ohio", 45, 20, 0);
    WildPoke pok("kkkk", "zz","ohio", 45, 20, 0);

    Berry ber("Hi", 50);
    Player ek(ber);

    World pokeWorld(ek);
    pokeWorld.addwilds(poke);
    pokeWorld.addwilds(pok);
    pokeWorld.addwilds(poe);

    Pokeball ball("fire", 20);
    Pokeball ball2("air", 50);
    Pokeball ball1("water", 80);
   
    bool ballsAdded = false;


    while (true){
        cout << "Choose an action:\n";
        cout << "1. Add pokeballs\n";
        cout << "2. Walk\n";
        cout << "3. List Balls \n";
        cout << "4. List Caught Pokemon\n";
        cout << "5. Exit\n";

        int choice; cin  >> choice;

        switch(choice){
            case 1:
                if (ballsAdded){
                    cout << "Only have one chance to add your balls.\n";
                    break;
                }
                ballsAdded = true;
                for (int i = 0; i  < 5; i++) {
                        int num = rand() % 3 + 1;
                        if (num == 1){
                            ek.addBalls(ball);
                        }
                        else if (num == 2){
                            ek.addBalls(ball1);
                        }
                        else{
                            ek.addBalls(ball2);
                        }
                }
   
                break;
            
            case 2:
                pokeWorld.explore();
                break;
            case 3:
                for (int i = 0; i < ek.getBalls().size(); i++){
                    cout << ek.getBalls()[i].getName() << ":" << ek.getBalls()[i].getEff() << endl;
                }
                break;

            case 4:
                for (int i = 0; i < ek.getfriends().size(); i++){
                    cout << ek.getfriends()[i].getName()<< endl;
                }
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice\n";
                

        }
    }
    srand(time(0));
    // GameTester::testCatch();
    return 0;
}