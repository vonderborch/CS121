
#include "lab4t1.h"

int main (void)
{
	FILE *receipt = NULL;
	double purchases = 0.0;
	int is_teacher = 0;
	receipt = fopen ("receipt.txt", "w");

	printf ("Total Purchase Price? ");
	purchases = double_input ();
	is_teacher = teacher_input ();

	if (is_teacher == 0)
	{
		normal_main (purchases, receipt);
	}
	else
	{
		teacher_main (purchases, receipt);
	}

	fclose (receipt);

	return 0;
}