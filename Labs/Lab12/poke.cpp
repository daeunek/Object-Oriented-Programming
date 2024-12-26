#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;


class Pokemon {

public:
    Pokemon(string p_name, string p_sound, string p_type, int p_power, int p_speed){
        name = p_name;
        sound = p_sound;
        type = p_type;
        power = p_power;
        speed = p_speed;
    }

    string get_name() const {
        return name;
    }
    void set_name(string nm) {
        name = nm;
    }
    string get_sound() const {
        return sound;
    }
    void set_sound(string s) {
        sound = s;
    }

    string get_type() const {
        return type;
    }
    void set_type(string ty) {
        type = ty;
    }
    int get_power() const {
        return power;
    }
    void set_power(int p){
        power = p;
    }

    int get_speed() {
        return speed;
    }
    void set_speed(int sp){
        speed = sp;
    }

private:

string name;
string sound;
string type;
int power;
int speed;

};


class WildPokemon: public Pokemon {

public:

    WildPokemon(string p_name, string p_sound, string p_type, int p_power, int p_speed, int rate)
    : Pokemon(p_name, p_sound, p_type, p_power, p_speed) {
        catchRate = rate;
    }

    int get_catch_rate() const {
        return catchRate;
    }

    bool attemptEscape() {
        return true;
        // return get_power() > ball.get_efficiency();

    }
private:

    int catchRate;

};


class Pokeball {
public:
    Pokeball(string p_name, int eff){
        name = p_name;
        efficiency = eff;
    }

    bool catchPokemon(WildPokemon wpok) {
        
        return wpok.get_power() < efficiency;
    }

    string get_name() const {
        return name;
    }
    void set_name(string p_name){
        name = p_name;
    }

    int get_efficiency() {
        return efficiency;
    }

    void set_efficiency(int eff){
        efficiency = eff;
    }


private:
    string name;
    int efficiency;
};

class PalPokemon: public Pokemon {

public:

    PalPokemon(string p_name, string p_sound, string p_type, int p_power, int p_speed)
    : Pokemon(p_name, p_sound, p_type, p_power, p_speed) {
    }

};


class Berry {
public:
    Berry(string p_name, int eff){
        name = p_name;
        efficiency = eff;
    }

    string get_name() const {
        return name;
    }
    void set_name(string p_name){
        name = p_name;
    }

    int get_efficiency() const {
        return efficiency;
    }

    void set_efficiency(int eff){
        efficiency = eff;
    }

    void apply_effect(Pokeball& ball) {
        ball.set_efficiency(ball.get_efficiency() + efficiency);
    }

private:
    string name;
    int efficiency;
};


class Player {

public:

    Player(const Berry& berry = Berry("", 0)) : berryball(berry) {};
    void add_pokeball(Pokeball ball) {
        pokeballs.push_back(ball);
    }

    void catchPokemon(WildPokemon wpok, vector<WildPokemon>& world) {
        
        if(pokeballs.size() <=0){
            cout<<"No balls! Game Over!!!"<<endl;
            exit(EXIT_SUCCESS);
        }
        if (pokeballs[pokeballs.size() -1].get_efficiency() >= wpok.get_power()) {
            cout<<"Got the Pokemon. Transfering to Friendly Pokemon"<<endl;
            PalPokemon pal(wpok.get_name(), wpok.get_sound(), wpok.get_type(), wpok.get_power(),
            wpok.get_speed());

            frineds.push_back(pal);
            // errase a pok from the world.
            string wpoke_name = wpok.get_name();
            world.erase(std::remove_if(world.begin(), world.end(),
                                [wpoke_name](const WildPokemon& obj) {
                                    return obj.get_name() == wpoke_name;
                                }),
                world.end());
        }else{
            cout<<"Ohhh Escape!!"<<endl;
        }

        pokeballs.pop_back();
    }

    vector<Pokeball> get_balls() {
        return pokeballs;
    }

    vector<PalPokemon> get_freinds() {
        return frineds;
    }

private:
    vector<Pokeball> pokeballs;
    vector<PalPokemon> frineds;
    Berry berryball;
};



class World {

public:

