#include "lab5.h"

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