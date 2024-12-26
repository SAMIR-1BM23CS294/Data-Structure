#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    if (*head) (*head)->prev = newNode;
    *head = newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) *head = newNode;
    else {
        Node *temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtPosition(Node **head, int data, int pos) {
    if (pos == 1) return insertAtBeginning(head, data);
    Node *newNode = createNode(data);
    Node *temp = *head;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
    if (temp == NULL) return;  // Invalid position
    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void display(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                display(head);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
