/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Programming Assignment: Programming Assignment 2
 * Created: September 28th, 2011
 * Last Revised: October 4th, 2011
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
 * File Description: "craps.h" contains the commonly needed library calls for the
 *								entire program, as well as the function prototypes for the functions.
 *********************************************************************************************/
#ifndef CRAPS_H
#define CRAPS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int display_messages (int message);

int display_menu (char menu_title[], char menu_items[], int num_items, int min_items);
int is_valid_item (int option, int num_items, int min_items);
void print_game_rules (void);
int options_chatter (int chatter);

double get_bank_balance (void);
double get_wager_amount (void);
int check_wager_amount (double wager, double balance);
double show_game_balance (double balance);
int roll_die (void);
int calculate_sum_dice (int die1_value, int die2_value);
int is_win_loss_or_point (int sum_dice);
int is_point_loss_or_neither (int sum_dice, int point_value);
double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract);
void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance, int specific_message, int chatter_enabled);

#endif