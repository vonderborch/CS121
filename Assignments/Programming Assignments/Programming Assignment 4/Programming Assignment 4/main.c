/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Programming Assignment: Programming Assignment 2
 * Created: September 28th, 2011
 * Last Revised: October 5th, 2011
 * Description: This program allows the user to play the dice game called "Craps."
 *
 * Rules for Craps:A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3,
 *								4, 5, and 6 spots. After the dice have come to rest, the sum of the spots
 *								on the two upward faces is calculated. If the sum is 7 or 11 on the first
 *								throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called
 *								"craps"), the player loses (i.e. the "house" wins). If the sum is 4, 5, 6, 8,
 *								9, or 10 on the first throw, then the sum becomes the player's "point." To
 *								win, you must continue rolling the dice until you "make your point." The
 *								player loses by rolling a 7 before making the point.
 *
 * File Description: "main.c" contains the main() function from which the entire program is run.
 *********************************************************************************************/
#include "craps.h"

/*************************************************************
 * Function: main ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function is the primary control function of the
 *							program, from whence all other functions
 *							are called from as needed.
 * Input parameters: None
 * Returns: Nothing
 * Preconditions: Equations/Problems need to be solved.
 * Postconditions: Equations/Problems solved.
 *************************************************************/
int main (void)
{
	/* Game State Variable
	 * -2 = Quit game
	 * -1 = End game
	 *  0 = Main Menu
	 *  1 = Options Menu
	 *  2 = Set Game Balance
	 *  3 = Game Menu
	 *  4 = Game
	 *  5 = Defeat
	*/
	int game_state = 0;
	/*
	 * Option: Used for determining menu state.
	*/
	int option = 0;
	/* Enable Chatter
	 * 1 is chatter enabled
	 * 0 is chatter disabled
	*/
	int enable_chatter = 1;

	int wager_taken = 0, roll_number = 1;
	int die1 = 0, die2 = 0, dice_roll = 0, is_point = 0, player_points = 0, last_roll_won = 0;
	double money_balance = 0.0, basic_balance = 0.0, current_wager = 0.0;

	// display welcome message and pause (then clear the screen)
	display_messages (1);
	system ("pause");
	system ("cls");

	do
	{
		// Main Menu
		while (game_state == 0)
		{
			// show main menu
			option = display_menu ("********************************** Main Menu **********************************",
				"1. Start Game\n2. Display Rules\n3. Options\n4. Quit", 4, 1);
			// Option = 1: go to game setup if
			if (option == 1)
			{
				game_state = 2;
			}
			// Option = 2: Show game rules
			else if (option == 2)
			{
				print_game_rules ();
			}
			// Option = 3: Show options menu
			else if (option == 3)
			{
				game_state = 1;
			}
			// Option = 4: Exit Craps game
			else if (option == 4)
			{
				game_state = -2;
			}
		}

		// Options Menu
		while (game_state == 1)
		{
			// Show options menu
			option = display_menu ("********************************* Options Menu ********************************",
				"1. Back to Main Menu\n2. Enable / Disable Chatter\n", 2, 1);
			// Option = 1: Return to main menu
			if (option == 1)
			{
				game_state = 0;
			}
			// Option = 2: Enable/Disable chatter messages
			else if (option == 2)
			{
				enable_chatter = options_chatter (enable_chatter);
			}
		}

		// Set Game Balance / Settings
		while (game_state == 2)
		{
			// Set rand() seed to the current time
			srand((unsigned)time(NULL));
			// Get the starting money balance and set current/initial balance vars
			money_balance = get_bank_balance ();
			basic_balance = money_balance;
			// Set roll number to 1
			roll_number = 1;
			// Set player points to 0
			player_points = 0;
			// Go to game menu
			game_state = 3;
		}

		// Game Menu
		while (game_state == 3)
		{
			// if player has no money, they lose
			if (money_balance <= 0)
			{
				game_state = 5;
			}
			else
			{
				// show game menu
				option = display_menu ("********************************* Game Menu ********************************",
					"1. New Wager\n2. Roll Dice\n3. Check Balance\n4. Display Rules\n5. End Game", 5, 1);
				// if option is 1, set/check wager and display a chatter message
				if (option == 1)
				{
					chatter_messages (roll_number, last_roll_won, basic_balance, money_balance, 0, enable_chatter);
					wager_taken = 0;
					while (wager_taken != 1)
					{
						current_wager = get_wager_amount ();
						wager_taken = check_wager_amount (current_wager, money_balance);
					}
					if (current_wager == money_balance)
					{
						chatter_messages (0, 0, 0, 0, 5, enable_chatter);
					}
				}
				// Option = 2: Check if wager taken. If it is, do game "turn"
				else if (option == 2)
				{
					if (wager_taken == 0)
					{
						display_messages (2);
					}
					else
					{
						game_state = 4;
					}
				}
				// Option = 3: Show current player balance
				else if (option == 3)
				{
					show_game_balance (money_balance);
				}
				// Option = 4: Show game rules
				else if (option == 4)
				{
					print_game_rules ();
				}
				// Option = 5: Return to main menu
				else
				{
					game_state = 0;
				}
			}
		}
		// Game "Turn"
		while (game_state == 4)
		{
			// Display beginning turn message
			chatter_messages (0, 0, 0, 0, 1, enable_chatter);
			// roll the dice
			die1 = roll_die ();
			die2 = roll_die ();
			// calculate roll sum
			dice_roll = calculate_sum_dice (die1, die2);
			// if roll is first, use the first roll function
			if (roll_number == 1)
			{
				is_point = is_win_loss_or_point (dice_roll);
				player_points = dice_roll;
			}
			// Else use standard roll function
			else
			{
				is_point = is_point_loss_or_neither (dice_roll, player_points);
			}
			// adjust balance to result
			money_balance = adjust_bank_balance (money_balance, current_wager, is_point);
			// add number to the current roll number
			roll_number++;
			// Tell player the result of the roll
			if (is_point == 1)
			{
				// victory: reset vars and display message
				last_roll_won = 1;
				roll_number = 1;
				player_points = 0;
				chatter_messages (0, 0, 0, 0, 2, enable_chatter);
			}
			else if (is_point == 0)
			{
				// defeat: reset vars and display message
				last_roll_won = 0;
				roll_number = 1;
				player_points = 0;
				chatter_messages (0, 0, 0, 0, 3, enable_chatter);
			}
			else
			{
				// neither: display message
				last_roll_won = -1;
				chatter_messages (0, 0, 0, 0, 4, enable_chatter);
			}
			// Revert to game menu
			game_state = 3;
		}
		// show defeat screen
		while (game_state == 5)
		{
			// display defeat message and return to main menu
			display_messages (3);
			game_state = 0;
		}
	} while (game_state > -2);

	return 0;
}