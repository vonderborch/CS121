/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Programming Assignment: Lab 3
 * Created: September 14th, 2011
 * Last Revised: September 14th, 2011
 * Description: This program performs character processing on data on 10
 *						characters read from a file and then writes the results to another
 *						file.
 *
 * File Description: "functions.h" contains the definitions for constants as well as the
 *								shared includes. Also contains function prototypes.
 *********************************************************************************************/

// standard includes
#include <stdio.h>

// defines
#define NEWLINE 1
#define NOT_NEWLINE 0
#define VOWEL 2
#define NOT_VOWEL 0
#define DIGIT 3
#define NOT_DIGIT 0
#define ALPHA 4
#define NOT_ALPHA 0
#define LOWER 5
#define NOT_LOWER 0
#define UPPER 6
#define NOT_UPPER 0
#define WHITESPACE 7
#define NOT_WHITESPACE 0
#define ALNUM 8
#define NOT_ALNUM 0
#define PUNCT 9
#define NOT_PUNCT 0

// prototypes
int display_welcome (int type);
FILE *open_input_file (void);
char read_character (FILE *infile);
int determine_ascii_value (char character);
int is_line (char character);
int number_lines (int line_result, int current_number_lines);
int is_vowel (char character);
int number_vowels (int vowel_result, int current_number_vowels);
int is_digit (char character);
int number_digit (int digit_result, int current_number_digits);
int is_alpha (char character);
int number_alphas (int alpha_result, int current_number_alphas);
int is_lower (char character);
int number_lowers (int lower_result, int current_number_lowers);
int is_upper (char character);
int number_uppers (int upper_result, int current_number_uppers);
int is_space (char character);
int number_spaces (int spaces_result, int current_number_spaces);
int is_alnum (char character);
int number_alnums (int alnum_result, int current_number_alnums);
int is_punct (char character);
int number_puncts (int punct_result, int current_number_puncts);
void print_int (FILE *outfile, int number);
void print_stats (FILE *outfile, char header[], int number);
