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
 * File Description: "screens.c" contains the various menus and views that users will see.
 *********************************************************************************************/

#include "math_game.h"

/*************************************************************
 * Function: screen_load_game ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function loads the game files.
 * Input parameters: The basic variables to assign to.
 * Returns: the assigned variables (pointers)
 * Preconditions: Game must be loaded
 * Postconditions: Game is loaded
 *************************************************************/
int screen_load_game (int *firstrun, char *initial_a, char *initial_b, char *initial_c, int *difficulty,
					  int *autosave_use, int *save1_use, int *save2_use, int *save3_use,
					  int *menu_type, int game_state)
{
	// temp file variables
	FILE *resources = NULL;
	// print that game is being loaded
	printf ("Loading Game...");
	// (attempt to) open the file
	resources = fopen ("resources.mgr", "r");

	// check if opened successfully
	if (resources == NULL)
	{
		// if not, print that failed to load, creating new version
		printf ("Failed to find resources file...Creating default file...");
		// save default settings
		save_settings (1, 'A', 'A', 'A', 1, 0, 0, 0, 0,
			0);
		// open the file for reading
		resources = fopen ("resources.mgr", "r");
		// print that the file was created
		printf ("Default resources file created...");
	}
	// read the file and assign the variables
	fscanf (resources, " %d", &*firstrun);
	fscanf (resources, " %c", &*initial_a);
	fscanf (resources, " %c", &*initial_b);
	fscanf (resources, " %c", &*initial_c);
	fscanf (resources, " %d", &*difficulty);
	fscanf (resources, " %d", &*autosave_use);
	fscanf (resources, " %d", &*save1_use);
	fscanf (resources, " %d", &*save2_use);
	fscanf (resources, " %d", &*save3_use);
	fscanf (resources, " %d", &*menu_type);

	// print that the settings were loaded
	printf ("Settings loaded...Closing file...");
	// close the file
	fclose (resources);
	// pause, then clear the screen
	system ("pause");
	system ("cls");
	// return 1 to set new gamestate
	return 1;
}

/*************************************************************
 * Function: screen_main_menu ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function djsplays the main menu
 * Input parameters: The current game state and menutype
 * Returns: the new game state
 * Preconditions: main menu needed
 * Postconditions: option selected
 *************************************************************/
int screen_main_menu (int game_state, int menu_type)
{
	int option = 0;
	// display menu
	if (menu_type == 0)
	{
		// number-based version
		option = display_standard_menu ("Main Menu",
			"1. Play Game\n2. How to Play\n3. High Scores\n4. Options\n5. Quit",
			menu_type, 5, 1);
	}
	else if (menu_type == 1)
	{
		// letter-based version
		option = display_standard_menu ("Main Menu",
			"A. Play Game\nB. How to Play\nC. High Scores\nD. Options\nE. Quit",
			menu_type, 5, 1);
	}
	// determine option
	if (option == 1)
	{
		// show play game menu
		game_state = 3;
	}
	else if (option == 2)
	{
		// show how to play
		screen_how_to_play ();
	}
	else if (option == 3)
	{
		// display high scores
		screen_display_highscores ();
	}
	else if (option == 4)
	{
		// display options menu
		game_state = 2;
	}
	else if (option == 5)
	{
		// exit the game loops
		game_state = -1;
	}

	// return new gamestate
	return game_state;
}

/*************************************************************
 * Function: screen_how_to_play ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function explains how to play
 * Input parameters: Nothing
 * Returns: Nothing
 * Preconditions: how to play needed
 * Postconditions: how to play displayed
 *************************************************************/
void screen_how_to_play (void)
{
	// print title
	printf ("How to Play\n\n");
	// print how to play
	printf ("Math Game is played by solving various mathematical equations that are generated. The difficulty of the game effects what type of equations are generated. Help to help solve a particular type of equation can be reached at any point. The game can also be saved at any point, as well as there being an autosave that fires after every question. To win, simply score as many points as possible with the 10 given questions. When entering answers for questions, please round your answer to the nearest whole number.\n");
	// pause then clear screen
	system ("pause");
	system ("cls");
}

/*************************************************************
 * Function: screen_display_highscores ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function shows the high scores
 * Input parameters: Nothing
 * Returns: Nothing
 * Preconditions: High scores needed
 * Postconditions: high scores displayed
 *************************************************************/
