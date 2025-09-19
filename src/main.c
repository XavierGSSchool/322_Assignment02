char * AUTHOR_NAME = (char *) "Jakub Pach";
char * AUTHOR_AUTHORSHIP = (char *) "I acknowledge that I have worked on this assignment independently, except where explicitly noted and referenced. Any collaboration or use of external resources has been properly cited. I am fully aware of the consequences of academic dishonesty and agree to abide by the university's academic integrity policy. I understand the seriousness and implications of plagiarism.";


//#define clearBuffer() while (getchar() != '\n');
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "math_ops.h"

//#include "tests\tests.c"
// ----------------- MAIN PROGRAM -----------------



int main(int argc, char *argv[]) 
{

// To change the command-line parameters, modify the following line:
// lanuch.json.10:
// "args": ["--help"], 
// "args": ["--subtraction", "5", "3.0"] , // argues! attention not ["--subtraction 5 3.0"] <-- whole string in argv[1]!!!
// etc.

    int failed_tests  = 0;

    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    printf("%s\n", argv[3]);
    printf("%f\n", atof(argv[2]) );

    if (argc > 1 )
    {
        if(strcmp(argv[1], "--author") == 0) 
            printf("author"); //printf(AUTHOR_NAME);
        else if(strcmp(argv[1], "--authorship") == 0) 
           printf("AUTHOR"); //printf(AUTHOR_AUTHORSHIP);
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
            printf("  --sin a steps        Compute sine of a (radians) using Taylor series with steps terms\n");
        }
        // Math operations Implemented how I think Pach wants
        else if (strcmp(argv[1], "--addition") == 0 && argc == 4) {
            float a = atof(argv[2]);
            float b = atof(argv[3]);
            printf("%f\n", add(a, b));
            
        } else if (strcmp(argv[1], "--subtraction") == 0 && argc == 4) {
            float a = atof(argv[2]);
            float b = atof(argv[3]);
            printf("%f\n", sub(a, b));

        } else if (strcmp(argv[1], "--multiplication") == 0 && argc == 4) {
            float a = atof(argv[2]);
            float b = atof(argv[3]);
            printf("%f\n", multiply(a, b));

        } else if (strcmp(argv[1], "--division") == 0 && argc == 4) {
            float a = atof(argv[2]);
            float b = atof(argv[3]);
            printf("%f\n", divide(a, b));  

        } else if (strcmp(argv[1], "--power") == 0 && argc == 4) {
            float base = atof(argv[2]);
            int exponent = atoi(argv[3]);
            printf("%f\n", pow(base, exponent));

        } else if (strcmp(argv[1], "--square") == 0 && argc == 3) {
            float a = atof(argv[2]);
            printf("%f\n", square(a));

        } else if (strcmp(argv[1], "--cube") == 0 && argc == 3) {
            float a = atof(argv[2]);
            printf("%f\n", cube(a));
        }
        else if (strcmp(argv[1], "--sin") == 0 && argc == 4) {
            float a = atof(argv[2]);
            int steps = atoi(argv[3]);
            if (steps <= 0) {
                printf("Steps must be a positive integer.\n");
                return 1;
            }
            printf("%f\n", sin(a, steps));
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

