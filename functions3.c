#include "monty.h"

/**
 * monty_swap - swap the top two elements
 *
 * @stack: pointer to the stack list
 * @line_num: number of the line
*/

void monty_swap(stack_t **stack, unsigned int line_num)
{
	(void) line_num;

	stack_t *top = *stack;
	stack_t *box = top->next;

	top->prev = box;
	top->next = box->next;
	box->next = top;
	box->prev = NULL;

	*stack = box;
}

/**
 * monty_add - add the top two elements
 *
 * @stack: pointer to the stack list
 * @line_num: number of the line
*/

void monty_add(stack_t **stack, unsigned int line_num)
{
	stack_t *top = *stack;
	stack_t *top2 = top->next;
	stack_t *add;
	stack_t *stackmod = top2->next;

	int first = top->n;
	int second = top2->n;

	add = malloc(sizeof(stack_t));
	if (!add)
	{
		fprintf(stderr, "L%d: can't create a new node ADD\n", line_num);
		exit(EXIT_FAILURE);
	}

	add->prev = NULL;
	add->n = (first) + (second);
	add->next = stackmod;
	stackmod->prev = add;

	free(top);
	free(top2);

	*stack = add;
}
