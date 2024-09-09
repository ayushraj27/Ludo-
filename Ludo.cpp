#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


const int BOARD_SIZE = 40;

class Player {
public:
    string name;
    int position;
    Player(string n) : name(n), position(0) {}
};


int rollDie() {
    return rand() % 6 + 1;
}


void movePlayer(Player& player, int steps) {
    player.position = (player.position + steps) % BOARD_SIZE;
}

int main() {
    srand(time(nullptr)); 

  
    vector<Player> players;
    players.push_back(Player("Player 1"));
    players.push_back(Player("Player 2"));


    while (true) {
        for (auto& player : players) {
            cout << player.name << ", press Enter to roll the die...";
            cin.get(); 
            int steps = rollDie();
            cout << "You rolled a " << steps << ". ";
            movePlayer(player, steps);
            cout << "Your new position: " << player.position << endl;

            
            if (player.position == BOARD_SIZE - 1) {
                cout << player.name << " wins!" << endl;
                return 0; 
            }
        }
    }

    return 0;
}
