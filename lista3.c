#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertOrdered(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL || head->data >= data) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node* removeNode(Node* head, int data) {
    if (head == NULL) return NULL;

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    head = insertOrdered(head, 10);
    head = insertOrdered(head, 40);
    head = insertOrdered(head, 70);
    printList(head);

    head = insertOrdered(head, 20);
    head = insertOrdered(head, 50);
    printList(head);

    head = removeNode(head, 40);
    printList(head);

    return 0;
}
