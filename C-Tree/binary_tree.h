/**
 * @file binary_tree.h
 * @brief Declare functions and macro for Binary Trees
 * @author D0pp3lgang3r
 * @version 1.0
 * @date 11/12/2022
 * */
#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H
#define ROOT 0
#define max(a,b) \
	({ __typeof__ (a) _a = (a); \
		__typeof__ (b) _b = (b); \
		_a > _b ? _a : _b; })
#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Node
 * 
 * @brief Declare a node which will also be considered as a binary tree.
 * 
 * @var Node::int value
 * 
 * Contain the value of the node
 * 
 * @var Node::struct node *left
 * 
 * Refer to the left child node
 * 
 * @var Node::struct node *right
 * Refer to the right child node
 * */
typedef struct node
{
	int value;
	struct node *left;
	struct node *right;
} Node;

/**
 * @brief Implement in the function print_node, to help printing our node.
 * 
 * @param ch
 * Char to print
 *
 * @param stage
 * Current node level
 * 
 * @return void
 * */
void offset(char ch, int stage);

/**
 * @brief Use to print the binary tree structure.
 * 
 * @param node
 * Pointer to a node
 * 
 * @param stage
 * Current node level
 *
 * @return int
 * */
int print_node(Node *node, int stage);

/**
 * @brief Will create your node in the memory.
 *
 * @param value
 * Value of the node
 *
 * @return struct *node
 * */
Node *create_node(int value);

/**
 * @brief Will free the node in the memory.
 * 
 * @param node
 * Pointer to the node
 *
 * @return void
 * */
void destroy_node(Node *node);

/**
 * @brief Insert left child node.
 *
 * @param node1
 * Pointer to the parent node
 *
 * @param node2
 * Pointer to the child node
 *
 * @return void
 * */
void insert_left_children(Node *node1, Node *node2);

/**
 * @brief Insert right child node.
 *
 * @param node1
 * Pointer to the parent node
 *
 * @param node2
 * Pointer to the child node
 *
 * @return void
 * */
void insert_right_children(Node *node1, Node *node2);

/**
 * @brief Test if a node is consider as a leaf, that means he has no child node.
 *
 * @param node
 * Pointer to the node
 *
 * @return int
 * */
int is_a_leaf(Node *node);

/**
 * @brief Test if a node is internal to the binary tree. A node is considered as internal, if it has at least 1 child.
 *
 * @param node
 * Pointer to the node
 *
 * @return int
 * */
int is_an_internal_node(Node *node);

/**
 * @brief Function to get the number of nodes in the tree.
 *
 * @param node
 * Pointer to the node
 *
 * @return int
 * */
int get_number_of_nodes(Node *node);

/**
 * @brief Function to get the number of internal nodes in the tree.
 *
 * @param node
 * Pointer to the node
 *
 * @return int
 * */
int get_number_of_internal_nodes(Node *node);

/**
 * @brief Function to get the number of leaves in the tree.
 *
 * @param node
 * Pointer to the node
 *
 * @return int
 * */
int get_number_of_leaves(Node *node);

/**
 * @brief Function to get the height of the tree (number of stage between root, and last lower leaf).
 *
 * @param node
 * Pointer to the node
 *
 * @return int
 * */
int get_height(Node *node);

/**
 * @brief Function to swap the childs node of a parent node.
 *
 * @param node
 * Pointer to the node
 *
 * @return void
 * */
void swap_node(Node *node);

/**
 * @brief Function to get mirror of your tree.
 *
 * @param node
 * Pointer to the node
 *
 * @return void
 * */
void get_mirror(Node *node);


/**
 * @brief Print the postfixe way to the user.
 *
 * @param node
 * Pointer to the node
 *
 * @return void
 * */
void postfixe_way(Node *node);

/**
 * @brief Print the prefixe way to the user.
 *
 * @param node
 * Pointer to the node
 *
 * @return void
 * */
void prefixe_way(Node *node);

/**
 * @brief Print the infixe way to the user.
 *
 * @param node
 * Pointer to the node
 *
 * @return void
 * */
void infixe_way(Node *node);

#endif