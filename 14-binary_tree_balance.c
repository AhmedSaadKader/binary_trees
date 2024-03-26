#include "binary_trees.h"


/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree or 0 if tree is NULL
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);
	if ((tree->left == NULL && tree->right == NULL))
		return (1);
	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	if (height_left >= height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}


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
