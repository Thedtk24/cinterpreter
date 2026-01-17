/* Author : Thed Arthur, Jan. 2026 */

#ifndef LEXER_H
#define LEXER_H

/* Counts number of operators in TOKENS[]*/
int count_ops(char *tokens, int size);

/* Extracts numbers for TOKENS[] for evaluator*/
int extract_numbers(char *tokens, int *values);

/* Extracts numbers of operators for evaluator*/
void extract_ops(char *tokens, char *operators, int size);

#endif