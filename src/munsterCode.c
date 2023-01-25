#include <stdio.h>
#include <math.h>

// define the goal function to be minimized
double goal_function(double x, double y, double a, double b) 
{
    return a*x*x + b*y*y + a*x + b*y;
}

// define the gradient of the goal function
void gradient(double x, double y, double a, double b, double* dx, double* dy) 
{
	double h = 1e-10;
	double dgF_dx = (goal_function(x+h, y, a, b)-goal_function(x, y, a, b))/h; 
	double dgF_dy = (goal_function(x, y+h, a, b)-goal_function(x, y, a, b))/h;
    *dx = dgF_dx;
    *dy = dgF_dy;
}

// the gradient descent algorithm
void gradient_descent(double x0, double y0, double a, double b, double learning_rate, int num_iterations) 
{
    double x = x0;
    double y = y0;
    double dx, dy;
    double x_old, y_old, error_x = 10, error_y = 10;
    int i = 0;
	
	printf("Input to simulation:  %f, %f, %f, %f, %f, %d\n", x0, y0, a, b, learning_rate, num_iterations);
	printf("#########################################################\n");
	
    while (error_x > 1e-15 && error_y > 1e-15)
    {
		x_old = x; 
		y_old = y; 
        // calculate the gradient at the current point
        gradient(x, y, a, b, &dx, &dy);
        // update the x and y values
        x -= learning_rate * dx;
        y -= learning_rate * dy;
        error_x = fabs((x_old - x)/x_old);
        error_y = fabs((y_old - y)/y_old);
        i++;
        if(i > num_iterations) break;
        
        printf("Error x and y value: %d, %f, %f\n", i, error_x, error_y);
        printf("Iterative x and y value: %d, %f, %f\n", i, x, y);
        printf("-----------------------------------------------------\n");
    }

    // print the final values of x and y
    printf("#########################################################\n");
    printf("The minima of the function is at the following\n");
    printf("Minimum at: (%f, %f)\n", x, y);
}
