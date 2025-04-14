#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAX 100

typedef struct Stack {
    char data[MAX];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, char value) {
    if (stack->top < MAX - 1) {
        stack->data[++(stack->top)] = value;
    }
}

char pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    }
    return '\0';
}

void reverseString(const char* str) {
    Stack stack;
    initializeStack(&stack);

    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }

    while (stack.top >= 0) {
        cout << pop(&stack);
    }
    cout << endl;
}

int main() {
    const char* str = "Hello, World!";
    reverseString(str);
    return 0;
}
