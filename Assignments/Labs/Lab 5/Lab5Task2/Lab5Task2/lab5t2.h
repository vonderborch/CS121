#include <stdio.h>

#define FILE_NAME_SIZE 30

char get_file_name (void);
int open_file_read (FILE *infile);
int open_file_write (char file_name[FILE_NAME_SIZE]);
int check_file_exists (FILE *infile);
double read_double (FILE *infile);
double calculate_average_value (int number_values, double sum_values);
void print_output_double (FILE *outfile, char header[], double number);