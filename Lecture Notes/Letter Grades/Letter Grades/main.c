/* Letter grades
 * Lecture Notes
 * September 14th, 2011 - September 
*/

#include "letter_grades.h"

int main (void)
{
	double percentage = 0.0;
	char letter_grade = '\0';

	percentage = get_percentage ();
	letter_grade = determine_letter_grade (percentage);
	printf ("For percentage %.2lf, the letter grade is %c.\n", percentage, letter_grade);

	return 0;
}
