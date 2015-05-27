/*
 * GPA In-Class Example Program
 * Computes the GPA of a student based upon 3 classes.
 * Main file.
*/
#include "definitions.h"

int main(void)
{
	// Variables
	double grade_point1 = 0.0,
		grade_point2 = 0.0,
		grade_point3 = 0.0,
		gpa = 0.0,
		weighted_credits = 0.0;
	int num_credits1 = 0,
		num_credits2 = 0,
		num_credits3 = 0,
		total_num_credits = 0,
		i = 0;
	// File open variable
	FILE *infile = NULL, *outfile = NULL;
	infile = fopen ("classInfo.txt", "r");
	outfile = fopen ("GPA.txt", "w");

	// Get inputs
	// read input
	num_credits1 = read_credits(infile);
	printf("Credits 1: %d\n", num_credits1);
	num_credits2 = read_credits(infile);
	printf("Credits 2: %d\n", num_credits2);
	num_credits3 = read_credits(infile);
	printf("Credits 3: %d\n", num_credits3);
	
	grade_point1 = read_grade_points(infile);
	printf("Grade Point 1: %lf\n", grade_point1);
	grade_point2 = read_grade_points(infile);
	printf("Grade Point 2: %lf\n", grade_point2);
	grade_point3 = read_grade_points(infile);
	printf("Grade Point 3: %lf\n", grade_point3);
	/* // User Input
	grade_point1 = get_grade_point(1);
	num_credits1 = get_num_credits(1);
	grade_point2 = get_grade_point(2);
	num_credits2 = get_num_credits(2);
	grade_point3 = get_grade_point(3);
	num_credits3 = get_num_credits(3);
	*/

	// Computations
	total_num_credits = compute_total_credits(num_credits1, num_credits2, num_credits3);
	weighted_credits = compute_weighted_credits(num_credits1, grade_point1, num_credits2, 
		grade_point2, num_credits3, grade_point3);
	gpa = compute_gpa(weighted_credits, total_num_credits);

	// Results
	dispaly_results(gpa);
	fprintf (outfile, "GPA = %.2lf", gpa);
	fclose (infile);
	fclose (outfile);

	return 0;
}
