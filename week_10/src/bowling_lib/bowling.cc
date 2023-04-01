#include "bowling.h"

namespace Bowling
{
  Game::Game(Player player)
    : player(player),
      frames(10, std::vector<int>(2)),
      current_frame(0),
      current_ball(0),
      total_score(0)
      {
      }

    int Game::get_score() {
      return total_score;
    }

    int Game::get_curr_ball() {
      return current_ball;
    }
}

