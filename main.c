/* Author : Thed Arthur, Jan. 2026 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "eval.h"
#include "lexer.h"

#define MAX_ENTRY 1024

/* ASCII VALUES
 * '+' = 43
 * '-' = 45
 * '/' = 47
 * '*' = 42
 * (0-9) = (48-57)
*/

int main(){
    char buffer[MAX_ENTRY];
    bool execute = true;

    printf("Cinterpreter 1.0.0 (v1.0.0, Jan 17 2026)\n"
            "Type \"help\" for more information.\n");

    while(execute){
        printf(">>> ");
        scanf("%1000s", buffer);

        int SIZE = strlen(buffer);

        if(strcmp(buffer, "exit") == 0){
            execute = false;
            break;
        }
        if(strcmp(buffer, "clear") == 0){
            system("clear");
        }

        if(strcmp(buffer, "clear") != 0){
            //printf("ops = %d ; ", count_ops(buffer, SIZE));

            int ops = count_ops(buffer, SIZE);

            

            int *values = malloc((ops + 1) * sizeof(int));
            char *operators = malloc((ops + 1) * sizeof(char));

            extract_ops(buffer, operators, ops);

            /*printf("Operators = {");
            for(int i = 0; i < ops - 1; i++){
                printf("%c, ", operators[i]);
            }
            printf("%c}\n\n", operators[ops - 1]);

            printf("numbers = %d ; ", extract_numbers(buffer, values));

            printf("Values = {");
            for(int i = 0; i < ops; i++){
                printf("%d, ", values[i]);
            }
            printf("%d}\n", values[ops]);*/

            int n_values = extract_numbers(buffer, values);
            if(n_values != ops + 1){
                fprintf(stderr, "Error : number of values != number of operators + 1\n");
            }


            reduce_md(values, operators, &ops);
            printf("%d\n", evaluate(values, operators, ops));
        }

        
    }

    return 0;
}