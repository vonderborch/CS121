#include "task1.h"

int task1_main (void)
{
	FILE *infile = NULL;
	int task1_array[10];
	int items = 0, temp_items = 0,
		temp_value = 0,
		good_assign = 0;

	infile = fopen ("task1_input.txt", "r");

	if (infile != NULL)
	{
		while (items < 10)
		{
			good_assign = fscanf (infile, " %d", &task1_array[items]);
			if (good_assign)
			{
				print_line (items, task1_array[items]);
			}
			items++;
		}
		fclose (infile);
		printf ("\n");
		items = 0;
		temp_items = 9;
		while (items < 5)
		{
			temp_value = task1_array[items];
			task1_array[items] = task1_array[temp_items];
			task1_array[temp_items] = temp_value;
			items++;
			temp_items--;
		}
		items = 0;
		while (items < 10)
		{
			print_line (items, task1_array[items]);
			items++;
		}
	}
	else
	{
		printf ("Failed to find file, exiting to Lab Main Menu.");
	}
	pause_clear (1, 1);
	return 0;
}

void print_line (int item, int value)
{
	printf ("Item %d: %d\n", item, value);
}