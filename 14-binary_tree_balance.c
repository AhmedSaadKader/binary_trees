#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: the balance factor, 0 otherwise
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (tree == NULL)
		return (0);
	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);
	return (height_left - height_right);
}
