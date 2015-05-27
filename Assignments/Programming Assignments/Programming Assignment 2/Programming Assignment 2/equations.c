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
 * File Description: "equations.c" contains the start welcome function (display_introduction),
 *								the 3 basic input functions (double_input, int_input, char_input),
 *								as well as the 7 computation functions for the equations being
 *								solved (newtons_2nd_law, volume_cylinder, character_encoding,
 *								atomic_mass_phosphate, height_projectile, circuit_current,
 *								general_equation).
 *********************************************************************************************/

// Includes
#include "equations.h"

/*************************************************************
 * Function: display_introduction ()
 * Date Created: September 13, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function displays the initial program
 *							greeting.
 * Input parameters: None
 * Returns: Nothing
 * Preconditions: Start of the program.
 * Postconditions: A welcome message is shown.
 *************************************************************/
int display_introduction(void)
{
	printf ("Programming Assignment 2 - Modular Equation Evaluator\n\n"); // print welcome
	return 0;
}

/*************************************************************
 * Function: double_input ()
 * Date Created: September 13, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function waits for keyboard input
 *						and interprets the results as a double.
 * Input parameters: None
 * Returns: A number as a double.
 * Preconditions: A double-type input is needed.
 * Postconditions: A double-type result is returned.
 *************************************************************/
double double_input(void)
{
	// declare temporary variable used for the scanf
	double temp_number = 0.0;
	// detect user input and assign to the temporary variable
	scanf ("%lf", &temp_number);
	// return the temporary variable
	return temp_number;
}

/*************************************************************
 * Function: int_input ()
 * Date Created: September 13, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function waits for keyboard input
 *						and interprets the results as an int.
 * Input parameters: None
 * Returns: A number as an int.
 * Preconditions: An int-type input is needed.
 * Postconditions: An int-type result is returned.
 *************************************************************/
int int_input(void)
{
	// declare temporary variable used for the scanf
	int temp_number = 0;
	// detect user input and assign to the temporary variable
	scanf ("%d", &temp_number);
	// return the temporary variable
	return temp_number;
}

/*************************************************************
 * Function: char_input ()
 * Date Created: September 13, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function waits for keyboard input
 *						and interprets the results as a character.
 * Input parameters: None
 * Returns: A character.
 * Preconditions: A character-type input is needed.
 * Postconditions: A character-type result is returned.
 *************************************************************/
char char_input(void)
{
	// declare temporary variable used for the scanf
	char temp_character = '\0';
	// detect user input and assign to the temporary variable
	scanf (" %c", &temp_character);
	// return the temporary variable
	return temp_character;
}

/*************************************************************
 * Function: newtons_2nd_law ()
 * Date Created: September 7, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function calculates force based
 *						upon given mass and acceleration.
 * Input parameters: The mass and accleration.
 * Returns: The force according to the 2nd Law.
 * Preconditions: Mass and Acceleration are known
 *							while force is not.
 * Postconditions: The force based upon the given mass
 *								and accleration is returned.
 *************************************************************/
double newtons_2nd_law (double mass, double acceleration)
{
	// declare force variable
	double force = 0.0;
	// calculate force using mass and acceleration
	force = mass * acceleration;
	// return the calculated force
	return force;
}

/*************************************************************
 * Function: volume_cylinder ()
 * Date Created: September 7, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function calculates the volume of a
 *						cylinder based upon given radius and
 *						height.
 * Input parameters: The radius and height.
 * Returns: The volume of the cylinder.
 * Preconditions: Radius and Height are known
 *							while volume is not.
 * Postconditions: The volume based upon the given radius
 *								and height is returned.
 *************************************************************/
double volume_cylinder (double radius, double height)
{
	// declare volume of a cylinder temp variable
	double volume_cylinder = 0.0;
	// calculate the volume of the cylinder
	volume_cylinder = PI * radius * radius * height;
	// return the volume of the cylinder
	return volume_cylinder;
}

/*************************************************************
 * Function: character_encoding ()
 * Date Created: September 7, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function a new character encoding
 *						(4 higher) based upon the given character.
 * Input parameters: The original character.
 * Returns: A new character 4 positions higher (ASCII)
 * Preconditions: The original character is known.
 * Postconditions: A new character is generated.
 *************************************************************/
char character_encoding (char plaintext_character)
{
	// declare local encoded character variable
	char encoded_character = '\0';
	// add 4 to the original variable to get the encoded variable
	encoded_character = plaintext_character + 4;
	// return the encoded character
	return encoded_character;
}

/*************************************************************
 * Function: atomic_mass_phosphate ()
 * Date Created: September 7, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function calculates the atomic mass
 *						of phosphate using known constants.
 * Input parameters: None.
 * Returns: The atomic mass of phosphate.
 * Preconditions: The atomic mass of phosphate is needed.
 * Postconditions: The atomic mass of phosphate is returned.
 *************************************************************/
double atomic_mass_phosphate (void)
{
	// declare local phosphate mass variable
	double phosphate_mass = 0.0;
	// calculate the mass of a mol of phosphate
	phosphate_mass = 3 * HYDROGEN + 4 * OXYGEN + PHOSPHOROUS;
	// return the phosphate mass
	return phosphate_mass;
}

/*************************************************************
 * Function: height_projectile ()
 * Date Created: September 7, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function calculates the height of
 *						a projectile based upon inputted
 *						time, initial velocity, and initial height.
 * Input parameters: The time, initial velocity, and initial
 *								height.
 * Returns: The height of the projectile at the given time.
 * Preconditions: Time, initial velocity, and initial height
 *							are known while current height is not.
 * Postconditions: The current height is returned.
 *************************************************************/
double height_projectile (double time, double initial_velocity, double initial_height)
{
	// declare the local projectile height variable
	double projectile_height = 0.0;
	// calculate the height of the projectile
	projectile_height = -16 * time * time + initial_velocity * time + initial_height;
	// return the height of the projectile
	return projectile_height;
}

/*************************************************************
 * Function: circuit_current ()
 * Date Created: September 7, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function calculates the current of
 *						a circuit based upon inputted power
 *						and resistance.
 * Input parameters: The power and resistance.
 * Returns: The current of the circuit.
 * Preconditions: Power and resistance are known while
 *							the current is not.
 * Postconditions: The current based upon the given
 *								power and resistance is returned.
 *************************************************************/
double circuit_current (double power, double resistance)
{
	// declare local current variable
	double current = 0.0;
	// calculate the current of the circuit
	current = sqrt(power / resistance);
	// return the current of the variable
	return current;
}

/*************************************************************
 * Function: general_equation ()
 * Date Created: September 7, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function calculates the answer to a
 *						equation based upon the inputted variables.
 * Equation: y = (3 / 4) * x - z / (a % 2) + PI
 * Input parameters: Variables A, X, and Z.
 * Returns: The answer (variable Y) of the equation.
 * Preconditions: The variables of the equation are known
 *							while the answer is not.
 * Postconditions: The answer to the equation is returned.
 *************************************************************/
double general_equation (int a, double x, double z)
{
	// declare the local y (answer) variable
	double var_Y = 0.0;
	// calculate the answer (y variable)
	var_Y = (3.0 / 4) * x - z / (a % 2) + PI;
	// return the answer (y variable)
	return var_Y;
}
