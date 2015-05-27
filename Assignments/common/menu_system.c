/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Standard Menu System
 * Created: October 5th, 2011
 * Last Revised: October 19th, 2011
 * Description: This function set allows a menu to be generated and a valid answer
 *							to be selected and returned.
 *
 * File Description: "menu_system.h" contains the various includes and function
 *									prototypes which control the menu_system.c file functions.
 *********************************************************************************************/

#include "menu_system.h"

/*************************************************************
 * Function: display_standard_menu ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 10th, 2011
 * Changelog:
 *					September 28th, 2011: Function created to generate main menu.
 *					September 29th, 2011: Changed function to work for any menu inputed.
 *					October 5th, 2011: Added comments to function.
 *					October 10th, 2011: Adjusted input detection to check for errors (invalid
 *														datatype). Modified to accept option for using
 *														character input rather than menu. Modified
 *														input parameter description for descriptiveness.
 * Description: This function displays a menu, determined by a string
 *					passed into it, and allows the user to select a
 *					valid item (error-checks for invalid item).
 * Input parameters:
 *							menu_title: A string containing the title of the menu. No need for
 *													included new line.
 *							menu_items: A string containing all menu items (printed as one,
 *													include new lines aside from last one).
 *							menu_type: Use 0 for number menu, 1 for letter menu.
 *							num_items: Maximum option. If menu_type is Char-based, use
 *													'highest' uppercase character used in Menu (i.e. Z).
 *													Will automatically calculate lowercase version.
 *													Pass as an integer.
 *							min_items: Lowest option. If menu_type is Char-based, use
 *													'lowest' uppercase character used in Menu (i.e. A).
 *													Will automatically calculate lowercase version.
 *													Pass as an integer.
 * Returns: Item selected as an int
 * Preconditions: Menu needs to be displayed for an option to be gotten
 * Postconditions: Returns the menu option selected.
 *************************************************************/
int display_standard_menu (char menu_title[], char menu_items[], int menu_type, int num_items, int min_items)
{
	// set current option to 0
	int option = 0, error_check = 0;
	char char_option = '\0';

	// repeat while option is invalid
	do
	{
		// display menu title
		printf ("%s\n\n",menu_title);
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
		//rewind (stdin);
		flushall();

		// clear screen
		system ("cls");
		// determine validity of option
	} while (!is_valid_item (option, num_items, min_items));

	// return option as an int
	return option;
}

int char_convert (char value)
{
	int int_value = (int)value - 64;
	if (int_value > 32)
	{
		int_value -= 32;
	}
	return int_value;
}

/*************************************************************
 * Function: is_valid_item ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 10th, 2011
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
	// if option falls inside the min/max items, validity is yes
	if ((option >= min_items) && (option <= num_items))
	{
		valid = 1;
	}
	// if option falls outside the min/max items, validity is no
	//			and the user is informed of a input-error.
	else
	{
		printf ("Please enter valid input.\n");
	}
	// return validity
	return valid;
}