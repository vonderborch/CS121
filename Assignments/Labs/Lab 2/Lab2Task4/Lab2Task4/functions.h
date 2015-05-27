/*******************************************************************************************
* Programmer: Christian Webber																	  *
* Class: Cpt S 121, Spring 2011; Lab Section 3										 	  *
* Programming Assignment: Lab 2, Task 4													  *
*							Functions header file.														  *
* Date: September 7th, 2011																		  *
* Description: This program calculates the Bowl Championship Series score of *
							a college football team.													  *
*******************************************************************************************/

#include <stdio.h>

double get_harris_poll (void);
double get_coaches_poll (void);
double get_computer_ranking (void);
double display_intermediate_harris_results(double harris_poll);
double display_intermediate_coaches_results(double coaches_poll);
double compute_total_score (double harris_poll, double coaches_poll, double computer_ranking);
double display_bcs_results(double bcs_score);
