#include <iostream>
#include <cmath>

using namespace std;

double function(double x) {
    return x * x - 16.0; //f(x) = x^2 - 16
}

// The derivative of the function
double derivative(double x) {
    return 2.0 * x; // f'(x) = x^2 - 16 is 2x
}

// Newton-Raphson method
double newtonRaphson(double initialGuess, double tolerance, int maxIterations) {
    double x = initialGuess;

    for (int i = 0; i < maxIterations; ++i) {
        double f_x = function(x);
        double f_prime_x = derivative(x);

        if (abs(f_prime_x) < 1e-6) {
            cout << "Derivative is too small. Cannot continue." << endl;
            return x;
        }

        double x_next = x - (f_x / f_prime_x);

        if (abs(x_next - x) < tolerance) {
            cout << "Converged to a root after " << i + 1 << " iterations." << endl;
            return x_next;
        }

        x = x_next;
    }

    cout << "Did not converge after " << maxIterations << " iterations." << endl;
    return x;
}

int main() {
    double initialGuess = 4.0;
    double tolerance = 1e-6;
    int maxIterations = 100;

    double root = newtonRaphson(initialGuess, tolerance, maxIterations);
    cout << "Approximate root: " << root << endl;

    return 0;
}
