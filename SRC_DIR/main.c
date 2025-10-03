char * AUTHOR_NAME = (char *) "Jakub Pach";
char * AUTHOR_AUTHORSHIP = (char *) "I acknowledge that I have worked on this assignment independently, except where explicitly noted and referenced. Any collaboration or use of external resources has been properly cited. I am fully aware of the consequences of academic dishonesty and agree to abide by the university's academic integrity policy. I understand the seriousness and implications of plagiarism.";

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "math_ops.h"

// ----------------- MAIN PROGRAM -----------------

int main(int argc, char *argv[]) 
{
    int failed_tests  = 0;

    // Debug prints (safer version)
    printf("Program: %s\n", argv[0]);
    if (argc > 1) printf("Arg1: %s\n", argv[1]);
    if (argc > 2) printf("Arg2: %s\n", argv[2]);
    if (argc > 3) printf("Arg3: %s\n", argv[3]);
    if (argc > 2) printf("Arg2 as float: %f\n", atof(argv[2]));

    if (argc > 1 )
    {
        if(strcmp(argv[1], "--author") == 0) 
            printf("%s\n", AUTHOR_NAME);  
        else if(strcmp(argv[1], "--authorship") == 0) 
            printf("%s\n", AUTHOR_AUTHORSHIP);  
        else if(strcmp(argv[1], "--help") == 0) 
        {
            printf("\nOptions:\n");
            printf("  --author             Print author name\n");
            printf("  --authorship         Print academic honesty statement\n");
            printf("  --addition a b       Add two numbers\n");
            printf("  --subtraction a b    Subtract two numbers\n");
            printf("  --multiplication a b Multiply two numbers\n");
            printf("  --division a b       Divide two numbers\n");
            printf("  --power a b          Raise a to the power of b\n");
            printf("  --square a           Square of a number\n");
            printf("  --cube a             Cube of a number\n");
            printf("  --sin x steps        Compute sine of a (radians) using Taylor series with steps terms\n");
            printf("  --cos x steps        Compute cosine of a (radians) using Taylor series with steps terms\n");
        }
        // Math operations
        else if (strcmp(argv[1], "--addition") == 0 && argc == 4) {
            float a = atof(argv[2]);
            float b = atof(argv[3]);
            printf("%f\n", math_add(a, b));  
            
        } else if (strcmp(argv[1], "--subtraction") == 0 && argc == 4) {
            float a = atof(argv[2]);
            float b = atof(argv[3]);
            printf("%f\n", math_sub(a, b));  

        } else if (strcmp(argv[1], "--multiplication") == 0 && argc == 4) {
            float a = atof(argv[2]);
            float b = atof(argv[3]);
            printf("%f\n", math_multiply(a, b));  

        } else if (strcmp(argv[1], "--division") == 0 && argc == 4) {
            float a = atof(argv[2]);
            float b = atof(argv[3]);
            printf("%f\n", math_divide(a, b));   

        } else if (strcmp(argv[1], "--power") == 0 && argc == 4) {
            float base = atof(argv[2]);
            int exponent = atoi(argv[3]);
            printf("%f\n", math_pow(base, exponent)); 

        } else if (strcmp(argv[1], "--square") == 0 && argc == 3) {
            float a = atof(argv[2]);
            printf("%f\n", math_square(a));  

        } else if (strcmp(argv[1], "--cube") == 0 && argc == 3) {
            float a = atof(argv[2]);
            printf("%f\n", math_cube(a));  
        }
        else if (strcmp(argv[1], "--sin") == 0 && argc == 4) {
            float a = atof(argv[2]);
             int steps = atoi(argv[3]);
            printf("%f\n", math_sin(a, steps)); 
        }
        else if (strcmp(argv[1], "--cos") == 0 && argc == 4) {
            float a = atof(argv[2]);
            int steps = atoi(argv[3]);
            printf("%f\n", math_cos(a, steps)); 
        }
        else
        {
            printf("Unknown option '%s'. Use --help to see available options.\n", argv[1]);
            return 1;
        }
    }
    else
    {
        printf("Wrong parameter. Use --help to see available options.\n");
        return 1; // Wrong parameter
    } 
    

     getchar(); // pause before exit (Windows)

    return failed_tests; // cmd/powershell:  echo $LASTEXITCODE
}