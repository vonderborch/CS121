#include "lab8.h"

void pause_clear (int pause_true, int clear_true)
{
	if (pause_true)
	{
		system ("pause");
	}
	if (clear_true)
	{
		system ("cls");
	}
}