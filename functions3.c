#include "monty.h"

/**
 * monty_swap - swap the top two elements
 *
 * @stack: pointer to the stack list
 * @line_num: number of the line
*/

void monty_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *box;

	if ((*stack) == NULL || ((*stack)->next) == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	box = top->next;

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
	stack_t *top, *top2, *add, *stackmod;
	int first, second;

	if ((*stack) == NULL || ((*stack)->next) == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	top2 = top->next;
	stackmod = top2->next;

	first = top->n;
	second = top2->n;

	add = malloc(sizeof(stack_t));
	if (!add)
	{
		fprintf(stderr, "L%d: can't create a new node ADD\n", line_num);
		exit(EXIT_FAILURE);
	}

	add->prev = NULL;
	add->n = (first) + (second);

	if (stackmod != NULL)
	{
		add->next = stackmod;
		stackmod->prev = add;
	}
	else
		add->next = NULL;

	free(top);
	free(top2);

	*stack = add;
}
