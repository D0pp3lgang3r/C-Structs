#include "stack.h"

Element *create_element(int value)
{
    Element *elt = malloc(sizeof(Element*));
    if (elt == NULL)
    {
        fprintf(stderr, "[-] Could not allocate an element in the memory\n");
        exit(EXIT_FAILURE);
    }
    elt->value = value;
    elt->next = NULL;
    return elt;
}

void destroy_element(Element *elt)
{
	free(elt->next);
    free(elt);
}

Stack *create_stack(void)
{
	Stack *stack = malloc(sizeof(Stack*));
	if (stack == NULL)
	{
		fprintf(stderr, "Could not allocate memory for the stack");
		exit(EXIT_FAILURE);
	}
	stack->top = NULL;
	return stack;
}

void destroy_stack(Stack *stack)
{
    Element *top;
    while (stack->top != NULL)
    {
        top = stack->top->next;
        free(stack->top);
        stack->top = top;
    }
    free(stack);
}

int is_stack_empty(Stack *stack)
{
	return stack->top == NULL;
}
int get_stack_size(Stack *stack)
{
	return stack->nb_elements;
}

void stacked(Stack *stack, Element *elt)
{
	if (is_stack_empty(stack))
		stack->top = elt;
	else
	{
		elt->next = stack->top;
		stack->top = elt;
	}
	stack->nb_elements++;
}

void unstacked(Stack *stack)
{
	Element *top;
	top = stack->top;
	stack->top = stack->top->next;
	free(top);
	stack->nb_elements--;
}

void print_stack(Stack *stack)
{
	if (is_stack_empty(stack))
	{
		printf("The stack is empty, can't print anything...");
		return;
	}
	Element *tmp;
	tmp = stack->top;
	while (stack->top != NULL)
	{
		printf("[%d]\n", stack->top->value);
		stack->top = stack->top->next;
	}
	stack->top = tmp;
}