#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, int data) {
    if (stack->top < MAX - 1) {
        stack->data[++(stack->top)] = data;
    } else {
        printf("Pilha cheia!\n");
    }
}

int pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
}

int top(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top];
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Topo da pilha: %d\n", top(&stack));

    printf("Removendo topo: %d\n", pop(&stack));

    printf("Topo da pilha após pop: %d\n", top(&stack));

    if (isEmpty(&stack)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("A pilha não está vazia.\n");
    }

    return 0;
}
