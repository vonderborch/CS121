#include "battleship.h"

int screen_control (int game_state)
{
	// Control Variables
	int sub_state = 0;

	while (game_state > -1)
	{
		/* Possible Game States
		 * -1 = Exit Game
		 *  0 = Load Game
		 *  1 = Main Menu
		 *  2 = Options Menu
		 *  3 = Play Game Menu
		 *  4 = Gameplay
		 *  5 = End Game
		*/
		
		/* LOAD GAME
		 * Possible Sub-States
		 * 0 = Display Welcome Message
		 * 1 = Load Settings
		*/
		if (game_state == 0)
		{
		}
		/* MAIN MENU
		 * Possible Sub-States
		 * 0 = 
		*/
		else if (game_state == 1)
		{
		}
		/* OPTIONS MENU
		 * Possible Sub-States
		 * 0 = 
		*/
		else if (game_state == 2)
		{
		}
		/* PLAY GAME MENU
		 * Possible Sub-States
		 * 0 = 
		*/
		else if (game_state == 3)
		{
		}
		/* GAMEPLAY
		 * Possible Sub-States
		 * 0 = 
		*/
		else if (game_state == 4)
		{
		}
		/* END GAME
		 * Possible Sub-States
		 * 0 = 
		*/
		else if (game_state == 5)
		{
		}
	}
	return -1;
}