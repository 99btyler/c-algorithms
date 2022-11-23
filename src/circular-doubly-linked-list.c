#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *nextNode;
	struct Node *previousNode;
};

void printCircularDoublyLinkedList(struct Node *node) {

	struct Node *startingNode = node;
	while (node != NULL) {
		printf("[%d]%d[%d] ", (node->previousNode != NULL ? node->previousNode->data : 0), node->data, (node->nextNode != NULL ? node->nextNode->data : 0));
		node = node->nextNode;
		if (node == startingNode) {
			break;
		}
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
		if (indexNode == *headNode) {
			break;
		}
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
		if (dataNode == *headNode) {
			break;
		}
	}

	return -1;

}

int size(struct Node **headNode) {

	struct Node *node = *headNode;
	int i = 0;
	while (node != NULL) {
		node = node->nextNode;
		i += 1;
		if (node == *headNode) {
			break;
		}
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
		if (dataNode == *headNode) {
			break;
		}
	}

	return false;

}

void add(int data, struct Node **headNode) {

	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;

	if (*headNode == NULL) {

		newNode->previousNode = newNode;
		newNode->nextNode = newNode;
		*headNode = newNode;

	} else {

		struct Node *lastNode = (*headNode)->previousNode;

		lastNode->nextNode = newNode;
		newNode->previousNode = lastNode;
		newNode->nextNode = *headNode;
		(*headNode)->previousNode = newNode;

	}

	printCircularDoublyLinkedList(*headNode); // For demonstration

}

void insert(int index, int data, struct Node **headNode) {

	if (index == 0) {

		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = data;

		struct Node *lastNode = (*headNode)->previousNode;

		newNode->previousNode = lastNode;
		newNode->nextNode = *headNode;
		(*headNode)->previousNode = newNode;
		lastNode->nextNode = newNode;
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
				newNode->previousNode = preIndexNode;
				newNode->nextNode = indexNode;
				indexNode->previousNode = newNode;

			}
			preIndexNode = preIndexNode->nextNode;
			i += 1;
			if (preIndexNode == *headNode) {
				break;
			}
		}

	}

	printCircularDoublyLinkedList(*headNode); // For demonstration

}

void removeIndex(int index, struct Node **headNode) {

	if (*headNode == NULL) {
		return;
	}

	if (index == 0) {

		struct Node *indexNode = *headNode;
		struct Node *lastNode = (*headNode)->previousNode;

		*headNode = (*headNode)->nextNode;
		(*headNode)->previousNode = lastNode;
		lastNode->nextNode = *headNode;
		free(indexNode);
		indexNode = NULL;

	} else {

		struct Node *preIndexNode = *headNode;
		int i = 0;
		while (preIndexNode != NULL) {
			if (i == index-1) {

				struct Node *indexNode = preIndexNode->nextNode;
				struct Node *postIndexNode = indexNode->nextNode;

				preIndexNode->nextNode = postIndexNode;
				postIndexNode->previousNode = preIndexNode;
				free(indexNode);
				indexNode = NULL;
				break;

			}
			preIndexNode = preIndexNode->nextNode;
			i += 1;
			if (preIndexNode->nextNode == *headNode) {
				break;
			}
		}

	}

	printCircularDoublyLinkedList(*headNode); // For demonstration

}

void removeData(int data, struct Node **headNode) {

	if (*headNode == NULL) {
		return;
	}

	if (data == (*headNode)->data) {

		struct Node *dataNode = *headNode;
		struct Node *lastNode = (*headNode)->previousNode;

		*headNode = (*headNode)->nextNode;
		(*headNode)->previousNode = lastNode;
		lastNode->nextNode = *headNode;
		free(dataNode);
		dataNode = NULL;

	} else {

		struct Node *preDataNode = *headNode;
		while (preDataNode != NULL) {
			if (preDataNode->nextNode != NULL && preDataNode->nextNode->data == data) {

				struct Node *dataNode = preDataNode->nextNode;
				struct Node *postDataNode = dataNode->nextNode;

				preDataNode->nextNode = postDataNode;
				postDataNode->previousNode = preDataNode;
				free(dataNode);
				dataNode = NULL;
				break;

			}
			preDataNode = preDataNode->nextNode;
			if (preDataNode == *headNode) {
				break;
			}
		}

	}

	printCircularDoublyLinkedList(*headNode); // For demonstration

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
		if (node == *headNode) {
			break;
		}

	}

	*headNode = NULL;

	printCircularDoublyLinkedList(*headNode); // For demonstration

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