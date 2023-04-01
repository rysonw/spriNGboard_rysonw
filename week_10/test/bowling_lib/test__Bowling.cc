#include "bowling.h"

#include <catch2/catch_test_macros.hpp>

SCENARIO("Game initialization tests")
{
  GIVEN("A newly created game") {
    std::string player_name = "Ryson";
    Bowling::Player player(player_name);
    Bowling::Game g(player);

    //THEN("The game should have correct player") {
      //REQUIRE(g.get_player().get_name() == player_name);
    //}

    //THEN("There should be no frames recorded") {
      //for (int i = 0; i < 10; i++) {
         // REQUIRE(g.get_frames()[i].empty());
        //}
    //}

    THEN("The current ball should be zero") {
      REQUIRE(g.get_curr_ball() == 0);
    }

    THEN("The current score should be zero") {
      REQUIRE(g.get_score() == 0);
    }
  }
}

