#include "lab5.h"
#include "lab5t1.h"
#include "lab5t2.h"
#include "lab5t3.h"

int main (void)
{
	int option = 0, lab_task = 0;
	while (lab_task >= 0)
	{
		while (lab_task == 0)
		{
			option = display_menu ("Lab 5 Main Menu", "1. Task 1 - Prime Numbers\n2. Task 2 - Employee Pay\n3. Task 3 - Number Guess Ultra\n4. Quit", 4, 1);
			if (option == 1)
			{
				lab_task = 1;
			}
			else if (option == 2)
			{
				lab_task = 2;
			}
			else if (option == 3)
			{
				lab_task = 3;
			}
			else
			{
				lab_task = -1;
			}
		}
		while (lab_task == 1)
		{
			task1_main ();
			system ("pause");
			system ("cls");
			lab_task = 0;
		}
		while (lab_task == 2)
		{
			task2_main ();
			system ("pause");
			system ("cls");
			lab_task = 0;
		}
		while (lab_task == 3)
		{
			task3_main ();
			system ("pause");
			system ("cls");
			lab_task = 0;
		}
	}
}