#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *leftNode;
	struct Node *rightNode;
};

struct Node* get(int data, struct Node *node);
struct Node* add(int data, struct Node *node);
struct Node* removeData(int data, struct Node *node);
void printBinarySearchTree(struct Node *node);

int main() {

	struct Node *rootNode = NULL;

	rootNode = add(4, rootNode);
	rootNode = add(2, rootNode);
	rootNode = add(5, rootNode);
	rootNode = add(1, rootNode);
	rootNode = add(3, rootNode);
	rootNode = add(6, rootNode);

	printBinarySearchTree(rootNode);
	printf("\n");

	struct Node *dataNode = get(3, rootNode);
	printf("Data 3: %d\n", dataNode != NULL ? dataNode->data : 0);
	dataNode = get(99, rootNode);
	printf("Data 99: %d\n", dataNode != NULL ? dataNode->data : 0);

	rootNode = removeData(2, rootNode);

	printBinarySearchTree(rootNode);
	printf("\n");

	return 0;

}

struct Node* get(int data, struct Node *node) {

	if (node == NULL || node->data == data) {

		return node;

	} else {

		if (data < node->data) {
			return get(data, node->leftNode);
		} else if (data > node->data) {
			return get(data, node->rightNode);
		}

		return node;

	}

}

struct Node* add(int data, struct Node *node) {

	if (node == NULL) {

		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->leftNode = NULL;
		newNode->rightNode = NULL;

		return newNode;

	} else {

		if (data < node->data) {
			node->leftNode = add(data, node->leftNode);
		} else if (data > node->data) {
			node->rightNode = add(data, node->rightNode);
		}

		return node;

	}

}

struct Node* removeData(int data, struct Node *node) {

	if (node == NULL) {

		return node;

	} else {

		if (data < node->data) {
			node->leftNode = removeData(data, node->leftNode);
		} else if (data > node->data) {
			node->rightNode = removeData(data, node->rightNode);
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

				node->leftNode = removeData(maxLeftNode->data, node->leftNode);

			}

		}

		return node;

	}

}

void printBinarySearchTree(struct Node *node) {

	if (node == NULL) {
		return;
	}

	printBinarySearchTree(node->leftNode);
	printf("[%d]%d[%d] ", (node->leftNode != NULL ? node->leftNode->data : 0), node->data, (node->rightNode != NULL ? node->rightNode->data : 0));
	printBinarySearchTree(node->rightNode);

}
