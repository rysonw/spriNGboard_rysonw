#include "Game.h"

#include <iostream>
#include <sstream>

using namespace std;

Game::Game ()
  : places(6),
    purses(6),
    inPenaltyBox(6),
    currentPlayer(0)
{
  // preserve existing bug behavior
  inPenaltyBox[0] = true;

  for (int question_idx=0; question_idx<50; question_idx++)
  {
    {
      ostringstream oss(ostringstream::out);
      oss << "Pop Question " << question_idx;
      popQuestions.push_back(oss.str());
    }

    {
      ostringstream oss(ostringstream::out);
      oss << "Science Question " << question_idx;
      scienceQuestions.push_back(oss.str());
    }

    {
      ostringstream oss(ostringstream::out);
      oss << "Sports Question " << question_idx;
      sportsQuestions.push_back(oss.str());
    }

    {
      ostringstream oss(ostringstream::out);
      oss << "Rock Question " << question_idx;
      rockQuestions.push_back(oss.str());
    }
  }
}

bool Game::add (string playerName)
{
  players.push_back(playerName);
  int currPlayerIndex = players.size() - 1;
  places[currPlayerIndex] = 0;
  purses[currPlayerIndex] = 0;
  inPenaltyBox[currPlayerIndex] = false;

  cout << playerName << " was added" << endl;
  cout << "They are player number " << currPlayerIndex + 1 << endl;

  return true;
}

void Game::roll (int roll)
{
  cout << players[currentPlayer]
       << " is the current player"
       << endl;
  cout << "They have rolled a " << roll << endl;

  isGettingOutOfPenaltyBox = (roll % 2 != 0);

  if (inPenaltyBox[currentPlayer])
  {
    if (isGettingOutOfPenaltyBox) {
      cout << players[currentPlayer]
           << " is getting out of the penalty box"
           << endl;
    }
    else {
      cout << players[currentPlayer]
           << " is not getting out of the penalty box"
           << endl;
    }
  }

  if (!inPenaltyBox[currentPlayer] || isGettingOutOfPenaltyBox)
  {
    places[currentPlayer] = (places[currentPlayer] + roll) % 12;

    cout << players[currentPlayer]
         << "'s new location is "
         << places[currentPlayer]
         << endl;
    cout << "The category is "
         << currentCategory()
         << endl;

    askQuestion();
  }
}

void Game::askQuestion ()
{
  if (currentCategory() == "Pop")
  {
    cout << popQuestions.front() << endl;
    popQuestions.pop_front();
  }
  else if (currentCategory() == "Science")
  {
    cout << scienceQuestions.front() << endl;
    scienceQuestions.pop_front();
  }
  else if (currentCategory() == "Sports")
  {
    cout << sportsQuestions.front() << endl;
    sportsQuestions.pop_front();
  }
  else if (currentCategory() == "Rock")
  {
    cout << rockQuestions.front() << endl;
    rockQuestions.pop_front();
  }
}

string Game::currentCategory ()
{
  vector<string> categories = {
    "Pop", "Science", "Sports", "Rock"
  };
  return categories[places[currentPlayer] % 4];
}

bool Game::handleCorrectAnswer ()
{
  bool player_has_not_won = true;

  if (inPenaltyBox[currentPlayer] && !isGettingOutOfPenaltyBox) {
    player_has_not_won = true;
  }
  else
  {
    // preserve existing bug behavior
    //string correct = inPenaltyBox[currentPlayer];
    cout << "Answer was correct!!!!" << endl;

    purses[currentPlayer]++;
    cout << players[currentPlayer]
         << " now has "
         << purses[currentPlayer]
         <<  " Gold Coins."
         << endl;

    player_has_not_won = hasPlayerNotWon();
  }

  currentPlayer = (currentPlayer + 1) % players.size();

  return player_has_not_won;
}

bool Game::handleIncorrectAnswer ()
{
  cout << "Question was incorrectly answered" << endl;
  cout << players[currentPlayer]
       << " was sent to the penalty box"
       << endl;

  inPenaltyBox[currentPlayer] = true;

  currentPlayer = (currentPlayer + 1) % players.size();

  bool player_has_not_won = true;
  return player_has_not_won;
}

bool Game::hasPlayerNotWon ()
{
  return purses[currentPlayer] != 6;
}