void screen_display_highscores (void)
{
	// declare file variable
	FILE *scores = NULL;
	// set initial holding variables
	char temp_initial_a = '0', temp_initial_b = '0', temp_initial_c = '0', temp_char = '0',
		initial_a[] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
		initial_b[] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
		initial_c[] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'};
	// set points variables, etc.
	int points[] = {-100, -100, -100, -100, -100, -100, -100, -100, -100, -100},
			temp_points = 0, total_scores = -1,
			position = 0, new_position = 0, old_position = 0;

	// print title, column names
	printf ("Top 10 Highscores List\n");
	printf (" # --|-- Initials --|-- Score\n");

	// open the scores file
	scores = fopen ("high_scores.mgh", "r");
	// check if the file opened successfully
	if (scores == NULL)
	{
		// if not, tell user
		display_message (7, 0);
	}
	// otherwise...
	else
	{
		// cycle through file while possible
		while (!feof(scores))
		{
			// read score data
			fscanf (scores, " %d", &temp_points);
			fscanf (scores, "%c", &temp_initial_a);
			fscanf (scores, "%c", &temp_initial_b);
			fscanf (scores, "%c", &temp_initial_c);
			fscanf (scores, "%c", &temp_char);
			// add one to the total score count
			total_scores++;
			if (total_scores > 9)
			{
				total_scores = 9;
			}
			// check score position vs. top ten
			position = -1;
			do
			{
				position++;
			} while (temp_points < points[position]);

			// sort high scores list
			if (position < 10)
			{
				for (new_position = 9; new_position >= position; new_position--)
				{
					old_position = new_position - 1;
					if (new_position != position)
					{
						initial_a[new_position] = initial_a[old_position];
						initial_b[new_position] = initial_b[old_position];
						initial_c[new_position] = initial_c[old_position];
						points[new_position] = points[old_position];
					}
					else
					{
						initial_a[position] = temp_initial_a;
						initial_b[position] = temp_initial_b;
						initial_c[position] = temp_initial_c;
						points[position] = temp_points;
					}
				}
			}
		}
		// print scores
		if (total_scores == 0)
		{
			// if no scores, inform user (OBSOLETE)
			display_message (7, 0);
		}
		else
		{
			// print scores
			for (position = 0; position <= total_scores;position++)
			{
				if (position != 9)
				{
					printf (" %d --|--    %c%c%c   --|-- %d\n", position + 1,
						initial_a[position], initial_b[position], initial_c[position], points[position]);
				}
				else
				{
					printf ("%d --|--    %c%c%c   --|-- %d\n", 10,
						initial_a[position], initial_b[position], initial_c[position], points[position]);
				}
			}
		}
	}
	// pause then clear screen
	system ("pause");
	system ("cls");
}

/*************************************************************
 * Function: screen_options_menu ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function displays the options menu.
 * Input parameters: The gamestate, menutype, and menustate
 * Returns: the game state and menustate (pointer)
 * Preconditions: Options menu needed
 * Postconditions: options menu showed
 *************************************************************/
int screen_options_menu (int game_state, int menu_type, int *menu_state)
{
	int option = 0;
	// display menu
	if (menu_type == 0)
	{
		// number-based version
		option = display_standard_menu ("Options Menu",
			"1. Back\n2. Difficulty\n3. New Initials\n4. Menu Selection Type\n5. Clear High Scores\n6. Reset Saves\n7. Reset Game Settings",
			menu_type, 7, 1);
	}
	else if (menu_type == 1)
	{
		// letter-based version
		option = display_standard_menu ("Options Menu",
			"A. Back\nB. Difficulty\nC. New Initials\nD. Menu Selection Type\nE. Clear High Scores\nF. Reset Saves\nG. Reset Game Settings",
			menu_type, 7, 1);
	}
	// determine option
	// back
	if (option == 1)
	{
		game_state = 1;
		*menu_state = 0;
	}
	// difficulty
	else if (option == 2)
	{
		*menu_state = 1;
	}
	// new initials
	else if (option == 3)
	{
		*menu_state = 2;
	}
	// menu selection
	else if (option == 4)
	{
		*menu_state = 3;
	}
	// clear high scores
	else if (option == 5)
	{
		*menu_state = 4;
	}
	// reset saves
	else if (option == 6)
	{
		*menu_state = 5;
	}
	// reset game
	else if (option == 7)
	{
		*menu_state = 6;
	}

	// return game state
	return game_state;
}

/*************************************************************
 * Function: screen_play_game_menu ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function displays the play game menu.
 * Input parameters: The gamestate, menutype, and menu state
 * Returns: the game state, and menu state (pointer)
 * Preconditions: play game menu needed
 * Postconditions: play game menu showed
 *************************************************************/
int screen_play_game_menu (int game_state, int menu_type, int *menu_state)
{
	int option = 0;
	// display menu
	if (menu_type == 0)
	{
		// number-based version
		option = display_standard_menu ("Play Game Menu",
			"1. Back\n2. Start New Game\n3. Continue Game\n4. Load Game\n5. Enter New Initials\n6. Change Difficulty",
			menu_type, 6, 1);
	}
	else if (menu_type == 1)
	{
		// letter-based version
		option = display_standard_menu ("Play Game Menu",
			"A. Back\nB. Start New Game\nC. Continue Game\nD. Load Game\nE. Enter New Initials\nF. Change Difficulty",
			menu_type, 6, 1);
	}
	// back to main menu
	if (option == 1)
	{
		game_state = 1;
	}
	// new game
	else if (option == 2)
	{
		// Set rand() seed to the current time
		srand((unsigned)time(NULL));
		game_state = 5;
		*menu_state = 7;
	}
	// continue game (autosave)
	else if (option == 3)
	{
		// Set rand() seed to the current time
		srand((unsigned)time(NULL));
		*menu_state = 1;
	}
	// load game menu
	else if (option == 4)
	{
		// Set rand() seed to the current time
		srand((unsigned)time(NULL));
		game_state = 4;
	}
	// new initials
	else if (option == 5)
	{
		*menu_state = 3;
	}
	// change difficulty
	else if (option == 6)
	{
		*menu_state = 2;
	}

	// return gamestate
	return game_state;
}

