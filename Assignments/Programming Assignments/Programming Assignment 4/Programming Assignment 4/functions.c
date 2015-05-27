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
 * File Description: "functions.c" contains the various sub-functions that make up various
 *								reusable components of the game.
 *********************************************************************************************/
#include "craps.h"

/*************************************************************
 * Function: display_messages ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function displays 'game-critical'
 *					messages to the user, ones that are always
 *					shown.
 * Input parameters: Message # to display
 * Returns: Nothing
 * Preconditions: Message needs to be displayed
 * Postconditions: Message has been displayed
 *************************************************************/
int display_messages (int message)
{
	// Message #1: Welcome to the Game
	if (message == 1)
	{
		printf ("*******************************************************************************\n");
		printf ("***************************** Welcome to Craps ********************************\n");
		printf ("*******************************************************************************\n\n");
	}
	// Message #2: No wager set yet.
	else if (message == 2)
	{
		printf ("Please set your wager first.\n");
	}
	// Message #3: Player has lost the game.
	else if (message == 3)
	{
		printf ("*******************************************************************************\n");
		printf ("*********************** Defeat!!!!!!!!!!!!!!!!!!!!!! **************************\n");
		printf ("*******************************************************************************\n\n");
	}
}
/*************************************************************
 * Function: display_menu ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function displays a menu, determined by a string
 *					passed into it, and allows the user to select a
 *					valid item (error-checks for invalid item).
 * Input parameters: menu_title shows the title of the menu (Main Menu, etc.),
 *						menu_items shows the menu itself, num_items is the
 *						number of total items in the menu, and min_items is the
 *						lowest selectable item.
 * Returns: Item selected
 * Preconditions: Menu needs to be displayed for an option to be gotten
 * Postconditions: Returns the menu option selected.
 *************************************************************/
int display_menu (char menu_title[], char menu_items[], int num_items, int min_items)
{
	// set current option to 0
	int option = 0;

	// repeat while option is invalid
	do
	{
		// display menu title
		printf ("%s\n\n",menu_title);
		// display menu items
		printf ("%s\n", menu_items);

		// get user selection input
		scanf (" %d", &option);
		// clear screen
		system ("cls");
		// determine validity of option
	} while (!is_valid_item (option, num_items, min_items));

	// return option
	return option;
}

/*************************************************************
 * Function: is_valid_item ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function determines whether the selected
 *					menu choice is a valid option or not.
 * Input parameters: option - selected option, num_items - 
 *						total number of menu options, 
 *						min_items - lowest selectable option.
 * Returns: Whether the option selected is valid or not.
 * Preconditions: Option needs to be checked if valid.
 * Postconditions: Validity of option returned.
 *************************************************************/
int is_valid_item (int option, int num_items, int min_items)
{
	// set validity to no
	int valid = 0;
	// if option falls within the min/max items, validity is yes
	if ((option >= min_items) && (option <= num_items))
	{
		valid = 1;
	}
	// return validity
	return valid;
}
/*************************************************************
 * Function: print_game_rules ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function shows the user the rules for the game.
 * Input parameters: None
 * Returns: Nothing
 * Preconditions: Rules need to be displayed.
 * Postconditions: Rules displayed.
 *************************************************************/
void print_game_rules (void)
{
	// display game rules, pause, then clear screen
	printf ("********************************** Game Rules *********************************\n\n");
	printf ("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the spots on the two upward faces is calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called 'craps'), the player loses (i.e. the 'house' wins). If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's 'point.' To win, you must continue rolling the dice until you 'make your point.' The player loses by rolling a 7 before making the point.\n\n");
	system ("pause");
	system ("cls");
}
/*************************************************************
 * Function: options_chatter ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function sets whether chatter is displayed
 *					or not.
 * Input parameters: Current chatter setting.
 * Returns: New chatter setting
 * Preconditions: Chatter setting needs to be set differently.
 * Postconditions: Chatter setting set differently.
 *************************************************************/
