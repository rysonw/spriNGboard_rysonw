#include "Game.h"

#include <iostream>
#include <sstream>

using namespace std;

std::ostream & operator<< (std::ostream & ostr, Category const & category)
{
  switch (category)
  {
    case Category::pop:
      ostr << "Pop";
      break;
    case Category::science:
      ostr << "Science";
      break;
    case Category::sports:
      ostr << "Sports";
      break;
    case Category::rock:
      ostr << "Rock";
      break;
    default:
      throw "ERROR: unknown category";
  };

  return ostr;
}

Board::Board (int32_t num_places)
  : m_num_places(num_places)
{ }

int32_t Board::get_new_place_idx (int32_t place_idx, int32_t roll) const
{ return (place_idx + roll) % m_num_places; }

BasicBoard::BasicBoard ()
  : Board(12)
{
  for (int32_t q_idx=0; q_idx<50; ++q_idx)
  {
    {
      std::ostringstream oss(std::ostringstream::out);
      oss << "Pop Question " << q_idx;
      m_pop_questions.push_back(Question{Category::pop, oss.str()});
    }
    {
      std::ostringstream oss(std::ostringstream::out);
      oss << "Science Question " << q_idx;
      m_science_questions.push_back(Question{Category::science, oss.str()});
    }
    {
      std::ostringstream oss(std::ostringstream::out);
      oss << "Sports Question " << q_idx;
      m_sports_questions.push_back(Question{Category::sports, oss.str()});
    }
    {
      std::ostringstream oss(std::ostringstream::out);
      oss << "Rock Question " << q_idx;
      m_rock_questions.push_back(Question{Category::rock, oss.str()});
    }
  }
}

Category BasicBoard::get_category_for_place_idx (int32_t place_idx) const
{
  vector<Category> categories = {
    Category::pop,
    Category::science,
    Category::sports,
    Category::rock
  };

  return categories[place_idx % 4];
}

Question BasicBoard::get_question_for_place_idx (int32_t place_idx)
{
  Category category = get_category_for_place_idx(place_idx);
  if (category == Category::pop) {
    if (m_pop_questions.size() == 0) {
      throw "no more Pop questions!";
    }
    auto question = m_pop_questions.front();
    m_pop_questions.pop_front();
    return question;
  }
  else if (category == Category::science) {
    if (m_pop_questions.size() == 0) {
      throw "no more Science questions!";
    }
    auto question = m_science_questions.front();
    m_science_questions.pop_front();
    return question;
  }
  else if (category == Category::sports) {
    if (m_pop_questions.size() == 0) {
      throw "no more Sports questions!";
    }
    auto question = m_sports_questions.front();
    m_sports_questions.pop_front();
    return question;
  }
  else if (category == Category::rock) {
    if (m_pop_questions.size() == 0) {
      throw "no more Rock questions!";
    }
    auto question = m_rock_questions.front();
    m_rock_questions.pop_front();
    return question;
  }
  else {
    throw "invalid category";
  }
}

Player::Player (std::string const & name)
  : m_name{name},
    m_purse{0},
    m_place_idx{0},
    m_is_in_penalty_box{false}
{ }

std::string Player::get_name () const
{ return m_name; }

int32_t Player::get_purse () const
{ return m_purse; }

void Player::set_purse (int32_t purse)
{ m_purse = purse; }

void Player::increment_purse ()
{ ++m_purse; }

int32_t Player::get_place_idx () const
{ return m_place_idx; }

void Player::set_place_idx (int32_t place_idx)
{ m_place_idx = place_idx; }

bool Player::get_is_in_penalty_box () const
{ return m_is_in_penalty_box; }

void Player::set_is_in_penalty_box (bool is_in_penalty_box)
{ m_is_in_penalty_box = is_in_penalty_box; }

BotPlayer::BotPlayer (std::string name, bool print_messages)
  : Player(move(name)),
    m_print_messages(print_messages)
{ }

void BotPlayer::display (std::string const & msg)
{
  if (m_print_messages) {
    std::cout << msg;
  }
}

int32_t BotPlayer::roll () const
{ return rand() % 5 + 1; }

bool BotPlayer::response_is_correct () const
{ return rand() % 9 != 7; }

