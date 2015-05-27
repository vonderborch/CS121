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
 * File Description: "main.c" contains the main() function from which the entire program is run.
 *********************************************************************************************/

#include "functions.h"

int main (void)
{
	FILE *infile = NULL, *out_stats = NULL, *out_ascii = NULL;
	char character = '\0';
	int ascii_value = 0;
	int current_number_lines = 0, current_number_vowels = 0, current_number_digits = 0,
		current_number_alphas = 0, current_number_lowers = 0, current_number_uppers = 0,
		current_number_spaces = 0, current_number_alnums = 0, current_number_puncts = 0;
	int temp_int = 0, i = 0, total_characters = 0;

	display_welcome(0);

	infile = open_input_file ();
	if (infile == NULL)
	{
		printf("Input file failed to open.\n");
	}

	out_stats = fopen ("output_stats.dat", "w");
	out_ascii = fopen ("output_ascii.dat", "w");

	total_characters = read_character (infile);
	temp_int = read_character (infile);

	while (i <= total_characters)
	{
		character = read_character (infile);
		ascii_value = determine_ascii_value (character);
		print_int (out_ascii, ascii_value);
		temp_int = is_line (character);
		current_number_lines = number_lines (temp_int, current_number_lines);
		temp_int = is_vowel (character);
		current_number_vowels = number_vowels (temp_int, current_number_vowels);
		temp_int = is_digit (character);
		current_number_digits = number_vowels (temp_int, current_number_digits);
		temp_int = is_alpha (character);
		current_number_alphas = number_vowels (temp_int, current_number_alphas);
		temp_int = is_lower (character);
		current_number_lowers = number_vowels (temp_int, current_number_lowers);
		temp_int = is_upper (character);
		current_number_uppers = number_vowels (temp_int, current_number_uppers);
		temp_int = is_space (character);
		current_number_spaces = number_vowels (temp_int, current_number_spaces);
		temp_int = is_alnum (character);
		current_number_alnums = number_vowels (temp_int, current_number_alnums);
		temp_int = is_punct (character);
		current_number_puncts = number_vowels (temp_int, current_number_puncts);
		i++;
	}

	// Print stats
	print_stats (out_stats, "Number of Lines: ", current_number_lines);
	print_stats (out_stats, "Number of Vowels: ", current_number_vowels);
	print_stats (out_stats, "Number of Digits: ", current_number_digits);
	print_stats (out_stats, "Number of Alphas: ", current_number_alphas);
	print_stats (out_stats, "Number of Lowers: ", current_number_lowers);
	print_stats (out_stats, "Number of Uppers: ", current_number_uppers);
	print_stats (out_stats, "Number of Spaces: ", current_number_spaces);
	print_stats (out_stats, "Number of Alphanumerics: ", current_number_alnums);
	print_stats (out_stats, "Number of Punctuations: ", current_number_puncts);

	// close message
	display_welcome(1);

	// close files
	fclose (infile);
	fclose (out_stats);
	fclose (out_ascii);
	return 0;
}
