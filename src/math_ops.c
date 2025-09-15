#include "math_ops.h"

// --------- FUNCTION IMPLEMENTATIONS ------------


float square(float x) 
{
    return x * x;
}

float cube(float x) 
{
    return x * x * x;
}

float pow(float base, int exponent ) 
{
    float res = 1;
    for(int i = 0; i < exponent; i++) 
    {
        res *= base;
    }
    return res;
}

float multiply(float x, float y) 
{
    return x * y;
}

float add(float x, float y) 
{
    return x + y;
}

float sub(float a, float b)
{
    return a - b;
}

float divide(float a, float b)
{
    if (b == 0.0f)
    {
        // cannot divide by zero
        printf("Error: Division by zero\n");
        return 0.0f;
    }
    return a / b;
}