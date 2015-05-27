/**********************************************************************************************
 * Programmer: Andrew S. O'Fallon                                                             *
 * Class: CptS 121, Fall 2011  ; Lab Section 0                                                *
 * Programming Assignment: Programming Project 6 in Chapter 3                                 *
 *                         of Hanly/Koffman book                                              *
 * Date: September 4, 2011                                                                    *
 *                                                                                            *
 * Description: This program calculates the speed of a runner for a mile                      *
 *              in feet per second and meters per second. The program reads input             *
 *              from a user. The input is the number of minutes and seconds                   *
 *              that it took a runner to complete a mile. There are four entries              *
 *              of times that need to be read, corresponding to four runners in the race.     *
 *              The results of feet/sec and meters/sec calculations are displayed             *
 *              to the screen.                                                                *
 *                                                                                            *
 * Relevant Formulas: 1 mile = 5,280 ft                                                       *
 *                    1 km   = 3,282 ft                                                       *
 *********************************************************************************************/

#include <stdio.h> /* Header file for scanf, printf */

#define SECONDS_PER_MINUTE 60.0 /* Number of seconds in a minute */
#define FEET_PER_MILE 5280.0    /* Number of feet in one mile */
#define FEET_PER_KM 3282.0      /* Number of feet in one kilometer */
#define METERS_PER_KM 1000.0    /* Number of meters in one kiometer */

/* These are the function prototypes; functions are described more by the comment
   blocks before the function definition */

void display_initial_message ();
int read_minutes (int runner_number);
double read_seconds (int runner_number);
double convert_time_to_seconds (int minutes, double seconds);
double calculate_feet_per_second (double time_in_seconds);
double calculate_meters_per_second (double time_in_seconds);
void display_speeds (double feet_per_second, double meters_per_second, int runner_num);
