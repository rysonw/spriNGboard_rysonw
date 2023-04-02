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

    void calculate_carryover(const std::vector<std::vector<int>>& frames, std::vector<int>& carryover) {
      int num_frames = frames.size();

      // Calculate carryover for spares
      for (int i = 0; i < num_frames - 1; i++) {
          if (frames[i][0] + frames[i][1] == 10) { // Spare
              carryover[i] = frames[i+1][0];
          }
      }

      // Calculate carryover for strikes
      for (int i = 0; i < num_frames - 2; i++) {
          if (frames[i][0] == 10) { // Strike
              if (frames[i+1][0] == 10) { // Double
                  carryover[i] = frames[i+1][0] + frames[i+2][0];
              } else { // Single
                  carryover[i] = frames[i+1][0] + frames[i+1][1];
              }
          }
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

      // Check if the frame is complete
      bool frame_complete = false;
      if (current_frame == 10) {
          // Last frame
          if (current_ball == 3 || (current_ball == 2 && (frames[9][0] + frames[9][1] < 10))) {
              frame_complete = true;
          }
      } else {
          // Regular frame
          if (current_ball == 2 || frames[current_frame - 1][0] == 10) {
              frame_complete = true;
          }
      }

      if (frame_complete) {
          // Calculate carryover and update score for completed frame
          std::vector<int> carryover(10, 0); // Initialize carryover vector to all zeros
          int frame_score = calculate_frame_score(frames[current_frame - 1], carryover, current_frame - 1);
          total_score += frame_score;
          // Add carryover to previous frames
          for (int i = current_frame - 2; i >= 0 && carryover[i] > 0; i--) {
              total_score += carryover[i];
          }
          // Reset current ball and frame
          current_ball = 1;
          current_frame++;
      } else {
          // Update current ball
          if (current_ball == 1 && num_pins < 10) {
              current_ball++;
          } else {
              current_ball = 1;
              current_frame++;
          }
      }
  }
}
