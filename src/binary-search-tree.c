#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *leftNode;
	struct Node *rightNode;
};

struct Node* search(int data, struct Node **rootNode);
struct Node* recursive_search(int data, struct Node *node);
void insert(int data, struct Node **rootNode);
struct Node* recursive_insert(int data, struct Node *node);
void delete(int data, struct Node **rootNode);
struct Node* recursive_delete(int data, struct Node *node);
void printBinarySearchTree(struct Node **rootNode);
void recursive_printBinarySearchTree(struct Node *node);

int main() {

	struct Node *rootNode = NULL;

	insert(4, &rootNode);
	insert(2, &rootNode);
	insert(5, &rootNode);
	insert(1, &rootNode);
	insert(3, &rootNode);
	insert(6, &rootNode);
	printf("Data 3 exists: %d\n", search(3, &rootNode) != NULL ? 1 : 0);
	printf("Data 99 exists: %d\n", search(99, &rootNode) != NULL ? 1 : 0);
	delete(2, &rootNode);

	return 0;

}

struct Node* search(int data, struct Node **rootNode) {

	return recursive_search(data, *rootNode);

}

struct Node* recursive_search(int data, struct Node *node) {

	if (node == NULL || node->data == data) {

		return node;

	} else {

		if (data < node->data) {
			return recursive_search(data, node->leftNode);
		} else if (data > node->data) {
			return recursive_search(data, node->rightNode);
		}

		return node;

	}

}

void insert(int data, struct Node **rootNode) {

	*rootNode = recursive_insert(data, *rootNode);

	printBinarySearchTree(rootNode); // For main

}

struct Node* recursive_insert(int data, struct Node *node) {

	if (node == NULL) {

		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->leftNode = NULL;
		newNode->rightNode = NULL;

		return newNode;

	} else {

		if (data < node->data) {
			node->leftNode = recursive_insert(data, node->leftNode);
		} else if (data > node->data) {
			node->rightNode = recursive_insert(data, node->rightNode);
		}

		return node;

	}

}

void delete(int data, struct Node **rootNode) {

	*rootNode = recursive_delete(data, *rootNode);

	printBinarySearchTree(rootNode); // For main

}

struct Node* recursive_delete(int data, struct Node *node) {

	if (node == NULL) {

		return node;

	} else {

		if (data < node->data) {
			node->leftNode = recursive_delete(data, node->leftNode);
		} else if (data > node->data) {
			node->rightNode = recursive_delete(data, node->rightNode);
		} else {

			if (node->leftNode == NULL) {

				struct Node *rightNode = node->rightNode;
				free(node);
				node = NULL;

				return rightNode;

			} else if (node->rightNode == NULL) {

				struct Node *leftNode = node->leftNode;
				free(node);
				node = NULL;

				return leftNode;

			} else {

				struct Node *maxLeftNode = node->leftNode;
				while (maxLeftNode->rightNode != NULL) {
					maxLeftNode = maxLeftNode->rightNode;
				}
				node->data = maxLeftNode->data;

				node->leftNode = recursive_delete(maxLeftNode->data, node->leftNode);

			}

		}

		return node;

	}

}

void printBinarySearchTree(struct Node **rootNode) {

	recursive_printBinarySearchTree(*rootNode);

	printf("\n");

}

void recursive_printBinarySearchTree(struct Node *node) {

	if (node == NULL) {
		return;
	}

	recursive_printBinarySearchTree(node->leftNode);
	printf("[%d]%d[%d] ", (node->leftNode != NULL ? node->leftNode->data : 0), node->data, (node->rightNode != NULL ? node->rightNode->data : 0));
	recursive_printBinarySearchTree(node->rightNode);

}
