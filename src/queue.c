#include <stdbool.h> 
#include <stdio.h>

#define CAPACITY 10

struct Queue {
	int index_front;
	int index_back;
	int items[CAPACITY];
	int size;
};

void printQueue(struct Queue *queue) {

	if (queue->size != 0) {
		printf("=%d", queue->items[queue->index_back]);
		if (queue->size > 1) {
			for (int i = 0; i < queue->size-2; i++) {
				printf("=*");
			}
			printf("=%d", queue->items[queue->index_front]);
		}
	}
	printf("=>");

	printf("\n");

}

int peek(struct Queue *queue) {
	return queue->size != 0 ? queue->items[queue->index_front] : -1;
}

bool isFull(struct Queue *queue) {
	return queue->size >= CAPACITY;
}

bool isEmpty(struct Queue *queue) {
	return queue->size == 0;
}

void push(int data, struct Queue *queue) {

	if (isFull(queue)) {
		return;
	}

	if (queue->index_front == -1) {
		queue->index_front = 0;
	}
	queue->index_back = (queue->index_back + 1) % CAPACITY;
	queue->items[queue->index_back] = data;
	queue->size += 1;

	printQueue(queue); // For demonstration

}

void pop(struct Queue *queue) {

	if (isEmpty(queue)) {
		return;
	}

	queue->index_front = (queue->index_front + 1) % CAPACITY;
	queue->size -= 1;

	printQueue(queue); // For demonstration

}

int main () {

	struct Queue queue;
	queue.index_front = -1;
	queue.index_back = -1;
	queue.size = 0;

	printf("Front: %d\n", peek(&queue));
	for (int i = 0; i < CAPACITY; i++) {
		push(i+1, &queue);
	}
	printf("Front: %d\n", peek(&queue));
	for (int i = 0; i < CAPACITY; i++) {
		pop(&queue);
	}
	printf("Front: %d\n", peek(&queue));

	return 0;

}