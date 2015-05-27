#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int display_menu (char menu_title[], char menu_items[], int num_items, int min_items);
int is_valid_item (int option, int num_items, int min_items);