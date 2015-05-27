
#include <stdio.h>

int int_input (void);
int prompt_month (void);
int prompt_day (void);
int prompt_year (void);
int is_leap_year (int year);
int calculate_day_number (int month, int day, int is_leap_year);
int display_day_number (int month, int day, int year, int day_number);