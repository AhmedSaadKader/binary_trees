#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node
 * a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of the node or 0 otherwise
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	depth = binary_tree_depth(tree->parent);
	return (depth + 1);
}


/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two nodes
*/

binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	size_t first_depth, second_depth;
	const binary_tree_t *first_parent, *second_parent;

	if (first == NULL || second == NULL)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	first_parent = first;
	second_parent = second;

	while (second_depth > first_depth)
	{
		second_parent = second_parent->parent;
		if (second_parent == NULL)
			return (NULL);
		second_depth--;
	}

	while (first_depth > second_depth)
	{
		first_parent = first_parent->parent;
		if (first_parent == NULL)
			return (NULL);
		first_depth--;
	}

	if (first_depth == second_depth)
	{
		while (first_parent != second_parent &&
		first_parent != NULL &&
		second_parent != NULL)
		{
			first_parent = first_parent->parent;
			second_parent = second_parent->parent;
		}
	}

	return (first_parent);
}
