#include "monty.h"

/**
 * nop - doesn’t do anything
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 *
 * Description: simply skips execution
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
