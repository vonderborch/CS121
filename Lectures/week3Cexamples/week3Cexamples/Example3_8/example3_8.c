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

/*************************************************************
 * Function: beginning_program_message ()                    *
 * Date Created: September 5, 2011                           *
 * Date Last Modified: September 5, 2011                     *
 * Description: This function displays an initial message    *
 *              about the program when it is first executed. *
 * Input parameters: None                                    *
 * Returns: Nothing                                          *
 * Preconditions: Start of program.                          *
 * Postconditions: A start message is displayed.             *
 *************************************************************/

void beginning_program_message (void)
{
	printf ("****************************************************\n");
	printf ("This program calculates the amount of time\n");
	printf ("it takes a cyclist to come to rest given an\n");
	printf ("initial velocity, final velocity, and time_interval.\n");
	printf ("****************************************************\n\n");
}

/*************************************************************
 * Function: get_initial_velocity ()                         *
 * Date Created: September 5, 2011                           *
 * Date Last Modified: September 5, 2011                     *
 * Description: This function gets the initial velocity      *
 *              from the user. The initial velocity is the   *
 *              velocity that needed to calculate the        *
 *              constant rate of acceleration.               *
 * Input parameters: None                                    *
 * Returns: The initial velocity as a double.                *
 * Preconditions: None                                       *
 * Postconditions: The initial velocity in mi/hr is returned.*
 *************************************************************/

double get_initial_velocity (void)
{
	double initial_velocity = 0.0;

	/* Get the initial velocity from the user. This is the initial velocity used
	   to calculate the constant rate of acceleration. */

	printf ("Enter the initial velocity (mi/s): ");
	scanf ("%lf", &initial_velocity);

	return initial_velocity;
}

/*************************************************************
 * Function: get_final_velocity ()                           *
 * Date Created: September 5, 2011                           *
 * Date Last Modified: September 5, 2011                     *
 * Description: This function gets the final velocity        *
 *              from the user. The final velocity is the     *
 *              velocity that needed to calculate the        *
 *              constant rate of acceleration.               *
 * Input parameters: None                                    *
 * Returns: The final velocity.                              *
 * Preconditions: None                                       *
 * Postconditions: The final velocity in mi/hr is returned.  *
 *************************************************************/

double get_final_velocity (void)
{
	double final_velocity = 0.0;

	/* Get the final velocity from the user. This is the final velocity used
	   to calculate the constant rate of acceleration. */

	printf ("Enter the final velocity (mi/s): ");
	scanf ("%lf", &final_velocity);

	return final_velocity;
}

/*************************************************************
 * Function: get_time_interval ()                            *
 * Date Created: September 5, 2011                           *
 * Date Last Modified: September 5, 2011                     *
 * Description: This function gets the initial time interval *
 *              from the user. The time interval represents  *
 *              the amount of time it took the cyclist to    *
 *              slow from the initial velocity to the final  *
 *              velocity. The final velocity is not a stop.  *
 * Input parameters: None                                    *
 * Returns: The initial time interval.                       *
 * Preconditions: None                                       *
 * Postconditions: The time interval in minutes is returned. *
 *************************************************************/

double get_time_interval (void)
{
	double time_interval = 0.0;

	/* Get the time interval, in minutes, of the time that it took the cyclist
	   to slow from an initial velocity to a final velocity */

	printf ("Enter the amount of time (min.) it took to reach the final velocity\n");
	printf ("given the initial velocity you entered: ");
	scanf ("%lf", &time_interval);

	return time_interval;
}

/*************************************************************
 * Function: calculate_acceleration_mi_hour ()               *
 * Date Created: September 5, 2011                           *
 * Date Last Modified: September 5, 2011                     *
 * Description: This function calculates the constant rate   *
 *              of acceleration in mi/hr^2.                  *
 * Input parameters: The initial and final velocities,       *
 *                   and initial time interval.              *
 * Returns: The constant acceleration in mi/hr^2.            *
 * Preconditions: The final and initial velocities           *
 *                and initial_time_interval                  *
 * Postconditions: The acceleration has been calculated in   *
 *                 mi/hr^2.                                  *
 *************************************************************/

