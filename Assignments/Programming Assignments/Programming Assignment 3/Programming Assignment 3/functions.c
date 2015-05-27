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
 * File Description: "functions.c" contains all function prototype definitions.
 *********************************************************************************************/

// Include program common header file
#include "pa3.h"

/*************************************************************
 * Function: display_message ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function displays common messages.
 * Input parameters: Which message will be displayed.
 * Returns: Nothing
 * Preconditions: A standard message needs to be displayed.
 * Postconditions: A message is displayed.
 *************************************************************/
int display_message (int type)
{
	// Startup Message
	if (type == 0)
	{
		printf ("****** Programming Assignment 3: Statistical Analysis of Student Records *******\n");
	}
	// Opening file message
	else if (type == 1)
	{
		printf ("Opening student records from input file...\n");
	}
	// Record analysis message
	else if (type == 2)
	{
		printf ("Analysing student records...\n\n");
	}
	// Input file failure message
	else if (type == 3)
	{
		printf ("Error 1 - Input file failed to open.\n\n");
	}
	// Unsuccesful exit message
	else if (type == 4)
	{
		printf ("******** Analysis of Student Records Failed! ********\n\n");
	}
	// Succesful Exit message
	else
	{
		printf ("******** Analysis of Student Records Completed! ********\n\n");
	}
	// Return nothing
	return;
}

/*************************************************************
 * Function: read_double ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function reads a double-type variable
 *						from a file.
 * Input parameters: The file to read the double from.
 * Returns: The double value read from the file.
 * Preconditions: An input file exists and data from it is
 *							needed.
 * Postconditions: The needed variable is returned.
 *************************************************************/
double read_double (FILE *infile)
{
	// Declare a temporary value and set to 0.0
	double temp_value = 0.0;
	// Read the temporary value from the passed file
	fscanf (infile, " %lf", &temp_value);
	// Return the temporary value
	return temp_value;
}

/*************************************************************
 * Function: read_integer ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function reads a integer-type variable
 *						from a file.
 * Input parameters: The file to read the integer from.
 * Returns: The integer value read from the file.
 * Preconditions: An input file exists and data from it is
 *							needed.
 * Postconditions: The needed variable is returned.
 *************************************************************/
int read_integer (FILE *infile)
{
	// Declare a temporary value and set to 0
	int temp_value = 0;
	// Read the temporary value from the passed file
	fscanf (infile, " %d", &temp_value);
	// Return the temporary value
	return temp_value;
}

/*************************************************************
 * Function: calculate_sum ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function calculates the sum of 5 numbers
 *						read into it.
 * Input parameters: The 5 numbers that the sum is needed
 *								from.
 * Returns: The sum of the 5 numbers.
 * Preconditions: The sum of the 5 numbers is needed.
 * Postconditions: The sum of the 5 numbers is returned.
 *************************************************************/
double calculate_sum (double number1, double number2, double number3,
					  double number4, double number5)
{
	// Declare temporary variable and set as being the sum of the passed numbers.
	double value = number1 + number2 +
		number3 + number4 + number5;
	// Return the temporary variable
	return value;
}

/*************************************************************
 * Function: calculate_mean ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function calculates the mean of
 *						of the sum based into it based on the
 *						number of variables that the sum is
 *						calculated from. Returns a -1.0 if the
 *						"number" variable is 0.
 * Input parameters: The sum and the number of variables
 *								the sum is made from.
 * Returns: The mean value.
 * Preconditions: The sum and number of variables it it
 *							calculated from are known and mean
 *							is needed.
 * Postconditions: The mean value is returned.
 *************************************************************/
double calculate_mean (double sum, int number)
{
	// Declare a temporary value and set to -1.0 (default return value)
	double value = -1.0;
	// If the passed variable "number" is not 0, make value = sum / number
	if (number != 0)
	{
		value = sum / number;
	}
	// return the temporary variable
	return value;
}

/*************************************************************
 * Function: calculate_deviation ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function calculates the
 *						deviation of the number read into it
 *						based on the mean.
 * Input parameters: The number deviation is
 *								needed of and the mean.
 * Returns: The deviation of the number.
 * Preconditions: The standard is unknown and
 *							the mean and number are.
 * Postconditions: The deviation is returned.
 *************************************************************/
double calculate_deviation (double number, double mean)
{
	// Set a temporary variable as the passed number - the passed mean
	double value = number - mean;
	// Return the temporary variable
	return value;
}

/*************************************************************
 * Function: calculate_variance ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function calculates the variance between
 *						5 standard deviations.
 * Input parameters: The number of deviations and 5 deviations.
 * Returns: The variance between the deviations.
 * Preconditions: The variance is unknown while 5 deviations are.
 * Postconditions: The variance is returned.
 *************************************************************/
