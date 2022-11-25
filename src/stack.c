#include <stdbool.h> 
#include <stdio.h>

#define CAPACITY 3

struct Stack {
	int index_top;
	int items[CAPACITY];
};

void printStack(struct Stack *stack) {

	for (int i = 0; i <= stack->index_top; i++) {
		printf("%d=>", stack->items[i]);
	}

	printf("\n");

}

int peek(struct Stack *stack) {
	return stack->items[stack->index_top];
}

bool isFull(struct Stack *stack) {
	return stack->index_top == CAPACITY-1;
}

bool isEmpty(struct Stack *stack) {
	return stack->index_top == -1;
}

void push(int data, struct Stack *stack) {

	if (isFull(stack)) {
		return;
	}

	stack->index_top += 1;
	stack->items[stack->index_top] = data;

	printStack(stack); // For demonstration

}

void pop(struct Stack *stack) {

	if (isEmpty(stack)) {
		return;
	}

	stack->index_top -= 1;

	printStack(stack); // For demonstration

}

int main() {

	struct Stack stack;
	stack.index_top = -1;

	push(1, &stack);
	push(2, &stack);
	push(3, &stack);
	printf("Top is: %d\n", peek(&stack));
	pop(&stack);
	printf("Top is: %d\n", peek(&stack));
	pop(&stack);
	pop(&stack);

	return 0;

}