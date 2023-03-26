#include "Game.h"

#include <functional>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
  if (argc == 1) {
    srand(time(NULL));
  }
  else {
    unsigned seed = stoi(argv[1]);
    srand(seed);
  }

  BasicBoard board;

  BotPlayer chet("Chet", false);
  BotPlayer pat("Pat", true);
  BotPlayer sue("Sue", false);

  vector<reference_wrapper<Player>> players;
  players.emplace_back(ref(chet));
  players.emplace_back(ref(pat));
  players.emplace_back(ref(sue));

  Game game(board, players);

  game.play();
}

