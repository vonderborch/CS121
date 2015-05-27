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

#include "example3_6.h"

int main (void)
{
	/* Declare a variable to store the minute part of the times for each of the
	   four runners */
	int runner1_min = 0, runner2_min = 0, runner3_min = 0, runner4_min = 0;

	/* Declare a variable to store the second part of the times for each of the 
	   four runners */
	double runner1_sec = 0.0, runner2_sec = 0.0, runner3_sec = 0.0, runner4_sec = 0.0;

	/* Store the total time, of each of the four runners, in seconds */
	double runner1_time_sec = 0.0, runner2_time_sec = 0.0, runner3_time_sec = 0.0,
		   runner4_time_sec = 0.0;

	/* Store the speed of each of the four runners in feet per second (fps) */
	double runner1_fps = 0.0, runner2_fps = 0.0, runner3_fps = 0.0, runner4_fps = 0.0;

	/* Store the speed of each of the four runners in meters per second (mps) */
	double runner1_mps = 0.0, runner2_mps = 0.0, runner3_mps = 0.0, runner4_mps = 0.0;

	display_initial_message ();


	/* Read the minute part of the time for each runner */
	runner1_min = read_minutes (1);
	runner2_min = read_minutes (2);
	runner3_min = read_minutes (3);
	runner4_min = read_minutes (4);
	printf ("\n");

	/* Read the seconds part of the time for each runner */
	runner1_sec = read_seconds (1);
	runner2_sec = read_seconds (2);
	runner3_sec = read_seconds (3);
	runner4_sec = read_seconds (4);

	/* Convert each runner's total time from min and sec to just sec */
	runner1_time_sec = convert_time_to_seconds (runner1_min, runner1_sec);
	runner2_time_sec = convert_time_to_seconds (runner2_min, runner2_sec);
	runner3_time_sec = convert_time_to_seconds (runner3_min, runner3_sec);
	runner4_time_sec = convert_time_to_seconds (runner4_min, runner4_sec);

	/* Calculate the speed of each runner in feet per second */
	runner1_fps = calculate_feet_per_second (runner1_time_sec);
	runner2_fps = calculate_feet_per_second (runner2_time_sec);
	runner3_fps = calculate_feet_per_second (runner3_time_sec);
	runner4_fps = calculate_feet_per_second (runner4_time_sec);

	/* Calculate the speed of each runner in meters per second */
	runner1_mps = calculate_meters_per_second (runner1_time_sec);
	runner2_mps = calculate_meters_per_second (runner2_time_sec);
	runner3_mps = calculate_meters_per_second (runner3_time_sec);
	runner4_mps = calculate_meters_per_second (runner4_time_sec);

	/* Display the speeds of each of the runners (both mps and fps) */
	printf ("\n********************\n");
	printf ("Runner\tFPS\tMPS\n");
	printf ("********************\n");
	display_speeds (runner1_fps, runner1_mps, 1);
	display_speeds (runner2_fps, runner2_mps, 2);
	display_speeds (runner3_fps, runner3_mps, 3);
	display_speeds (runner4_fps, runner4_mps, 4);
	printf ("********************\n");

	return (0);
}