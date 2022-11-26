#include <stdbool.h> 
#include <stdio.h>

#define CAPACITY 3

struct Stack {
	int index_top;
	int items[CAPACITY];
};

int peek(struct Stack *stack);
bool isFull(struct Stack *stack);
bool isEmpty(struct Stack *stack);
void push(int data, struct Stack *stack);
void pop(struct Stack *stack);
void printStack(struct Stack *stack);

int main() {

	struct Stack stack;
	stack.index_top = -1;

	printf("Data at top: %d\n", peek(&stack));
	pop(&stack);
	for (int i = 0; i < 2; i++) {
		for (int index = 0; index < CAPACITY; index++) {
			push(index+1, &stack);
		}
		printf("Data at top: %d\n", peek(&stack));
		for (int index = 0; index < CAPACITY; index++) {
			pop(&stack);
		}
		printf("Data at top: %d\n", peek(&stack));
	}

	return 0;

}

int peek(struct Stack *stack) {
	return stack->index_top > -1 ? stack->items[stack->index_top] : 0;
}

bool isFull(struct Stack *stack) {
	return stack->index_top >= CAPACITY-1;
}

bool isEmpty(struct Stack *stack) {
	return stack->index_top <= -1;
}

void push(int data, struct Stack *stack) {

	if (isFull(stack)) {
		printf("stack is full (data %d rejected)\n", data);
		return;
	}

	stack->index_top += 1;
	stack->items[stack->index_top] = data;

	printStack(stack); // For main

}

void pop(struct Stack *stack) {

	if (isEmpty(stack)) {
		printf("stack is empty (pop rejected)\n");
		return;
	}

	stack->index_top -= 1;

	printStack(stack); // For main

}

void printStack(struct Stack *stack) {

	for (int i = 0; i <= stack->index_top; i++) {
		printf("=%d", stack->items[i]);
	}
	printf("=>");

	printf("\n");

}