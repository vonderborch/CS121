/*******************************************************************************************
* Programmer: Christian Webber																	  *
* Class: Cpt S 121, Spring 2011; Lab Section 3										 	  *
* Programming Assignment: Lab 2, Task 3													  *
*							Main file.																		  *
* Date: September 7th, 2011																		  *
* Description: This program calculates the gear ratio between a maximum and  *
								a minimum inputted speeds.										  *
*******************************************************************************************/

#include "functions.h"

int main(void)
{
	double speed_max = 0.0, speed_min = 0.0, ratio = 0.0;
	speed_max = prompt_maximum_speed();
	speed_min = prompt_minimum_speed();
	ratio = speeds_ratio(speed_max, speed_min);
	display_ratio (speed_max, speed_min, ratio);
	return 0;
}