#include "bowling.h"
#include <stdexcept>

namespace Bowling
{
  Game::Game(Player player)
    : player(player),
      frames(10, std::vector<int>(2)),
      current_frame(1),
      current_ball(1),
      total_score(0)
      {
      }

    //Getters and Setters

    int Game::get_score() {
      return total_score;
    }

    int Game::get_curr_ball() {
      return current_ball;
    }
    

    //Class Functions
    
    bool Game::is_complete() {
        if (current_frame == 11) {
          return true;
        }

        else if (current_frame == 10) { //Last Frame
         return (frames[9][0] + frames[9][1] >= 10 && (current_ball == 3 || current_ball == 4)); //Check to see if the player is eligible for a third roll
        }

        else {
          return false;
        }
    }

    void Game::record_ball(int num_pins) {
      if (is_complete()) {
        throw std::runtime_error("Game has already finished");
      }

      if (num_pins < 0 || num_pins > 10) {
        throw std::invalid_argument("Invalid input");
      }

      frames[current_frame - 1][current_ball - 1] = num_pins;

      if (Game::get_curr_ball() == 1 && num_pins < 10) { //roll was not a strike
          current_ball++;
      }
      else {
        current_ball = 1;
        current_frame++;
      }
    }

    int player_roll() {
        int pinsHitThisRoll = 0;
        int frame_index = 0;
    }
}

