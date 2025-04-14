#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct CustomerQueue {
    int data[MAX];
    int front, rear;
};

void initializeQueue(struct CustomerQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(struct CustomerQueue *queue) {
    return (queue->front == -1);
}

int isQueueFull(struct CustomerQueue *queue) {
    return (queue->front == (queue->rear + 1) % MAX);
}

void enqueue(struct CustomerQueue *queue, int customerId) {
    if (isQueueFull(queue)) {
        printf("Fila cheia! Não é possível inserir o cliente.\n");
        return;
    }

    if (isQueueEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = customerId;
    printf("Cliente %d entrou na fila de atendimento.\n", customerId);
}

int dequeue(struct CustomerQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Fila vazia! Não há clientes para atender.\n");
        return -1;
    }

    int servedCustomer = queue->data[queue->front];
    
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    
    printf("Cliente %d foi atendido.\n", servedCustomer);
    return servedCustomer;
}

void displayQueue(struct CustomerQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Clientes na fila: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue->data[queue->rear]);
}

int main() {
    struct CustomerQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 101);
    enqueue(&queue, 102);
    enqueue(&queue, 103);
    displayQueue(&queue);

    dequeue(&queue);
    displayQueue(&queue);

    enqueue(&queue, 104);
    enqueue(&queue, 105);
    enqueue(&queue, 106);
    displayQueue(&queue);

    return 0;
}
