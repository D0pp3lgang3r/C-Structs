#include "binary_tree.h"

int main(void)
{
	
	Node *node0 = create_node(0);
	Node *node1 = create_node(1);
	Node *node2 = create_node(2);
	Node *node3 = create_node(3);
	Node *node4 = create_node(4);
	Node *node5 = create_node(5);
	Node *node6 = create_node(6);
	Node *node7 = create_node(7);

	insert_left_children(node0, node1);
	insert_right_children(node0, node2);
	insert_left_children(node1, node3);
	insert_right_children(node1, node4);
	insert_left_children(node2, node5);
	insert_right_children(node2, node6);
	insert_right_children(node6, node7);

	printf("[+] Size of the tree: %d\n", get_number_of_nodes(node0));
	printf("[+] Number of internal nodes : %d\n", get_number_of_internal_nodes(node0));
	printf("[+] Number of leaves : %d\n", get_number_of_leaves(node0));
	printf("[+] Height of the tree : %d\n", get_height(node0));
	printf("[+] Content of the tree :\n");
	print_node(node0, ROOT);
	printf("[+] Prefixe : ");
	prefixe_way(node0);
	printf("\n");
	printf("[+] Postfixe : ");
	postfixe_way(node0);
	printf("\n");
	printf("[+] Infixe : ");
	infixe_way(node0);
	printf("\n");
	get_mirror(node0);
	printf("[+] Mirror tree content :\n");
	print_node(node0, ROOT);
	destroy_node(node0);
	return 0;
}
