#pragma once

#include <string>
#include <vector>

namespace Bowling {

    class Player {
    public:
        Player(std::string name) {
            this->name = name;
        }

        std::string get_name() {
            return name;
        }

    private:
        std::string name;
    };

    class Game {
    public:
        Game(Player player);
        bool is_complete();
        void record_ball(int num_pins);
        int get_score();
        int get_curr_ball();
        std::vector<std::vector<int>> get_frames();

    private:
        Player player;
        std::vector<std::vector<int>> frames;
        int current_frame;
        int current_ball;
        int total_score;
    };

}  
