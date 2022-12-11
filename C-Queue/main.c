#include "queue.h"

int main(void)
{
	/* DEFINITION OF ELEMENTS */
	
	Element *a = create_element(1);
	Element *b = create_element(2);
	Element *c = create_element(3);

	/* DEFINITION OF THE QUEUE */

	Queue *q = create_queue();

	if (is_queue_empty(q))
		printf("[+] The queue is empty\n");
	printf("[+] Number of elements : %d\n", get_queue_size(q));

	/* TEST ON THE QUEUE */

	printf("[+] Add elements a,b,c\n");
	enqueue(q, a);
	enqueue(q, b);
	enqueue(q, c);
	printf("[+] Number of elements : %d\n", get_queue_size(q));
	print_queue(q);
	
	printf("[+] Delete a\n");
	dequeue(q);
	print_queue(q);
	
	printf("[+] Delete b\n");
	dequeue(q);
	print_queue(q);
	destroy_queue(q);
	return 0;
}