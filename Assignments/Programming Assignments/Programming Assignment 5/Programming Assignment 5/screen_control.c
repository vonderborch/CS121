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
 * File Description: "screen_control.c" contains the screen_control function which
 *									controls what state the game is currently in.
 *********************************************************************************************/

#include "math_game.h"

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

/*************************************************************
 * Function: screen_control ()
 * Date Created: October 6th, 2011
 * Date Last Modified: October 18th, 2011
 * Description: This function displays controls the current "screen"
 *					the game is in
 * Input parameters: The gamestate
 * Returns: the new gamestate
 * Preconditions: Game must be played
 * Postconditions: Game has been played
 *************************************************************/
int screen_control (int game_state)
{
	// Main Settings/State Variables
	int state_state = 0,
		first_run = 0, difficulty = 0,
		autosave_use = 0, save1_use = 0, save2_use = 0, save3_use = 0,
		menu_type = 0,
		good_var = 0, save_load = 0;
	char initial_a = 'A', initial_b = 'A', initial_c = 'A';
	// Game Variables
	int points = 0, questions = 0, temp_questions = 0, question_difficulty = 1,
		term1 = 0, term2 = 0, term3 = 0, term4 = 0, terms = 0,
		answer_gen_int = 0, points_gain = 0;
	double entered_answer = 0.0, answer_gen_double = 0.0;
	char operand1 = 0, operand2 = 0, operand3 = 0;

	// loop through game while the game is *not* exiting
	while (game_state >= 0)
	{
		// load game
		if (game_state == 0)
		{
			// run the load game function
			game_state = screen_load_game (&first_run, &initial_a, &initial_b, &initial_c, &difficulty,
				&autosave_use, &save1_use, &save2_use, &save3_use,
				&menu_type, game_state);
			// check if this is the first time the game is being played
			if (first_run == 1)
			{
				// repeat ask for initials until gotten good ones
				do
				{
					printf ("Please enter your initials (all capital letters): ");
					good_var = enter_initials (&initial_a, &initial_b, &initial_c);
					system ("cls");
					if (good_var == 0)
					{
						display_message (4, 0);
					}
				} while (good_var == 0);
				// display that new initials have been entered
				display_message (8, 0);
				// set that this is now not the first run
				first_run = 0;
				// save the settings
				save_settings (first_run, initial_a, initial_b, initial_c, difficulty,
					autosave_use, save1_use, save2_use, save3_use,
					menu_type);
			}
		}
		// Main Menu
		else if (game_state == 1)
		{
			// show the main menu
			game_state = screen_main_menu (game_state, menu_type);
		}
		// Options Menu
		else if (game_state == 2)
		{
			// Show Options Menu
			if (state_state == 0)
			{
				game_state = screen_options_menu (game_state, menu_type, &state_state);
			}
			// Show difficulty selection menu
			else if (state_state == 1)
			{
				// display menu
				if (menu_type == 0)
				{
					// number-based version
					difficulty = display_standard_menu ("Select a Difficulty",
						"1. Easy\n2. Fair\n3. Intermediate\n4. Hard\n5. Impossible",
						menu_type, 5, 1);
				}
				else if (menu_type == 1)
				{
					// letter-based version
					difficulty = display_standard_menu ("Select a Difficulty",
						"A. Easy\nB. Fair\nC. Intermediate\nD. Hard\nE. Impossible",
						menu_type, 5, 1);
				}
				// show difficulty selected
				printf ("Difficulty changed to ");
				if (difficulty == 1)
				{
					printf ("easy.\n");
				}
				else if (difficulty == 2)
				{
					printf ("fair.\n");
				}
				else if (difficulty == 3)
				{
					printf ("intermediate.\n");
				}
				else if (difficulty == 4)
				{
					printf ("hard.\n");
				}
				else if (difficulty == 5)
				{
					printf ("impossible.\n");
				}
				// save settings
				save_settings (first_run, initial_a, initial_b, initial_c, difficulty,
					autosave_use, save1_use, save2_use, save3_use,
					menu_type);
				// go back to options menu
				state_state = 0;
			}
			// Enter new initials
			else if (state_state == 2)
			{
				// enter initials until good
				do
				{
					printf ("Please enter your initials (all capital letters): ");
					good_var = enter_initials (&initial_a, &initial_b, &initial_c);
					system ("cls");
					if (good_var == 0)
					{
						display_message (4, 0);
					}
				} while (good_var == 0);
				// say new initials entered
				display_message (8, 0);
				// save settings
				save_settings (first_run, initial_a, initial_b, initial_c, difficulty,
					autosave_use, save1_use, save2_use, save3_use,
					menu_type);
				// go back to options menu
				state_state = 0;
			}
			// Select Menu Type
			else if (state_state == 3)
			{
				if (menu_type == 0)
				{
					printf ("Menus are now letter-based for selection.\n");
					menu_type = 1;
				}
				else if (menu_type == 1)
				{
					printf ("Menus are now number-based for selection.\n");
					menu_type = 0;
				}
				// And just in case something gets messed up...
				else
				{
					printf ("Menus are now number-based for selection.\n");
					menu_type = 0;
				}
				// save settings
				save_settings (first_run, initial_a, initial_b, initial_c, difficulty,
					autosave_use, save1_use, save2_use, save3_use,
					menu_type);
				// go back to options menu
				state_state = 0;
			}
			// Clear High Scores
			else if (state_state == 4)
			{
				// file variable
				FILE *scores = NULL;
				// say resetting
				printf ("Resetting high scores list...");
				// open high scores file
				scores = fopen ("high_scores.mgh", "w");
				// print blank to it
				fprintf (scores, "");
				// close it
				fclose (scores);
				// enter 10 default scores
				printf (".");
				enter_score ('B', 'C', 'D', -2);
				printf (".");
				enter_score ('Y', 'Z', 'A', -1);
				printf (".");
				enter_score ('V', 'W', 'X', 0);
				printf (".");
				enter_score ('S', 'T', 'U', 1);
				printf (".");
				enter_score ('P', 'Q', 'R', 2);
				printf (".");
				enter_score ('M', 'N', 'O', 3);
				printf (".");
				enter_score ('J', 'K', 'L', 4);
				printf (".");
				enter_score ('G', 'H', 'I', 5);
				printf (".");
				enter_score ('D', 'E', 'F', 6);
				printf (".");
				enter_score ('A', 'B', 'C', 7);
				// say reset and go to options menu
				printf ("High scores list reset!\n");
				state_state = 0;
			}
			// Reset Saves
			else if (state_state == 5)
			{
				// say resetting says
				printf ("Resetting saves...");
				// reset all saves as "blank" files
				printf ("Resetting autosave...");
				save_game (0, 'A', 'A', 'A',
					1, 0, 0, 0,
					0, 0, 0, 0,
					0, 0, 0);
				printf ("Resetting save 1...");
				save_game (1, 'A', 'A', 'A',
					1, 0, 0, 0,
					0, 0, 0, 0,
					0, 0, 0);
				printf ("Resetting save 2...");
				save_game (2, 'A', 'A', 'A',
					1, 0, 0, 0,
					0, 0, 0, 0,
					0, 0, 0);
				printf ("Resetting save 3...");
				save_game (3, 'A', 'A', 'A',
					1, 0, 0, 0,
					0, 0, 0, 0,
					0, 0, 0);
				printf ("Saves Reset!\n");
				// say saves not in use
				autosave_use = 0;
				save1_use = 0;
				save2_use = 0;
				save3_use = 0;
				// save settings
				save_settings (first_run, initial_a, initial_b, initial_c, difficulty,
					autosave_use, save1_use, save2_use, save3_use,
					menu_type);
				state_state = 0;
			}
			// Reset Game
			else if (state_state == 6)
			{
				// say restting
				printf ("Resetting game...");
				// save default settings
				save_settings (1, 'A', 'A', 'A', 1, 0, 0, 0, 0,
					0);
				// say game reset
				printf ("Game Reset!\n");
				// reload game
				game_state = 0;
				state_state = 0;
			}
		}
		// Play Game Menu
		else if (game_state == 3)
		{
			// reset all game vars and display play game menu
			if (state_state == 0)
			{
				points = 0;
				questions = 0;
				question_difficulty = 1;
				term1 = 0;
				term2 = 0;
				term3 = 0;
				term4 = 0;
				entered_answer = 0;
				operand1 = 0;
				operand2 = 0;
				operand3 = 0;
				game_state = screen_play_game_menu (game_state, menu_type, &state_state);
			}
			// load autosave/continue game
			else if (state_state == 1)
			{
				// check if autosave is even in use at all
				if (autosave_use == 0)
				{
					display_message (3, 0);
				}
				// if it is, try to load it and play it
				else if (autosave_use == 1)
				{
					good_var = load_saved_game (0, &initial_a, &initial_b, &initial_c,
						&difficulty, &points, &questions, &question_difficulty,
						&term1, &term2, &term3, &term4,
						&operand1, &operand2, &operand3);
					if (good_var)
					{
						game_state = 5;
					}
					else
					{
						display_message (5, 0);
					}
				}
				// default state state
				state_state = 0;
			}
			// change difficulty
			else if (state_state == 2)
			{
				// display menu
				if (menu_type == 0)
				{
					// number-based version
					difficulty = display_standard_menu ("Select a Difficulty",
						"1. Easy\n2. Fair\n3. Intermediate\n4. Hard\n5. Impossible",
						menu_type, 5, 1);
				}
				else if (menu_type == 1)
				{
					// letter-based version
					difficulty = display_standard_menu ("Select a Difficulty",
						"A. Easy\nB. Fair\nC. Intermediate\nD. Hard\nE. Impossible",
						menu_type, 5, 1);
				}
				// say difficulty changed to
				printf ("Difficulty changed to ");
				if (difficulty == 1)
				{
					printf ("easy.\n");
				}
				else if (difficulty == 2)
				{
					printf ("fair.\n");
				}
				else if (difficulty == 3)
				{
					printf ("intermediate.\n");
				}
				else if (difficulty == 4)
				{
					printf ("hard.\n");
				}
				else if (difficulty == 5)
				{
					printf ("impossible.\n");
				}
				// save settings
				save_settings (first_run, initial_a, initial_b, initial_c, difficulty,
					autosave_use, save1_use, save2_use, save3_use,
					menu_type);
				// head back to play game menu
				state_state = 0;
			}
			else if (state_state == 3)
			{
				// keep entering initials until "good"
				do
				{
					printf ("Please enter your initials (all capital letters): ");
					good_var = enter_initials (&initial_a, &initial_b, &initial_c);
					system ("cls");
					if (good_var == 0)
					{
						display_message (4, 0);
					}
				} while (good_var == 0);
				display_message (8, 0);
				// save settings
				save_settings (first_run, initial_a, initial_b, initial_c, difficulty,
					autosave_use, save1_use, save2_use, save3_use,
					menu_type);
				// play game menu
				state_state = 0;
			}
		}
		// Load Game
		else if (game_state == 4)
		{
			// show load game menu
			if (state_state == 0)
			{
				good_var = 0;
				game_state = screen_load_game_menu (game_state, menu_type, &state_state);
			}
			else if (state_state == 1)
			{
				// see if save 1 is in use, if it is, continue to load,
				//else return to load game menu
				if (save1_use)
				{
					save_load = 1;
					state_state = 4;
				}
				else
				{
					display_message (6, 0);
					state_state = 0;
				}
			}
			else if (state_state == 2)
			{
				// see if save 2 is in use, if it is, continue to load,
				//else return to load game menu
				if (save2_use)
				{
					save_load = 2;
					state_state = 4;
				}
				else
				{
					display_message (6, 0);
					state_state = 0;
				}
			}
			else if (state_state == 3)
			{
				// see if save 3 is in use, if it is, continue to load,
				//else return to load game menu
				if (save3_use)
				{
					save_load = 3;
					state_state = 4;
				}
				else
				{
					display_message (6, 0);
					state_state = 0;
				}
			}
			// try to load selected game, then play the game
			else if (state_state == 4)
			{
				good_var = load_saved_game (save_load, &initial_a, &initial_b, &initial_c,
					&difficulty, &points, &questions, &question_difficulty,
					&term1, &term2, &term3, &term4,
					&operand1, &operand2, &operand3);
				if (good_var)
				{
					game_state = 5;
				}
				else
				{
					display_message (5, 0);
				}
				state_state = 0;
			}
		}
		// gameplay
		else if (game_state == 5)
		{
			// show game menu
			if (state_state == 0)
			{
				temp_questions = questions + 1;
				game_state = screen_game_menu (game_state, menu_type, &state_state,
					temp_questions, term1, term2, term3, term4, operand1, operand2, operand3);
			}
			// enter answer
			else if (state_state == 1)
			{
				// show equation again
				printf ("Question #%d: %d %c %d", temp_questions, term1, operand1, term2);
				if (operand2 != '0')
				{
					printf (" %c %d", operand2, term3);
				}
				if (operand3 != '0')
				{
					printf (" %c %d", operand3, term4);
				}
				// ask for answer
				printf (" = ?\nWhat is your answer? ");
				// get answer
				entered_answer = enter_answer ();
				// determine if it is correct
				entered_answer = determine_answer (entered_answer, term1, term2, term3, term4,
									operand1, operand2, operand3);
				// increase question count #
				questions++;
				// determine point gain or loss
				points_gain = (double)difficulty + ((double)difficulty * ((double)question_difficulty / 2.0));
				// correct answer
				if (entered_answer)
				{
					// points are decreased determined by points_gain + 1
					points += (points_gain + 1);
					// increase question difficulty
					question_difficulty++;
					// say answer correctly
					printf ("Your answer was correct!\n");
				}
				// wrong answer
				else
				{
					// points are decreased determined by points_gain
					points -= points_gain;
					// decrease question difficulty (min of 1)
					question_difficulty--;
					if (question_difficulty < 1)
					{
						question_difficulty = 1;
					}
					// say answer wrong
					printf ("Your answer was wrong!\n");
				}
				// generate new question
				state_state = 7;
			}
			// Show Points
			else if (state_state == 2)
			{
				printf ("You have %d Points!\n", points);
				// return to in-game menu
				state_state = 0;
			}
			// show help
			else if (state_state == 3)
			{
				// display help
				display_help ();
				// return to in-game menu
				state_state = 0;
			}
			// save game
			else if (state_state == 4)
			{
				// show save game menu
				screen_save_game_menu (menu_type, &state_state,
					initial_a, initial_b, initial_c,
					difficulty, points, questions, question_difficulty,
					term1, term2, term3, term4,
					operand1, operand2, operand3);
			}
			// quit
			else if (state_state == 6)
			{
				state_state = 0;
				// goto main menu
				game_state = 1;
			}
			// Check if game should be over and/or
			// generate new question and autosave
			else if (state_state == 7)
			{
				// if less than 10 questions, generate new equation
				if (questions < 10)
				{
					// say generating new equations
					printf ("Generating new equation..");
					// keep getting new equations until the int answer and double answer match
					// this will ensure that the answer is always a whole number
					do
					{
						// print "." to denote a question try
						printf (".");
						// get new equation
						new_equation (difficulty, question_difficulty,
							&term1, &term2, &term3, &term4,
							&operand1, &operand2, &operand3);
						// get term count
						terms = calculate_terms (operand2, operand3);
						// get the answer as an int
						answer_gen_int = calculate_answer (terms, term1, term2, term3, term4,
															operand1, operand2, operand3);
						// get the answer as a double
						answer_gen_double = calculate_answer_precise (terms, term1, term2, term3, term4,
															operand1, operand2, operand3);
					} while (answer_gen_int != answer_gen_double);
					// print a new line
					printf ("\n");
					// save to the autosave file (in case user quits without saving and/or
					// wants to continue playing at a later date
					save_game (0, initial_a, initial_b, initial_c,
						difficulty, points, questions, question_difficulty,
						term1, term2, term3, term4,
						operand1, operand2, operand3);
					// go autosave informer sub-state
					state_state = 11;
				}
				// if final question, go to high score entering game state
				else
				{
					state_state = 0;
					game_state = 6;
				}
			}
			// tell game that save slot 1 is now in use
			else if (state_state == 8)
			{
				// if save 1 isn't in use, tell game it is and save that setting
				if (!save1_use)
				{
					save1_use = 1;
					save_settings (first_run, initial_a, initial_b, initial_c, difficulty,
						autosave_use, save1_use, save2_use, save3_use,
						menu_type);
				}
				state_state = 0;
			}
			// tell game that save slot 2 is now in use
			else if (state_state == 9)
			{
				// if save 2 isn't in use, tell game it is and save that setting
				if (!save2_use)
				{
					save2_use = 1;
					save_settings (first_run, initial_a, initial_b, initial_c, difficulty,
						autosave_use, save1_use, save2_use, save3_use,
						menu_type);
				}
				state_state = 0;
			}
			// tell game that save slot 3 is now in use
			else if (state_state == 10)
			{
				// if save 3 isn't in use, tell game it is and save that setting
				if (!save3_use)
				{
					save3_use = 1;
					save_settings (first_run, initial_a, initial_b, initial_c, difficulty,
						autosave_use, save1_use, save2_use, save3_use,
						menu_type);
				}
				state_state = 0;
			}
			// tell game that the autosave is now in use
			else if (state_state == 11)
			{
				// if the autosave isn't in use, tell game it is and save that setting
				if (!autosave_use)
				{
					autosave_use = 1;
					save_settings (first_run, initial_a, initial_b, initial_c, difficulty,
						autosave_use, save1_use, save2_use, save3_use,
						menu_type);
				}
				state_state = 0;
			}
		}
		// enter high score
		else if (game_state == 6)
		{
			// enter score in high scores list
			enter_score (initial_a, initial_b, initial_c, points);
			// display game over message
			display_end_message (points, difficulty);
			// return to main menu
			game_state = 1;
		}
	}
	// return a -1 for game state once main game loop is broken,
	// so that the game will exit in the main function
	return -1;
}