/*******************************************************************************************
* Programmer: Christian Webber																	  *
* Class: Cpt S 121, Spring 2011; Lab Section 3										 	  *
* Programming Assignment: Lab 2, Task 1													  *
*							Functions file.																  *
* Date: September 7th, 2011																		  *
* Description: This program computes the formula of a perpendicular line to that*
								of two inputted points.													  *
*******************************************************************************************/

#include "functions.h"

double get_number(char coord_vector, int coord_num)
{
	double temp_coord = 0.0;
	printf("Enter %c coord %d: ", coord_vector, coord_num);
	scanf("%lf", &temp_coord);
	return temp_coord;
}

double compute_slope(double x_1, double y_1, double x_2, double y_2)
{
	double slope = 0.0;
	slope = (y_2 - y_1) / (x_2 - x_1);
	return slope;
}

double compute_midpoint(double coord_1, double coord_2)
{
	double midpoint = 0.0;
	midpoint = (coord_1 + coord_2) / 2;
	return midpoint;
}

double compute_bisector_slope(double slope)
{
	double bisector = 0.0;
	bisector = -1/slope;
	return bisector;
}

double compute_y_intercept(double slope, double x_mid, double y_mid)
{
	double y_intercept = 0.0;
	y_intercept = y_mid - (slope * x_mid);
	return y_intercept;
}

double display_results(double x_1, double y_1, double x_2, double y_2, double slope, double y_intercept)
{
	printf("For the points (%.2lf, %.2lf) and (%.2lf, %.2lf), the equation of the \n                 perpendicular bisector is: y = %.2lfx + %.2lf\n\n", 
		x_1, y_1, x_2, y_2, slope, y_intercept);
	return 0;
}