    void addWildPokemon(WildPokemon pok) {
        wildpokemons.push_back(pok);
    }

    void expolore(Player& player) {
        if(wildpokemons.size() <=0){
            cout<<"The world is empty!"<<endl;
            return;
        }

        int index = 0 + rand() % 10;
        if(index >= wildpokemons.size()){
            cout<<"This walk has not WildPokemon"<<endl;
        }else{
            cout<<"Found a pokemon. His name is : ";
            cout<< wildpokemons[index].get_name()<<endl;
            cout<<"Do you want to catch (y/ n) ? : ";
            char catch_pok;
            cin>> catch_pok;
            if(catch_pok =='y'){
                player.catchPokemon(wildpokemons[index], wildpokemons);
            }
        }
    }

    vector<WildPokemon> get_wildpoks() {
        return wildpokemons;
    }


private:
    vector<WildPokemon> wildpokemons;
};

class GameTester {

public:

    static void test() {

        Player player;
        bool balls_added= false;

        World world;

        // for(int i=0; i< 10; i++){
        world.addWildPokemon(WildPokemon("Pikachu", "Pika Pika!", "Electric", 50, 70, 50));
        // }
        world.addWildPokemon(WildPokemon("Pikachu", "Pika Pika!", "Electric", 50, 70, 50));
        world.addWildPokemon(WildPokemon("Charmander", "Char Char!", "Fire", 60, 40, 70));
        world.addWildPokemon(WildPokemon("Squirtle", "Squirt Squirt!", "Water", 55, 60, 60));
        world.addWildPokemon(WildPokemon("Bulbasaur", "Bulba Bulba!", "Grass", 45, 55, 55));
        world.addWildPokemon(WildPokemon("Jigglypuff", "Jiggly Jiggly!", "Fairy", 40, 45, 40));



        bool gameover = false;
        while (!gameover && world.get_wildpoks().size() > 0) {
            
            if(player.get_balls().size() <=0 && balls_added){
                cout<<"You have no more balls";
                break;
            }
            std::cout << "Choose an action:\n";
            std::cout << "1. Add Pokeballs to stock \n";
            std::cout << "2. Walk\n";
            std::cout << "3. List Balls \n";
            std::cout << "4. List Caught Pokemon\n";
            std::cout << "5. Exit\n";

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                
                if(balls_added){
                    cout<<"You only have on chance to load your balls"<<endl;
                    break;
                }
                balls_added = true;
                for(int i=0; i< 5; i++){
                    int type_index= 0+ rand() %2;
                    if(type_index==1){
                        player.add_pokeball(Pokeball{"Normal", 30+ rand() %30});
                    }else{
                        player.add_pokeball(Pokeball{"Ultra", 60 + rand()  %41});
                    }
                }
                    // player.add_pokeball(Pokeball{"Normal Ball",30});
                    // player.add_pokeball(Pokeball{"Ultra Ball",80});
                    // player.add_pokeball(Pokeball{"Super Ultra Ball",100});
                    // player.add_pokeball(Pokeball{"Super Ultra Ball",100});
                    // player.add_pokeball(Pokeball{"Super Ultra Ball",100});
                    break;
                case 2:
                    world.expolore(player);
                    break;
                case 3:
                    cout<<"List all balls : "<<endl;
                    for(Pokeball ball: player.get_balls()){
                        cout<<ball.get_name()<<" : "<< ball.get_efficiency()<<endl;
                    }
                    break;
                case 4:
                    cout<<"List all Caught Pokemons : "<<endl;
                    for(PalPokemon pok: player.get_freinds()){
                        cout<<pok.get_name()<<endl;
                    }
                    break;
                case 5:
                    exit(EXIT_SUCCESS);
                    break;
                default:
                    std::cout << "Invalid choice. Please choose again.\n";
            }
        }

        if(player.get_balls().size() <=0 && world.get_wildpoks().size() >0){
            cout<<"You loose the game!!!"<<endl;
        }else{
            cout<<"You win the game. All Poks are caught!"<<endl;
        }
        
    }

};


int main() {

    GameTester::test();
    return 0;
}