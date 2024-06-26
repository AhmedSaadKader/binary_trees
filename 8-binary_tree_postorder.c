#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary
 * tree using postorder traversal
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to call for each node,
 * the value in the node must be passed as a parameter
 * to this function
*/

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (!func)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
