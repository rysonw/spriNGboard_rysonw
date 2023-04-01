#pragma once
#include <vector>
#include <string>

namespace Bowling
{
  class Game
  {
    Game(Player player) {
      this->player = player;
      std::vector<std::vector<int>> frames;
      int current_frame = 0;
      int current_ball = 0;
      int total_score = 0;
    }
    //public:
      
  };

  class Player
  {
    Player(std::string name) {
      this->name = name;
    }

    public:
      std::string get_name() {
        return name;
      };

    private:
      std::string name;
  }; 
}

