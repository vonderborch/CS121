/*******************************************************************************************
* Programmer: Christian Webber																	  *
* Class: Cpt S 121, Spring 2011; Lab Section 3										 	  *
* Programming Assignment: Lab 2, Task 2													  *
*							Main file.																		  *
* Date: September 7th, 2011																		  *
* Description: This program calculates the Body Mass Index (BMI) of a person, *	
								based upon inputted height and weight.						  *
*******************************************************************************************/

#include "functions.h"

int main (void)
{
	int height_feet = 0, height_inches = 0, height_final = 0;
	double weight = 0.0, result_BMI = 0.0;
	weight = get_weight();
	height_feet = get_height_feet();
	height_inches = get_height_inches();
	height_final = compute_height (height_feet, height_inches);
	result_BMI = compute_BMI (weight, height_final);
	display_results(result_BMI);
	return 0;
}