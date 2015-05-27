/*******************************************************************************************
* Programmer: Christian Webber																*
* Class: Cpt S 121, Spring 2011; Lab Section 3												*
* Programming Assignment: Lab 1 Task 2														*
* Date: August 31, 2011																		*
* Description: This program solves several different mathematical equations.				*
*******************************************************************************************/

// includes
#include <stdio.h> // printf(), scanf()
#include <math.h> // pow()

// defines
#define PI 3.14159265

int main(void)
{
	int menuDecider = 0;
	printf("\n\nSelect Problem: \n    1: Problem A - Integers and Floating-points.\n    2: Problem B - Ohm's Law.\n    3: Problem C - Joule's Law.\n    4: Problem D - Third Order Polynomial.\n    5: Problem E - Circumference of a Circle\n    6: Quit \n");
	scanf("%d", &menuDecider);
	printf("\n");
	if (menuDecider == 1)
	{
		problemA();
	}
	else if (menuDecider == 2)
	{
		problemB();
	}
	else if (menuDecider == 3)
	{
		problemC();
	}
	else if (menuDecider == 4)
	{
		problemD();
	}
	else if (menuDecider == 5)
	{
		problemE();
	}
	return 0;
}

// Problem A - Integers and Floating-points.
int problemA(void)
{
	// Asked for variables...
	int number1_int = 0, number2_int = 0;
	double number1_float = 0.0, number2_float = 0.0;
	// Computed variables...
	int int_result = 0, int_result2 = 0; // result storage for integers
	double float_result = 0; // result storage for floating-points

	// Ask for integers...
	printf("Input Integer #1: ");
	scanf("%d", &number1_int);
	printf("Input Integer #2: " );
	scanf("%d", &number2_int);
	// Ask for floating-points...
	printf("Input Floating-point #1: ");
	scanf("%lf", &number1_float);
	printf("Input Floating-point #2: " );
	scanf("%lf", &number2_float);

	// A.1: Int1 + Int2
	int_result = number1_int + number2_int; // A.1
	printf("A.1: Result = Integer #1 + Integer #2 = %d + %d = %d \n", number1_int, number2_int, int_result);

	// A.2: Float1 - Float2
	float_result = number1_float - number2_float;
	printf("A.2: Result = Floating-point #1 - Floating-point #2 = %lf - %lf = %lf \n", number1_float, number2_float, float_result);
	
	// A.3: Int1 * Float1
	int_result = number1_int * number1_float;
	printf("A.3: Result = Integer #1 * Floating-point #1 = %d * %lf = %d \n", number1_int, number1_float, int_result);
	
	// A.4: Int1 / Int2 - Int and Float results
	int_result = number1_int / number2_int;
	float_result = number1_int / number2_int;
	printf("A.4: Result = Integer #1 / Integer #2 = %d / %d = %d (Integer version), %lf (Floating-point version)\n", number1_int, number2_int, int_result, float_result);

	// A.5: Int1 / Float2 - Int and Float results
	int_result = number1_int / number2_float;
	float_result = number1_int / number2_float;
	printf("A.5: Result = Integer #1 / Floating-point #2 = %d / %lf = %d (Integer version), %lf (Floating-point version)\n", number1_int, number2_float, int_result, float_result);

	// A.6: Casted Int1 / Int2
	float_result = (double)number1_int / number2_int;
	printf("A.6: Result = Integer #1 / Integer #2 = %d / %d = %lf \n", number1_int, number2_int, float_result);

	// A.7: Float1 % Float2
	int_result = (int)number1_float % (int)number2_float;
	printf("A.7: Result = Floating-point #1 mod Floating-point #2 = %lf mod %lf = %d \n", number1_float, number2_float, int_result);

	// A.8: Even/Odd Int1 and Int2
	int_result = number1_int % 2;
	int_result2 = number2_int % 2;
	printf("A.8: Result = 0 if integer is even, 1 if integer is odd.\n    Integer #1: %d \n    Integer #2: %d \n", int_result, int_result2);

	return main();
}

// Problem B - Ohm's Law
int problemB(void)
{
	int current = 0, resistance = 0, voltage = 0;
	printf("Input Current (I): ");
	scanf("%d", &current);
	printf("Input Resistance (R): ");
	scanf("%d", &resistance);
	voltage = current * resistance;
	printf("V = Voltage = IR = Current * Resistance = %d * %d = %d \n", current, resistance, voltage);
	return main();
}

// Problem C - Joule's Law
int problemC(void)
{
	int voltage = 0, resistance = 0, power = 0;
	printf("Input Voltage (V): ");
	scanf("%d", &voltage);
	printf("Input Resistance (R): ");
	scanf("%d", &resistance);
	power = (voltage * voltage) / resistance;
	printf("P = Power = (V^2) / R = Voltage^2 / Power = Voltage * Voltage / Power = %d * %d / %d = %d \n", voltage, voltage, resistance, power);
	return main();
}

// Problem D - Third Order Polynomial
int problemD(void)
{
	int var_y = 0, var_x = 0, var_A = 0, var_B = 0, var_C = 0, var_D = 0;
	printf("Input x: ");
	scanf("%d", &var_x);
	printf("Input A: ");
	scanf("%d", &var_A);
	printf("Input B: ");
	scanf("%d", &var_B);
	printf("Input C: ");
	scanf("%d", &var_C);
	printf("Input D: ");
	scanf("%d", &var_D);
	var_y = 3 * (var_A * pow((double)var_x, 3.0)) + (1.0/4) + (var_B * pow((double)var_x, 2.0)) + 10 * (var_C * var_x) - 5 * var_D;
	printf("y = 3 * Ax^3 + (1 / 4) + Bx^2 + 10 * Cx - 5 * D = 3 * %d(%d^3) + (1 / 4) * %d(%d^2) + 10 * %d(%d) - 5 * %d = %d \n", var_A, var_x, var_B, var_x, var_C, var_x, var_D, var_y);
	return main();
}

// Problem E - Circumference of a Circle
int problemE(void)
{
	double circumference = 0.0, radius = 0.0;
	printf("Input Radius: ");
	scanf("%lf", &radius);
	circumference = 2 * PI * radius;
	printf("Circumference = 2 * PI * radius = 2 * 3.14159265 * %lf = %lf \n", radius, circumference);
	return main();
}
