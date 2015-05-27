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
 * File Description: "functions.c" contains "minor" function definitions.
 *********************************************************************************************/

#include "math_game.h"

/*************************************************************
 * Function: display_message ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 18th, 2011
 * Description: This function displays various messages
 *							to the user, determined by the parameters.
 * Input parameters: The message number and whether
 *									the screen should be paused
 *									and cleared after it is displayed.
 * Returns: Nothing
 * Preconditions: A message needs to be displayed.
 * Postconditions: A message has been displayed.
 *************************************************************/
void display_message (int message, int pause)
{
	// print welcome message.
	if (message == 1)
	{
		printf ("*******************************************************************************\n");
		printf ("*************************** Welcome to Math Game ******************************\n");
		printf ("*******************************************************************************\n\n");
	}
	// print whether that no resource file could be found.
	else if (message == 2)
	{
		printf ("Can not find resources file, returning default data.\n");
	}
	// print that there is no autosave to load
	else if (message == 3)
	{
		printf ("No previous autosave to load.\n");
	}
	// print that the user inputted invalid initials
	else if (message == 4)
	{
		printf ("Invalid initials.\n");
	}
	// print that no save can be found
	else if (message == 5)
	{
		printf ("Cannot find save!\n");
	}
	// print that there is no save to load
	else if (message == 6)
	{
		printf ("No save to load.");
	}
	// OBSOLETE: print that there are no high scores recorded
	else if (message == 7)
	{
		printf ("No scores recorded yet...\n");
	}
	// print that new initials have been entered
	else if (message == 8)
	{
		printf ("New Initials Entered...");
	}
	// if the function was told to be paused and cleared, do so...
	if (pause)
	{
		pause_clear (1, 1);
	}
}

/*************************************************************
 * Function: pause_clear ()
 * Date Created: October 18th, 2011
 * Date Last Modified: October 18th, 2011
 * Description: This function can pause and clear the
 *						screen based upon the input.
 * Input parameters: Whether the screen should be
 *								paused and whether the screen
 *								should be cleared.
 * Returns: Nothing
 * Preconditions: Screen needs to be paused or cleared.
 * Postconditions: Program is paused or cleared.
 *************************************************************/
void pause_clear (int pause_true, int clear_true)
{
	// if the screen should be paused, pause it
	if (pause_true)
	{
		system ("pause");
	}
	// if the screen should be cleared, clear it
	if (clear_true)
	{
		system ("cls");
	}
}

/*************************************************************
 * Function: enter_initials ()
 * Date Created: October 7th, 2011
 * Date Last Modified: October 18th, 2011
 * Description: This function allows the user to enter
 *						initials, and it will assign the initials
 *						to the inputed variables and then return
 *						whether those initials are "good."
 * Input parameters: Initials to be assigned new letters.
 * Returns: The assigned variables and whether they are
 *					"good."
 * Preconditions: User initials are needed.
 * Postconditions: New initials and whether they are good
 *							are returned.
 *************************************************************/
int enter_initials (char *initial_a, char *initial_b, char *initial_c)
{
	// initialize variables
	int good_initials = 0, a_result = 0, b_result = 0, c_result = 0;
	char a_initial = 'A', b_initial = 'A', c_initial = 'A';

	// clear the input buffer
	_flushall();
	// assign initials and whether the assign was good
	a_result = scanf ("%c", &a_initial);
	b_result = scanf ("%c", &b_initial);
	c_result = scanf ("%c", &c_initial);

	// check if the initials fall in the correct range of letters
	if (((a_initial >= 'A') && (a_initial <= 'Z')) &&
		((b_initial >= 'A') && (b_initial <= 'Z')) &&
		((c_initial >= 'A') && (c_initial <= 'Z')))
	{
		good_initials = 1;
	}
	// check if any of the initials was not a successful assign
	if ((!a_result) || (!b_result) || (!c_result))
	{
		good_initials = 0;
	}

	// return the initials and whether it was a success
	*initial_a = a_initial;
	*initial_b = b_initial;
	*initial_c = c_initial;
	return good_initials;
}

/*************************************************************
 * Function: save_settings ()
 * Date Created: October 12th, 2011
 * Date Last Modified: October 18th, 2011
 * Description: This function saves the inputted variables
 *						to the resources file.
 * Input parameters: Variables to be saved.
 * Returns: Nothing
 * Preconditions: Settings must be saved due to changes.
 * Postconditions: Settings have been saved.
 *************************************************************/
