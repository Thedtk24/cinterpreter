#include <stdio.h>
#include <stdlib.h>

/* ASCII VALUES
 * '+' = 43
 * '-' = 45
 * '/' = 47
 * '*' = 42
 * (0-9) = (48-57)
*/

/* Counts number of operators in TOKENS[]*/
int count_ops(char *tokens, int size){
    int i, n = 0;

    for (i = 0; i < size; i++)
        if (tokens[i] == '*' || tokens[i] == '+' ||
            tokens[i] == '-' || tokens[i] == '/')
            n++;
    return n;
}

int extract_numbers(char *tokens, int *values){
    int i = 0, j = 0;

    while (tokens[i] != '\0') {
        // 1. Si on tombe sur un chiffre
        if (tokens[i] >= '0' && tokens[i] <= '9') {
            // atoi lit le nombre complet à partir de cet index
            values[j++] = atoi(&tokens[i]);

            // 2. CRUCIAL : On avance 'i' pour sauter TOUS les chiffres du nombre
            // qu'on vient de lire. Sinon, au prochain tour, on relit le 2ème chiffre.
            while (tokens[i] >= '0' && tokens[i] <= '9') {
                i++;
            }
        } 
        else {
            // 3. Si ce n'est pas un chiffre (espace, +, etc.), on avance d'une case
            i++;
        }
    }
    return j;
}

void extract_ops(char *tokens, char *operators, int size){
    int i = 0, j = 0;

    while (tokens[i] != '\0') {
        // 1. Si on tombe sur un opérateur
        if (tokens[i] == '-' || tokens[i] == '+' || tokens[i] == '/' || tokens[i] == '*') {
            operators[j++] = tokens[i];
        }

        i++;
    }

    operators[size + 1] = '\0';
}