/**
 * @file queue.h
 * @brief Declare functions and macro for Queues
 * @author D0pp3lgang3r
 * @version 1.0
 * @date 11/12/2022
 * */
#ifndef __QUEUE_H
#define __QUEUE_H
#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Element
 * 
 * @brief Declare an element of the queue, we can change int value to anything...
 * 
 * @var Element::int value
 *
 * Contain the value of the element
 * 
 * @var Element::struct element *next
 *
 * Refer to the next element
 * 
 * */
typedef struct element
{
	int value;
	struct element *next;
} Element;

/**
 * @struct Queue
 * 
 * @brief Declare a queue
 * 
 * @var Queue::int nb_elements
 *
 * @var Queue::struct element *first
 *
 * @var Queue::struct element *last
 *
 * Define the first element of the queue and last element, which will link other elements 
 * */
typedef struct queue
{
	int nb_elements;
	Element *first;
	Element *last;
} Queue;

/**
 * @brief Will create an element of your queue
 *
 * @param value
 * Value of the element
 *
 * @return struct *element
 * */
Element *create_element(int value);

/**
 * @brief Will destroy an element of your queue
 *
 * @param Element
 * Pointer to the element
 *
 * @return void
 * */
void destroy_element(Element *elt);

/**
 * @brief Will allocate necessary space for the Queue in the memory
 *
 * @return Queue
 * */
Queue *create_queue(void);

/**
 * @brief Will destroy the Queue in the memory
 *
 * @param Queue
 * Pointer to the queue
 *
 * @return void
 * */
void destroy_queue(Queue *Q);

/**
 * @brief Test if the queue is empty
 *
 * @param Queue
 * Pointer to the queue
 *
 * @return int
 * */
int is_queue_empty(Queue *Q);

/**
 * @brief Will return the size of the queue
 *
 * @param Queue
 * Pointer to the queue
 *
 * @return int
 * */
int get_queue_size(Queue *Q);

/**
 * @brief Will return the value of the first element from the Queue
 *
 * @param Queue
 * Pointer to the queue
 *
 * @return int
 * */
int queue_first(Queue *Q);

/**
 * @brief Will return the value of the last element from the Queue
 *
 * @param Queue
 * Pointer to the queue
 *
 * @return int
 * */
int queue_last(Queue *Q);

/**
 * @brief Will enqueue an element in the queue
 *
 * @param Queue
 * Pointer to the queue
 *
 * @param Element
 * Pointer to the element
 *
 * @return void
 * */
void enqueue(Queue *Q, Element *elt);

/**
 * @brief Will dequeue an element from the queue
 *
 * @param Queue
 * Pointer to the queue
 *
 *
 * @return void
 * */
void dequeue(Queue *Q);

/**
 * @brief Will print the content of the queue
 *
 * @param Queue
 * Pointer to the queue
 *
 * @return void
 * */
void print_queue(Queue *Q);
#endif