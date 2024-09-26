#include "monty.h"

/**
 * push - pushes an integer to the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * @value: integer value to push
 *
 * Description: adds a node at the beginning of the stack
 */
void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node;

	(void) line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 *
 * Description: starts from the top of the stack
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
