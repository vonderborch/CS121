#include "task3.h"

int task3_main (void)
{
	int max_guesses = 6,
		current_guesses = -1,
		i = 0,
		guessed[27],
		word_letters[10],
		victory = 0,
		letter = 0;
	char word[10],
		guess = '0';

	for (i = 0; i < 27; i++)
	{
		guessed[i] = 0;
		if (i < 10)
		{
			word[i] = '0';
			word_letters[i] = 0;
		}
	}

	random_word (word, word_letters);

	while ((max_guesses > current_guesses) && (!victory))
	{
		victory = check_victory (word_letters, guessed);
		if (!victory)
		{
			current_guesses++;
		}
		printf ("Guesses Left: %d\nGuess a Letter...", max_guesses - current_guesses);
		_flushall ();
		scanf ("%c", &guess);
		letter = char_convert (guess) - 1;
		guessed[letter]++;
	}

	pause_clear (0, 1);
	if (victory)
	{
		printf ("You guessed the word!\n");
	}
	else
	{
		printf ("You didn't guess the word!\n");
	}

	pause_clear (1, 1);
	return 0;
}

void random_word (char word[10], int word_letters[10])
{
	int random_word = 0, i = 0,
		words = 3, letters = 0;
	srand((unsigned)time(NULL));
	random_word = rand () % words;
	if (random_word == 0)
	{
		letters = 4;
		word[0] = 'T';
		word[1] = 'H';
		word[2] = 'E';
		word[3] = 'E';
	}
	else if (random_word == 1)
	{
		letters = 3;
		word[0] = 'C';
		word[1] = 'A';
		word[2] = 'T';
	}
	else if (random_word == 2)
	{
		letters = 5;
		word[0] = 'W';
		word[1] = 'H';
		word[2] = 'E';
		word[3] = 'R';
		word[4] = 'E';
	}
	else if (random_word == 3)
	{
		letters = 6;
		word[0] = 'S';
		word[1] = 'A';
		word[2] = 'L';
		word[3] = 'U';
		word[4] = 'T';
		word[5] = 'E';
	}
	for (i = 0; i < letters; i++)
	{
		word_letters[i] = char_convert (word[i]) - 1;
	}
}

int check_victory (int word_letters[10], int guessed[27])
{
	int letter_guessed = 1, i = 0, letter = 0;
	while (letter_guessed)
	{
		letter = word_letters[i];
		if (!guessed[letter])
		{
			letter_guessed = 0;
		}
		i++;
	}
	return letter_guessed;
}