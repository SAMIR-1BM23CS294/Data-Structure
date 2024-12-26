#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct CircularQueue {
    int items[SIZE];
    int front;
    int rear;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue* cq = (CircularQueue*)malloc(sizeof(CircularQueue));
    cq->front = -1;
    cq->rear = -1;
    return cq;
}

int isEmpty(CircularQueue* cq) {
    return (cq->front == -1);
}

int isFull(CircularQueue* cq) {
    return ((cq->rear + 1) % SIZE == cq->front);
}

void insert(CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Queue Overflow: Cannot insert element.\n");
        return;
    }
    if (isEmpty(cq)) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % SIZE;
    cq->items[cq->rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

void delete(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue Underflow: Cannot delete element.\n");
        return;
    }
    int removedValue = cq->items[cq->front];
    if (cq->front == cq->rear) {
        cq->front = -1;
        cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % SIZE;
    }
    printf("Deleted %d from the queue.\n", removedValue);
}

void display(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    int i = cq->front;
    while (1) {
        printf("%d ", cq->items[i]);
        if (i == cq->rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue* cq = createQueue();
    int choice, value;

    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to insert: ");
                scanf("%d", &value);
                insert(cq, value);
                break;
            case 2:
                delete(cq);
                break;
            case 3:
                display(cq);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    free(cq);
    return 0;
}
