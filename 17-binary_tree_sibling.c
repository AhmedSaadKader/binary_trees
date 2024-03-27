#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling node
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent_node, *sibling;

	parent_node = node->parent;

	if (node == NULL || parent_node == NULL)
		return (NULL);

	if (node == parent_node->left)
		sibling = parent_node->right;
	else
		sibling = parent_node->left;

	return (sibling);
}
