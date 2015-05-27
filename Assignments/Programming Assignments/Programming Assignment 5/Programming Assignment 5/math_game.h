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
 * File Description: "math_game.h" has all the includes and function prototypes for the math_game.
 *********************************************************************************************/

#ifndef MATH_GAME
#define MATH_GAME

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
// include menu systems function
#include "menu_system.h"

// screen_control.c Prototypes
int screen_control (int game_state);

// screens.c Prototypes
int screen_load_game (int *firstrun, char *initial_a, char *initial_b, char *initial_c, int *difficulty,
					  int *autosave_use, int *save1_use, int *save2_use, int *save3_use,
					  int *menu_type, int game_state);
int screen_main_menu (int game_state, int menu_type);
void screen_how_to_play (void);
void screen_display_highscores (void);
int screen_options_menu (int game_state, int menu_type, int *menu_state);
int screen_play_game_menu (int game_state, int menu_type, int *menu_state);
int screen_load_game_menu (int game_state, int menu_type, int *menu_state);
int screen_game_menu (int game_state, int menu_type, int *menu_state,
					  int questions, int term1, int term2, int term3, int term4,
					  char operand1, char operand2, char operand3);
void screen_save_game_menu (int menu_type, int *menu_state,
						char initial_a, char initial_b, char initial_c,
						int difficulty, int points, int questions, int question_difficulty,
						int term1, int term2, int term3, int term4,
						char operand1, char operand2, char operand3);

// functions.c Prototypes
void display_message (int message, int pause);
void pause_clear (int pause_true, int clear_true);
int enter_initials (char *initial_a, char *initial_b, char *initial_c);
void save_settings (int firstrun, char initial_a, char initial_b, char initial_c, int difficulty,
					  int autosave_use, int save1_use, int save2_use, int save3_use,
					  int menu_type);
int load_saved_game (int save, char *initial_a, char *initial_b, char *initial_c,
					  int *difficulty, int *points, int *questions, int *question_difficulty,
					  int *term1, int *term2, int *term3, int *term4,
					  char *operand1, char *operand2, char *operand3);
void save_game (int save, char initial_a, char initial_b, char initial_c,
					  int difficulty, int points, int questions, int question_difficulty,
					  int term1, int term2, int term3, int term4,
					  char operand1, char operand2, char operand3);
int display_game_menu (int questions, int term1, int term2, int term3, int term4,
					   char operand1, char operand2, char operand3,
					   char menu_items[], int menu_type, int num_items, int min_items);
double enter_answer (void);
int determine_answer (double entered_answer, int term1, int term2, int term3, int term4,
					  char operand1, char operand2, char operand3);
int calculate_terms (char operand2, char operand3);
int calculate_answer (int terms, int term1, int term2, int term3, int term4,
					  char operand1, char operand2, char operand3);
double calculate_answer_precise (int terms, int term1, int term2, int term3, int term4,
					  char operand1, char operand2, char operand3);
void new_equation (int difficulty, int question_difficulty,
				  int *term1, int *term2, int *term3, int *term4,
				  char *operand1, char *operand2, char *operand3);
char determine_operand (int difficulty);
int determine_term (int difficulty);
void enter_score (char initial_a, char initial_b, char initial_c, int points);
void display_end_message (int points, int difficulty);
void display_help (void);

#endif