/*******************************************************************************************
* Programmer: Christian Webber																	  *
* Class: Cpt S 121, Spring 2011; Lab Section 3										 	  *
* Programming Assignment: Lab 2, Task 3													  *
*							Functions file.																  *
* Date: September 7th, 2011																		  *
* Description: This program calculates the gear ratio between a maximum and  *
								a minimum inputted speeds.										  *
*******************************************************************************************/

#include "functions.h"

double prompt_maximum_speed (void)
{
	double value = 0.0;
	printf("Maximum Speed (RPM) of the Gearbox? ");
	scanf("%lf", &value);
	return value;
}

double prompt_minimum_speed (void)
{
	double value = 0.0;
	printf("Minimum Speed (RPM) of the Gearbox? ");
	scanf("%lf", &value);
	return value;
}

double speeds_ratio (double maximum_speed, double minimum_speed)
{
	double value = 0.0;
	value = maximum_speed / minimum_speed;
	value = pow(value, -5);
	return value;
}

double display_ratio (double maximum_speed, double minimum_speed, double ratio)
{
	printf("The ratio between successive speeds of a six-speed gearbox with maximum speed %.1lf RPM and minimum speed %.1lf RPM is %lf.\n\n",
		maximum_speed, minimum_speed, ratio);
	return 0;
}
