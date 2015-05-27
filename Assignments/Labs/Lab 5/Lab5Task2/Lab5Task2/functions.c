#include "lab5t2.h"

char get_file_name (void)
{
	char file_name[FILE_NAME_SIZE];
	printf ("Enter name of file to read from: ");
	scanf (" %s", &file_name);
	return file_name;
}

int open_file_read (char file_name[FILE_NAME_SIZE])
{
	FILE *infile = NULL;
	infile = fopen (file_name, "r");
	return infile;
}

int open_file_write (char file_name[FILE_NAME_SIZE])
{
	FILE *outfile = NULL;
	outfile = fopen (file_name, "w");
	return outfile;
}

int check_file_exists (FILE *infile)
{
	int exists = 1;
	if (infile == NULL)
	{
		exists = 0;
	}
	return exists;
}

double read_double (FILE *infile)
{
	double temp_value = 0.0;
	fscanf (infile, "%lf", &temp_value);
	return temp_value;
}

double calculate_average_value (int number_values, double sum_values)
{
	double average = sum_values / (double)number_values;
	return average;
}

void print_output_double (FILE *outfile, char header[], double number)
{
	fprintf (outfile, "%s%lf\n", header, number);
}