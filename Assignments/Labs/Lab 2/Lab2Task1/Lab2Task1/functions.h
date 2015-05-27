/*******************************************************************************************
* Programmer: Christian Webber																	  *
* Class: Cpt S 121, Spring 2011; Lab Section 3										 	  *
* Programming Assignment: Lab 2, Task 1													  *
*							Functions header file.														  *
* Date: September 7th, 2011																		  *
* Description: This program computes the formula of a perpendicular line to that*
								of two inputted points.													  *
*******************************************************************************************/
#include <stdio.h>
double get_number(char coord_vector, int coord_num);
double compute_slope(double x_1, double y_1, double x_2, double y_2);
double compute_midpoint(double coord_1, double coord_2);
double compute_bisector_slope(double slope);
double compute_y_intercept(double slope, double x_mid, double y_mid);
double display_results(double x_1, double y_1, double x_2, double y_2, double slope, double y_intercept);