void save_settings (int firstrun, char initial_a, char initial_b, char initial_c, int difficulty,
					  int autosave_use, int save1_use, int save2_use, int save3_use,
					  int menu_type)
{
	// create a file operation variable
	FILE *resources = NULL;
	// open the resources file for writing
	resources = fopen ("resources.mgr", "w");
	// write the new settings to the file
	fprintf (resources,
		"%d\n%c%c%c\n%d\n%d\n%d\n%d\n%d\n%d\n",
		firstrun, initial_a, initial_b, initial_c, difficulty,
		autosave_use, save1_use, save2_use, save3_use,
		menu_type);
	// close the resources file
	fclose (resources);
	// print that the settings were saved
	printf ("Settings Saved!\n");
}

/*************************************************************
 * Function: load_saved_game ()
 * Date Created: October 14th, 2011
 * Date Last Modified: October 18th, 2011
 * Description: This function loads a saved game and
 *						allows the user to play it.
 * Input parameters: the save file to save load and the
 *								game variables to be loaded.
 * Returns: whether the save loaded correctly.
 * Preconditions: Saved game needs to be loaded
 * Postconditions: Saved game is loaded
 *************************************************************/
int load_saved_game (int save, char *initial_a, char *initial_b, char *initial_c,
					  int *difficulty, int *points, int *questions, int *question_difficulty,
					  int *term1, int *term2, int *term3, int *term4,
					  char *operand1, char *operand2, char *operand3)
{
	// declare a save game file variable
	FILE *save_game = NULL;
	// declare a variable to check if the file loaded correctly
	int loaded_correctly = 0;

	// Open Autosave
	if (save == 0)
	{
		save_game = fopen ("autosave.mgs", "r");
	}
	// Open Save 1
	else if (save == 1)
	{
		save_game = fopen ("save_1.mgs", "r");
	}
	// Open Save 2
	else if (save == 2)
	{
		save_game = fopen ("save_2.mgs", "r");
	}
	// Open Save 3
	else
	{
		save_game = fopen ("save_3.mgs", "r");
	}
	// check if the file didn't load
	if (save_game == NULL)
	{
		loaded_correctly = 0;
	}
	// if it did, read the file, and assign the variables to the game vars
	else
	{
		fscanf (save_game, " %d", &*difficulty);
		fscanf (save_game, " %c", &*initial_a);
		fscanf (save_game, " %c", &*initial_b);
		fscanf (save_game, " %c", &*initial_c);
		fscanf (save_game, " %d", &*points);
		fscanf (save_game, " %d", &*questions);
		fscanf (save_game, " %d", &*question_difficulty);
		fscanf (save_game, " %d", &*term1);
		fscanf (save_game, " %d", &*term2);
		fscanf (save_game, " %d", &*term3);
		fscanf (save_game, " %d", &*term4);
		fscanf (save_game, " %c", &*operand1);
		fscanf (save_game, " %c", &*operand2);
		fscanf (save_game, " %c", &*operand3);
		fclose (save_game);
		loaded_correctly = 1;
	}
	// return whether the load loaded properly
	return loaded_correctly;
}

/*************************************************************
 * Function: save_game ()
 * Date Created: October 14th, 2011
 * Date Last Modified: October 18th, 2011
 * Description: This function saves the current game to a file.
 * Input parameters: The file to save to and the variables to save
 * Returns: Nothing
 * Preconditions: A game needs to be saved
 * Postconditions: The game is saved
 *************************************************************/
void save_game (int save, char initial_a, char initial_b, char initial_c,
					  int difficulty, int points, int questions, int question_difficulty,
					  int term1, int term2, int term3, int term4,
					  char operand1, char operand2, char operand3)
{
	// declare a file variable
	FILE *save_game = NULL;
	// Open autosave file to save to
	if (save == 0)
	{
		save_game = fopen ("autosave.mgs", "w");
	}
	// open save 1 to save to
	else if (save == 1)
	{
		save_game = fopen ("save_1.mgs", "w");
	}
	// open save 2 to save to
	else if (save == 2)
	{
		save_game = fopen ("save_2.mgs", "w");
	}
	// open save 3 to save to
	else if (save == 3)
	{
		save_game = fopen ("save_3.mgs", "w");
	}

	// save variables to the save file
	fprintf (save_game,
		"%d\n%c%c%c\n%d %d %d\n%d %d %d %d\n%c%c%c",
		difficulty, initial_a, initial_b, initial_c,
		points, questions, question_difficulty,
		term1, term2, term3, term4,
		operand1, operand2, operand3);

	// close the save file
	fclose (save_game);
}

/*************************************************************
 * Function: display_game_menu ()
 * Date Created: October 14th, 2011
 * Date Last Modified: October 18th, 2011
 * Description: This function modifies the standard
 *							display menu function (menu_system.c)
 *							to a version capable of displaying the
 *							current equation being asked.
 * Input parameters: The question count, the question
 *								terms, the question operands,
 *								the menu item list, the menu type,
 *								the number of items, and the lowest
 *								possible item.
 * Returns: The option choosen.
 * Preconditions: A version of the menu displaying the
 *							current question is needed.
 * Postconditions: The menu option choosen is returned.
 *************************************************************/
