/*******************************************************************************************
* Programmer: Christian Webber																	  *
* Class: Cpt S 121, Spring 2011; Lab Section 3										 	  *
* Programming Assignment: Lab 2, Task 3													  *
*							Functions Header file.														  *
* Date: September 7th, 2011																		  *
* Description: This program calculates the gear ratio between a maximum and  *
								a minimum inputted speeds.										  *
*******************************************************************************************/

#include <stdio.h>
#include <math.h>

double prompt_maximum_speed (void);
double prompt_minimum_speed (void);
double speeds_ratio (double maximum_speed, double minimum_speed);
double display_ratio (double maximum_speed, double minimum_speed, double ratio);
