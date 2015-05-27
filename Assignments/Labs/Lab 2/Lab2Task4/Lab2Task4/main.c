/*******************************************************************************************
* Programmer: Christian Webber																	  *
* Class: Cpt S 121, Spring 2011; Lab Section 3										 	  *
* Programming Assignment: Lab 2, Task 4													  *
*							Main file.																		  *
* Date: September 7th, 2011																		  *
* Description: This program calculates the Bowl Championship Series score of *
							a college football team.													  *
*******************************************************************************************/

#include "functions.h"

int main (void)
{
	double harris_poll = 0.0, coaches_poll = 0.0, computer_ranking = 0.0, bcs_score = 0.0;
	harris_poll = get_harris_poll();
	coaches_poll = get_coaches_poll();
	computer_ranking = get_computer_ranking();
	display_intermediate_harris_results(harris_poll);
	display_intermediate_coaches_results(coaches_poll);
	bcs_score = compute_total_score(harris_poll, coaches_poll, computer_ranking);
	display_bcs_results(bcs_score);
	return 0;
}