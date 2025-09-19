#include "math_ops.h"

// --------- FUNCTION IMPLEMENTATIONS ------------

float math_square(float x) 
{
    return x * x;
}

float math_cube(float x) 
{
    return x * x * x;
}

float math_pow(float base, int exponent) 
{
    float res = 1;
    for(int i = 0; i < exponent; i++) 
    {
        res *= base;
    }
    return res;
}

float math_multiply(float x, float y) 
{
    return x * y;
}

float math_add(float x, float y) 
{
    return x + y;
}

float math_sub(float a, float b)
{
    return a - b;
}

float math_divide(float a, float b)
{
    if (b == 0.0f)
    {
        printf("Error: Division by zero\n");
        return 0.0f;
    }
    return a / b;
}

float math_sin(float x, int steps) {
    float result = 0.0;
    float term;
    int sign = 1;

    for (int n = 0; n < steps; ++n) {
        int power = 2 * n + 1;

        // Compute numerator (x^power)
        float numerator = 1.0;
        for (int i = 0; i < power; ++i) {
            numerator *= x;
        }

        // Compute denominator (power!)
        float denominator = 1.0;
        for (int i = 1; i <= power; ++i) {
            denominator *= i;
        }

        term = sign * (numerator / denominator);
        result += term;
        sign *= -1;
    }

    return result;
}