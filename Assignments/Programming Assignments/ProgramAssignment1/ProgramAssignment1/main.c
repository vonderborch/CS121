/*******************************************************************************************
* Programmer: Christian Webber																*
* Class: Cpt S 121, Spring 2011; Lab Section 3												*
* Programming Assignment: Programming Assignment 1											*
* Date: August 31, 2011																		*
* Description: This program solves several different equations and various other problems.	*
*******************************************************************************************/

// Includes
#include <stdio.h>
#include <math.h> // eq6: sqrt()
// Defines
#define PI 3.14159265
#define HYDROGEN 1.008
#define OXYGEN 16.00
#define PHOSPHOROUS 30.97

int main (void)
{
	double force = 0.0, mass = 0.0, acceleration = 0.0; // Equation 1 Variables
	double volume_cylinder = 0.0, radius = 0.0, height = 0.0; // Equation 2 Variables
	char plaintext_character = '\0', encoded_character = '\0'; // Equation 3 Variables
	double phosphate_atomic_mass = 0.0, hydrogen_mass = 1.008, oxygen_mass = 16.00, phosphorous_mass = 30.97; // Equation 4 Variables
	double projectile_height = 0.0, time = 0.0, initial_velocity = 0.0, initial_height = 0.0; // Equation 5 Variables
	double current = 0.0, power = 0.0, resistance = 0.0; // Equation 6 Variables
	double var_X = 0.0, var_Y = 0.0, var_Z = 0.0; // Equation 7 Variables
	int var_A = 0; // Equation 7 Variables (Continued)

	// Equation 1
	printf("*******************Equation 1: Newton's Second Law of Motion********************");
	printf("Please enter the mass: ");
	scanf("%lf", &mass);
	printf("Please enter the acceleration: ");
	scanf("%lf", &acceleration);
	force = mass * acceleration;
	printf("Force = mass * acceleration = %lf * %lf = %lf\n\n", mass, acceleration, force);
	
	// Equation 2
	printf("************************Equation 2: Volume of a Cylinder************************");
	printf("Please enter the radius: ");
	scanf("%lf", &radius);
	printf("Please enter the height: ");
	scanf("%lf", &height);
	volume_cylinder = PI * radius * radius * height;
	printf("Volume of a Cylinder = PI * radius^2 * height = 3.14 * %.2lf^2 * %.2lf = 3.14159265 * %.2lf * %.2lf * %.2lf = %lf\n\n",
		radius, height, radius, radius, height, volume_cylinder);

	// Equation 3
	printf("************************Equation 3: Encoding a Character************************");
	printf("Please enter a character: ");
	scanf(" %c", &plaintext_character);
	encoded_character = plaintext_character + 4;
	printf("Encoded Character = Original Character + 4 = %c + 4 = %c\n\n", plaintext_character, encoded_character);

	// Equation 4
	printf("*********************Equation 4: Atomic Mass of Phosphate***********************");
	phosphate_atomic_mass = 3 * HYDROGEN + 4 * OXYGEN + PHOSPHOROUS;
	printf("Atomic Mass of Phosphate = 3 * Mass of Hydrogen + 4 * Mass of Oxygen + Mass of Phosphorous = 3 * %.3lf + 4 * %.3lf + %.3lf = %.3lf\n\n",
		hydrogen_mass, oxygen_mass, phosphorous_mass, phosphate_atomic_mass);

	// Equation 5
	printf("**********************Equation 5: Height of a Projectile************************");
	printf("Please enter time: ");
	scanf("%lf", &time);
	printf("Please enter initial velocity: ");
	scanf("%lf", &initial_velocity);
	printf("Please enter initial height: ");
	scanf("%lf", &initial_height);
	projectile_height = -16 * time * time + initial_velocity * time + initial_height;
	printf("Projectile Height = -16 * Time^2 + Initial Velocity * Time + Initial Height = -16 * %lf^2 + %lf * %lf + %lf = %lf\n\n",
		time, initial_velocity, time, initial_height, projectile_height);
	
	// Equation 6
	printf("****************Equation 6: Current through Circuit in Amperes******************");
	printf("Please enter power: ");
	scanf("%lf", &power);
	printf("Please enter resistance: ");
	scanf("%lf", &resistance);
	current = sqrt(power / resistance);
	printf("Current = sqrt(power / resistance) = sqrt(%lf / %lf ) = %lf", power, resistance, current);
	printf("\n\n");

	// Equation 7
	printf("*************************Equation 7: General Equation***************************");
	printf("Please enter x: ");
	scanf("%lf", &var_X);
	printf("Please enter z: ");
	scanf("%lf", &var_Z);
	printf("Please enter A: ");
	scanf("%d", &var_A);
	var_Y = (3.0 / 4) * var_X - var_Z / (var_A % 2) + PI;
	printf("Y = (3 / 4) * x - z / (A %% 2) + PI = (3 / 4) * %lf - %lf / (%d %% 2) + 3.14159265 = %lf\n",
		var_X, var_Z, var_A, var_Y);
	
	return 0;
}