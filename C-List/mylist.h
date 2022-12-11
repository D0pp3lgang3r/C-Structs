/**
 * @file list.h
 * @brief Declare functions and macro for Lists
 * @author D0pp3lgang3r
 * @version 1.0
 * @date 11/12/2022
 * */
#ifndef __LIST_H
#define __LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @struct Element
 * 
 * @brief Declare an element of the list, we can change int value to anything...
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
 * @struct List
 * 
 * @brief Declare a list
 * 
 * @var List::struct element *first
 *
 * Define the first element of the list, which will link other element to it
 * 
 * */
typedef struct list
{
	Element *first;
}List;

/**
 * @brief Will create an element of your list
 *
 * @param value
 * Value of the element
 *
 * @return struct *element
 * */
Element *create_element(int value);

/**
 * @brief Will destroy an element of your list
 *
 * @param Element
 * Pointer to the element
 *
 * @return void
 * */
void destroy_element(Element *elt);

/**
 * @brief Will allocate necessary space for the List in the memory
 *
 * @return List
 * */
List *create_list(void);

/**
 * @brief Will destroy the List in the memory
 *
 * @param List
 * Pointer to the list
 *
 * @return void
 * */
void destroy_list(List *L);

/**
 * @brief Will tell you if the list is empty
 *
 * @param L
 * Pointer to the list
 *
 * @return int
 * */
int is_list_empty(List *L);

/**
 * @brief Will return you the size of your list
 *
 * @param L
 * Pointer to the list
 *
 * @return int
 * */
int get_list_size(List *L);

/**
 * @brief Will pirnt the content of your list
 *
 * @param L
 * Pointer to the list
 *
 * @return void
 * */
void print_list(List *L);

/**
 * @brief Will add an element at the end of the list
 *
 * @param L
 * Pointer to the list
 * 
 * @param e
 * Pointer to the element
 *
 * @return void
 * */
void append_back(List *L, Element *e);

/**
 * @brief Will add an element at the beginning of the list
 *
 * @param L
 * Pointer to the list
 *
 * @return void
 * */
void append_front(List *L, Element *e);

/**
 * @brief Will delete an element at the beginning of the list and return it
 *
 * @param L
 * Pointer to the list
 *
 * @return struct *element
 * */
Element *pop_front(List *L);

/**
 * @brief Will delete an element at the end of the list and return it
 *
 * @param L
 * Pointer to the list
 *
 * @return struct *element
 * */
Element *pop_back(List *L);
#endif
