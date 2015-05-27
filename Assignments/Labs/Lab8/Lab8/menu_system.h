/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Standard Menu System
 * Created: October 5th, 2011
 * Last Revised: October 18th, 2011
 * Description: This function set allows a menu to be generated and a valid answer
 *							to be selected and returned.
 *
 * File Description: "menu_system.h" contains the various includes and function
 *									prototypes which control the menu_system.c file functions.
 *********************************************************************************************/

#ifndef MENU_SYSTEM
#define MENU_SYSTEM
#include <stdio.h>
#include <stdlib.h>

int display_standard_menu (char menu_title[], char menu_items[], int menu_type, int num_items, int min_items);
int char_convert (char value);
int is_valid_item (int option, int num_items, int min_items);

#endif