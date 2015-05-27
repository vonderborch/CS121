/*
 * GPA In-Class Example Program
 * Computes the GPA of a student based upon 3 classes.
 * Functions file.
*/

#include "definitions.h"

double get_grade_point (int class_number)
{
	double grade_point = 0.0; // local variable
	printf("Enter grade point for class %d: ", class_number);
	scanf("%lf", &grade_point);
	return grade_point;
}

int get_num_credits (int class_number)
{
	int num_credits = 0;
	printf("Enter credits for class %d: ", class_number);
	scanf("%d", &num_credits);
	return num_credits;
}

int read_credits(FILE * file_handle)
{
	int credits = 0;
	credits = fscanf (file_handle, "%d", &credits);
	return credits;
}

int read_grade_points(FILE * file_handle)
{
	double grade_point = 0.0;
	grade_point = fscanf (file_handle, "%lf", &grade_point);
	return grade_point;
}

int compute_total_credits (int class1_credits, int class2_credits, int class3_credits)
{
	int total_credits = 0;
	total_credits = class1_credits + class2_credits + class3_credits;
	return total_credits;
}

double compute_weighted_credits (int class1_credits, double class1_grade, 
								  int class2_credits, double class2_grade, 
								  int class3_credits, double class3_grade)
{
	double weighted_credits = 0;
	weighted_credits = (class1_credits * class1_grade) + (class2_credits * class2_grade) + (class3_credits * class3_grade);
	return weighted_credits;
}

double compute_gpa (double weighted_credits, int total_cedits)
{
	double total_gpa = 0;
	total_gpa = weighted_credits / total_cedits;
	return total_gpa;
}

int dispaly_results(double gpa)
{
	printf("GPA =  %.2lf\n", gpa);
	return 0;
}