/*************************************************************
 * Function: screen_load_game_menu ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function displays a load save menu
 * Input parameters: The gamestate, menutype, and menustate
 * Returns: the gamestate, and menu state (pointer)
 * Preconditions: Saved game to be loaded
 * Postconditions: Saved game menu loaded.
 *************************************************************/
int screen_load_game_menu (int game_state, int menu_type, int *menu_state)
{
	int option = 0;
	// display menu
	if (menu_type == 0)
	{
		// number-based version
		option = display_standard_menu ("Load Game Menu",
			"1. Back\n2. Load Save 1\n3. Load Save 2\n4. Load Save 3",
			menu_type, 4, 1);
	}
	else if (menu_type == 1)
	{
		// letter-based version
		option = display_standard_menu ("Load Game Menu",
			"A. Back\nB. Load Save 1\nC. Load Save 2\nD. Load Save 3",
			menu_type, 4, 1);
	}
	// Determine option
	// back
	if (option == 1)
	{
		game_state = 3;
	}
	// save 1 load
	else if (option == 2)
	{
		*menu_state = 1;
	}
	// save 2 load
	else if (option == 3)
	{
		*menu_state = 2;
	}
	// save 3 load
	else if (option == 4)
	{
		*menu_state = 3;
	}

	// return game state
	return game_state;
}

/*************************************************************
 * Function: screen_game_menu ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function shows in-game menu
 * Input parameters: The gamestate, menutype, menu state,
 *						and the equation's variables
 * Returns: the gamestate and menu state (pointer)
 * Preconditions: In-game menu needed
 * Postconditions: In-game menu displayed
 *************************************************************/
int screen_game_menu (int game_state, int menu_type, int *menu_state,
					  int questions, int term1, int term2, int term3, int term4,
					  char operand1, char operand2, char operand3)
{
	int option = 0;
	// display menu
	if (menu_type == 0)
	{
		// number-based menu
		option = display_game_menu (questions, term1, term2, term3, term4,
						operand1, operand2, operand3,
						"1. Enter Answer\n2. Show Points\n3. Help\n4. Save Game\n5. Exit Game",
						menu_type, 5, 1);
	}
	else if (menu_type == 1)
	{
		// letter-based menu
		option = display_game_menu (questions, term1, term2, term3, term4,
						operand1, operand2, operand3,
						"A. Enter Answer\nB. Show Points\nC. Help\nD. Save Game\nE. Exit Game",
						menu_type, 5, 1);
	}

	// determine option
	// enter answer
	if (option == 1)
	{
		*menu_state = 1;
	}
	// show points
	else if (option == 2)
	{
		*menu_state = 2;
	}
	// show help/tips
	else if (option == 3)
	{
		*menu_state = 3;
	}
	// save game menu
	else if (option == 4)
	{
		*menu_state = 4;
	}
	// exit game
	else if (option == 5)
	{
		*menu_state = 6;
	}

	// return gamestate
	return game_state;
}

/*************************************************************
 * Function: screen_save_game_menu ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function displays a menu to save the game to.
 * Input parameters: The menutype, menustate, and game variables
 * Returns: the menustate (pointer)
 * Preconditions: Game must be loaded
 * Postconditions: Game is loaded
 *************************************************************/
void screen_save_game_menu (int menu_type, int *menu_state,
						char initial_a, char initial_b, char initial_c,
						int difficulty, int points, int questions, int question_difficulty,
						int term1, int term2, int term3, int term4,
						char operand1, char operand2, char operand3)
{
	int option = 0;
	// display menu
	if (menu_type == 0)
	{
		// number-based version
		option = display_standard_menu ("Save Game Menu",
			"1. Back\n2. Save 1\n3. Save 2\n4. Save 3",
			menu_type, 4, 1);
	}
	else if (menu_type == 1)
	{
		// letter-based version
		option = display_standard_menu ("Save Game Menu",
			"A. Back\nB. Save 1\nC. Save 2\nD. Save 3",
			menu_type, 4, 1);
	}

	// determine options
	// back
	if (option == 1)
	{
		*menu_state = 0;
	}
	// save 1
	else if (option == 2)
	{
		save_game (1, initial_a, initial_b, initial_c,
			difficulty, points, questions, question_difficulty,
			term1, term2, term3, term4,
			operand1, operand2, operand3);
		*menu_state = 8;
	}
	// save 2
	else if (option == 3)
	{
		save_game (2, initial_a, initial_b, initial_c,
			difficulty, points, questions, question_difficulty,
			term1, term2, term3, term4,
			operand1, operand2, operand3);
		*menu_state = 9;
	}
	// save 3
	else
	{
		save_game (3, initial_a, initial_b, initial_c,
			difficulty, points, questions, question_difficulty,
			term1, term2, term3, term4,
			operand1, operand2, operand3);
		*menu_state = 10;
	}
}