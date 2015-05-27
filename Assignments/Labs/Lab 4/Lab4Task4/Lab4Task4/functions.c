
#include "pa4t4.h"

int white_bread_main (char double_size, char manual_bake)
{
	char temp_value = '\0';
	int temp_time = 45;

	if (double_size = 'y')
	{
		temp_time = 90;
	}

	print_message ("******************** Creating White Bread ********************");
	if (double_size == 'n' && manual_bake == 'n')
	{
		print_message ("Selected Options: N/A");
	}
	else if (double_size == 'y' && manual_bake == 'n')
	{
		print_message ("Selected Options: Double Size");
	}
	else if (double_size == 'n' && manual_bake == 'y')
	{
		print_message ("Selected Options: Manual Bake");
	}
	else if (double_size == 'y' && manual_bake == 'y')
	{
		print_message ("Selected Options: Double Size, Manual Bake");
	}
	print_message ("******** Press Any Key Then Enter to go to Next Step ********");
	
	print_message ("Kneading: 15 minutes");
	scanf (" %c", &temp_value);
	
	print_message ("Rising: 60 minutes");
	scanf (" %c", &temp_value);

	print_message ("Kneading: 18 minutes");
	scanf (" %c", &temp_value);

	print_message ("Rising: 20 minutes");
	scanf (" %c", &temp_value);

	print_message ("Shaping: 2 seconds");
	scanf (" %c", &temp_value);

	print_message ("Rising: 75 minutes");
	scanf (" %c", &temp_value);

	if (manual_bake == 'n')
	{
		print_message_number ("Bake for minutes: ", temp_time);
		scanf (" %c", &temp_value);

		print_message ("Cool: 30 minutes");
		scanf (" %c", &temp_value);
	}
	else
	{
		print_message_number ("User: Bake Bread for minutes = ", temp_time);
		scanf (" %c", &temp_value);

		print_message ("User: Cool Bread for 30 minutes");
		scanf (" %c", &temp_value);
	}

	print_message ("White Bread Complete!");
	return 0;
}

int sweet_bread_main (char double_size, char manual_bake)
{
	char temp_value = '\0';
	int temp_time = 35;

	if (double_size = 'y')
	{
		temp_time = 70;
	}

	print_message ("******************** Creating Sweet Bread ********************");
	if (double_size == 'n' && manual_bake == 'n')
	{
		print_message ("Selected Options: N/A");
	}
	else if (double_size == 'y' && manual_bake == 'n')
	{
		print_message ("Selected Options: Double Size");
	}
	else if (double_size == 'n' && manual_bake == 'y')
	{
		print_message ("Selected Options: Manual Bake");
	}
	else if (double_size == 'y' && manual_bake == 'y')
	{
		print_message ("Selected Options: Double Size, Manual Bake");
	}
	print_message ("******** Press Any Key Then Enter to go to Next Step ********");
	
	print_message ("Kneading: 20 minutes");
	scanf (" %c", &temp_value);
	
	print_message ("Rising: 60 minutes");
	scanf (" %c", &temp_value);

	print_message ("Kneading: 33 minutes");
	scanf (" %c", &temp_value);

	print_message ("Rising: 30 minutes");
	scanf (" %c", &temp_value);

	print_message ("Shaping: 2 seconds");
	scanf (" %c", &temp_value);

	print_message ("Rising: 75 minutes");
	scanf (" %c", &temp_value);

	if (manual_bake == 'n')
	{
		print_message_number ("Bake for minutes: ", temp_time);
		scanf (" %c", &temp_value);

		print_message ("Cool: 30 minutes");
		scanf (" %c", &temp_value);
	}
	else
	{
		print_message_number ("User: Bake Bread for minutes = ", temp_time);
		scanf (" %c", &temp_value);

		print_message ("User: Cool Bread for 30 minutes");
		scanf (" %c", &temp_value);
	}

	print_message ("Sweet Bread Complete!");
	return 0;
}

char prompt_bread (void)
{
	char temp_value = '\0';
	printf ("What type of Bread (w = White, s = Sweet) ?");
	scanf (" %c", &temp_value);
	return temp_value;
}

char prompt_double (void)
{
	char temp_value = '\0';
	printf ("Is the bread double sized (y = yes, n = no) ?");
	scanf (" %c", &temp_value);
	return temp_value;
}

char prompt_manual (void)
{
	char temp_value = '\0';
	printf ("Is the baking manual (y = yes, n = no) ?");
	scanf (" %c", &temp_value);
	return temp_value;
}

void print_message (char header[])
{
	printf ("%s\n", header);
	return;
}

void print_message_number (char header[], int number)
{
	printf ("%s%d\n", header, number);
	return;
}