#include "task2.h"

int task2_main (void)
{
	int task2_array_random[20],
		task2_array_index[101],
		temp_value = 0,
		counter = 0,
		i = 0;

	srand((unsigned)time(NULL));

	for (i = 0; i < 101; i++)
	{
		task2_array_index[i] = 0;
	}

	for (i = 0; i < 20; i++)
	{
		task2_array_random[i] = task2_random_int ();
		printf ("Random Array %d Value: %d\n", i, task2_array_random[i]);
		temp_value = task2_array_random[i];
		task2_array_index[temp_value]++;
	}

	pause_clear (1, 1);
	counter = 0;
	for (i = 0; i < 101; i++)
	{
		counter++;
		if (counter == 20)
		{
			printf ("\n");
			pause_clear (1, 0);
			counter = 0;
		}
		printf ("Number %d: %d times.\n", i, task2_array_index[i]);
	}
	pause_clear (1, 1);
	return 0;
}

int task2_random_int (void)
{
	int random = 0;
	random = (rand () % 100);
	return random;
}