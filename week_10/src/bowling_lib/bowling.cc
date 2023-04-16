#include "bowling.h"
#include <stdexcept>
#include "bowling.h"
#include <iostream>

namespace Bowling
{
  Game::Game(Player player)
    : player(player),
      frames(10, std::vector<int>(3)), //[roll 1, roll 2, score at this frame]
      current_frame(1),
      current_ball(1)
      {
      }

    //Getters and Setters

    int Game::get_score() {
      return frames[current_frame - 1][2];
    }

    int Game::get_curr_ball() {
      return current_ball;
    }
    
    int Game::get_curr_frame() {
      return current_frame;
    }

    //Class Functions
    
    bool Game::is_complete() {
        if (current_frame == 11) {
          return true;
        }

        else if (current_frame == 10) { // Last Frame
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

      if (num_pins < 0 || num_pins > 10 || num_pins + frames[current_frame - 1][0] > 10) {
          throw std::invalid_argument("Invalid input");
      }
      
      //Spare = 10 + next roll
      //Strike = 10 + sum of next two rolls; Need to account for multiple strikes in a row
      
      //New Frame; Carryover score for prev frame
      if (current_frame != 1 && current_ball == 1) {
          frames[current_frame - 1][2] = frames[current_frame - 2][2];
      }
      
      frames[current_frame - 1][current_ball - 1] = num_pins;
      frames[current_frame - 1][2] = frames[current_frame - 1][2] + num_pins;
      bool frame_complete = false;
      //Roll has been completed and documented
      
      //Check for prev spares and strikes
      
        if (frames[current_frame - 1][0] + frames[current_frame - 1][1] == 10) { //Either spare or a strike
            if (current_frame != 1 && frames[current_frame - 2][0] == 10) { //Prev frame is strike
                if (get_curr_ball() == 1 && frames[current_frame - 1][0] == 10) { 
                    frames[get_curr_frame()][2] += 10;
                    // Check for a double or a turkey
                    if (current_frame >= 3 && frames[current_frame - 2][0] == 10 && frames[current_frame - 3][0] == 10) {
                        frames[get_curr_frame()][2] += 20; // Add 20 for a turkey
                    } else if (current_frame >= 2 && frames[current_frame - 2][0] == 10) {
                        frames[get_curr_frame()][2] += 10; // Add 10 for a double
                    } else {
                        // Add the score for the next two balls
                        frames[get_curr_frame()][2] += frames[current_frame - 1][1] + frames[current_frame][0];
                    }
                    // Move to the next frame
                    current_frame++;
                } else {
                    // Add the score for the current frame
                    frames[get_curr_frame()][2] += frames[current_frame - 1][0] + frames[current_frame - 1][1];
                    // Check for a spare
                    if (frames[current_frame - 1][0] + frames[current_frame - 1][1] == 10) {
                        // Add the score for the next ball
                        frames[get_curr_frame()][2] += frames[current_frame][0];
                    }
                    // Move to the next frame
                    current_frame++;
                }
            }
        } else { //Spare
            frames[current_frame - 1][2] += frames[current_frame - 1][0];
        }

      
      //Check to see what roll we are on
      if (current_frame == 10) {
          // Last frame
          if (current_ball == 3 || (current_ball == 2 && (frames[9][0] + frames[9][1] < 10))) {
              frame_complete = true;
          }
      } else {
          // Regular frame
          if (current_ball == 2 || frames[current_frame - 1][0] == 10) { //If we rolled twice or bowled a strike
              frame_complete = true;
              current_frame++;
              current_ball = 1;
          }
          
          else {
              current_ball++;
          }
      }
    }
}



int main() {
    Bowling::Player player("John");
    Bowling::Game game(player);
    
    game.record_ball(6);
    game.record_ball(4);


    // Print the frame data to the console
    std::cout << "Total Score: " << game.frames[1][2] << std::endl;
    std::cout << "Current Roll: " << game.get_curr_ball() << std::endl;
    std::cout << "Curr Frame: " << game.get_curr_frame() << std::endl;


    return 0;
}