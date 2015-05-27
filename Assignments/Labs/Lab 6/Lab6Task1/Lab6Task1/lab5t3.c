#include "lab5.h"
#include "lab5t3.h"

int task3_main (void)
{
	int number_to_guess = 0, number_guessed = 0,
		guesses = 0, game_state = 1, guess_state = 0;
	number_to_guess = rand() % 200 - 100;

	while (game_state == 1)
	{
		do 
		{
			printf ("Guess a number (-100 to 100): ");
			scanf (" %d", &number_guessed);
		} while (task3_valid_input (number_guessed) == 0);

		guess_state = task3_guess_control (number_to_guess, number_guessed);
		if (guess_state == 0)
		{
			game_state = 2;
		}
		guesses++;
	}
	while (game_state == 2)
	{
		printf ("Congratulations, you have guessed the number!\nYou guessed it in %d guesses!\n\n", guesses);
		game_state = -1;
	}
}

int task3_valid_input (int guessed)
{
	int valid_input = 1;
	if ((guessed > 100) || (guessed < -100))
	{
		valid_input = 0;
	}
	return valid_input;
}

int task3_guess_control (int number, int guessed)
{
	int guess_state = 0; // Correct guess
	if (guessed > number)
	{
		guess_state = 1; // too high
		printf ("Your number guessed was too High!\n");
	}
	else if (guessed < number)
	{
		guess_state = -1; // too low
		printf ("Your number guessed was too Low!\n");
	}
	return guess_state;
}