double calculate_acceleration_mi_hour (double init_velocity, double final_velocity, double time_interval)
{
	double acceleration = 0.0;

	/* Calculate the constant rate of acceleration in mi/hr^2, given the 
	   initial velocity, final velocity, and the time interval */

	acceleration = (final_velocity - init_velocity) / (time_interval / MIN_PER_HOUR);

	return acceleration;
}

/*************************************************************
 * Function: calculate_acceleration_m_sec ()                 *
 * Date Created: September 5, 2011                           *
 * Date Last Modified: September 5, 2011                     *
 * Description: This function calculates the constant rate   *
 *              of acceleration in m/s^2.                    *
 * Input parameters: The initial and final velocities,       *
 *                   and initial time interval.              *
 * Returns: The constant acceleration in m/s^2.              *
 * Preconditions: The final and initial velocities           *
 *                and initial_time_interval                  *
 * Postconditions: The acceleration has been calculated in   *
 *                 m/s^2.                                    *
 *************************************************************/

double calculate_acceleration_m_sec (double init_velocity, double final_velocity, double amount_time)
{
	double acceleration = 0.0;

	/* Calculate the acceleration in meters / second^2 */

	acceleration = ((final_velocity - init_velocity) * (METERS_PER_MILE / SEC_PER_HOUR)) /
		           (amount_time * SEC_PER_MIN);

	return acceleration;
}

/*************************************************************
 * Function: calculate_time_to_stop ()                       *
 * Date Created: September 5, 2011                           *
 * Date Last Modified: September 5, 2011                     *
 * Description: This function calculates the total time it   *
 *              takes a cyclist to role to a stop on a flat  *
 *              surface, given an initial velocity.          *
 * Input parameters: The initial and final velocities,       *
 *                   constant acceleration, and initial      *
 *                   time interval.                          *
 * Returns: The total time to stop as a double.              *
 * Preconditions: The final and initial velocities,          *
 *                acceleration, and initial_time_interval    *
 * Postconditions: The total time it takes the cyclist to    *
 *                 role to a stop.                           *
 *************************************************************/

double calculate_time_to_stop (double init_velocity, double final_velocity, double acceleration,
							   double initial_time_interval)
{
	double time = 0.0;

	/* Calculate the total time to slow to a stop */

	time = (((final_velocity - init_velocity) / acceleration) * SEC_PER_HOUR) +
		   (initial_time_interval * SEC_PER_MIN);

	return time;
}

/*************************************************************
 * Function: display_acceleration_and_time ()                *
 * Date Created: September 5, 2011                           *
 * Date Last Modified: September 5, 2011                     *
 * Description: This function displays acceleration of the   *
 *              cyclist in mi/hr^2 and m/s^2. The function   *
 *              also displays the total time to stop.        *
 * Input parameters: The acceleration in mi/hr^2 and m/s^2   *
 *                   and the total time to stop.             *
 * Returns: Nothing                                          *
 * Preconditions: The acceleration and time to stop need to  *
 *                already been calculated.                   *
 * Postconditions: Display of the accelerations and time to  *
 *                 stop.                                     *
 *************************************************************/

void display_acceleration_and_time (double acceleration_mi_hr, double acceleration_m_sec, 
									double time_to_stop)
{
	/* The display shows the acceleration in mi/hr^2 and in m/s^2 */
	/* The display only shows the time to stop in seconds */
	/* The time to stop indicates the total time from the initial */
	/*  movement of the cyclist until the cyclist comes to a stop */

	printf ("\n****************************************\n");
	printf ("Rate of acceleration (mi/hr^2): %0.2lf\n", acceleration_mi_hr);
	printf ("Rate of acceleration (m/s^2):   %0.2lf\n", acceleration_m_sec);
	printf ("Total time to stop (s):         %0.2lf\n", time_to_stop);
	printf ("****************************************\n");
}