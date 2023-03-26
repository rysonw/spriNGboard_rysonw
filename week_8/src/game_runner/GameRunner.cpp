#include "Game.h"

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

  Game game;

  game.add("Chet");
  game.add("Pat");
  game.add("Sue");

  bool not_a_winner = true;

  do
  {
    game.roll(rand() % 5 + 1);

    if (rand() % 9 == 7)
    {
      not_a_winner = game.handleIncorrectAnswer();
    }
    else
    {
      not_a_winner = game.handleCorrectAnswer();
    }
  } while (not_a_winner);
}

