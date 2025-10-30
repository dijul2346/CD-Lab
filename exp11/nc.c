#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 10

struct Code
{
    char lhs[10];
    char op1[10];
    char op;
    char op2[10];
};

int main()
{
    struct Code code[MAX];
    char var[MAX][10];
    int val[MAX];
    int constCount = 0;
    int n;

    printf("Enter number of statements: ");
    scanf("%d", &n);

    printf("\nEnter statements in the form:\n");
    printf("  x = a + b  OR  x = 5  (use '_' if not applicable)\n\n");

    // Input code statements
    for (int i = 0; i < n; i++)
    {
        printf("Statement %d: ", i + 1);
        scanf("%s = %s %c %s", code[i].lhs, code[i].op1, &code[i].op, code[i].op2);
    }

    // Perform constant propagation
    for (int i = 0; i < n; i++)
    {

        // Replace variables with known constant values
        for (int j = 0; j < constCount; j++)
        {
            if (strcmp(code[i].op1, var[j]) == 0)
            {
                sprintf(code[i].op1, "%d", val[j]);
            }
            if (strcmp(code[i].op2, var[j]) == 0)
            {
                sprintf(code[i].op2, "%d", val[j]);
            }
        }

        // Check if operands are constants (or '_' for unused)
        if (isdigit(code[i].op1[0]) &&
            (code[i].op2[0] == '_' || isdigit(code[i].op2[0])))
        {

            int v1 = atoi(code[i].op1);
            int v2 = (code[i].op2[0] != '_') ? atoi(code[i].op2) : 0;
            int result = 0;

            switch (code[i].op)
            {
            case '+':
                result = v1 + v2;
                break;
            case '-':
                result = v1 - v2;
                break;
            case '*':
                result = v1 * v2;
                break;
            case '/':
                result = (v2 != 0) ? v1 / v2 : 0;
                break;
            case '_':
                result = v1;
                break;
            default:
                continue;
            }

            // Store the variable and its computed constant value
            strcpy(var[constCount], code[i].lhs);
            val[constCount++] = result;

            // Update statement to reflect constant result
            sprintf(code[i].op1, "%d", result);
            code[i].op = '_';
            strcpy(code[i].op2, "_");
        }
    }

    // Display the updated statements
    printf("\nAfter Constant Propagation:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s = %s", code[i].lhs, code[i].op1);
        if (code[i].op != '_')
            printf(" %c %s", code[i].op, code[i].op2);
        printf("\n");
    }

    return 0;
}