#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Player{
  private:
    string name;
  public:
    Player(string x){
      this->name = x;
    }
    string getPlayerName(){ return this->name; }
};

class Game{
  private:
    vector<Player> players;
    vector<vector <char>> board;
  public:
    void runGame(Player playerToStart);
    
    Game(Player x){
      this->players.push_back(x);
      Player player2("Mr. Robot");
      this->players.push_back(player2);
    }

    vector<Player> getPlayersVector(){ return this->players; }
};

Player setupGame(){
  string playerInputName;
  cout << "Setup Game" << "\n\n";
  cout << "Player name: ";
  getline(cin, playerInputName);
  Player player1(playerInputName);
  return player1;
}

bool checkWinningLogic(){ // TODO
  cout << "Checking winning logic" << endl << endl;
  return false;
}

void Game::runGame(Player playerToStart){
  cout << "Game starting..." << endl;
  cout << "Starting player " << playerToStart.getPlayerName() << endl;
  type playerTurn = playerToStart;
  do{
  // 1. let playerToStart pick a square (input (1-9) + validate simple input)
  
  // 2. check if square is empty (validate square)
  
  // 3. check winning logic (return bool)
  
  // 4. switch turn
  playerTurn = 
  } while(!checkWinningLogic())
}


int main(){
  cout << "Main triggered" << endl; 
  Game mainGame(setupGame());

  for (auto& player : mainGame.getPlayersVector()){
    cout << player.getPlayerName() << endl;
  }  // DB LOOP FOR CHECKING PLAYERS

  srand(time(0)); // FOR RANDOM SEED

  // GAMEPLAY LOOP
  
  Player playerToStart = mainGame.getPlayersVector()[rand() % 2];
  mainGame.runGame(playerToStart);




  return 0;
}
