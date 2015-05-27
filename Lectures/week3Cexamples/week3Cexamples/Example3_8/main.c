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

#include "example3_8.h"

int main (void)
{
	double initial_velocity = 0.0, final_velocity = 0.0, time_interval = 0.0,
		   acceleration_mi_hour = 0.0, /* Acceleration miles/hour */
		   acceleration_m_sec = 0.0,    /* Acceleration meters/sec */
		   time_to_stop = 0.0; /* Stores the time required to stop */

	beginning_program_message ();

    /* Collect the necessary velocity and time interval information needed to
	   calculate the constant rate of acceleration, from the user. */

	initial_velocity = get_initial_velocity ();
	final_velocity = get_final_velocity ();
	time_interval = get_time_interval ();

    /* Calculate the acceleration in miles per hours^2 and meters per sec^2. */

	acceleration_mi_hour = calculate_acceleration_mi_hour (initial_velocity, final_velocity, time_interval);
	acceleration_m_sec = calculate_acceleration_m_sec (initial_velocity, final_velocity, time_interval);

    /* Determine the time it takes the cyclist to slow to a stop. */

	time_to_stop = calculate_time_to_stop (final_velocity, 0, acceleration_mi_hour, time_interval);

	/* Display the acceleration in mi/hr^2 and m/s^2 and also the time to stop. */

	display_acceleration_and_time (acceleration_mi_hour, acceleration_m_sec, time_to_stop);

	return (0);
}