int display_game_menu (int questions, int term1, int term2, int term3, int term4,
					   char operand1, char operand2, char operand3,
					   char menu_items[], int menu_type, int num_items, int min_items)
{
	// set current option to 0
	int option = 0, error_check = 0;
	char char_option = '\0';

	// repeat while option is invalid
	do
	{
		// display the current equation
		printf ("Question #%d: %d %c %d", questions, term1, operand1, term2);
		if (operand2 != '0')
		{
			printf (" %c %d", operand2, term3);
		}
		if (operand3 != '0')
		{
			printf (" %c %d", operand3, term4);
		}
		printf (" = ?\n");
		// display menu items
		printf ("%s\n\n", menu_items);

		// If the menu is integer based...
		if (menu_type == 0)
		{
			// get user selection input and assign the results of the scanf to a variable to error check
			error_check = scanf (" %d", &option);
			// determine if the scanf failed to read an integer
			if (!error_check)
			{
				// if it did, assign option var to the lowest item -1 (always invalid).
				option = min_items - 1;
			}
		}
		// if the menu is char-based...
		else if (menu_type == 1)
		{
			error_check = scanf (" %c", &char_option);
			// determine if the scanf failed to read an integer
			//num_items = char_convert (num_items);
			//min_items = char_convert (min_items);
			if (!error_check)
			{
				// if it did, assign option var to the lowest item -1 (always invalid).
				option = min_items - 1;
			}
			else
			{
				option = char_convert (char_option);
			}
		}
		_flushall();

		// clear screen
		system ("cls");
		// determine validity of option
	} while (!is_valid_item (option, num_items, min_items));

	// return option as an int
	return option;
}

/*************************************************************
 * Function: enter_answer ()
 * Date Created: October 14th, 2011
 * Date Last Modified: October 18th, 2011
 * Description: This function gets the player's answer
 *						and error checks to make sure it is a
 *						valid input type
 * Input parameters: None
 * Returns: the entered answer
 * Preconditions: Player answer is needed
 * Postconditions: the player's answer is returned
 *************************************************************/
double enter_answer (void)
{
	// declare error checking variable and answer variable
	int error_check = 0;
	double answer = 0.0;
	// run the scanf while the scanf fails
	while (!error_check)
	{
		// clear the input buffer
		_flushall();
		// get user selection input and assign the results of the scanf to a variable to error check
		error_check = scanf ("%lf", &answer);
	}
	// return the answer
	return answer;
}

/*************************************************************
 * Function: determine_answer ()
 * Date Created: October 14th, 2011
 * Date Last Modified: October 18th, 2011
 * Description: This function determines whether the
 *						player's answer is the correct answer.
 * Input parameters: The player's answer, the equations terms,
 *								and the equations operands
 * Returns: whether the player's answer is correct
 * Preconditions: The player's answer needs to be validated
 * Postconditions: The player's answer is validated
 *************************************************************/
int determine_answer (double entered_answer, int term1, int term2, int term3, int term4,
					  char operand1, char operand2, char operand3)
{
	// declare the terms, valid answer, and answer variables
	int valid_answer = 0, terms = 0;
	double answer = 0.0;
	// Determine quantity of terms in the equation
	terms = calculate_terms (operand2, operand3);
	// Gets the answer as a double, for extra precision at larger answers
	// The user will never see this
	answer = calculate_answer_precise (terms, term1, term2, term3, term4,
		operand1, operand2, operand3);
	// display the correct answer (with no decimal places)
	printf ("Correct Answer: %.0lf\n", answer);

	// determine if the calculated answer is the same as that entered.
	if (answer == entered_answer)
	{
		valid_answer = 1;
	}
	// return the validity of the answer.
	return valid_answer;
}

/*************************************************************
 * Function: calculate_terms ()
 * Date Created: October 17th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function is used to calculate
 *					the number of terms in the equations.
 * Input parameters: The second and third operand.
 * Returns: The number of terms.
 * Preconditions: The number of terms is needed to be known.
 * Postconditions: The number of terms is returned.
 *************************************************************/
int calculate_terms (char operand2, char operand3)
{
	// set terms var to 2 (least amount)
	int terms = 2;
	// Determine term quantity
	if (operand2 != '0')
	{
		// if operand2 is used, increase term count
		terms++;
	}
	if (operand3 != '0')
	{
		// if operand3 is used, increase term count
		terms++;
	}
	// return term count
	return terms;
}

