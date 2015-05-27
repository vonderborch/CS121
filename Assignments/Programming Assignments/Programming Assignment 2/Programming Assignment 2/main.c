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
 * File Description: "main.c" contains the main() function from which the entire program is run.
 *********************************************************************************************/

// Includes
#include "equations.h"

/*************************************************************
 * Function: main ()
 * Date Created: September 7, 2011
 * Date Last Modified: September 14, 2011
 * Description: This function is the primary control function of the
 *							program, from whence all other functions
 *							are called from as needed.
 * Input parameters: None
 * Returns: Nothing
 * Preconditions: Equations/Problems need to be solved.
 * Postconditions: Equations/Problems solved.
 *************************************************************/
int main (void)
{
	double force = 0.0, mass = 0.0, acceleration = 0.0; // Equation 1 Variables
	double cylinder_volume = 0.0, radius = 0.0, height = 0.0; // Equation 2 Variables
	char plaintext_character = '\0', encoded_character = '\0'; // Equation 3 Variables
	double phosphate_atomic_mass = 0.0; // Equation 4 Variables
	double projectile_height = 0.0, time = 0.0, initial_velocity = 0.0, initial_height = 0.0; // Equation 5 Variables
	double current = 0.0, power = 0.0, resistance = 0.0; // Equation 6 Variables
	double var_X = 0.0, var_Y = 0.0, var_Z = 0.0; // Equation 7 Variables
	int var_A = 0; // Equation 7 Variables (Continued)

	//*********************************** Start message ***********************************//

	display_introduction(); // calls the display_introduction () function to display the introduction.


	//*********************************** Equation 1 ***********************************//
	
	printf("*******************Equation 1: Newton's Second Law of Motion********************"); // Print equation # and name
	printf("Please enter the mass: "); // Ask for input
	mass = double_input(); // calls the double_input () function for the mass.
	printf("Please enter the acceleration: "); // Ask for input
	acceleration = double_input(); // calls the double_input () function for the acceleration.
	force = newtons_2nd_law(mass, acceleration); // Calls the newtons_2nd_law () function to calculate the force.
	printf("Force = mass * acceleration = %.2lf * %.2lf = %.2lf\n\n", mass, acceleration, force); // Display results
	

	//*********************************** Equation 2 ***********************************//
	
	printf("************************Equation 2: Volume of a Cylinder************************"); // Print equation # and name
	printf("Please enter the radius: "); // Ask for input
	radius = double_input(); // calls the double_input () function for the radius.
	printf("Please enter the height: "); // Ask for input
	height = double_input(); // calls the double_input () function for the height.
	cylinder_volume = volume_cylinder(radius, height); // Calls the volume_cylinder () function to calculate the volume of the cylinder.
	printf("Volume of a Cylinder = PI * radius^2 * height = %.2lf * %.2lf^2 * %.2lf = %.2lf * %.2lf * %.2lf * %.2lf = %.2lf\n\n",
		PI, radius, height, PI, radius, radius, height, cylinder_volume); // Display results


	//*********************************** Equation 3 ***********************************//
	
	printf("************************Equation 3: Encoding a Character************************"); // Print equation # and name
	printf("Please enter a character: "); // Ask for input
	plaintext_character = char_input(); // calls the char_input () function for the original character.
	encoded_character = character_encoding (plaintext_character); // Calls the character_encoding () function to encode a new character.
	printf("Encoded Character = Original Character + 4 = %c + 4 = %c\n\n", plaintext_character, encoded_character); // Display results


	//*********************************** Equation 4 ***********************************//
	
	printf("*********************Equation 4: Atomic Mass of Phosphate***********************"); // Print equation # and name
	phosphate_atomic_mass = atomic_mass_phosphate(); // Calls the atomic_mass_phosphate () function to calculate the mass of phosphate.
	printf("Atomic Mass of Phosphate = 3 * Mass of Hydrogen + 4 * Mass of Oxygen + Mass of Phosphorous = 3 * %.2lf + 4 * %.2lf + %.2lf = %.2lf\n\n",
		HYDROGEN, OXYGEN, PHOSPHOROUS, phosphate_atomic_mass); // Display results


	//*********************************** Equation 5 ***********************************//
	
	printf("**********************Equation 5: Height of a Projectile************************"); // Print equation # and name
	printf("Please enter time: "); // Ask for input
	time = double_input(); // calls the double_input () function for the time.
	printf("Please enter initial velocity: "); // Ask for input
	initial_velocity = double_input(); // calls the double_input () function for the initial velocity.
	printf("Please enter initial height: "); // Ask for input
	initial_height = double_input(); // calls the double_input () function for the initial height.
	projectile_height = height_projectile(time, initial_velocity, initial_height); // Calls the height_projectile () function to calculate the height of the projectile.
	printf("Projectile Height = -16 * Time^2 + Initial Velocity * Time + Initial Height = -16 * %.2lf^2 + %.2lf * %.2lf + %.2lf = %.2lf\n\n",
		time, initial_velocity, time, initial_height, projectile_height); // Display results
	
	
	//*********************************** Equation 6 ***********************************//
	
	printf("****************Equation 6: Current through Circuit in Amperes******************"); // Print equation # and name
	printf("Please enter power: "); // Ask for input
	power = double_input(); // calls the double_input () function for the power.
	printf("Please enter resistance: "); // Ask for input
	resistance = double_input(); // calls the double_input () function for the resistance.
	current = circuit_current(power, resistance); // Calls the circuit_current () function to calculate the current.
	printf("Current = sqrt(power / resistance) = sqrt(%.2lf / %.2lf ) = %.2lf\n\n", power, resistance, current); // Display results

	
	//*********************************** Equation 7 ***********************************//
	
	printf("*************************Equation 7: General Equation***************************"); // Print equation # and name
	printf("Please enter x: "); // Ask for input
	var_X = double_input(); // calls the double_input () function for the X variable.
	printf("Please enter z: "); // Ask for input
	var_Z = double_input(); // calls the double_input () function for the Z variable.
	printf("Please enter A: "); // Ask for input
	var_A = int_input(); // calls the int_input () function for the A variable.
	var_Y =general_equation(var_A, var_X, var_Z); // Calls the general_equation () function to calculate the Y variable (the answer).
	printf("Y = (3 / 4) * x - z / (A %% 2) + PI = (3.0 / 4.0) * %.2lf - %.2lf / (%d %% 2) + %.2lf = %.2lf\n",
		var_X, var_Z, var_A, PI, var_Y); // Display results
	
	return 0;
}