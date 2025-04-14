#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int data[MAX];
    int front, rear;
};

void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

int isQueueFull(struct Queue *queue) {
    return (queue->front == (queue->rear + 1) % MAX);
}

void enqueue(struct Queue *queue, int value) {
    if (isQueueFull(queue)) {
        printf("Fila cheia! Não é possível inserir o elemento.\n");
        return;
    }

    if (isQueueEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX;
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
        queue->front = (queue->front + 1) % MAX;
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
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue->data[queue->rear]);
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    displayQueue(&queue);

    dequeue(&queue);
    displayQueue(&queue);

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);
    displayQueue(&queue);

    return 0;
}
