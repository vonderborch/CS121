/*
 * GPA In-Class Example Program
 * Computes the GPA of a student based upon 3 classes.
 * Definitions Header file.
*/
/*
#ifndef GPA_H
#define GPA_H
*/

#include <stdio.h>

// Functions - Input
int read_credits(FILE * file_handle);
int read_grade_points(FILE * file_handle);
double get_grade_point (int class_number);
int get_num_credits (int class_number);

// Functions - Computations
int compute_total_credits (int class1_credits, int class2_credits, int class3_credits);
double compute_weighted_credits (int class1_credits, double class1_grade, int class2_credits, double class2_grade, int class3_credits, double class3_grade);
double compute_gpa (double weighted_credits, int total_cedits);

// Functions - Results
int dispaly_results(double gpa);
