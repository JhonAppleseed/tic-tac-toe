#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <map>
using namespace std;

class Player{
  private:
    string name;
    int wins = 0;
  public:
    Player(string x){
      this->name = x;
    }
    string getPlayerName(){ return this->name; }
    int getWins(){ return this->wins; }
    void incrementWin(){ this->wins++; }
};

class Game{
  private:
    vector<Player> players;
    vector<vector <char>> board = { {'#', '#', '#'}, {'#', '#', '#'}, {'#', '#', '#'}  };
  public:
    void runGame(Player& playerToStart, Player& nextPlayer);
    
    Game(Player x){
      this->players.push_back(x);
      Player player2("Mr. Robot");
      this->players.push_back(player2);

    }

    vector<Player>& getPlayersVector(){ return this->players; }
    void presentBoard();
    bool checkWinningLogic();
};

Player setupGame(){
  string playerInputName;
  cout << "Setup Game" << "\n\n";
  cout << "Player name: ";
  getline(cin, playerInputName);
  Player player1(playerInputName);
  return player1;
}

bool Game::checkWinningLogic(){ // TODO
  for (int row = 0; row < 3; row++){
    if (board[row][0] != '#' && board[row][0] == board[row][1] && board[row][1] == board[row][2]){
      return false;
    }
  }

  for (int col = 0; col < 3; col++){
    if (board[0][col] != '#' && board[0][col] == board[1][col] && board[1][col] == board[2][col]){
      return false;
    }
  }

  if (board[0][0] != '#' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
      return false;
    }
  if (board[0][2] != '#' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
      return false;
    }

  return true;
}

void Game::presentBoard(){
  for (auto& row : board){
    for (auto& value : row){
      cout << value << " ";
    }
    cout << " " << endl;
  }
}


void Game::runGame(Player& playerToStart, Player& nextPlayer){
  cout << "Game starting..." << endl;
  string currentPlayer = playerToStart.getPlayerName();
  int turns = 0;
  bool tie = false;
  while(true){
    turns++;
    int playerChoice;
    cout << "Player " << currentPlayer << "'s turn" << endl;
    presentBoard();
    while (true){
      cin.clear();
      cout << "Pick a square: ";
      cin >> playerChoice;
      if (playerChoice < 1 || playerChoice > 9){
        continue;
      }

      int firstIndex = (playerChoice-1) / 3;
      int secondIndex = (playerChoice-1) % 3;
      // cout << "(" << firstIndex << "," << secondIndex << ")" << endl;

      if (board[firstIndex][secondIndex] == '#'){
        cout << "Valid square" << endl;
        
        board[firstIndex][secondIndex] = (currentPlayer == playerToStart.getPlayerName()) ? 'X' : board[firstIndex][secondIndex] = 'O';
        break;
      }
    }
    if (!checkWinningLogic()) {
      presentBoard();
      break;
    } else if (turns >= 9) {
      tie = true;
      break;
    } else {
      currentPlayer = (currentPlayer == nextPlayer.getPlayerName()) ? playerToStart.getPlayerName() : nextPlayer.getPlayerName(); 
    }
  }
  if (tie == false) {
    Player& winner = (currentPlayer == playerToStart.getPlayerName()) ? playerToStart : nextPlayer;
    cout << winner.getPlayerName() << " won!" << endl;
    winner.incrementWin();
  }
  else {
    cout << "Game ended in a tie" << endl;
  }
  return;
}


int main(){
  cout << "Main triggered" << endl; 
  Game mainGame(setupGame());

  srand(time(0)); // FOR RANDOM SEED

  // GAMEPLAY LOOP
  int ans;
  while (true){
    cout << "Commands: " << "\n\n";
    cout << "1. New game" << endl;
    cout << "2. Check wins" << endl;
    cout << "3. Exit" << endl;
    cout << "->: ";
    cin >> ans;
    if (ans == 1){
      int randomPlayerInt = rand() % 2;
      Player& playerToStart = mainGame.getPlayersVector()[randomPlayerInt];
      Player& nextPlayer = mainGame.getPlayersVector()[1-randomPlayerInt];
      mainGame.runGame(playerToStart,nextPlayer);
    } else if (ans == 2){
        cout << mainGame.getPlayersVector()[0].getPlayerName() << ": " << mainGame.getPlayersVector()[0].getWins() << endl;
        cout << mainGame.getPlayersVector()[1].getPlayerName()  << ": " << mainGame.getPlayersVector()[1].getWins() << endl;
    } else if ( ans == 3 ){
      return 0;
    } else {
      continue;
    }
  }
   
  return 0;
}
