#pragma once

#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <vector>

enum class Category
{
  pop, science, sports, rock
};

std::ostream & operator<< (std::ostream & ostr, Category const & category);

struct Question
{
  Category    m_category;
  std::string m_text;
};

class Board
{
  protected:
    Board ();
    Board (int32_t num_places);
    Board (Board const & orig) = default;
    Board (Board && orig) noexcept = default;
    Board & operator= (Board const & orig) = default;
    Board & operator= (Board && orig) noexcept = default;
  public:
    virtual ~Board () = default;

  public:
    int32_t get_new_place_idx (int32_t place_idx, int32_t roll) const;

    virtual Category get_category_for_place_idx (int32_t place_idx) const = 0;
    virtual Question get_question_for_place_idx (int32_t place_idx) = 0;

  private:
    int32_t m_num_places;
};

class Player
{
  protected:
    Player () = delete;
    Player (std::string const & name);
    Player (Player const & orig) = default;
    Player (Player && orig) noexcept = default;
    Player & operator= (Player const & orig) = default;
    Player & operator= (Player && orig) noexcept = default;
  public:
    virtual ~Player () = default;

  public:
    std::string get_name () const;

    int32_t get_purse () const;
    void    set_purse (int32_t purse);
    void    increment_purse ();

    int32_t get_place_idx () const;
    void    set_place_idx (int32_t place_idx);

    bool get_is_in_penalty_box () const;
    void set_is_in_penalty_box (bool is_in_penalty_box);

    virtual void display (std::string const & msg) = 0;

    virtual int32_t roll () const = 0;

    virtual bool response_is_correct () const = 0;

  private:
    std::string m_name;
    int32_t m_purse;
    int32_t m_place_idx;
    bool    m_is_in_penalty_box;
};

class BotPlayer : public Player
{
  public:
    BotPlayer () = delete;
    BotPlayer (std::string name, bool print_messages);
    BotPlayer (BotPlayer const & orig) = default;
    BotPlayer (BotPlayer && orig) noexcept = default;
    BotPlayer & operator= (BotPlayer const & orig) = default;
    BotPlayer & operator= (BotPlayer && orig) noexcept = default;
    virtual ~BotPlayer () = default;

  public:
    virtual void display (std::string const & msg) override;

    virtual int32_t roll () const override;

    virtual bool response_is_correct () const override;

  private:
    bool m_print_messages;
};

class BasicBoard : public Board
{
  public:
    BasicBoard ();
    BasicBoard (BasicBoard const & orig) = default;
    BasicBoard (BasicBoard && orig) noexcept = default;
    BasicBoard & operator= (BasicBoard const & orig) = default;
    BasicBoard & operator= (BasicBoard && orig) noexcept = default;
    ~BasicBoard () = default;

    virtual Category get_category_for_place_idx (int32_t place_idx) const override;
    virtual Question get_question_for_place_idx (int32_t place_idx) override;

  private:
    std::deque<Question> m_pop_questions;
    std::deque<Question> m_science_questions;
    std::deque<Question> m_sports_questions;
    std::deque<Question> m_rock_questions;
};

class Game
{
  public:
    Game () = delete;
    Game (
      Board & board,
      std::vector<std::reference_wrapper<Player>> const & players
    );
    Game (Game const & orig) = delete;
    Game (Game && orig) = delete;
    Game& operator= (Game const & orig) = delete;
    Game& operator= (Game && orig) = delete;
    ~Game () = default;

  public:
    void play ();

    void _handle_player_turn (
      Board & board,
      Player & cur_player,
      int32_t roll
    );

    void _add_players ();

  private:
    void _broadcast (std::string const & msg);
    bool _is_winner ();
    Player & _move_to_next_player ();

  private:
    Board & m_board;
    std::vector<std::reference_wrapper<Player>> m_players;
    int32_t m_cur_player_idx;

#if 0
    bool add (std::string playerName);

    void roll (int roll);

    bool handleCorrectAnswer ();
    bool handleIncorrectAnswer ();

  private:
    void askQuestion ();
    std::string currentCategory ();
    bool hasPlayerNotWon ();

  private:
    std::vector<std::string> players;
    std::vector<int>         places;
    std::vector<int>         purses;
    std::vector<bool>        inPenaltyBox;

    std::list<std::string> popQuestions;
    std::list<std::string> scienceQuestions;
    std::list<std::string> sportsQuestions;
    std::list<std::string> rockQuestions;

    unsigned int currentPlayer;

    bool isGettingOutOfPenaltyBox;
#endif
};

