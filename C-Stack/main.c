#include "stack.h"

int main(void)
{
	Element *a = create_element(1);
	Element *b = create_element(2);
	Element *c = create_element(3);

	printf("[+] Create the stack...\n");
	Stack *stack = create_stack();
	
	if (is_stack_empty(stack))
		printf("The stack is empty\n");

	printf("[*] Stacking a,b,c to stack...\n");
	stacked(stack, a);
	stacked(stack, b);
	stacked(stack, c);
	
	printf("[+] Content of the stack :\n");
	print_stack(stack);
	
	printf("[*] Unstacking the stack : \n");
	unstacked(stack);

	printf("[+] Number of elements in the stack : %d\n", get_stack_size(stack));
	printf("[+] Content of the stack :\n");
	print_stack(stack);

	printf("[*] Destroying the stack...\n");
	destroy_stack(stack);
	
	return 0;
}