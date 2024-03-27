#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: size of the tree or 0 if tree is NULL
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_left = 0, size_right = 0;

	if (tree == NULL)
		return (0);

	size_left = binary_tree_size(tree->left);
	size_right = binary_tree_size(tree->right);

	return (size_left + size_right + 1);
}

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
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: number of leaves, 0 otherwise
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_left, leaves_right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL || tree->right == NULL)
		return (1);

	leaves_left = binary_tree_leaves(tree->left);
	leaves_right = binary_tree_leaves(tree->right);

	return (leaves_left + leaves_right);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_height, tree_leaves, tree_size;
	size_t expected_nodes, expected_leaves;

	if (tree == NULL)
		return (0);

	tree_size = binary_tree_size(tree);
	tree_height = binary_tree_height(tree);
	tree_leaves = binary_tree_leaves(tree);

	expected_nodes = (1 << tree_height) - 1;
	expected_leaves = (1 << (tree_height - 1));

	if (tree_size != expected_nodes)
		return (0);
	if (tree_leaves != expected_leaves)
		return (0);

	return (1);
}
