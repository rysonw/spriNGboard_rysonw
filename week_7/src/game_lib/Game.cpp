#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <deque>

using namespace std;

Game::Game() : places{}, purses{}, currentPlayer(0){ //Initializes a Game Object
	unordered_map<string, list<string>*> questionDecks = {
		{"Pop", &popQuestions},
		{"Science", &scienceQuestions},
		{"Sports", &sportsQuestions},
		{"Rock", &rockQuestions}
	};
	createQuestions();
}

void Game::createQuestions() {
	for (int i = 0; i < 50; i++)
		{
			popQuestions.push_back(createQuestionString("Pop", i));
			scienceQuestions.push_back(createQuestionString("Science", i));
			sportsQuestions.push_back(createQuestionString("Sports", i));
			rockQuestions.push_back(createQuestionString("Rock", i));
		}
}

string Game::createQuestionString(const string& category, int index) {
	ostringstream oss;
    oss << category << " Question " << index;
    return oss.str();
}

// string Game::createRockQuestion(int index)
// {
// 	char indexStr[127];
// 	sprintf(indexStr, "Rock Question %d", index);
// 	return indexStr;
// }


bool Game::add(string playerName){
	players.push_back(playerName);
	places[players.size()] = 0;
	purses[players.size()] = 0;
	inPenaltyBox[players.size()] = false;

	cout << playerName << " was added" << endl;
	cout << "They are player number " << players.size() << endl;
	return true;
}

void Game::roll(int roll)
{
	cout << players[currentPlayer] << " is the current player" << endl;
	cout << "They have rolled a " << roll << endl;


	if (inPenaltyBox[currentPlayer])
	{
		if (roll % 2 == 1) //Rolled an odd number
		{
			isGettingOutOfPenaltyBox = true;
			cout << players[currentPlayer] << " is getting out of the penalty box" << endl;
		}
		else
		{
			cout << players[currentPlayer] << " is not getting out of the penalty box" << endl;
			isGettingOutOfPenaltyBox = false; //Not needed I believe as it should already be false
			return;
		}
	}

	places[currentPlayer] += roll;
	places[currentPlayer] = (places[currentPlayer] + roll) % 12;

	cout << players[currentPlayer] << "'s new location is " << places[currentPlayer] << endl;
	cout << "The category is " << currentCategory() << endl;
	askQuestion();
}

void Game::askQuestion()
{
	string category = currentCategory();
	list<string>* questionDeck = questionDecks.at(category);
    cout << questionDeck->front() << endl; // Ask question
    questionDeck->pop_front(); // Remove question from deck
}


string Game::currentCategory()
{
	string categories[] = {"Pop", "Science", "Rock", "Sports"};
    return categories[places[currentPlayer] % 4];
}

bool Game::handleCorrectAnswer()
{
	bool isWinner = false;
	if (inPenaltyBox[currentPlayer] && !isGettingOutOfPenaltyBox) {
		currentPlayer++;
		currentPlayer = (currentPlayer + 1) % players.size();
		return true;
	}

	if (inPenaltyBox[currentPlayer]) {
		cout << "Answer was correct!!!!" << endl;
	}
	else {
		cout << "Answer was corrent!!!!" << endl;
	}

	purses[currentPlayer]++;
	cout << players[currentPlayer] << " now has " << purses[currentPlayer] <<  " Gold Coins." << endl;

	bool isWinner = didPlayerWin();

	currentPlayer = (currentPlayer + 1) % players.size();
	return isWinner;
}



bool Game::handleWrongAnswer()
{
	cout << "Question was incorrectly answered" << endl;
	cout << players[currentPlayer] + " was sent to the penalty box" << endl;
	inPenaltyBox[currentPlayer] = true;

	currentPlayer++;
	currentPlayer = (currentPlayer + 1) % players.size();
	return true;
}


bool Game::didPlayerWin()
{
	return purses[currentPlayer] != 6;
}
