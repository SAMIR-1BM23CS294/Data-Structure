#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    if (!head) { printf("Empty\n"); return; }
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (!*top) { printf("Stack empty!\n"); return -1; }
    struct Node* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (!*rear) *front = *rear = newNode;
    else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(struct Node** front, struct Node** rear) {
    if (!*front) { printf("Queue empty!\n"); return -1; }
    struct Node* temp = *front;
    int data = temp->data;
    *front = temp->next;
    if (!*front) *rear = NULL;
    free(temp);
    return data;
}

int main() {
    struct Node *stackTop = NULL, *queueFront = NULL, *queueRear = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Push to Stack\n2. Pop from Stack\n3. Enqueue to Queue\n4. Dequeue from Queue\n5. Print Stack\n6. Print Queue\n7. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stackTop, data);
                break;
            case 2:
                data = pop(&stackTop);
                if (data != -1) printf("Popped from Stack: %d\n", data);
                break;
            case 3:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queueFront, &queueRear, data);
                break;
            case 4:
                data = dequeue(&queueFront, &queueRear);
                if (data != -1) printf("Dequeued from Queue: %d\n", data);
                break;
            case 5:
                printf("Stack: "); printList(stackTop);
                break;
            case 6:
                printf("Queue: "); printList(queueFront);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