Game::Game (
  Board & board,
  std::vector<reference_wrapper<Player>> const & players
)
  : m_board(board),
    m_players(players),
    m_cur_player_idx(-1)
{ }

void Game::play ()
{
  _add_players();

  while (!_is_winner())
  {
    auto & cur_player = _move_to_next_player();

    auto roll = cur_player.roll();

    {
      ostringstream ostr(std::ostringstream::out);
      ostr << cur_player.get_name()
           << " is the current player"
           << endl;
      ostr << "They have rolled a "
           << roll
           << endl;

      _broadcast(ostr.str());
    }

    _handle_player_turn(m_board, cur_player, roll);
  }
}

void Game::_handle_player_turn (
  Board & board,
  Player & cur_player,
  int32_t roll
)
{
  bool const is_getting_out_of_penalty_box = (roll % 2 == 1);

  if (cur_player.get_is_in_penalty_box())
  {
    if (!is_getting_out_of_penalty_box) {
      ostringstream ostr(std::ostringstream::out);
      ostr << cur_player.get_name()
           << " is not getting out of the penalty box"
           << endl;
      // preserve existing bug behavior
      if (!cur_player.response_is_correct()) {
        ostr << "Question was incorrectly answered" << endl;
        ostr << cur_player.get_name()
             << " was sent to the penalty box"
             << endl;
      }
      _broadcast(ostr.str());
      return;
    }
    else
    {
      // preserve existing bug behavior
      //cur_player.set_is_in_penalty_box(false);

      ostringstream ostr(std::ostringstream::out);
      ostr << cur_player.get_name()
           << " is getting out of the penalty box"
           << endl;
      _broadcast(ostr.str());
    }
  }

  cur_player.set_place_idx(
    m_board.get_new_place_idx(
      cur_player.get_place_idx(),
      roll
    )
  );

  Question question = m_board.get_question_for_place_idx(cur_player.get_place_idx());

  {
    ostringstream ostr(std::ostringstream::out);
    ostr << cur_player.get_name()
         << "'s new location is "
         << cur_player.get_place_idx()
         << endl;
    ostr << "The category is "
         << question.m_category
         << endl;
    ostr << question.m_text << endl;
    _broadcast(ostr.str());
  }

  bool response_is_correct = cur_player.response_is_correct();

  if (response_is_correct)
  {
    cur_player.increment_purse();

    ostringstream ostr(std::ostringstream::out);
    if (cur_player.get_is_in_penalty_box()) {
      ostr << "Answer was correct!!!!" << endl;
    }
    else {
      ostr << "Answer was corrent!!!!" << endl;
    }
    ostr << cur_player.get_name()
         << " now has "
         << cur_player.get_purse()
         << " Gold Coins."
         << endl;
    _broadcast(ostr.str());
  }
  else
  {
    cur_player.set_is_in_penalty_box(true);

    ostringstream ostr(std::ostringstream::out);
    ostr << "Question was incorrectly answered" << endl;
    ostr << cur_player.get_name()
         << " was sent to the penalty box"
         << endl;
    _broadcast(ostr.str());
  }
}

void Game::_add_players ()
{
  for (int32_t idx=0; idx<m_players.size(); ++idx)
  {
    auto & new_player = m_players[idx].get();
    new_player.set_place_idx(0);
    new_player.set_purse(0);

    if (idx == 0) {
      new_player.set_is_in_penalty_box(true);
    }
    else {
      new_player.set_is_in_penalty_box(false);
    }

    ostringstream ostr(std::ostringstream::out);
    ostr << new_player.get_name() << " was added" << endl;
    ostr << "They are player number " << (idx+1) << endl;
    _broadcast(ostr.str());
  }
}

bool Game::_is_winner ()
{
  bool winner = false;
  for (auto & player : m_players) {
    winner = winner || (player.get().get_purse() >= 6);
  }
  return winner;
}

Player & Game::_move_to_next_player ()
{
  m_cur_player_idx = (m_cur_player_idx + 1) % m_players.size();
  return m_players[m_cur_player_idx];
}

void Game::_broadcast (std::string const & msg)
{
  for (auto & player : m_players) {
    player.get().display(msg);
  }
}

