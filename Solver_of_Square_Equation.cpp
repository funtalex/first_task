#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <assert.h>

const int INF_NUM_OF_ROOTS = 3;



/*!
	\author Alex Sergeechev aka funtalex
	\version 2.0
	\brief This function solves an equation ax^2 + bx + c = 0

	\param[in] a - coefficient for x^2
	\param[in] b - coefficient for x
	\param[in] c - constant element
	\param[out] x1 - pointer of first root (if exist)
	\param[out] x2 - pointer of second root (if exist)

	\return number of roots
	\warning don't enter nan or inf, only finite number
*/
int solve_equation(double a, double b, double c, double* x1, double* x2) {
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));
	assert(isfinite(x1));
	assert(isfinite(x2));
	assert(x1 != x2);

	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				return INF_NUM_OF_ROOTS;
			}
			else {
				return 0;
			}
		}
		else {
			*x1 = -c / b;
			return 1;
		}
	}
	else {
		double disc = b * b - 4 * a * c;
		if (disc > 0) {
			double sqrt_disc = sqrt(disc);
			*x1 = (-b - sqrt_disc) / (2 * a);
			*x2 = (-b + sqrt_disc) / (2 * a);
			return 2;
		}
		else if (disc == 0) {
			*x1 = -b / (2 * a);
			return 1;
		}
		else {
			return 0;
		}
	}

	assert(false); // must return before
}



int main() {

	printf("Program - Solver of a square equation\n");
	printf("Sergeechev Alex aka funtalex, 2021\n");
	printf("Enter a, b, c - coeffitients for equation a* x ^ 2 + b * x + c\n");

	double a = 0, b = 0, c = 0;
	scanf("%lf %lf %lf", &a, &b, &c);

	double x1 = 0, x2 = 0;

	int numRoots = solve_equation(a, b, c, &x1, &x2);

	switch (numRoots) {
	case 0:
		printf("No roots\n");
		break;

	case 1:
		printf("x = %lf\n", x1);
		break;

	case 2:
		printf("x1 = %lf\nx2 = %lf\n", x1, x2);
		break;

	case INF_NUM_OF_ROOTS:
		printf("Any number\n");
		break;

	default:
		printf("ERROR: Wrong number of roots = %d\n", numRoots);
	}

	return 0;
}