double calculate_variance (double deviation1,
			double deviation2, double deviation3,
			double deviation4, double deviation5, int number)
{
	// Declare a temporary variable and set it as being equal to
	//			 ((deviation1)^2 + (deviation2)^2 + (deviation3)^2 +
	//			    (deviation4)^2 + (deviation5)^2)
	double value = pow (deviation1, 2.0) + pow (deviation2, 2.0) +
		pow (deviation3, 2.0) + pow (deviation4, 2.0) +
		pow (deviation5, 2.0);
	// Set the temporary variable as being equal to the result of a
	//			call to the calculate_mean function with the temporary
	//			variable and the number variables being sent to it.
	value = calculate_mean(value, number);
	// Return the temporary variable
	return value;
}

/*************************************************************
 * Function: calculate_standard_deviation ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function calculates the standard
 *						deviation of the variance.
 * Input parameters: The variance of 5 deviations.
 * Returns: The standard deviation.
 * Preconditions: The variance between 5 deviations is known
 *							while the standard deviation is not.
 * Postconditions: The standard deviation is returned.
 *************************************************************/
double calculate_standard_deviation (double variance)
{
	// Declare and set a temporary variable as being equal
	//			to the square root of the passed variance variable
	double value = sqrt(variance);
	// Return the temporary variable
	return value;
}

/*************************************************************
 * Function: find_max ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function is finds the largest of 5 numbers.
 * Input parameters: 5 numbers.
 * Returns: The largest of the numbers.
 * Preconditions: 5 numbers are known and the largest
 *							needs to be determined.
 * Postconditions: The largest of the numbers is returned.
 *************************************************************/
double find_max (double number1, double number2, double number3, double number4, double number5)
{
	// Set a temporary variable as being equal to number1
	double max_number = number1;

	// Determine if number2 is the largest variable
	// If true, set the temporary variable as being = number2
	if ((number2 >= number1) && (number2 >= number3) && (number2 >= number4) && (number2 >= number5))
	{
		max_number = number2;
	}
	// Determine if number3 is the largest variable
	// If true, set the temporary variable as being = number3
	else if ((number3 >= number1) && (number3 >= number2) && (number3 >= number4) && (number3 >= number5))
	{
		max_number = number3;
	}
	// Determine if number4 is the largest variable
	// If true, set the temporary variable as being = number4
	else if ((number4 >= number1) && (number4 >= number2) && (number4 >= number3) && (number4 >= number5))
	{
		max_number = number4;
	}
	// Determine if number5 is the largest variable
	// If true, set the temporary variable as being = number5
	else if ((number5 >= number1) && (number5 >= number2) && (number5 >= number3) && (number5 >= number4))
	{
		max_number = number5;
	}

	// Return the temporary variable
	return max_number;
}

/*************************************************************
 * Function: find_min ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function is finds the smallest of 5 numbers.
 * Input parameters: 5 numbers.
 * Returns: The smallest of the numbers.
 * Preconditions: 5 numbers are known and the smallest
 *							needs to be determined.
 * Postconditions: The smallest of the numbers is returned.
 *************************************************************/
double find_min (double number1, double number2, double number3, double number4, double number5)
{
	// Set a temporary variable as being equal to number1
	double min_number = number1;

	// Determine if number2 is the smallest variable
	// If true, set the temporary variable as being = number2
	if ((number2 <= number1) && (number2 <= number3) && (number2 <= number4) && (number2 <= number5))
	{
		min_number = number2;
	}
	// Determine if number3 is the smallest variable
	// If true, set the temporary variable as being = number3
	else if ((number3 <= number1) && (number3 <= number2) && (number3 <= number4) && (number3 <= number5))
	{
		min_number = number3;
	}
	// Determine if number4 is the smallest variable
	// If true, set the temporary variable as being = number4
	else if ((number4 <= number1) && (number4 <= number2) && (number4 <= number3) && (number4 <= number5))
	{
		min_number = number4;
	}
	// Determine if number5 is the smallest variable
	// If true, set the temporary variable as being = number5
	else if ((number5 <= number1) && (number5 <= number2) && (number5 <= number3) && (number5 <= number4))
	{
		min_number = number5;
	}

	// Return the temporary variable
	return min_number;
}

/*************************************************************
 * Function: print_double ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function writes a string and a number
 *						to an output file.
 * Input parameters: The output file, the number to write to it,
 *								and a string to write as well.
 * Returns: Nothing
 * Preconditions: A number needs to be written to a file.
 * Postconditions: The number is written to the file.
 *************************************************************/
void print_double (FILE *outfile, char string[], double number)
{
	// Print to the output file the passed string and
	//			number (to 2 decimal places)
	fprintf (outfile, "%s = %.2lf\n", string, number);
	// Return nothing
	return;
}