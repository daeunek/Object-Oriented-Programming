#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>

using namespace std;

class Pokemon {
public:
    string name, sound, type;
    int power, speed;
    Pokemon(string names, string sounds, string types, int pow, int speeds ) {
        name = names;
        sound = sounds;
        type = types;
        power = pow;
        speed = speeds;
    }
    string getName() const {return name;}
    string getSount() const {return sound;}
    string getType() const {return type;}
    int getPower() const {return power;}
    int getSpeed() const {return speed;}
};

class WildPokemon : public Pokemon {
    public:
        int catchRate;
        WildPokemon(string names, string sounds, string types, int pow, int speed, int catchRate) 
        : Pokemon(names, sounds, types, pow, speed), catchRate(catchRate) {}

        int getRate() const {return catchRate;}

        bool attemptEscape() {
            int escapeChance = rand() % 100 + 0;
            return escapeChance > catchRate;
        }
};

class PalPokemon : public Pokemon {
    public:
        PalPokemon(string a,string b, string c, int pow, int speed ): Pokemon(a, b, c, pow, speed) {};

};

class Pokeball {
    public:
        string name; int efficiency;
        Pokeball(string names, int eff) : name(names), efficiency(eff) {};

        string getName() const {return name;}
        int geteff() const {return efficiency;}

        bool catchPokemon(WildPokemon& wild) {
            int wildEff= wild.getRate() * efficiency;
            int catchChance = rand() % 100 + 0;
            return catchChance > wildEff; //true catch
        }
};

class Berry {
    private:
        string name; int effectiveness;
    public:
        Berry(string name, int eff) : name(name), effectiveness(eff) {}

        void applyeffect(Pokeball &poke){
            poke.efficiency += effectiveness;
        }

};

class Player {
    private:
        vector<Pokeball> pokeballs;
        Berry* berry;
    public:
        Player() : berry(nullptr) {}

        void addPokeball(Pokeball &ball) {
            pokeballs.push_back(ball);
        }

        bool catchPoke(WildPokemon& wild){
            if (pokeballs.empty()) {
                cout << "Pokeballs not enough." << endl;
                return false;
            }

            //select random pokeball
            int index = rand() % pokeballs.size();
            Pokeball& selectedBall = pokeballs[index];

            //check if berry is here?
            if (berry != nullptr) {
                berry->applyeffect(selectedBall);
            }

            return selectedBall.catchPokemon(wild);
        }
};

class World{
    private:
        vector<WildPokemon>wildsCollection;
    public:
        World(vector<WildPokemon> wilds) : wildsCollection(wilds) {}

        void addWild(WildPokemon& wild){
            wildsCollection.push_back(wild);
        }

        void explore(Player& player) {
            if (wildsCollection.empty()) {
                cout << "No pokemon here.\n";
                return;
            }

            int index = rand() % wildsCollection.size();
            WildPokemon& encounteredPoke = wildsCollection[index];

            if (player.catchPoke(encounteredPoke)) {
                cout << "caught " << encounteredPoke.getName() << endl;
            }
            else{
                cout << encounteredPoke.getName() << " escaped.\n";
            }
        }
};


int main(){
    return 0;
}

       