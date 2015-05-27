// Letter grades

#include "letter_grades.h"

double get_percentage (void)
{
	double percentage = 0.0;

	printf ("Enter a percentage for your class: ");
	scanf ("%lf", &percentage);
	
	return percentage;
}

char determine_letter_grade (double percentage)
{
	char letter_grade = '\0';

	if (percentage >= 90.0)
	{
		letter_grade = 'A';
	}
	else if (percentage >= 80.0)
	{
		letter_grade = 'B';
	}
	else if (percentage >= 70.0)
	{
		letter_grade = 'C';
	}
	else if (percentage >= 60.0)
	{
		letter_grade = 'D';
	}
	else
	{
		letter_grade = 'F';
	}

	return letter_grade;
}