/*************************************************************************
 * Programmer: Andrew O'Fallon                                           *
 * Class: CptS 121, Fall 2011  ; Lab Section 0                           *
 * Programming Assignment: Programming Project 8 in Chapter 3            *
 *                         of Hanly/Koffman book                         *
 * Date: September 5, 2011                                               *
 *                                                                       *
 * Description: This program calculates the cyclist's constant rate      *
 *              of acceleration and determines how long it will take     *
 *              for a cyclist to stop moving. The program displays the   *
 *              rate of acceleration and amount of time it takes the     *
 *              cyclist to stop moving.                                  *
 *                                                                       *
 * Relevant Formulas: a = (vf - vi) / t, where a is acceleration,        *
 *                                       vi is initial velocity,         *
 *                                       vf is final velocity,           *
 *                                       t is time interval              *
 ************************************************************************/


#include <stdio.h> /* Header file for scanf, printf */

#define MIN_PER_HOUR 60.0      /* There are 60 minutes in one hour */
#define METERS_PER_MILE 1608.0 /* Approximately 1608 meters per mile */
#define SEC_PER_HOUR 3600.0    /* 3600 seconds in one hour */
#define SEC_PER_MIN 60.0       /* 60 seconds in one minute */

/* List the function prototypes for the program */\
/* The descriptions for each of the functions can be seen in a comment block
   above each function definition */

void beginning_program_message (void);
double get_initial_velocity (void);
double get_final_velocity (void);
double get_time_interval (void);
double calculate_acceleration_mi_hour (double init_velocity, double final_velocity, double amount_time);
double calculate_acceleration_m_sec (double init_velocity, double final_velocity, double amount_time);
double calculate_time_to_stop (double init_velocity, double final_velocity, double acceleration,
							   double initial_time_interval);
void display_acceleration_and_time (double acceleration_mi_hours, double acceleration_m_sec,
									double time_to_stop);
