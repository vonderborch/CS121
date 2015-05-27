// October 19th

#include "battleship.h"

int main (void)
{
	int game_state = 0;
	while (game_state > -1)
	{
		game_state = screen_control (game_state);
	}
	return 0;
}