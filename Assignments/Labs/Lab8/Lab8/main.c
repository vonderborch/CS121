#include "lab8.h"

int main (void)
{
	int lab_state = 0, option = 0;

	while (lab_state >= 0)
	{
		if (lab_state == 0)
		{
			option = display_standard_menu ("Lab 8: Awesome Arrays\nMain Menu",
				"1. Task 1 - Reading a File and Reversing an Array\n2. Task 2 - Random Array\n3. Task 3 - Project 9\n4. Quit",
				0, 4, 1);
			if (option == 1)
			{
				lab_state = 1;
			}
			else if (option == 2)
			{
				lab_state = 2;
			}
			else if (option == 3)
			{
				lab_state = 3;
			}
			else
			{
				lab_state = -1;
			}
		}
		else if (lab_state == 1)
		{
			lab_state = task1_main ();
		}
		else if (lab_state == 2)
		{
			lab_state = task2_main ();
		}
		else if (lab_state == 3)
		{
			lab_state = task3_main ();
		}
	}

	return 0;
}