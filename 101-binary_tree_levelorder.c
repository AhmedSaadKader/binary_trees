#include "binary_trees.h"

/**
 * createQueueNode - creates a queue node
 * @tree: the inner data of nodes
 *
 * Return: New node created
*/

QueueNode *createQueueNode(const binary_tree_t *tree)
{
	QueueNode *newNode;

	newNode = malloc(sizeof(QueueNode));
	if (newNode == NULL)
		return (NULL);
	newNode->tree = (binary_tree_t *)tree;
	newNode->next = NULL;
	return (newNode);
}

/**
 * createQueue - creates a new queue
 *
 * Return: new queue
*/

Queue *createQueue()
{
	Queue *queue;

	queue = malloc(sizeof(Queue));
	if (queue == NULL)
		return (NULL);
	return (queue);
}

/**
 * enqueue - insert an element into queue
 * @queue: the queue to insert into
 * @tree: the data of the node to insert
*/

void enqueue(Queue *queue, const binary_tree_t *tree)
{
	QueueNode *newNode;

	newNode = createQueueNode(tree);
	if (queue->front == NULL)
		queue->front = queue->rear = newNode;
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

/**
 * dequeue - remove an element from queue
 * @queue: the queue to remove element from
 *
 * Return: the tree removed from queue
*/

binary_tree_t *dequeue(Queue *queue)
{
	binary_tree_t *tree;
	QueueNode *temp;

	if (queue->front == NULL)
		return (NULL);
	tree = queue->front->tree;
	temp = queue->front;
	queue->front = queue->front->next;
	free(temp);
	return (tree);
}


/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root of the tree to traverse
 * @func: pointer to the function to call for each node.
 * The value in the node must be passed as a parameter to
 * this function
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	Queue *queue;
	const binary_tree_t *temp_node;

	if (tree == NULL || func == NULL)
		return;
	queue = createQueue();
	enqueue(queue, tree);
	while (queue->front)
	{
		temp_node = dequeue(queue);
		if (temp_node->left)
			enqueue(queue, temp_node->left);
		if (temp_node->right)
			enqueue(queue, temp_node->right);
		func(temp_node->n);
	}
}
