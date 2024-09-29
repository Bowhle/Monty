#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_LINE_LENGTH 1024

void execute_command(char *line, stack_t **stack) {
    if (strncmp(line, "push", 4) == 0) {
        int value = atoi(line + 5);
        push(stack, 1, value);
    } else if (strncmp(line, "pall", 4) == 0) {
        pall(stack, 1);
    }
}

void free_stack(stack_t **stack) {
    stack_t *current = *stack;
    stack_t *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    *stack = NULL;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    stack_t *stack = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file)) {
        execute_command(line, &stack);
    }

    fclose(file);
    free_stack(&stack);

    return EXIT_SUCCESS;
}

