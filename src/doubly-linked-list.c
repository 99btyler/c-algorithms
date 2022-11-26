#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *nextNode;
	struct Node *previousNode;
};

int get(int index, struct Node **headNode);
int indexOf(int data, struct Node **headNode);
bool contains(int data, struct Node **headNode);
int size(struct Node **headNode);
void add(int data, struct Node **headNode);
void insert(int index, int data, struct Node **headNode);
void removeIndex(int index, struct Node **headNode);
void removeData(int data, struct Node **headNode);
void clear(struct Node **headNode);
void printDoublyLinkedList(struct Node *node);

int main() {

	struct Node *headNode = NULL;

	add(1, &headNode);
	add(2, &headNode);
	add(3, &headNode);
	printf("Data at index 1: %d\n", get(1, &headNode));
	removeIndex(1, &headNode);
	insert(1, 99, &headNode);
	printf("Index of 99: %d\n", indexOf(99, &headNode));
	removeData(99, &headNode);
	printf("Size: %d\n", size(&headNode));
	printf("Contains 99: %d\n", contains(99, &headNode));
	clear(&headNode);

	return 0;

}

int get(int index, struct Node **headNode) {

	struct Node *indexNode = *headNode;
	int i = 0;
	while (indexNode != NULL) {
		if (i == index) {
			return indexNode->data;
		}
		indexNode = indexNode->nextNode;
		i += 1;
	}

	return 0;

}

int indexOf(int data, struct Node **headNode) {

	struct Node* dataNode = *headNode;
	int i = 0;
	while (dataNode != NULL) {
		if (dataNode->data == data) {

			return i;

		}
		dataNode = dataNode->nextNode;
		i += 1;
	}

	return -1;

}

bool contains(int data, struct Node **headNode) {

	struct Node *dataNode = *headNode;
	while (dataNode != NULL) {
		if (dataNode->data == data) {

			return true;

		}
		dataNode = dataNode->nextNode;
	}

	return false;

}

int size(struct Node **headNode) {

	struct Node *node = *headNode;
	int i = 0;
	while (node != NULL) {
		node = node->nextNode;
		i += 1;
	}

	return i;

}

void add(int data, struct Node **headNode) {

	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;

	if (*headNode == NULL) {

		newNode->previousNode = NULL;
		newNode->nextNode = NULL;
		*headNode = newNode;

	} else {

		struct Node *lastNode = *headNode;
		while (lastNode->nextNode != NULL) {
			lastNode = lastNode->nextNode;
		}

		lastNode->nextNode = newNode;
		newNode->previousNode = lastNode;
		newNode->nextNode = NULL;

	}

	printDoublyLinkedList(*headNode); // For main

}

void insert(int index, int data, struct Node **headNode) {

	if (index == 0) {

		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = data;

		newNode->previousNode = NULL;
		newNode->nextNode = *headNode;
		(*headNode)->previousNode = newNode;
		*headNode = newNode;

	} else {

		if (*headNode == NULL) {
			return;
		}

		struct Node *preIndexNode = *headNode;
		int i = 0;
		while (preIndexNode != NULL) {
			if (i == index-1) {

				struct Node *indexNode = preIndexNode->nextNode;

				struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
				newNode->data = data;

				preIndexNode->nextNode = newNode;
				newNode->previousNode = preIndexNode;
				newNode->nextNode = indexNode;
				if (indexNode != NULL) {
					indexNode->previousNode = newNode;
				}

			}
			preIndexNode = preIndexNode->nextNode;
			i += 1;
		}

	}

	printDoublyLinkedList(*headNode); // For main

}

void removeIndex(int index, struct Node **headNode) {

	if (*headNode == NULL) {
		return;
	}

	if (index == 0) {

		struct Node *indexNode = *headNode;

		*headNode = (*headNode)->nextNode;
		(*headNode)->previousNode = NULL;
		free(indexNode);
		indexNode = NULL;

	} else {

		struct Node *preIndexNode = *headNode;
		int i = 0;
		while (preIndexNode != NULL) {
			if (i == index-1 && preIndexNode->nextNode != NULL) {

				struct Node *indexNode = preIndexNode->nextNode;
				struct Node *postIndexNode = indexNode->nextNode;

				preIndexNode->nextNode = indexNode->nextNode;
				if (postIndexNode != NULL) {
					postIndexNode->previousNode = preIndexNode;
					free(indexNode);
					indexNode = NULL;
				}

			}
			preIndexNode = preIndexNode->nextNode;
			i += 1;
		}

	}

	printDoublyLinkedList(*headNode); // For main

}

void removeData(int data, struct Node **headNode) {

	if (*headNode == NULL) {
		return;
	}

	if (data == (*headNode)->data) {

		struct Node *dataNode = *headNode;

		*headNode = (*headNode)->nextNode;
		(*headNode)->previousNode = NULL;
		free(dataNode);
		dataNode = NULL;

	} else {

		struct Node *preDataNode = *headNode;
		while (preDataNode != NULL) {
			if (preDataNode->nextNode != NULL && preDataNode->nextNode->data == data) {

				struct Node *dataNode = preDataNode->nextNode;
				struct Node *postDataNode = dataNode->nextNode;

				preDataNode->nextNode = postDataNode;
				if (postDataNode != NULL) {
					postDataNode->previousNode = preDataNode;
					free(dataNode);
					dataNode = NULL;
				}

			}
			preDataNode = preDataNode->nextNode;
		}

	}

	printDoublyLinkedList(*headNode); // For main

}

void clear(struct Node **headNode) {

	if (*headNode == NULL) {
		return;
	}

	struct Node *node = *headNode;
	while (node != NULL) {

		struct Node *previousNode = node;
		node = node->nextNode;
		free(previousNode);
		previousNode = NULL;

	}

	*headNode = NULL;

	printDoublyLinkedList(*headNode); // For main

}

void printDoublyLinkedList(struct Node *node) {

	while (node != NULL) {
		printf("[%d]%d[%d] ", (node->previousNode != NULL ? node->previousNode->data : 0), node->data, (node->nextNode != NULL ? node->nextNode->data : 0));
		node = node->nextNode;
	}

	printf("\n");

}