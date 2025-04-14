#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int data[MAX];
    int front, rear;
};

struct Stack {
    int data[MAX];
    int top;
};

void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isQueueEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

int isQueueFull(struct Queue *queue) {
    return (queue->rear == MAX - 1);
}

int isStackEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int isStackFull(struct Stack *stack) {
    return (stack->top == MAX - 1);
}

void enqueue(struct Queue *queue, int value) {
    if (isQueueFull(queue)) {
        printf("Fila cheia! Não é possível inserir o elemento.\n");
        return;
    }

    if (isQueueEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1);
    queue->data[queue->rear] = value;
    printf("Elemento %d inserido na fila.\n", value);
}

int dequeue(struct Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Fila vazia! Não é possível remover elementos.\n");
        return -1;
    }

    int removed = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1);
    }

    printf("Elemento %d removido da fila.\n", removed);
    return removed;
}

void displayQueue(struct Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Elementos na fila: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

void push(struct Stack *stack, int value) {
    if (isStackFull(stack)) {
        printf("Pilha cheia! Não é possível empurrar o elemento.\n");
        return;
    }

    stack->data[++stack->top] = value;
}

int pop(struct Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Pilha vazia! Não há elementos para remover.\n");
        return -1;
    }

    return stack->data[stack->top--];
}

void reverseQueue(struct Queue *queue) {
    struct Stack stack;
    initializeStack(&stack);

    while (!isQueueEmpty(queue)) {
        push(&stack, dequeue(queue));
    }

    while (!isStackEmpty(&stack)) {
        enqueue(queue, pop(&stack));
    }

    printf("Fila invertida!\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    displayQueue(&queue);

    reverseQueue(&queue);
    displayQueue(&queue);

    return 0;
}
