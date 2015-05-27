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
 * File Description: "main.c" contains the main() function from which the entire program is run.
 *********************************************************************************************/

// Include program common header file
#include "pa3.h"

/*************************************************************
 * Function: main ()
 * Date Created: September 20th, 2011
 * Date Last Modified: September 20th, 2011
 * Description: This function is the primary control function of the
 *							program, from whence all other functions
 *							are called from as needed.
 * Input parameters: None
 * Returns: Nothing
 * Preconditions: Student records need to be analyzed.
 * Postconditions: Student records are analyzed.
 *************************************************************/
int main (void)
{
	// Variables
	FILE *infile = NULL, *outfile = NULL; // File variables
	int id_number1 = 0, id_number2 = 0,
		id_number3 = 0, id_number4 = 0, id_number5 = 0; // Student ID# variables
	double gpa_1 = 0.0, gpa_2 = 0.0, gpa_3 = 0.0,
		gpa_4 = 0.0, gpa_5 = 0.0;  // Student GPA variables
	int class_standing1 = 0, class_standing2 = 0,
		class_standing3 = 0, class_standing4 = 0,
		class_standing5 = 0; // Student Class Standing variables
	double age_1 = 0.0, age_2 = 0.0, age_3 = 0.0,
		age_4 = 0.0, age_5 = 0.0; // Student age variables
	double sum_gpas = 0.0, sum_ages = 0.0,
		sum_class_standing = 0.0; // Sum variables for GPA's, Ages, and Class Standings
	double mean_gpas = 0.0, mean_ages = 0.0,
		mean_class_standing = 0.0; // Mean variables for GPA's, Ages, and Class Standings
	double gpa_deviation1 = 0.0, gpa_deviation2 = 0.0,
		gpa_deviation3 = 0.0, gpa_deviation4 = 0.0,
		gpa_deviation5 = 0.0; // Deviations of student GPA compared to Mean GPA
	double gpa_variance = 0.0, gpa_standard_deviation = 0.0; // Average variance and standard deviation of the GPA's
	double min_gpa = 0.0, max_gpa = 0.0; // Lowest (min) and highest (max) GPA of the 5 recorded
	int input_failure = 0; // Variable for determining Input File status (0 = exists, -1 = does not exist)

	// Display introduction message
	display_message (0);

	// Tell user that records are being opened...
	display_message (1);

	// Open input file for reading data
	infile = fopen ("input.dat", "r");
	// Open output file for saving data
	outfile = fopen ("output.dat", "w");

	// Determine if the input file exists, and if it doesn't inform the user and
	//						set input_failure variable to -1.
	if (infile == NULL)
	{
		display_message(3);
		input_failure = -1;
	}

	// Student Record Analysis Main
	// Only run if input_failure variable is 0 (i.e. only run if input file exists).
	if (input_failure == 0)
	{
		// Read information for Student #1
		id_number1 = read_integer (infile);
		gpa_1 = read_double (infile);
		class_standing1 = read_integer (infile);
		age_1 = read_double (infile);

		// Read information for Student #2
		id_number2 = read_integer (infile);
		gpa_2 = read_double (infile);
		class_standing2 = read_integer (infile);
		age_2 = read_double (infile);

		// Read information for Student #3
		id_number3 = read_integer (infile);
		gpa_3 = read_double (infile);
		class_standing3 = read_integer (infile);
		age_3 = read_double (infile);

		// Read information for Student #4
		id_number4 = read_integer (infile);
		gpa_4 = read_double (infile);
		class_standing4 = read_integer (infile);
		age_4 = read_double (infile);

		// Read information for Student #5
		id_number5 = read_integer (infile);
		gpa_5 = read_double (infile);
		class_standing5 = read_integer (infile);
		age_5 = read_double (infile);

		// Tell user that the records are being analyzed...
		display_message (2);

		// Calculate sum of the GPA's
		sum_gpas = calculate_sum (gpa_1, gpa_2,
			gpa_3, gpa_4, gpa_5);

		// Calculate sum of the Ages
		sum_ages = calculate_sum (age_1, age_2,
			age_3, age_4, age_5);

		// Calculate sum of the Class Standings
		sum_class_standing = calculate_sum (class_standing1, class_standing2,
			class_standing3, class_standing4, class_standing5);

		// Calculate mean of the GPA's and write it to output file
		mean_gpas = calculate_mean (sum_gpas, 5);
		print_double (outfile, "Mean GPA", mean_gpas);

		// Calculate mean of the Class Standings and write it to output file
		mean_class_standing = calculate_mean (sum_class_standing, 5);
		print_double (outfile, "Mean Class Standing", mean_class_standing);

		// Calculate mean of the Ages and write it to output file
		mean_ages = calculate_mean (sum_ages, 5);
		print_double (outfile, "Mean Age", mean_ages);

		 // Calculate the deviation of each GPA from the mean
		gpa_deviation1 = calculate_deviation (gpa_1, mean_gpas);
		gpa_deviation2 = calculate_deviation (gpa_2, mean_gpas);
		gpa_deviation3 = calculate_deviation (gpa_3, mean_gpas);
		gpa_deviation4 = calculate_deviation (gpa_4, mean_gpas);
		gpa_deviation5 = calculate_deviation (gpa_5, mean_gpas);

		// Calculate the variance of the GPA's
		gpa_variance = calculate_variance (gpa_deviation1,
			gpa_deviation2, gpa_deviation3, gpa_deviation4,
			gpa_deviation5, 5);

		// Calculate the standard deviation of the GPA's and writes it to output file
		gpa_standard_deviation = calculate_standard_deviation (gpa_variance);
		print_double (outfile, "GPA Standard Deviation", gpa_standard_deviation);

		// Determine the lowest GPA and write it to the output file
		min_gpa = find_min (gpa_1, gpa_2, gpa_3, gpa_4, gpa_5);
		print_double (outfile, "Lowest GPA", min_gpa);

		// Determine the highest GPA and write it to the output file
		max_gpa = find_max (gpa_1, gpa_2, gpa_3, gpa_4, gpa_5);
		print_double (outfile, "Highest GPA", max_gpa);

		// display closing message
		display_message (-1);

		// Close the input file
		fclose (infile);
	}
	else
	{
		// Tell user program was not able to succesfully analyze the student records.
		display_message (4);
	}

	// Close the output file
	fclose (outfile);

	return 0;
}