#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *nextNode;
};

void printSinglyLinkedList(struct Node *node) {

	while (node != NULL) {
		printf("%d[%d] ", node->data, (node->nextNode != NULL ? node->nextNode->data : 0));
		node = node->nextNode;
	}

	printf("\n");

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

int size(struct Node **headNode) {

	struct Node *node = *headNode;
	int i = 0;
	while (node != NULL) {
		node = node->nextNode;
		i += 1;
	}

	return i;

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

void add(int data, struct Node **headNode) {

	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->nextNode = NULL;

	if (*headNode == NULL) {

		*headNode = newNode;

	} else {

		struct Node *lastNode = *headNode;
		while (lastNode->nextNode != NULL) {
			lastNode = lastNode->nextNode;
		}

		lastNode->nextNode = newNode;

	}

	printSinglyLinkedList(*headNode); // For demonstration

}

void insert(int index, int data, struct Node **headNode) {

	if (index == 0) {

		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = data;
		
		newNode->nextNode = *headNode;
		*headNode = newNode;

	} else {

		struct Node *preIndexNode = *headNode;
		int i = 0;
		while (preIndexNode != NULL) {
			if (i == index-1) {

				struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
				newNode->data = data;

				struct Node *indexNode = preIndexNode->nextNode;

				preIndexNode->nextNode = newNode;
				newNode->nextNode = indexNode;

			}
			preIndexNode = preIndexNode->nextNode;
			i += 1;
		}

	}

	printSinglyLinkedList(*headNode); // For demonstration

}

void removeIndex(int index, struct Node **headNode) {

	if (index == 0) {

		struct Node *indexNode = *headNode;

		*headNode = (*headNode)->nextNode;
		free(indexNode);
		indexNode = NULL;

	} else {

		struct Node *preIndexNode = *headNode;
		int i = 0;
		while (preIndexNode != NULL) {
			if (i == index-1 && preIndexNode->nextNode != NULL) {

				struct Node *indexNode = preIndexNode->nextNode;

				preIndexNode->nextNode = indexNode->nextNode;
				free(indexNode);
				indexNode = NULL;
				break;

			}
			preIndexNode = preIndexNode->nextNode;
			i += 1;
		}

	}

	printSinglyLinkedList(*headNode); // For demonstration

}

void removeData(int data, struct Node **headNode) {

	if (data == (*headNode)->data) {

		struct Node *dataNode = *headNode;

		*headNode = (*headNode)->nextNode;
		free(dataNode);
		dataNode = NULL;

	} else {

		struct Node *preDataNode = *headNode;
		while (preDataNode != NULL) {
			if (preDataNode->nextNode != NULL && preDataNode->nextNode->data == data) {

				struct Node *dataNode = preDataNode->nextNode;

				preDataNode->nextNode = dataNode->nextNode;
				free(dataNode);
				dataNode = NULL;
				break;

			}
			preDataNode = preDataNode->nextNode;
		}

	}

	printSinglyLinkedList(*headNode); // For demonstration

}

void clear(struct Node **headNode) {

	struct Node *node = *headNode;
	while (node != NULL) {

		struct Node *previousNode = node;
		node = node->nextNode;
		free(previousNode);
		previousNode = NULL;

	}

	*headNode = NULL;

	printSinglyLinkedList(*headNode); // For demonstration

}

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