int options_chatter (int chatter)
{
	// if chatter is enabled, disable and show user
	if (chatter == 1)
	{
		printf ("Chatter Disabled");
		chatter = 0;
	}
	// if chatter is disabled, enable and show user
	else
	{
		printf ("Chatter Enabled");
		chatter = 1;
	}
	// print new line
	printf ("\n");
	// return new chatter state
	return chatter;
}
/*************************************************************
 * Function: get_bank_balance ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function gets the starting bank balance
 *					of the player.
 * Input parameters: None
 * Returns: Starting balance
 * Preconditions: No starting balance set.
 * Postconditions: Starting balance is returned.
 *************************************************************/
double get_bank_balance (void)
{
	// set temp balance to 0.0
	double balance = 0.0;
	// ask for starting balance and get
	printf ("Starting balance? ");
	scanf (" %lf", &balance);
	// clear screen
	system ("cls");
	// return starting balance
	return balance;
}
/*************************************************************
 * Function: get_wager_amount ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function gets the user's wager for the roll.
 * Input parameters: None
 * Returns: New Wager
 * Preconditions: Wager needs to be set.
 * Postconditions: Returns new wager
 *************************************************************/
double get_wager_amount (void)
{
	// set temp wager to 0.0
	double wager = 0.0;
	// ask/get new wager
	printf ("What do you want to wager? ");
	scanf (" %lf", &wager);
	// clear screen
	system ("cls");
	// return wager
	return wager;
}
/*************************************************************
 * Function: check_wager_amount ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function determines if the wager is valid or not.
 * Input parameters: current wager and current bank balance
 * Returns: Validity of wager
 * Preconditions: Wager validity must be determined.
 * Postconditions: Validity of wager is returned
 *************************************************************/
int check_wager_amount (double wager, double balance)
{
	// set wager validity to no
	int is_valid = 0;
	// if wager is more than nothing and less than/equal to current balance
	//        set validity to yes
	if ((wager > 0) && (balance >= wager))
	{
		is_valid = 1;
	}
	// return validity
	return is_valid;
}
/*************************************************************
 * Function: show_game_balance ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function shows the current bank balance.
 * Input parameters: current balance
 * Returns: Nothing
 * Preconditions: Bank balance needs to be shown.
 * Postconditions: bank balance shown.
 *************************************************************/
double show_game_balance (double balance)
{
	// show current balance, pause, then clear screen
	printf ("Current Balance: %.2lf\n\n", balance);
	system ("pause");
	system ("cls");
}
/*************************************************************
 * Function: roll_die ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function gets a random number between 1 and 6.
 * Input parameters: None
 * Returns: Random number (face of die)
 * Preconditions: Die needs to be "rolled."
 * Postconditions: Die "roll" returned.
 *************************************************************/
int roll_die (void)
{
	// set temp roll to 0
	int die_face = 0;
	// get random number between 1 and 6
	die_face = rand() % 6 + 1;
	// return roll
	return die_face;
}
/*************************************************************
 * Function: calculate_sum_dice ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function calculates the sum of the dice.
 * Input parameters: Dice values
 * Returns: Dice sum
 * Preconditions: Sum of dice roll needed.
 * Postconditions: Sum of dice roll returned.
 *************************************************************/
int calculate_sum_dice (int die1_value, int die2_value)
{
	// calculate sum of the dice rolls
	int dice_sum = die1_value + die2_value;
	// return sum
	return dice_sum;
}
/*************************************************************
 * Function: is_win_loss_or_point ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function determines the "score" of the
 *					first dice roll.
 * Input parameters: sum of the dice
 * Returns: "Score" of the dice roll.
 * Preconditions: "Score" needs to be determined.
 * Postconditions: Score determined returned.
 *************************************************************/
