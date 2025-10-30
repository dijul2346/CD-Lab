#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20

char productions[SIZE][SIZE];
char nonTerminals[SIZE];
int n, ntCount = 0;

void findFIRST(char[], char);
void findFOLLOW(char[], char);
void addToSet(char[], char);
int isNonTerminal(char);
void removeSpaces(char[]);

int main() {
    char result[SIZE];

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (e.g., E=TR):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
        removeSpaces(productions[i]);

        // Store unique non-terminals
        int exists = 0;
        for (int j = 0; j < ntCount; j++)
            if (nonTerminals[j] == productions[i][0])
                exists = 1;

        if (!exists)
            nonTerminals[ntCount++] = productions[i][0];
    }

    printf("\nProductions:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", productions[i]);
    printf("\n");

    // FIRST sets
    for (int i = 0; i < ntCount; i++) {
        strcpy(result, "");
        findFIRST(result, nonTerminals[i]);
        printf("FIRST(%c) = { ", nonTerminals[i]);
        for (int j = 0; result[j]; j++)
            printf("%c%s", result[j], result[j + 1] ? ", " : "");
        printf(" }\n");
    }

    printf("\n");

    // FOLLOW sets
    for (int i = 0; i < ntCount; i++) {
        strcpy(result, "");
        findFOLLOW(result, nonTerminals[i]);
        printf("FOLLOW(%c) = { ", nonTerminals[i]);
        for (int j = 0; result[j]; j++)
            printf("%c%s", result[j], result[j + 1] ? ", " : "");
        printf(" }\n");
    }

    return 0;
}

// ---------------- Helper Functions ----------------

void removeSpaces(char str[]) {
    int k = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ') str[k++] = str[i];
    str[k] = '\0';
}

void addToSet(char set[], char c) {
    if (!strchr(set, c)) {
        int len = strlen(set);
        set[len] = c;
        set[len + 1] = '\0';
    }
}

int isNonTerminal(char c) {
    return isupper(c);
}

// ---------------- FIRST ----------------

void findFIRST(char result[], char symbol) {
    if (!isNonTerminal(symbol) && symbol != '#') {
        addToSet(result, symbol);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (productions[i][0] != symbol)
            continue;

        // E -> #
        if (productions[i][2] == '#') {
            addToSet(result, '#');
            continue;
        }

        // For other cases
        int k = 2, epsilon = 1;
        while (productions[i][k] && epsilon) {
            char next = productions[i][k++];
            char temp[SIZE] = "";
            findFIRST(temp, next);

            for (int j = 0; temp[j]; j++)
                if (temp[j] != '#')
                    addToSet(result, temp[j]);

            epsilon = strchr(temp, '#') != NULL;
        }
        if (epsilon)
            addToSet(result, '#');
    }
}

// ---------------- FOLLOW ----------------

void findFOLLOW(char result[], char symbol) {
    if (productions[0][0] == symbol)
        addToSet(result, '$'); // Start symbol

    for (int i = 0; i < n; i++) {
        for (int j = 2; productions[i][j]; j++) {
            if (productions[i][j] != symbol)
                continue;

            int k = j + 1, epsilon = 1;
            while (productions[i][k] && epsilon) {
                char next = productions[i][k++];
                if (!isNonTerminal(next) && next != '#') {
                    addToSet(result, next);
                    epsilon = 0;
                    break;
                }

                char temp[SIZE] = "";
                findFIRST(temp, next);
                for (int m = 0; temp[m]; m++)
                    if (temp[m] != '#')
                        addToSet(result, temp[m]);

                epsilon = strchr(temp, '#') != NULL;
            }

            if (epsilon && productions[i][0] != symbol) {
                char tempFollow[SIZE] = "";
                findFOLLOW(tempFollow, productions[i][0]);
                for (int m = 0; tempFollow[m]; m++)
                    addToSet(result, tempFollow[m]);
            }
        }
    }
}
