
#include <stdio.h>
#include <math.h>

int teacher_main (double purchases, FILE *outfile);
int normal_main (double purchases, FILE *outfile);

double int_input (void);
double double_input (void);
double purchases_input (void);
int teacher_input (void);
double determine_discount (double cost);
double calculate_discount (double purchases, double discount);
double calculate_discount_total (double purchases, double discount);
double calculate_sales_tax (double purchases);
double calculate_total (double purchases, double sales_tax);
void print_receipt (FILE *outfile, char header[], double number);
