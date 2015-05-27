/*******************************************************************************************
* Programmer: Christian Webber																	  *
* Class: Cpt S 121, Spring 2011; Lab Section 3										 	  *
* Programming Assignment: Lab 2, Task 4													  *
*							Functions file.																  *
* Date: September 7th, 2011																		  *
* Description: This program calculates the Bowl Championship Series score of *
							a college football team.													  *
*******************************************************************************************/

#include "functions.h"

double get_harris_poll (void)
{
	double value = 0.0;
	printf("What is the team's Harris Poll result? ");
	scanf("%lf", &value);
	return value;
}

double get_coaches_poll (void)
{
	double value = 0.0;
	printf("What is the team's Coaches Poll result? ");
	scanf("%lf", &value);
	return value;
}

double get_computer_ranking (void)
{
	double value = 0.0;
	printf("What is the team's Computer Ranking? ");
	scanf("%lf", &value);
	return value;
}

double display_intermediate_harris_results(double harris_poll)
{
	harris_poll = harris_poll / 2850;
	printf("Intermediate Results - Harris Poll = %lf\n", harris_poll);
	return 0;
}

double display_intermediate_coaches_results(double coaches_poll)
{
	coaches_poll = coaches_poll / 1475;
	printf("Intermediate Results - Coaches Poll = %lf\n", coaches_poll);
	return 0;
}

double compute_total_score (double harris_poll, double coaches_poll, double computer_ranking)
{
	double value = 0.0;
	value = ((harris_poll / 2850) + (coaches_poll / 1475) + computer_ranking) / 3;
	return value;
}

double display_bcs_results(double bcs_score)
{
	printf("Final Result - BCS Score = %lf\n\n", bcs_score);
	return 0;
}
