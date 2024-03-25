#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent of the new node
 * @value: value of the node
 *
 * Return: a pointer to the new node or NULL on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	if (parent == NULL)
		return (new_node);
	if (parent->left == NULL)
		parent->left = new_node;
	else if (parent->right == NULL)
		parent->right = new_node;
	else
		return (NULL);

	return (new_node);
}
