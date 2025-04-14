#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue {
    int data[MAX];
    int frontIndex;
    int rearIndex;
} Queue;

void initializeQueue(Queue* queue) {
    queue->frontIndex = 0;
    queue->rearIndex = -1;
}

void enqueue(Queue* queue, int value) {
    if (queue->rearIndex < MAX - 1) {
        queue->data[++(queue->rearIndex)] = value;
    } else {
        printf("Fila cheia!\n");
    }
}

int dequeue(Queue* queue) {
    if (queue->frontIndex <= queue->rearIndex) {
        int value = queue->data[queue->frontIndex++];
        return value;
    }
    printf("Fila vazia!\n");
    return -1;
}

int front(Queue* queue) {
    if (queue->frontIndex <= queue->rearIndex) {
        return queue->data[queue->frontIndex];
    }
    printf("Fila vazia!\n");
    return -1;
}

int isEmpty(Queue* queue) {
    return queue->frontIndex > queue->rearIndex;
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    int value;

    printf("Digite um valor para enfileirar: ");
    scanf("%d", &value);
    enqueue(&queue, value);

    printf("Digite um valor para enfileirar: ");
    scanf("%d", &value);
    enqueue(&queue, value);

    printf("Digite um valor para enfileirar: ");
    scanf("%d", &value);
    enqueue(&queue, value);

    printf("Primeiro elemento: %d\n", front(&queue));

    printf("Removendo elemento: %d\n", dequeue(&queue));
    printf("Primeiro elemento após dequeue: %d\n", front(&queue));

    if (isEmpty(&queue)) {
        printf("A fila está vazia.\n");
    } else {
        printf("A fila não está vazia.\n");
    }

    return 0;
}
