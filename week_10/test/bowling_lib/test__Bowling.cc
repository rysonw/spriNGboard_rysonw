#include "bowling.h"
#include <catch2/catch_test_macros.hpp>

class FakeGame {
public:
    FakeGame() : player_("Ryson"), game_(player_) {}

    Bowling::Player player_;
    Bowling::Game game_;
};

//is_complete() Tests

//record_ball() Tests

//get_score() Tests

TEST_CASE_METHOD(FakeGame, "Test game score with no pins hit") {
    // Test game score with no pins hit
    for (int i = 0; i < 20; i++) {
        game_.record_ball(0);
    }
    REQUIRE(game_.get_score() == 0);
}

TEST_CASE_METHOD(FakeGame, "Test game score with all pins hit") {
    // Test game score with all pins hit
    for (int i = 0; i < 12; i++) {
        game_.record_ball(10);
    }
    REQUIRE(game_.get_score() == 300);
}

TEST_CASE_METHOD(FakeGame, "Test game score with spare") {
    // Test game score with spare
    game_.record_ball(5);
    game_.record_ball(5);
    game_.record_ball(3);
    for (int i = 0; i < 17; i++) {
        game_.record_ball(0);
    }
    REQUIRE(game_.get_score() == 16);
}

TEST_CASE_METHOD(FakeGame, "Test game score with strike") {
    // Test game score with strike
    game_.record_ball(10);
    game_.record_ball(3);
    game_.record_ball(4);
    for (int i = 0; i < 16; i++) {
        game_.record_ball(0);
    }
    REQUIRE(game_.get_score() == 24);
}

