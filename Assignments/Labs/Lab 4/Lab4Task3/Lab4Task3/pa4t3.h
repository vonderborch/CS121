
#include <stdio.h>

int read_number (FILE *infile);
int calculate_total_minutes (int weekday_minutes, int night_minutes, int weekend_minutes);
double calculate_monthly_bill (int weekday_minutes, int night_minutes, int weekend_minutes);
double calculate_average_minute (double monthly_bill, int total_minutes);
double calculate_taxes (double monthly_bill);
double calculate_final_bill (double monthly_bill, double taxes);
void print_value (FILE *outfile, char header[], int number);
void print_double (FILE *outfile, char header[], double number);
