#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 *
 * Description: switches the values of the first two nodes
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
