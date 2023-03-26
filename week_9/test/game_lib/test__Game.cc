#include "Game.h"

#include <catch2/catch_test_macros.hpp>

#include <functional>
#include <vector>

using namespace std;

class FakePlayer : public Player
{
  public:
    FakePlayer () = delete;
    FakePlayer (string name)
      : Player(name),
        m_response_is_correct(true),
        m_was_asked_question(false)
    { }
    FakePlayer (FakePlayer const & orig) = default;
    FakePlayer (FakePlayer && orig) noexcept = default;
    FakePlayer & operator= (FakePlayer const & orig) = default;
    FakePlayer & operator= (FakePlayer && orig) noexcept = default;
    ~FakePlayer () = default;

    void set_respond_correctly (bool respond_correctly)
    { m_response_is_correct = respond_correctly; }

    bool get_was_asked_question () const
    { return m_was_asked_question; }

    void display (string const & msg) override
    { }

    int32_t roll () const override
    { return 0; }

    bool response_is_correct () const override
    {
      m_was_asked_question = true;
      return m_response_is_correct;
    }

  private:
    bool         m_response_is_correct;
    bool mutable m_was_asked_question;
};

SCENARIO ("player actions are handled correctly")
{
  GIVEN ("a valid Game")
  {
    FakePlayer player_1("1");
    FakePlayer player_2("2");
    FakePlayer player_3("3");

    vector<reference_wrapper<Player>> players;
    players.emplace_back(ref(player_1));
    players.emplace_back(ref(player_2));
    players.emplace_back(ref(player_3));

    BasicBoard board;

    Game game(board, players);
    game._add_players();

    player_2.set_place_idx(3);
    player_2.set_purse(3);
    player_2.set_is_in_penalty_box(false);

    int32_t roll = 3;

    AND_GIVEN ("a player is not in the penalty box")
    {
      player_2.set_is_in_penalty_box(false);

      AND_GIVEN ("that player responds correctly")
      {
        player_2.set_respond_correctly(true);

        WHEN ("the player turn is handled")
        {
          game._handle_player_turn(board, player_2, roll);

          THEN ("the player advances by the rolled amount") {
            REQUIRE(player_2.get_place_idx() == 6);
          }

          THEN ("the player is asked a question") {
            REQUIRE(player_2.get_was_asked_question() == true);
          }

          THEN ("the player is not sent to the penalty box") {
            REQUIRE(player_2.get_is_in_penalty_box() == false);
          }

          THEN ("the player gets one gold coin") {
            REQUIRE(player_2.get_purse() == 4);
          }
        }
      }

      AND_GIVEN("that player responds incorrectly")
      {
        player_2.set_respond_correctly(false);

        WHEN ("the player turn is handled")
        {
          game._handle_player_turn(board, player_2, roll);

          THEN ("the player advances by the rolled amount") {
            REQUIRE(player_2.get_place_idx() == 6);
          }

          THEN ("the player is asked a question") {
            REQUIRE(player_2.get_was_asked_question() == true);
          }

          THEN ("the player is sent to the penalty box") {
            REQUIRE(player_2.get_is_in_penalty_box() == true);
          }

          THEN ("the player does not get any gold coins") {
            REQUIRE(player_2.get_purse() == 3);
          }
        }
      }
    } // AND_GIVEN a player is not in the penalty box

    AND_GIVEN ("a player is in the penalty box")
    {
      player_2.set_is_in_penalty_box(true);

      AND_GIVEN ("that player responds correctly")
      {
        player_2.set_respond_correctly(true);

        AND_GIVEN ("the player rolls an odd number")
        {
          roll = 5;

          WHEN ("the player's turn is handled")
          {
            game._handle_player_turn(board, player_2, roll);

            THEN ("the player advances by the rolled amount") {
              REQUIRE(player_2.get_place_idx() == 8);
            }

            THEN ("the player is asked a question") {
              REQUIRE(player_2.get_was_asked_question() == true);
            }

            THEN ("the player does not get out of the penalty box") {
              REQUIRE(player_2.get_is_in_penalty_box() == true);
            }

            THEN ("the player gets one gold coin") {
              REQUIRE(player_2.get_purse() == 4);
            }
          }
        } // AND_GIVEN the player rolls an odd number

        AND_GIVEN ("the player rolls an even number")
        {
          roll = 4;

          WHEN ("the player's turn is handled")
          {
            game._handle_player_turn(board, player_2, roll);

            THEN ("the player does not advance by the rolled amount") {
              REQUIRE(player_2.get_place_idx() == 3);
            }

            THEN ("the player is asked a question") {
              REQUIRE(player_2.get_was_asked_question() == true);
            }

            THEN ("the player does not get out of the penalty box") {
              REQUIRE(player_2.get_is_in_penalty_box() == true);
            }

            THEN ("the player does not get any gold coins") {
              REQUIRE(player_2.get_purse() == 3);
            }
          }
        }
      } // AND_GIVEN that player responds correctly

      AND_GIVEN ("that player responds incorrectly")
      {
        player_2.set_respond_correctly(false);

        AND_GIVEN ("the player rolls an odd number")
        {
          roll = 5;

          WHEN ("the player's turn is handled")
          {
            game._handle_player_turn(board, player_2, roll);

            THEN ("the player advances by the rolled amount") {
              REQUIRE(player_2.get_place_idx() == 8);
            }

            THEN ("the player is asked a question") {
              REQUIRE(player_2.get_was_asked_question() == true);
            }

            THEN ("the player does not get out of the penalty box") {
              REQUIRE(player_2.get_is_in_penalty_box() == true);
            }

            THEN ("the player does not get any gold coins") {
              REQUIRE(player_2.get_purse() == 3);
            }
          }
        } // AND_GIVEN the player rolls an odd number

        AND_GIVEN ("the player rolls an even number")
        {
          roll = 4;

          WHEN ("the player's turn is handled")
          {
            game._handle_player_turn(board, player_2, roll);

            THEN ("the player does not advance by the rolled amount") {
              REQUIRE(player_2.get_place_idx() == 3);
            }

            THEN ("the player is asked a question") {
              REQUIRE(player_2.get_was_asked_question() == true);
            }

            THEN ("the player does not get out of the penalty box") {
              REQUIRE(player_2.get_is_in_penalty_box() == true);
            }

            THEN ("the player does not get any gold coins") {
              REQUIRE(player_2.get_purse() == 3);
            }
          }
        }
      }
    }
  }
}

