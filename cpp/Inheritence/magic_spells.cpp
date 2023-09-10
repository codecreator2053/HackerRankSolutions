#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    Fireball* fi = dynamic_cast< Fireball* > (spell);
    Frostbite* fr = dynamic_cast< Frostbite* > (spell);
    Waterbolt* wa = dynamic_cast< Waterbolt* > (spell);
    Thunderstorm* th = dynamic_cast< Thunderstorm *> (spell);
    if (fi != nullptr) {fi->revealFirepower();}
    else if (fr != nullptr) {fr->revealFrostpower();}
    else if (wa != nullptr) {wa->revealWaterpower();}
    else if (th != nullptr) {th->revealThunderpower();}
    else{
        string scroll_name = spell->revealScrollName();
        string spell_journal = SpellJournal::journal;

        int s_size = scroll_name.length();
        int j_size = spell_journal.length();
        
        if(s_size == 1 && j_size == 1 && scroll_name == spell_journal){
            cout << 1 << endl;
        }
        else{
            vector<vector<int>> s(s_size+1, vector<int>(j_size + 1, 0));
            for(int i = 0; i < s_size; i++ ){
                for(int j = 0; j < j_size; j++){
                    s[i+1][j+1] = max(s[i][j] + (scroll_name[i] == spell_journal[j]), max(s[i+1][j], s[i][j+1]));
                }
            }
            cout << s[s_size][j_size] << "\n";
        }
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}