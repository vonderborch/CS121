/*******************************************************************************************
* Programmer: Christian Webber																	  *
* Class: Cpt S 121, Spring 2011; Lab Section 3										 	  *
* Programming Assignment: Lab 2, Task 2													  *
*							Functions file.																  *
* Date: September 7th, 2011																		  *
* Description: This program 
*******************************************************************************************/

#include "functions.h"

double get_weight (void)
{
	double value = 0.0;
	printf("Please enter Weight: ");
	scanf("%lf", &value);
	return value;
}

int get_height_feet (void)
{
	int value = 0.0;
	printf("Please enter Height (x Foot): ");
	scanf("%d", &value);
	return value;
}

int get_height_inches (void)
{
	int value = 0.0;
	printf("Please enter Height (y Inches): ");
	scanf("%d", &value);
	return value;
}

int compute_height (int feet, int inches)
{
	int value = 0;
	value = (feet * 12) + inches;
	return value;
}

double compute_BMI (double weight, int height)
{
	double value = 0.0;
	value = (weight / (height * height)) * 703;
	return value;
}

double display_results(double BMI)
{
	printf("Your Body Mass Index (BMI) = %lf\n", BMI);
	printf("< 18 = Underweight, >= 18 and < 25 = Healthy, >= 25 and < 30 = Overweight, > 30 = Obese\n\n");
	return 0;
}