/*************************************************************
 * Function: calculate_answer ()
 * Date Created: October 17th, 2011
 * Date Last Modified: October 17th, 2011
 * Description: This function uses a brute-force method for solving equations.
 *							This version of the function calculates the equation out
 *							using ints.
 * Input parameters: # of terms, all 4 terms (even unused ones), all three operators
 *									(even unused ones).
 * Returns: The correct (double) answer.
 * Preconditions: Equation needs to be solved to check user answer
 * Postconditions: Correct answer returned to be checked against user's.
 *************************************************************/
int calculate_answer (int terms, int term1, int term2, int term3, int term4,
					  char operand1, char operand2, char operand3)
{
	// variable used for storing correct answer
	int answer = 0;
	// calculate the correct answer.
	// Calculate if only two terms
	if (terms == 2)
	{
		// if the operator is +
		if (operand1 == '+')
		{
			answer = term1 + term2;
		}
		// if the operator is -
		else if (operand1 == '-')
		{
			answer = term1 - term2;
		}
		// if the operator is *
		else if (operand1 == '*')
		{
			answer = term1 * term2;
		}
		// if the operator is /
		else if (operand1 == '/')
		{
			answer = term1 / term2;
		}
	}
	// Calculate for 3 terms
	else if (terms == 3)
	{
		// if the first operator is a *
		if (operand1 == '*')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				answer = term1 * term2 * term3;
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				answer = term1 * term2 / term3;
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				answer = term1 * term2 + term3;
			}
			// if the second operator is a -
			else
			{
				answer = term1 * term2 - term3;
			}
		}
		// if the first operator is a /
		else if (operand1 == '/')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				answer = term1 / term2 * term3;
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				answer = term1 / term2 / term3;
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				answer = term1 / term2 + term3;
			}
			// if the second operator is a -
			else
			{
				answer = term1 / term2 - term3;
			}
		}
		// if the first operator is a +
		else if (operand1 == '+')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				answer = term1 + term2 * term3;
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				answer = term1 + term2 / term3;
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				answer = term1 + term2 + term3;
			}
			// if the second operator is a -
			else
			{
				answer = term1 + term2 - term3;
			}
		}
		// if the first operator is a -
		else if (operand1 == '-')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				answer = term1 - term2 * term3;
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				answer = term1 - term2 / term3;
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				answer = term1 - term2 + term3;
			}
			// if the second operator is a -
			else
			{
				answer = term1 - term2 - term3;
			}
		}
	}
	// Calculate for 4 terms
	else if (terms == 4)
	{
		// if the first operator is a *
		if (operand1 == '*')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 * term2 * term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 * term2 * term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 * term2 * term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 * term2 * term3 - term4;
				}
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 * term2 / term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 * term2 / term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 * term2 / term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 * term2 / term3 - term4;
				}
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 * term2 + term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 * term2 + term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 * term2 + term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 * term2 + term3 - term4;
				}
			}
			// if the second operator is a -
			else if (operand2 == '-')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 * term2 - term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 * term2 - term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 * term2 - term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 * term2 - term3 - term4;
				}
			}
		}
		// if the first operator is a /
		else if (operand1 == '/')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 / term2 * term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 / term2 * term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 / term2 * term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 / term2 * term3 - term4;
				}
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 / term2 / term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 / term2 / term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 / term2 / term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 / term2 / term3 - term4;
				}
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 / term2 + term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 / term2 + term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 / term2 + term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 / term2 + term3 - term4;
				}
			}
			// if the second operator is a -
			else if (operand2 == '-')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 / term2 - term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 / term2 - term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 / term2 - term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 / term2 - term3 - term4;
				}
			}
		}
		// if the first operator is a +
		else if (operand1 == '+')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 + term2 * term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 + term2 * term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 + term2 * term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 + term2 * term3 - term4;
				}
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 + term2 / term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 + term2 / term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 + term2 / term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 + term2 / term3 - term4;
				}
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 + term2 + term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 + term2 + term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 + term2 + term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 + term2 + term3 - term4;
				}
			}
			// if the second operator is a -
			else if (operand2 == '-')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 + term2 - term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 + term2 - term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 + term2 - term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 + term2 - term3 - term4;
				}
			}
		}
		// if the first operator is a -
		else if (operand1 == '-')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 - term2 * term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 - term2 * term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 - term2 * term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 - term2 * term3 - term4;
				}
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 - term2 / term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 - term2 / term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 - term2 / term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 - term2 / term3 - term4;
				}
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 - term2 + term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 - term2 + term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 - term2 + term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 - term2 + term3 - term4;
				}
			}
			// if the second operator is a -
			else if (operand2 == '-')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = term1 - term2 - term3 * term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = term1 - term2 - term3 / term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = term1 - term2 - term3 + term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 - term2 - term3 - term4;
				}
			}
		}
	}
	// return the answer to the equation
	return answer;
}

