/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Programming Assignment: Programming Assignment 5
 * Created: October 6th, 2011
 * Last Revised: October 19th, 2011
 * Description: This program allows a user to play a math game,
 *							where random equations are generated which
 *							the user has to answer in order to win points.
 *
 * File Description: "main.c" contains the main() function from which the entire program is run.
 *********************************************************************************************/

#include "math_game.h"

/*************************************************************
 * Function: main ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 18th, 2011
 * Description: This function is the primary control function of the
 *							program, from whence all other functions
 *							are called from as needed. It will also exit the
 *							program when the game_state variable is less
 *							than a 0.
 * Input parameters: None
 * Returns: Nothing
 * Preconditions: Program needs to be run.
 * Postconditions: Program is exited.
 *************************************************************/
int main (void)
{
	/* game_state variable
	 * -1 = Exit game
	 *  0 = Load game
	 *  1 = Main Menu
	 *  2 = Options Menu
	 *  3 = Play Game Menu
	 *  4 = Load Game
	 *  5 = Gameplay
	 *  6 = Enter High Score
	*/
	int game_state = 0;

	// As long as the game state variable is greater or equal to 0,
	//			run the screen_control functions.
	while (game_state >= 0)
	{
		// get the new gamestate from the screen_control function.
		game_state = screen_control (game_state);
	}

	// exit the game
	return 0;
}