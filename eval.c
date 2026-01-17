/* Author : Thed Arthur, Jan. 2026 */

#include <stdio.h>
#include <stdlib.h>
#include "eval.h"

void reduce_md(int *values, char *ops, int *n_ops){
    int i, j = 0;

    for (i = 0; i < *n_ops; i++){
        if (ops[i] == '*' || ops[i] == '/'){
            if (ops[i] == '*') values[j] *= values[i + 1];
            else values[j] /= values[i + 1];
        } else{
            values[++j] = values[i + 1];
            ops[j - 1] = ops[i];
        }
    }
    *n_ops = j;
}

int evaluate(int *values, char *ops, int n_ops){
    int result = values[0];
    int i;

    for (i = 0; i < n_ops; i++){
        if (ops[i] == '+') result += values[i + 1];
        else result -= values[i + 1];
    }
    return result;
}