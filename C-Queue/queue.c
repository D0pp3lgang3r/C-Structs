#include "queue.h"

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
	if (elt == NULL)
		return;

	free(elt->next);
	free(elt);
}

Queue *create_queue(void)
{
	Queue *q = malloc(sizeof(Queue*));
	if (q == NULL)
	{
		fprintf(stderr, "[-] Could not allocate a queue in the memory\n");
		exit(EXIT_FAILURE);
	}
	q->first = NULL;
	q->last = NULL;
	q->nb_elements = 0;
	return q;
}

void destroy_queue(Queue *Q)
{
	if (is_queue_empty(Q))
	{
		return;
	}
	while(!is_queue_empty(Q))
		dequeue(Q);
	free(Q);
}

int is_queue_empty(Queue *Q)
{
	return Q->first == NULL && Q->last == NULL;
}

int get_queue_size(Queue *Q)
{
	return Q->nb_elements;
}

int queue_first(Queue *Q)
{
	if (is_queue_empty(Q))
	{
		fprintf(stderr, "[-] The list is empty, we can't get the value of the first element\n");
		exit(EXIT_FAILURE);
	}
	return Q->first->value;
}
int queue_last(Queue *Q)
{
	if (is_queue_empty(Q))
	{
		fprintf(stderr, "[-] The list is empty, we can't get the value of the last element\n");
		exit(EXIT_FAILURE);
	}
	return Q->last->value;
}


void enqueue(Queue *Q, Element *elt)
{
	if (is_queue_empty(Q))
	{
		Q->first = elt;
		Q->last = elt;
	}
	else
	{
		Q->last->next = elt;
		Q->last = elt;
	}
	Q->nb_elements++;
}

void dequeue(Queue *Q)
{
	if (is_queue_empty(Q))
	{
		printf("[+] List is empty can't get anything of it\n");
		return;
	}
	Element *tmp = Q->first;
	if (Q->first == Q->last)
	{
		Q->first = NULL;
		Q->last = NULL;
	}
	else
	{
		Q->first = Q->first->next;
	}
	free(tmp);
	Q->nb_elements--;
}

void print_queue(Queue *Q)
{
	if (is_queue_empty(Q))
	{
		printf("[+] List is empty\n");
		return;
	}
	Element *tmp = Q->first;
	while (tmp != NULL)
	{
		printf("[%d]", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}