/*************************************************************
 * Function: calculate_answer_precise ()
 * Date Created: October 17th, 2011
 * Date Last Modified: October 17th, 2011
 * Description: This function uses a brute-force method for solving equations.
 *							This version of the function calculates the equation out
 *							using doubles for precision.
 * Input parameters: # of terms, all 4 terms (even unused ones), all three operators
 *									(even unused ones).
 * Returns: The correct (double) answer.
 * Preconditions: Equation needs to be solved to check user answer
 * Postconditions: Correct answer returned to be checked against user's.
 *************************************************************/
double calculate_answer_precise (int terms, int term1, int term2, int term3, int term4,
					  char operand1, char operand2, char operand3)
{
	// variable used for storing correct answer
	double answer = 0;
	// calculate the correct answer.
	// Calculate if only two terms
	if (terms == 2)
	{
		// if the operator is +
		if (operand1 == '+')
		{
			answer = (double)term1 + (double)term2;
		}
		// if the operator is -
		else if (operand1 == '-')
		{
			answer = (double)term1 - (double)term2;
		}
		// if the operator is *
		else if (operand1 == '*')
		{
			answer = (double)term1 * (double)term2;
		}
		// if the operator is /
		else if (operand1 == '/')
		{
			answer = (double)term1 / (double)term2;
		}
	}
	// Calculate for 3 terms
	else if (terms == 3)
	{
		// if the first operator is a *
		if (operand1 == '*')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				answer = (double)term1 * (double)term2 * (double)term3;
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				answer = (double)term1 * (double)term2 / (double)term3;
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				answer = (double)term1 * (double)term2 + (double)term3;
			}
			// if the second operator is a -
			else
			{
				answer = (double)term1 * (double)term2 - (double)term3;
			}
		}
		// if the first operator is a /
		else if (operand1 == '/')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				answer = (double)term1 / (double)term2 * (double)term3;
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				answer = (double)term1 / (double)term2 / (double)term3;
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				answer = (double)term1 / (double)term2 + (double)term3;
			}
			// if the second operator is a -
			else
			{
				answer = (double)term1 / (double)term2 - (double)term3;
			}
		}
		// if the first operator is a +
		else if (operand1 == '+')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				answer = (double)term1 + (double)term2 * (double)term3;
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				answer = (double)term1 + (double)term2 / (double)term3;
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				answer = (double)term1 + (double)term2 + (double)term3;
			}
			// if the second operator is a -
			else
			{
				answer = (double)term1 + (double)term2 - (double)term3;
			}
		}
		// if the first operator is a -
		else if (operand1 == '-')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				answer = (double)term1 - (double)term2 * (double)term3;
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				answer = (double)term1 - (double)term2 / (double)term3;
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				answer = (double)term1 - (double)term2 + (double)term3;
			}
			// if the second operator is a -
			else
			{
				answer = (double)term1 - (double)term2 - (double)term3;
			}
		}
	}
	// Calculate for 4 terms
	else if (terms == 4)
	{
		// if the first operator is a *
		if (operand1 == '*')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 * (double)term2 * (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 * (double)term2 * (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 * (double)term2 * (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 * (double)term2 * (double)term3 - (double)term4;
				}
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 * (double)term2 / (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 * (double)term2 / (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 * (double)term2 / (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 * (double)term2 / (double)term3 - (double)term4;
				}
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 * (double)term2 + (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 * (double)term2 + (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 * (double)term2 + (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 * (double)term2 + (double)term3 - (double)term4;
				}
			}
			// if the second operator is a -
			else if (operand2 == '-')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 * (double)term2 - (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 * (double)term2 - (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 * (double)term2 - (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 * (double)term2 - (double)term3 - (double)term4;
				}
			}
		}
		// if the first operator is a /
		else if (operand1 == '/')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 / (double)term2 * (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 / (double)term2 * (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 / (double)term2 * (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 / (double)term2 * (double)term3 - (double)term4;
				}
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 / (double)term2 / (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 / (double)term2 / (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 / (double)term2 / (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 / (double)term2 / (double)term3 - (double)term4;
				}
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 / (double)term2 + (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 / (double)term2 + (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 / (double)term2 + (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 / (double)term2 + (double)term3 - (double)term4;
				}
			}
			// if the second operator is a -
			else if (operand2 == '-')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 / (double)term2 - (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 / (double)term2 - (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 / (double)term2 - (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 / (double)term2 - (double)term3 - (double)term4;
				}
			}
		}
		// if the first operator is a +
		else if (operand1 == '+')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 + (double)term2 * (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 + (double)term2 * (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 + (double)term2 * (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 + (double)term2 * (double)term3 - (double)term4;
				}
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 + (double)term2 / (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 + (double)term2 / (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 + (double)term2 / (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 + (double)term2 / (double)term3 - (double)term4;
				}
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 + (double)term2 + (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 + (double)term2 + (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 + (double)term2 + (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 + (double)term2 + (double)term3 - (double)term4;
				}
			}
			// if the second operator is a -
			else if (operand2 == '-')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 + (double)term2 - (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 + (double)term2 - (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 + (double)term2 - (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 + (double)term2 - (double)term3 - (double)term4;
				}
			}
		}
		// if the first operator is a -
		else if (operand1 == '-')
		{
			// if the second operator is a *
			if (operand2 == '*')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 - (double)term2 * (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 - (double)term2 * (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 - (double)term2 * (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 - (double)term2 * (double)term3 - (double)term4;
				}
			}
			// if the second operator is a /
			else if (operand2 == '/')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 - (double)term2 / (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 - (double)term2 / (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 - (double)term2 / (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 - (double)term2 / (double)term3 - (double)term4;
				}
			}
			// if the second operator is a +
			else if (operand2 == '+')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 - (double)term2 + (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 - (double)term2 + (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 - (double)term2 + (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = term1 - (double)term2 + (double)term3 - (double)term4;
				}
			}
			// if the second operator is a -
			else if (operand2 == '-')
			{
				// if the third operator is a *
				if (operand3 == '*')
				{
					answer = (double)term1 - (double)term2 - (double)term3 * (double)term4;
				}
				// if the third operator is a /
				else if (operand3 == '/')
				{
					answer = (double)term1 - (double)term2 - (double)term3 / (double)term4;
				}
				// if the third operator is a +
				else if (operand3 == '+')
				{
					answer = (double)term1 - (double)term2 - (double)term3 + (double)term4;
				}
				// if the third operator is a -
				else if (operand3 == '-')
				{
					answer = (double)term1 - (double)term2 - (double)term3 - (double)term4;
				}
			}
		}
	}
	// return the answer to the equation
	return answer;
}

/*************************************************************
 * Function: new_equation ()
 * Date Created: October 14th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function generates a new equation based
 *					upon overall and game difficulty.
 * Input parameters: The difficulty, question difficulty,
 *						and terms/operands to assign.
 * Returns: The equation.
 * Preconditions: A new equation is needed.
 * Postconditions: The equation is returned.
 *************************************************************/
void new_equation (int difficulty, int question_difficulty,
				  int *term1, int *term2, int *term3, int *term4,
				  char *operand1, char *operand2, char *operand3)
{
	// initialize temp versions of the equation variables
	int term_1 = 0, term_2 = 0, term_3 = 0, term_4 = 0;
	char operand_1 = '0', operand_2 = '0', operand_3 = '0';

	// easy difficult
	if (difficulty == 1)
	{
		// set not used terms/operands to "null" values
		term_4 = 0;
		operand_3 = '0';
		// randomize terms
		term_1 = rand () % 9;
		term_2 = rand () % 9;
		term_3 = rand () % 9;
		// if question difficulty is 3 or less, set operands to +
		if (question_difficulty < 4)
		{
			operand_1 = '+';
			operand_2 = '+';
		}
		// if question difficulty is 3 or less, set operands to -
		else if (question_difficulty <7)
		{
			operand_1 = '-';
			operand_2 = '-';
		}
		// else, randomize the operands
		else
		{
			operand_1 = determine_operand (difficulty);
			operand_2 = determine_operand (difficulty);
		}
	}
	// fair difficulty
	else if (difficulty == 2)
	{
		// set not used terms/operands to "null" values
		term_3 = 0;
		term_4 = 0;
		operand_2 = '0';
		operand_3 = '0';
		// randomize terms
		term_1 = rand () % 9;
		term_2 = rand () % 9;
		// if the difficulty is less than 4, set operand to a *
		if (question_difficulty < 4)
		{
			operand_1 = '*';
		}
		// if difficulty is less than 7, set operand to a /
		else if (question_difficulty < 7)
		{
			operand_1 = '/';
		}
		// else, randomize the operand
		else
		{
			operand_1 = determine_operand (difficulty);
		}
		// check if the operand is a division
		if (operand_1 == '/')
		{
			// if the second term is a 0, set it to a 1.
			if (!term_2)
			{
				term_2++;
			}
		}
	}
	// intermediate difficulty
	else if (difficulty == 3)
	{
		// set not used terms/operands to "null" values
		term_4 = 0;
		operand_3 = '0';
		// randomize terms
		term_1 = determine_term (difficulty);
		term_2 = determine_term (difficulty);
		term_3 = determine_term (difficulty);
		// set the operands based upon the difficulty
		if (question_difficulty < 3)
		{
			operand_1 = '+';
			operand_2 = '+';
		}
		else if (question_difficulty < 5)
		{
			operand_1 = '-';
			operand_2 = '-';
		}
		else if (question_difficulty < 7)
		{
			operand_1 = '*';
			operand_2 = '*';
		}
		else if (question_difficulty < 9)
		{
			operand_1 = '/';
			operand_2 = '/';
		}
		else
		{
			operand_1 = determine_operand (difficulty);
			operand_2 = determine_operand (difficulty);
		}
		// if operand1 is a /, check/set to make sure the term following is > 0.
		if (operand_1 == '/')
		{
			if (!term_2)
			{
				term_2++;
			}
		}
		// if operand2 is a /, check/set to make sure the term following is > 0.
		if (operand_2 == '/')
		{
			if (!term_3)
			{
				term_3++;
			}
		}
	}
	// hard difficulty
	else if (difficulty == 4)
	{
		// set not used terms/operands to "null" values
		term_4 = 0;
		operand_3 = '0';
		// randomize terms
		term_1 = determine_term (difficulty);
		term_2 = determine_term (difficulty);
		term_3 = determine_term (difficulty);
		// randomize operands based upon answered correctly questions.
		if (question_difficulty < 2)
		{
			operand_1 = '+';
			operand_2 = '+';
		}
		else if (question_difficulty < 4)
		{
			operand_1 = '-';
			operand_2 = '-';
		}
		else if (question_difficulty < 6)
		{
			operand_1 = '*';
			operand_2 = '*';
		}
		else if (question_difficulty < 8)
		{
			operand_1 = '/';
			operand_2 = '/';
		}
		else
		{
			operand_1 = determine_operand (difficulty);
			operand_2 = determine_operand (difficulty);
		}
		// if operand1 is a /, check/set to make sure the term following is > 0.
		if (operand_1 == '/')
		{
			if (!term_2)
			{
				term_2++;
			}
		}
		// if operand2 is a /, check/set to make sure the term following is > 0.
		if (operand_2 == '/')
		{
			if (!term_3)
			{
				term_3++;
			}
		}
	}
	// impossible difficulty
	else if (difficulty == 5)
	{
		// randomize terms
		term_1 = determine_term (difficulty);
		term_2 = determine_term (difficulty);
		term_3 = determine_term (difficulty);
		term_4 = determine_term (difficulty);
		// randomize operands based upon answered correctly questions.
		if (question_difficulty < 1)
		{
			operand_1 = '+';
			operand_2 = '+';
			operand_3 = '+';
		}
		else if (question_difficulty < 2)
		{
			operand_1 = '-';
			operand_2 = '-';
			operand_3 = '-';
		}
		else if (question_difficulty < 3)
		{
			operand_1 = '*';
			operand_2 = '*';
			operand_3 = '*';
		}
		else if (question_difficulty < 4)
		{
			operand_1 = '/';
			operand_2 = '/';
			operand_3 = '/';
		}
		else
		{
			operand_1 = determine_operand (difficulty);
			operand_2 = determine_operand (difficulty);
			operand_3 = determine_operand (difficulty);
		}
		// if operand1 is a /, check/set to make sure the term following is > 0.
		if (operand_1 == '/')
		{
			if (!term_2)
			{
				term_2++;
			}
		}
		// if operand2 is a /, check/set to make sure the term following is > 0.
		if (operand_2 == '/')
		{
			if (!term_3)
			{
				term_3++;
			}
		}
		// if operand3 is a /, check/set to make sure the term following is > 0.
		if (operand_3 == '/')
		{
			if (!term_4)
			{
				term_4++;
			}
		}
	}

	// assign the temp equation vars to the actual vars (kinda...)
	*term1 = term_1;
	*term2 = term_2;
	*term3 = term_3;
	*term4 = term_4;
	*operand1 = operand_1;
	*operand2 = operand_2;
	*operand3 = operand_3;
}

/*************************************************************
 * Function: determine_operand ()
 * Date Created: October 14th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function determines a operand based on
 *					the difficulty.
 * Input parameters: the current difficulty
 * Returns: an operand
 * Preconditions: an operand is needed.
 * Postconditions: an operand is returned
 *************************************************************/
char determine_operand (int difficulty)
{
	/* temp_operand
	 * 0 = +
	 * 1 = -
	 * 2 = *
	 * 3 = /
	*/
	int temp_operand = 0;
	char operand = '0';
	// easy (addition/subtration only)
	if (difficulty == 1)
	{
		temp_operand = rand () % 2;
	}
	// fair (multiplication/division only)
	else if (difficulty == 2)
	{
		temp_operand = (rand ()% 2) + 2;
	}
	// intermediate and up (all operands open)
	else
	{
		temp_operand = rand () % 4;
	}

	// get character of operand based on the randomized number
	if (temp_operand == 0)
	{
		operand = '+';
	}
	else if (temp_operand == 1)
	{
		operand = '-';
	}
	else if (temp_operand == 2)
	{
		operand = '*';
	}
	else if (temp_operand == 3)
	{
		operand = '/';
	}

	// return the operand
	return operand;
}

/*************************************************************
 * Function: determine_term ()
 * Date Created: October 14th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function randomizes a term based on the
 *					difficulty.
 * Input parameters: the difficulty
 * Returns: a randomized term
 * Preconditions: a term is needed.
 * Postconditions: a term is returned.
 *************************************************************/
int determine_term (int difficulty)
{
	// declares vars
	int pos_neg = 0, term = 0;
	// get random term based on difficulty
	// intermediate 0 - 9
	if (difficulty == 3)
	{
		term = rand () % 9;
	}
	// hard 0 - 99
	else if (difficulty == 4)
	{
		term = rand () % 99;
	}
	// impossible 10 - 999
	else
	{
		term = rand () % 999 + 10;
	}
	// get random positive vs. negative
	pos_neg = rand () % 2;
	// make term negative if necessary
	if (pos_neg == 1)
	{
		term = -term;
	}
	// return term
	return term;
}

/*************************************************************
 * Function: enter_score ()
 * Date Created: October 15th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function enters the score into the
 *					high scores list.
 * Input parameters: the initials and points of the game/player
 * Returns: Nothing
 * Preconditions: Game is over, score to be entered
 * Postconditions: Score is entered.
 *************************************************************/
void enter_score (char initial_a, char initial_b, char initial_c, int points)
{
	// declare file variable.
	FILE *scores = NULL;
	// open the high scores file for appending data
	scores = fopen ("high_scores.mgh", "a");
	// print the points and initials to the file
	fprintf (scores, "\n%d%c%c%c", points, initial_a, initial_b, initial_c);
	// close the file
	fclose (scores);
}

/*************************************************************
 * Function: display_end_message ()
 * Date Created: October 15th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function displays a "game over"-type message
 *					to the player
 * Input parameters: The points the player scored and the difficulty
 * Returns: Nothing
 * Preconditions: Game is over, end message needed.
 * Postconditions: end message displayed.
 *************************************************************/
void display_end_message (int points, int difficulty)
{
	// clear the screen
	system ("cls");
	// print the points
	printf ("You have answered all 10 question!\nYou got %d points while playing on ", points);
	// print the difficulty played on
	if (difficulty == 1)
	{
		printf ("easy!\n");
	}
	else if (difficulty == 2)
	{
		printf ("fair!\n");
	}
	else if (difficulty == 3)
	{
		printf ("intermediate!\n");
	}
	else if (difficulty == 4)
	{
		printf ("hard!\n");
	}
	else
	{
		printf ("impossible!\n");
	}
	// print high scores list remainder
	printf ("Your score has been entered in the high scores list, see how you did!\n\n");
	// pause, then clear the screen
	pause_clear (1, 1);
}

/*************************************************************
 * Function: display_help ()
 * Date Created: October 18th, 2011
 * Date Last Modified: October 19th, 2011
 * Description: This function displays some help/tips to the user.
 * Input parameters: None
 * Returns: Nothing
 * Preconditions: Help asked for
 * Postconditions: Help/tips displayed
 *************************************************************/
void display_help (void)
{
	// print title
	printf ("Help\n\n");
	// print order of operations
	printf ("Order of Operation: Multiply - Division, Addition - Subtraction\n");
	// print tips
	printf ("The key to solving the equations generated by this program lies in using the Order of Operations (given above) in order to help one solve them. When solving equations, you normally work left to right, provided that each operator (+, -, /, *) has the same precedence. However, if you have a multiplication or division operator, you must do its terms first, prior to doing any addition or subtraction. Operators of the same precedence still work left to right, so, for example, if you have the first and third operator being multiplication or division operators, do the first operator first, then the third, then do the second operator with the results of the first and third operators (in this example, the second operator has a different precedence).\nAlso, remember that an addition of a negative number is the samething as subtraction, and that the subtraction of a negative number is the same thing as addition. Dividing 0 by any number has a result of 0, and multiplying any number by 0 has a result of 0. Although this program doesn't generate any, any number divided by 0 does not exist.\n");
	// print new line
	printf ("\n");
	// pause, then clear the screen.
	pause_clear (1, 1);
}