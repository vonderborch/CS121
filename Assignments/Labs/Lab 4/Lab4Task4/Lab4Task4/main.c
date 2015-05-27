
#include "pa4t4.h"

int main (void)
{
	char bread_type = '\0', double_size = '\0', manual_bake = '\0';

	bread_type = prompt_bread ();
	double_size = prompt_double ();
	manual_bake = prompt_manual ();

	if (bread_type == 'w')
	{
		white_bread_main (double_size, manual_bake);
	}
	else
	{
		sweet_bread_main (double_size, manual_bake);
	}

	return 0;
}