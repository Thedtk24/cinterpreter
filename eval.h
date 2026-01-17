/* Author : Thed Arthur, Jan. 2026 */

#ifndef EVAL_H
#define EVAL_H

// Treat multiplication and division for BODMAS respect
void reduce_md(int *values, char *ops, int *n_ops);

/* Evaluator */
int evaluate(int *values, char *ops, int n_ops);

#endif /* EVAL_H */