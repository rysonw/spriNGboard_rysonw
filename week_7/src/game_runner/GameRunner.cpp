#include "Game.h"

int main()
{

	srand(time(NULL));
	Game game;

	game.add("Chet");
	game.add("Pat");
	game.add("Sue");

	static bool notAWinner;

	do
	{

		game.roll(rand() % 5 + 1);

		if (rand() % 9 == 7)
		{
			notAWinner = game.handleWrongAnswer();
		}
		else
		{
			notAWinner = game.handleCorrectAnswer();
		}
	} while (notAWinner);

}