int is_win_loss_or_point (int sum_dice)
{
	// check is the roll was a win/loss/point and return
	int is_point = -1;
	if ((sum_dice == 7) || (sum_dice == 11))
	{
		is_point = 1;
	}
	else if ((sum_dice > 3) && (sum_dice < 11))
	{
		is_point = 0;
	}
	return is_point;
}
/*************************************************************
 * Function: is_point_loss_or_neither ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function determines the "score" of the
 *					dice roll.
 * Input parameters: sum of the dice, point value.
 * Returns: "Score" of the dice roll.
 * Preconditions: "Score" needs to be determined.
 * Postconditions: Score determined returned.
 *************************************************************/
int is_point_loss_or_neither (int sum_dice, int point_value)
{
	// check is the roll was a win/loss/point and return
	int is_point = -1;
	if (sum_dice == point_value)
	{
		is_point = 1;
	}
	else if (sum_dice == 7)
	{
		is_point = 0;
	}
	return is_point;
}
/*************************************************************
 * Function: adjust_bank_balance ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function adjusts the bank balance based on the
 *					current bank balance, wager amount, and last roll.
 * Input parameters: Current bank balance, the wager amount, and
 *						the "score" of the last roll
 * Returns: New bank balance
 * Preconditions: Bank balance needs adjusting
 * Postconditions: New bank balance returned.
 *************************************************************/
double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract)
{
	// adjust bank balance based on results of roll and return new balance
	double temp_balance = bank_balance;
	if (add_or_subtract == 1)
	{
		temp_balance = bank_balance + wager_amount;
	}
	else if (add_or_subtract == 0)
	{
		temp_balance = bank_balance - wager_amount;
	}
	return temp_balance;
}
/*************************************************************
 * Function: chatter_messages ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 5th, 2011
 * Description: This function displays chatter messages to the user.
 * Input parameters: number of rolls done, whether the last roll was
 *						a victory, loss, or neither, the starting bank
 *						balance, the current bank balance, whether a 
 *						specific message should be displayed, whether
 *						chatter is currently enabled.
 * Returns: Nothing
 * Preconditions: Chatter message needed.
 * Postconditions: Message displayed
 *************************************************************/
void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance,
					   double current_bank_balance, int specific_message, int chatter_enabled)
{
	// if chatter is enabled, can display messages (1), else, don't (0)
	if (chatter_enabled == 1)
	{
		// is a specific message being called for or not? (0 = no)
		if (specific_message == 0)
		{
			// dispaly message if balance is less than 0 (obsolete)
			if (current_bank_balance <= 0)
			{
				printf ("Sorry, you're busted!");
			}
			// display message if user has 2.5x as much money as began with
			if ((current_bank_balance/initial_bank_balance) > 2.5)
			{
				printf ("You're up big, now's the time to cash in your chips!");
			}
			// display message if user has 1.5x as much money as began with
			else if ((current_bank_balance/initial_bank_balance) > 1.5)
			{
				printf ("Aww, cmon and take a chance!");
			}
			// display message if user has 0.5x as much money as began with
			else if ((current_bank_balance/initial_bank_balance) < 0.5)
			{
				printf ("Looks like you're not doing too well there...");
			}
			// ask what user will bet
			else
			{
				printf ("So...what're you gonna bet?");
			}
		}
		// Specific message 1: Rolling dice
		else if (specific_message == 1)
		{
			printf ("Rolling Dice...");
		}
		// Specific message 2: roll win
		else if (specific_message == 2)
		{
			printf ("You have won the roll! Money is now being deposited in your account.");
		}
		// Specific message 3: Roll loss
		else if (specific_message == 3)
		{
			printf ("You have lost the roll! Money is now being removed from in your account.");
		}
		// Specific message 4: Roll neither
		else if (specific_message == 4)
		{
			printf ("You have not won or lost the roll!");
		}
		// Specific message 5: all-in wager
		else if (specific_message == 5)
		{
			printf ("Oh, you're going for broke, huh?");
		}
		// 2 new lines, pause, then clear screen
		printf ("\n\n");
		system ("pause");
		system ("cls");
	}
}