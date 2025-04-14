#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtStart(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;

    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
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

void countListElements(Node* head) {
    int i = 0;
    while (head != NULL) {
        head = head->next;
        i++;
    }
    printf("A lista tem %d elementos.\n", i);
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

    head = insertAtStart(head, 10);
    head = insertAtStart(head, 40);
    head = insertAtStart(head, 70);
    printList(head);

    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 50);
    printList(head);

    countListElements(head);

    head = removeNode(head, 40);
    printList(head);

    return 0;
}
