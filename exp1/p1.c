#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char keywords[][10] = {"int", "main", "return"};
char operators[] = "+-*/=<>"; 
char separators[] = ",(){};";

bool isKeyword(char *word) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return true;
    }
    return false;
}

bool isOperator(char c) {
    for (int i = 0; operators[i] != '\0'; i++) {
        if (operators[i] == c)
            return true;
    }
    return false;
}

bool isSeparator(char c) {
    for (int i = 0; separators[i] != '\0'; i++) {
        if (separators[i] == c)
            return true;
    }
    return false;
}

int main() {
    FILE *f = fopen("input.c", "r");
    if (!f) {
        printf("Cannot open file!\n");
        return 1;
    }

    freopen("output.txt", "w", stdout); // Redirect output to file

    char c, token[50];
    int i;

    while ((c = fgetc(f)) != EOF) {
        if (isspace(c))
            continue;

        // Preprocessor
        if (c == '#') {
            printf("(#, Preprocessor Directive)\n(");
            while ((c = fgetc(f)) != '\n' && c != EOF)
                putchar(c);
            printf(", Preprocessor Instruction)\n");
        }

        // Operator
        else if (isOperator(c)) {
            if (c == '=') printf("(=, Assignment)\n");
            else printf("(%c, Operator)\n", c);
        }

        // Separator
        else if (isSeparator(c)) {
            printf("(%c, Separator)\n", c);
        }

        // Identifier or Keyword
        else if (isalpha(c) || c == '_') {
            i = 0;
            while (isalnum(c) || c == '_') {
                token[i++] = c;
                c = fgetc(f);
            }
            token[i] = '\0';
            ungetc(c, f);

            if (isKeyword(token))
                printf("(%s, Keyword)\n", token);
            else
                printf("(%s, Identifier)\n", token);
        }
    }

    fclose(f);
    return 0;
}
