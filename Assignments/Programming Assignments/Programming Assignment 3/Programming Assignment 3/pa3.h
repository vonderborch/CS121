/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Programming Assignment: Programming Assignment 3
 * Created: September 20th, 2011
 * Last Revised: September 20th, 2011
 * Description: This program reads 5 student records from a file ("input.dat")
 *						and then analyzes the records to determine the mean GPA,
 *						the mean Class Standing, the mean Age, the standard
 *						deviation of the GPA's, the lowest GPA, and the highest
 *						GPA, then saves the information to an output file.
 *
 * File Description: "pa3.h" contains the commen header files and the function
								prototypes.
 *********************************************************************************************/

#ifndef PA3_H
#define PA3_H

// Needed pre-defined header files
#include <stdio.h>
#include <math.h>

// Function prototypes
int display_message (int type);
double read_double (FILE *infile);
int read_integer (FILE *infile);
double calculate_sum (double number1, double number2, double number3, double number4, double number5);
double calculate_mean (double sum, int number);
double calculate_deviation (double number, double mean);
double calculate_variance (double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation (double variance);
double find_max (double number1, double number2, double number3, double number4, double number5);
double find_min (double number1, double number2, double number3, double number4, double number5);
void print_double (FILE *outfile, char string[], double number);

#endif