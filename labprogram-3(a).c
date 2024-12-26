#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Unable to insert %d.\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("%d inserted into the queue.\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Empty! Unable to delete an element.\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    printf("%d deleted from the queue.\n", item);
    return item;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = CreateQueue();
    int choice, value;

    do {
        printf("\nQueue Menu:\n");
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
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    free(q);
    return 0;
}
