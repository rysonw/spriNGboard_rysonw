#include "bowling.h"
#include <catch2/catch_test_macros.hpp>

class FakeGame {
public:
    FakeGame() : player_("Ryson"), game_(player_) {}

    Bowling::Player player_;
    Bowling::Game game_;
};

//is_complete() Tests

TEST_CASE_METHOD(FakeGame, "Test game completeness when created") {
    // Test game completeness when created
    REQUIRE_FALSE(game_.is_complete());
}

TEST_CASE_METHOD(FakeGame, "Test game completeness in-game and when game is completed") {
    // Test game completeness at middle frame
    for (int i = 0; i < 9; i++) {
        game_.record_ball(0); // Roll a gutter ball for each ball in first 9 frames
    }
    REQUIRE_FALSE(game_.is_complete()); //Test game completion at fram 9 (mid-game)
    game_.record_ball(5); 
    game_.record_ball(5); 
    game_.record_ball(0); 
    REQUIRE(game_.is_complete()); // Complete gme and test completion check
}

//record_ball() Tests

TEST_CASE_METHOD(FakeGame, "Test record_ball() function with invalid inputs") {
    REQUIRE_THROWS_AS(game_.record_ball(-1), std::invalid_argument); // Test Negative Inpuit
    REQUIRE_THROWS_AS(game_.record_ball(11), std::invalid_argument); // Test <10 Input
    // for (int i = 0; i < 20; i++) {
    //     game_.record_ball(0);
    // }
    // REQUIRE_THROWS_AS(game_.record_ball(1), std::runtime_error); // Should throw runtime_error exception for attempting to roll after game is complete
}

// TEST_CASE_METHOD(FakeGame, "Test record_ball() function with valid input") {
//     // Test record_ball function with valid input
//     game_.record_ball(4);
//     REQUIRE(game_.frames[0][0] == 4); // Should move to the second ball after rolling a 4
// }

//get_score() Tests

// TEST_CASE_METHOD(FakeGame, "Test game score with no pins hit") {
//     for (int i = 0; i < 20; i++) {
//         game_.record_ball(0);
//     }
//     REQUIRE(game_.get_score() == 0);
// }

// TEST_CASE_METHOD(FakeGame, "Test game score with all pins hit") {
//     for (int i = 0; i < 12; i++) {
//         game_.record_ball(10);
//     }
//     REQUIRE(game_.get_score() == 300);
// }

// TEST_CASE_METHOD(FakeGame, "Test game score with spare") {
//     game_.record_ball(5);
//     game_.record_ball(5);
//     game_.record_ball(3);
//     for (int i = 0; i < 17; i++) {
//         game_.record_ball(0);
//     }
//     REQUIRE(game_.get_score() == 16);
// }

// TEST_CASE_METHOD(FakeGame, "Test game score with strike") {
//     game_.record_ball(10);
//     game_.record_ball(3);
//     game_.record_ball(4);
//     for (int i = 0; i < 16; i++) {
//         game_.record_ball(0);
//     }
//     REQUIRE(game_.get_score() == 24);
//}

