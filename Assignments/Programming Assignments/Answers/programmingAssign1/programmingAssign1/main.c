/**************************************************************************************************
 * Programmer: Andrew S. O'Fallon                                                                 *
 * Class: CptS 121, Fall 2011; Lab Section 0                                                      *
 * Programming Assignment: Solution to Programming Assignment #1 -                                *
 *                         Equation Evaluator                                                     *
 * Date: September 1, 2011                                                                        *
 *                                                                                                *
 * Description: This program evaluates seven different equations.                                 *
 *              The constants represent coefficients and                                          *
 *              coordinates that are used in the provided equations.                              *
 *              The user is prompted to enter the constants, and the formulas                     *
 *              listed below are evaluated based on the user input.                               *
 *              The equations are displayed with the constants and results.                       *
 *                                                                                                *
 *              Inputs: acceleration, mass, radius, cylinder_height, plaintext_character,         *
 *                      time, initial_velocity, initial_height, power, resistance, x, z, a        *
 *              Constants: PI, HYDROGEN_MASS, OXYGEN_MASS, PHOSPHOROUS_MASS                       *
 *              Computations: See relevant formulas                                               *
 *              Outputs: force, current, volume_cylinder, encoded_character,                      *
 *                       phosphate_atomic_mass, projectile_height, general_y                      *
 *                                                                                                *
 *              This program does not provide error checking and only                             *
 *              uses sequential statements. This program defines only one                         *
 *              function, main ().                                                                *
 *                                                                                                *
 * Relevant Formulas (The equation numbers are referenced in the comments of                      *
 *                    the program):                                                               *                                                          
 *          (1)Newton's 2nd Law: force = mass * acceleration                                      *
 *          (2)Volume of a cylinder: volume_cylinder = PI * radius^2 * cylinder_height            *
 *          (3)Character encoding: encoded_character = (plaintext_character + 4)                  *
 *          (4)Atomic mass of phosphate: phophate_atomic_mass = 3 * hydrogen_mass +               *
 *                                       4 * oxygen_mass + phosphorous_mass                       *
 *          (5)Height of projectile: projectile_height = -16 * time^2 + initial_velocity * time + *
 *                                                       initial_height                           *
 *          (6)Current through circuit: current = sqrt (power / resistance)                       *
 *          (7)General equation: y = (3 / 4) * x - z / (a % 2) + PI                               *
 *************************************************************************************************/

#include <stdio.h> /* Include the standard input/output library for functions
                      printf ( ) and scanf ( )*/
#include <math.h>  /* Included for sqrt ( ) */

#define PI 3.141592             /* Define a constant macro to represent PI for the relevant equations */
#define HYDROGEN_MASS 1.008     /* amu / hydrogen atom */
#define OXYGEN_MASS 16.0        /* amu / oxygen atom */
#define PHOSPHOROUS_MASS 30.97  /* amu / phosphorous atom */
					     
