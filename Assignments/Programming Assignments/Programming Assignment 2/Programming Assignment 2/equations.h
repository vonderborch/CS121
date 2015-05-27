/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Programming Assignment: Programming Assignment 2
 * Created: September 7th, 2011
 * Last Revised: September 14th, 2011
 * Description: This program evaluates seven different equations/problems.
 *              The constants represent coefficients and
 *              coordinates that are used in the provided equations.
 *              The user is prompted to enter the constants, and the formulas
 *              listed below are evaluated based on the user input.
 *              The equations are displayed with the constants and results.
 *
 * Relevant Formulas: 
 *          1 - Newton's 2nd Law: force = mass * acceleration
 *          2 - Volume of a cylinder: volume_cylinder = PI * radius^2 * cylinder_height
 *          3 - Character encoding: encoded_character = (plaintext_character + 4)
 *          4 - Atomic mass of phosphate: phophate_atomic_mass = 3 * hydrogen_mass +
 *                                       4 * oxygen_mass + phosphorous_mass
 *          5 - Height of projectile: projectile_height = -16 * time^2 + initial_velocity * time +
 *                                                       initial_height
 *          6 - Current through circuit: current = sqrt (power / resistance)
 *          7 - General equation: y = (3 / 4) * x - z / (a % 2) + PI
 *
 * File Description: "equations.h" contains the include statements for the standard 
 *								libraries (stdio.h and math.h), defines various basic constants
 *								(PI, HYDROGEN, OXYGEN, and PHOSPHOROUS), and
 *								declares the function prototypes for all functions aside from main().
 *********************************************************************************************/

#ifndef EQUATIONS_H
#define EQUATIONS_H

// Includes
#include <stdio.h> // scanf(), printf()
#include <math.h> // Equation 6: sqrt()

// Defines
#define PI 3.14159265 // Value of pi
#define HYDROGEN 1.008 // Atomic mass of Hydrogen.
#define OXYGEN 16.00 // Atomic mass of Oxygen.
#define PHOSPHOROUS 30.97 // Atomic mass of Phosphorous.

// Function Prototypes (see relavent function in equations.c for a description)
int display_introduction(void);
double double_input(void);
int int_input(void);
char char_input(void);
double newtons_2nd_law (double mass, double acceleration);
double volume_cylinder (double radius, double height);
char character_encoding (char plaintext_character);
double atomic_mass_phosphate (void);
double height_projectile (double time, double initial_velocity, double initial_height);
double circuit_current (double power, double resistance);
double general_equation (int a, double x, double z);

#endif
