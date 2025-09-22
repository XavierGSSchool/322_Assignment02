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
   return 1.0; // changed applied
}