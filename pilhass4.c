#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, int value) {
    if (stack->top < MAX - 1) {
        stack->data[++(stack->top)] = value;
    }
}

int pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    }
    return -1;
}

void decimalToBinary(int number) {
    Stack stack;
    initializeStack(&stack);

    if (number == 0) {
        printf("0\n");
        return;
    }

    while (number > 0) {
        push(&stack, number % 2);
        number /= 2;
    }

    while (stack.top >= 0) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main() {
    int number1 = 10;
    int number2 = 25;

    decimalToBinary(number1);
    decimalToBinary(number2);

    return 0;
}