int main (void) /* The main ( ) function is the starting point of the program */
{
	int a = 0; /* Stores the value for the user inputted a coefficient in equation (7) */

	char plaintext_character = '\0', /* Stores the character inputted by the user for use in equation (3) */
		 encoded_character = '\0';   /* Stores the result of the encoding from equation (3) */

	double mass = 0.0,                  /* Stores the mass in grams of the value inputted by the user for equation (1) */
		   acceleration = 0.0,          /* Stores the acceleration in m/s^2 of the value inputted by the user for equation (1) */
		   force = 0.0,                 /* Stores the result of equation (1) */
		   radius = 0.0,                /* Stores the radius of the cylinder inputted by the user for equation (2) */
		   cylinder_height = 0.0,       /* Stores the height of the cylinder inputted by the user for equation (2) */
		   volume_cylinder = 0.0,       /* Stores the result of equation (2) */
		   phosphate_atomic_mass = 0.0, /* Stores the atomic mass of phosphate computed from equation (4) */
		   time = 0.0,                  /* Stores the time inputted by the user for equation (5) */
		   initial_velocity = 0.0,      /* Stores the initial velocity of a projectile inputted by the user for equation (5) */
		   initial_height = 0.0,        /* Stores the initial height of a projectile inputted by the user for equation (5) */
		   projectile_height = 0.0,     /* Stores the resultant height of a projectile computed from equation (5) */
		   power = 0.0,                 /* Stores the power of a circuit inputted by the user for equation (6) */
		   resistance = 0.0,            /* Stores the total resistance of a circuit inputted by the user for equation (6) */
		   current = 0.0,               /* Stores the resultant current through a circuit derived from equation (6) */ 
		   x = 0.0,                     /* Stores x value inputted by user for equation (7) */
		   z = 0.0,                     /* Stores z value inputted by user for equation (7) */
		   y = 0.0;                     /* Stores the result of the general equation (7) */

	printf ("*************** WELCOME TO THE EQUATION EVALUATOR **************\n\n");

	/* Prompt the user for 2 floating-point values that are used in Netwon's 2nd Law of Motion
	   equation (1) */
	printf ("Please enter the mass and acceleration (both floating-point values) for use in Newton's Second Law: ");
	
	/* Read the floating-point values into the proper variables: do not forget the
	   "address of" operator (&) before each variable */
	scanf ("%lf%lf", &mass, &acceleration);

	/* Calculate the result of equation (1), which is force on an object
	   provided its mass and acceleration */
	force = mass * acceleration;

	/* Print out the result of equation (1) */
	printf ("Newton's Second Law: force = mass * acceleration = %lf * %lf = %lf\n", 
		     mass, acceleration, force);



	/* Prompt the user for 2 floating-point values that are used in volume of a cylinder
	   equation (2) */
	printf ("\nPlease enter the radius and height (both floating_point values) for use in a volume of cylinder equation: ");
	
	/* Read the floating-point values into the proper variables that are used in equation (2) */
	scanf ("%lf%lf", &radius, &cylinder_height);

	/* Calculate the result of equation (2), which is the volume of the cylinder
	   derived from radius and height of it */
	volume_cylinder = PI * radius * radius * cylinder_height;

	/* Print out the result of equation (2) */
	printf ("Volume of a cylinder: volume_cylinder = PI * radius^2 * height = %lf * %lf^2 * %lf = %lf\n", 
		     PI, radius, cylinder_height, volume_cylinder);

	

	/* Prompt the user for 1 character value for use in equation (3) */
	printf ("\nPlease enter the plaintext character for use in a character encoding equation: ");
	
	/* Read the character into the proper variable that is used in equation (3) */
	/* Recall a space between the " and %c ignores all white space characters */
	scanf (" %c", &plaintext_character);

	/* Calculate the result of equation (3), which is the encoded character */
	encoded_character = (plaintext_character + 4);

	/* Print out the result of equation (3) */
	printf ("Character encoding: encoded_character = (plaintext_character + 4) = %c + 4 = %c\n", 
		     plaintext_character, encoded_character);



	/* Equation (4) does not require any user input */
	/* Calculate the atomic mass of phosphate for equation (4) */
	phosphate_atomic_mass = 3 * HYDROGEN_MASS + 4 * OXYGEN_MASS + PHOSPHOROUS_MASS;

	/*Print out the phosphate atomic mass derived from equation (4) */
	printf ("\nAtomic mass of phosphate: phosphate_atomic_mass = 3 * hydrogen_mass + 4 * oxygen_mass + phosphorous_mass\n");
	printf (" = 3 * %lf + 4 * %lf + %lf = %lf\n", HYDROGEN_MASS, OXYGEN_MASS, PHOSPHOROUS_MASS, phosphate_atomic_mass);



	/* Prompt the user for 3 floating-point values that are used in height of projectile equation (5) */
	printf ("\nPlease enter the time, initial velocity, and initial height (all floating-point values) for use in\n");
	printf (" the height of projectile equation: ");
	
	/* Read the floating-point values into the proper variables for equation (5) */
	scanf ("%lf%lf%lf", &time, &initial_velocity, &initial_height);

	/* Calculate the result of equation (5), which is height of the projectile */
	projectile_height = -16 * time * time + initial_velocity * time + initial_height;

	/* Print out the result of equation (5) */
	printf ("Height of projectile: height = -16 * time^2 + initial_velocity * time + initial_height\n");
	printf (" = -16 * %lf^2 + %lf * %lf + %lf = %lf\n", time, initial_velocity, time, initial_height, projectile_height);
		     


	/* Prompt the user for 2 floating-point values that are used in current through circuit
	   equation (6) */
	printf ("\nPlease enter the power and resistance (both floating-point values) for use in the current\n");
	printf (" through circuit equation: ");
	
	/* Read the floating-point values into the proper variables for equation (6) */
	scanf ("%lf%lf", &power, &resistance);

	/* Calculate the result of equation (6), which is current through a circuit given
	   the power and resistance of it */
	current = sqrt (power / resistance);

	/* Print out the result of equation (6) */
	printf ("Curent through circuit: current = square root of (power / resistance) = sqrt (%lf / %lf) = %lf\n", 
		     power, resistance, current);



	/* Prompt the user for 2 floating-point and 1 integer values to be used
	   in the general equation calculation (7) */
	printf ("\nPlease enter x and z (both floating_point values) and a (an integer value)\n");
	printf (" for use in a general equation: ");

	/* Get the values needed for equation (7) */
	scanf ("%lf%lf%d", &x, &z, &a);

	/* Calculate the result of equation (7), the result is a y-coordinate */
	y = ((double) 3 / 4) * x - z / (a % 2) + PI;
	
	/* Print the result of the general equation (7) */
	printf ("general equation: y = 3/4 * x - z / (a %% 2) + PI\n = %lf * %lf - %lf / (%d %% 2) + %lf = %lf\n\n",
		     ((double) 3 / 4), x, z, a, PI, y);


	return 0;
} /* End of program */