#include "lab7.h"
#include "task1.h"
#include "task2.h"

int main (void)
{
	int option = 0, lab_state = 0;
	while (lab_state >= 0)
	{
		option =  display_standard_menu ("Lab 7: Main Menu",
			"1. Task 1 - InternetLite\n2. Task 2 - Broadway Revenue\n3. Exit Lab 7",
			'i', 3, 1);
		if (option == 1)
		{
			lab_state = task1_main ();
		}
		else if (option == 2)
		{
			lab_state = task2_main ();
		}
		else if (option == 3)
		{
			lab_state = -1;
		}
	}
	return 0;
}