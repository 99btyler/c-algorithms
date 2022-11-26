#include <stdbool.h> 
#include <stdio.h>

#define CAPACITY 3

struct Queue {
	int index_front;
	int index_back;
	int items[CAPACITY];
};

void printQueue(struct Queue *queue) {

	printf("<=");
	if (queue->index_front > -1) {
		for (int i = queue->index_front; i <= queue->index_back; i++) {
			printf("%d=", queue->items[i]);
		}
	}

	printf("\n");

}

int peek(struct Queue *queue) {
	return queue->items[queue->index_front];
}

bool isFull(struct Queue *queue) {
	return queue->index_back >= CAPACITY-1;
}

bool isEmpty(struct Queue *queue) {
	return queue->index_front <= -1 || queue->index_front > queue->index_back;
}

void push(int data, struct Queue *queue) {

	if (isFull(queue)) {
		printf("queue is full (data %d rejected)\n", data);
		return;
	}

	if (queue->index_front <= -1) {
		queue->index_front = 0;
	}

	queue->index_back += 1;
	queue->items[queue->index_back] = data;

	printQueue(queue); // For demonstration

}

void pop(struct Queue *queue) {

	if (isEmpty(queue)) {
		printf("stack is empty (pop rejected)\n");
		return;
	}

	queue->index_front += 1;

	printQueue(queue); // For demonstration

}

int main() {

	struct Queue queue;
	queue.index_front = -1;
	queue.index_back = -1;

	printf("Data at front: %d\n", peek(&queue));
	pop(&queue);

	push(1, &queue);
	push(2, &queue);
	push(3, &queue);
	printf("Data at front: %d\n", peek(&queue));

	pop(&queue);
	pop(&queue);
	pop(&queue);
	printf("Data at front: %d\n", peek(&queue));

	push(4, &queue);
	push(5, &queue);
	push(6, &queue);
	printf("Data at front: %d\n", peek(&queue));

	pop(&queue);
	pop(&queue);
	pop(&queue);
	printf("Data at front: %d\n", peek(&queue));

	return 0;

}