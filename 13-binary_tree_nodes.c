#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at
 * least 1 child in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: the count of the nodes, otherwise 0
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes_left, nodes_right;

	if (tree == NULL)
		return (0);

	if ((tree->left != NULL || tree->right != NULL))
		return (1);

	nodes_left = binary_tree_nodes(tree->left);
	nodes_right = binary_tree_nodes(tree->right);

	return (nodes_left + nodes_right + 1);
}
