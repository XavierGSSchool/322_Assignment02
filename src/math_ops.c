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
    // hard code steps
    steps = 10;
    float result = 0.0;
    float term = x;    

    result += term;

    for (int n = 1; n < steps; ++n) {
        int power = 2 * n + 1;
        
        // term = term * (-1) * x^2 / ((2n)*(2n+1))
        term *= -1 * x * x / ((power - 1) * power);

        result += term;
    }

    return result;
}

float math_cos(float x, int steps) {
    // hard code steps
    steps = 10;
    float result = 1.0;   
    float term = 1.0;   
    // cos(x) uses even powers: 2, 4, 6, ... 
    for (int n = 1; n < steps; ++n) {
        int power = 2 * n; 

        // term = term * (-1) * x^2 / ((2n - 1) * (2n))
        term *= -1 * x * x / ((power - 1) * power);

        result += term;
    }
    return result;
}