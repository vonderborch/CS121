/*******************************************************************************************
* Programmer: Christian Webber																	  *
* Class: Cpt S 121, Spring 2011; Lab Section 3										 	  *
* Programming Assignment: Lab 2, Task 1													  *
*							Main file.																		  *
* Date: September 7th, 2011																		  *
* Description: This program computes the formula of a perpendicular line to that*
								of two inputted points.													  *
*******************************************************************************************/

#include "functions.h"

int main (void)
{
	double coord_x1 = 0.0, coord_x2 = 0.0, coord_y1 = 0.0, coord_y2 = 0.0,
		slope = 0.0, midpoint_X = 0.0, midpoint_Y = 0.0, y_intercept = 0.0;
	coord_x1 = get_number('X', 1);
	coord_y1 = get_number('Y', 1);
	coord_x2 = get_number('X', 2);
	coord_y2 = get_number('Y', 2);
	slope = compute_slope(coord_x1, coord_y1, coord_x2, coord_y2);
	midpoint_X = compute_midpoint(coord_x1, coord_x2);
	midpoint_Y = compute_midpoint(coord_y1, coord_y2);
	slope = compute_bisector_slope(slope);
	y_intercept = compute_y_intercept(slope, midpoint_X, midpoint_Y);
	display_results(coord_x1, coord_y1, coord_x2, coord_y2, slope, y_intercept);
	return 0;
}
