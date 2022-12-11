/**
 * @file stack.h
 * @brief Declare functions and macro for Stacks
 * @author D0pp3lgang3r
 * @version 1.0
 * @date 11/12/2022
 * */
#ifndef __STACK_H
#define __STACK_H
#include <stdio.h>
#include <stdlib.h>
/**
 * @struct Element
 * 
 * @brief Declare an element of the stack, we can change int value to anything...
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
 * @struct Stack
 * 
 * @brief Declare a stack
 * 
 * @var Stack::struct element *top
 *
 * Define the top element of the stack, which will link other element to it
 * 
 * */
typedef struct stack
{
	int nb_elements;
	Element *top;
} Stack;

/**
 * @brief Will create an element of your stack
 *
 * @param value
 * Value of the element
 *
 * @return struct *element
 * */
Element *create_element(int value);

/**
 * @brief Will destroy an element of your stack
 *
 * @param Element
 * Pointer to the element
 *
 * @return void
 * */
void destroy_element(Element *elt);

/**
 * @brief Will allocate necessary space for the Stack in the memory
 *
 * @return Stack
 * */
Stack *create_stack(void);

/**
 * @brief Will destroy the Stack in the memory
 *
 * @param Stack
 * Pointer to the stack
 *
 * @return void
 * */
void destroy_stack(Stack *stack);

/**
 * @brief Will tell you if the stack is empty
 *
 * @param Stack
 * Pointer to the stack
 *
 * @return int
 * */
int is_stack_empty(Stack *stack);

/**
 * @brief Print the content of the stack
 *
 * @param Stack
 * Pointer to the stack
 *
 * @return void
 * */
void print_stack(Stack *stack);

/**
 * @brief Will return you the size of the stack
 *
 * @param Stack
 * Pointer to the stack
 *
 * @return int
 * */
int get_stack_size(Stack *stack);

/**
 * @brief Will stack an element to the Stack
 *
 * @param Stack
 * Pointer to the stack
 *
 * @return void
 * */
void stacked(Stack *stack, Element *elt);

/**
 * @brief Will unstack an element to the Stack
 *
 * @param Stack
 * Pointer to the stack
 *
 * @return void
 * */
void unstacked(Stack *stack);

#endif