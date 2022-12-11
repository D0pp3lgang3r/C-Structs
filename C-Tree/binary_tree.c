#include "binary_tree.h"

Node *create_node(int value)
{
	Node *node = malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void destroy_node(Node *node)
{
	if (node == NULL)
		return;
	destroy_node(node->left);
	destroy_node(node->right);
	free(node);
}

void insert_left_children(Node *node1, Node *node2)
{
	node1->left = node2; 
}


void insert_right_children(Node *node1, Node *node2)
{
	node1->right = node2;
}

void offset(char ch, int n)
{
	for (int i = 0; i < n; i++ )
		putchar(ch);
}

int print_node(Node *node, int stage)
{
	if (node == NULL ) {
    	offset('\t', stage);
    	puts("#");
	}
	else {
    	print_node(node->right, stage + 1);
		offset('\t',stage);
		printf("%d\n", node->value);
		print_node(node->left,stage+1);
	}
}
int is_a_leaf(Node *node)
{
	return node != NULL && node->left == NULL && node->right == NULL;
}

int is_an_internal_node(Node *node)
{
	return node != NULL && node->left != NULL || node->right != NULL;
}

int get_number_of_nodes(Node *node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + get_number_of_nodes(node->left) + get_number_of_nodes(node->right);
	}
}

int get_number_of_internal_nodes(Node *node)
{	
	if (node == NULL)
	{
		return 0;
	}
	else if (!is_an_internal_node(node))
	{
		return 0;
	}
	else
	{
		return 1 + get_number_of_internal_nodes(node->left) + get_number_of_internal_nodes(node->right);
	}
}

int get_number_of_leaves(Node *node)
{
	if (node == NULL)
	{
		return 0;
	}
	else if (is_a_leaf(node))
	{
		return 1;
	}
	else
	{
		return get_number_of_leaves(node->left) + get_number_of_leaves(node->right);
	}
}


int get_height(Node *node)
{
	if (node == NULL || is_a_leaf(node))
		return 0;
	else
		return 1+max(get_height(node->left),get_height(node->right));
}

void swap_node(Node *node)
{
	Node *tmp;
	tmp = node->left;
	node->left = node->right;
	node->right = tmp;
}

void get_mirror(Node *node)
{
	if (node == NULL)
		return;
	get_mirror(node->left);
	get_mirror(node->right);
	swap_node(node);
}

void postfixe_way(Node *node)
{
	if (node != NULL)
	{
		postfixe_way(node->left);
		postfixe_way(node->right);
		printf("%d ", node->value);
	}
}

void prefixe_way(Node *node)
{
	if (node !=NULL)
	{
		printf("%d ",node->value);
		prefixe_way(node->left);
		prefixe_way(node->right);
	}
}

void infixe_way(Node *node)
{
	if (node != NULL)
	{
		infixe_way(node->left);
		printf("%d ", node->value);
		infixe_way(node->right);
	}
}