#include <stdio.h>

void display_message (int message);

int prompt_account_number (void);
char prompt_use_code (void);
int prompt_consumption (char string[]);
double determine_amount_due (char use_code, int consumption1, int consumption2);
double residential_calculation (int consumption);
double commercial_calculation (int consumption);
double industrial_calculation (int consumption_peak, int consumption_off);
void display_amount_due (int account_number, double amount_due);