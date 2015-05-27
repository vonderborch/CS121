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
 * File Description: "functions.c" contains all function prototype definitions.
 *********************************************************************************************/

#include "functions.h"

int display_welcome (int type)
{
	if (type == 0)
	{
		printf ("********Lab 3: C File Processing with Functions********\n\n");
	}
	else
	{
		printf ("********Characters successfully analyzed!********\n");
	}
	return;
}

FILE * open_input_file (void)
{
	FILE * infile = NULL, *outfile = NULL;
	infile = fopen ("input.dat", "r");
	return infile;
}

char read_character (FILE *infile)
{
	char temp_character = '\0';
	fscanf (infile, "%c", &temp_character);
	return temp_character;
}

int determine_ascii_value (char character)
{
	int ascii_value = 0;
	ascii_value = (int)character;
	return ascii_value;
}

int is_line (char character)
{
	int temp_ascii = (int)character;
	if (temp_ascii == 10)
	{
		return NEWLINE;
	}
	else
	{
		return NOT_NEWLINE;
	}
}

int number_lines (int line_result, int current_number_lines)
{
	if (line_result == 1)
	{
		current_number_lines++;
	}
	return current_number_lines;
}

int is_vowel (char character)
{
	int temp_ascii = (int)character;
	if ((temp_ascii == 65) || (temp_ascii == 97) || (temp_ascii == 69) || (temp_ascii == 101) || 
		(temp_ascii == 73) || (temp_ascii == 105) || (temp_ascii == 79) || (temp_ascii == 111) || (temp_ascii == 85) || (temp_ascii == 117))
	{
		return VOWEL;
	}
	else
	{
		return NOT_VOWEL;
	}
}

int number_vowels (int vowel_result, int current_number_vowels)
{
	if (vowel_result == 2)
	{
		current_number_vowels++;
	}
	return current_number_vowels;
}

int is_digit (char character)
{
	int temp_ascii = (int)character;
	if ((temp_ascii >= 48) && (temp_ascii <=57))
	{
		return DIGIT;
	}
	else
	{
		return NOT_DIGIT;
	}
}

int number_digit (int digit_result, int current_number_digits)
{
	if (digit_result == 3)
	{
		current_number_digits++;
	}
	return current_number_digits;
}

int is_alpha (char character)
{
	int temp_ascii = (int)character;
	if (((temp_ascii >= 65) && (temp_ascii <=90)) || ((temp_ascii >= 97) && (temp_ascii <=122)))
	{
		return ALPHA;
	}
	else
	{
		return NOT_ALPHA;
	}
}

int number_alphas (int alpha_result, int current_number_alphas)
{
	if (alpha_result == 4)
	{
		current_number_alphas++;
	}
	return current_number_alphas;
}

int is_lower (char character)
{
	int temp_ascii = (int)character;
	if ((temp_ascii >= 97) && (temp_ascii <=122))
	{
		return LOWER;
	}
	else
	{
		return NOT_LOWER;
	}
}

int number_lowers (int lower_result, int current_number_lowers)
{
	if (lower_result == 5)
	{
		current_number_lowers++;
	}
	return current_number_lowers;
}

int is_upper (char character)
{
	int temp_ascii = (int)character;
	if ((temp_ascii >= 65) && (temp_ascii <=90))
	{
		return UPPER;
	}
	else
	{
		return NOT_UPPER;
	}
}

int number_uppers (int upper_result, int current_number_uppers)
{
	if (upper_result == 6)
	{
		current_number_uppers++;
	}
	return current_number_uppers;
}

int is_space (char character)
{
	int temp_ascii = (int)character;
	if (temp_ascii == 32)
	{
		return WHITESPACE;
	}
	else
	{
		return NOT_WHITESPACE;
	}
}

int number_spaces (int spaces_result, int current_number_spaces)
{
	if (spaces_result == 7)
	{
		current_number_spaces++;
	}
	return current_number_spaces;
}

int is_alnum (char character)
{
	int temp_ascii = (int)character;
	if (((temp_ascii >= 65) && (temp_ascii <=90)) || ((temp_ascii >= 97) && (temp_ascii <=122)) || ((temp_ascii >= 48) && (temp_ascii <=57)))
	{
		return ALNUM;
	}
	else
	{
		return NOT_ALNUM;
	}
}

int number_alnums (int alnum_result, int current_number_alnums)
{
	if (alnum_result == 8)
	{
		current_number_alnums++;
	}
	return current_number_alnums;
}

int is_punct (char character)
{
	int temp_ascii = (int)character;
	if ((temp_ascii == 33) || (temp_ascii == 44) || (temp_ascii == 46) || (temp_ascii == 63))
	{
		return PUNCT;
	}
	else
	{
		return NOT_PUNCT;
	}
}

int number_puncts (int punct_result, int current_number_puncts)
{
	if (punct_result == 9)
	{
		current_number_puncts++;
	}
	return current_number_puncts;
}

void print_int (FILE *outfile, int number)
{
	fprintf (outfile, "%d\n", number);
	return;
}

void print_stats (FILE *outfile, char header[], int number)
{
	fprintf (outfile, "%s%d\n", header, number);
	return;
}
