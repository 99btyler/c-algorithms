#include <stdbool.h> 
#include <stdio.h>

#define CAPACITY 3

struct CircularQueue {
	int index_front;
	int index_back;
	int items[CAPACITY];
	int size;
};

int peek(struct CircularQueue *circularQueue);
bool isFull(struct CircularQueue *circularQueue);
bool isEmpty(struct CircularQueue *circularQueue);
void push(int data, struct CircularQueue *circularQueue);
void pop(struct CircularQueue *circularQueue);
void printCircularQueue(struct CircularQueue *circularQueue);

int main() {

	struct CircularQueue circularQueue;
	circularQueue.index_front = -1;
	circularQueue.index_back = -1;
	circularQueue.size = 0;

	printf("Data at front: %d\n", peek(&circularQueue));
	pop(&circularQueue);
	for (int i = 0; i < 2; i++) {
		for (int index = 0; index < CAPACITY; index++) {
			push(index+1, &circularQueue);
		}
		for (int index = 0; index < CAPACITY; index++) {
			pop(&circularQueue);
		}
		printf("Data at front: %d\n", peek(&circularQueue));
	}

	return 0;

}

int peek(struct CircularQueue *circularQueue) {
	return circularQueue->index_front > -1 ? circularQueue->items[circularQueue->index_front] : 0;
}

bool isFull(struct CircularQueue *circularQueue) {
	return circularQueue->size >= CAPACITY;
}

bool isEmpty(struct CircularQueue *circularQueue) {
	return circularQueue->size <= 0;
}

void push(int data, struct CircularQueue *circularQueue) {

	if (isFull(circularQueue)) {
		printf("circular-queue is full (data %d rejected)\n", data);
		return;
	}

	if (circularQueue->index_front <= -1) {
		circularQueue->index_front = 0;
	}

	circularQueue->index_back = (circularQueue->index_back + 1) % CAPACITY;
	circularQueue->items[circularQueue->index_back] = data;
	circularQueue->size += 1;

	printCircularQueue(circularQueue); // For main

}

void pop(struct CircularQueue *circularQueue) {

	if (isEmpty(circularQueue)) {
		printf("circular-queue is empty (pop rejected)\n");
		return;
	}

	circularQueue->index_front = circularQueue->size > 1 ? (circularQueue->index_front + 1) % CAPACITY : -1;
	circularQueue->size -= 1;

	printCircularQueue(circularQueue); // For main

}

void printCircularQueue(struct CircularQueue *circularQueue) {

	printf("<=");
	if (circularQueue->index_front > -1) {
		for (int i = circularQueue->index_front; i <= circularQueue->index_back; i++) {
			printf("%d=", circularQueue->items[i]);
		}
	}

	printf("\n");

}