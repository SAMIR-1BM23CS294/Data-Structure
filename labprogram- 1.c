#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct Stack {
    int arr[MAX], top;
};
void initStack(struct Stack *stack) {
    stack->top = -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX - 1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int element) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
    } else {
        stack->arr[++stack->top] = element;
        printf("Pushed %d\n", element);
    }
}

void pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped %d\n", stack->arr[stack->top--]);
    }
}

void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    int choice, element;
    initStack(&stack);

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter element: ");
            scanf("%d", &element);
            push(&stack, element);
        } else if (choice == 2) {
            pop(&stack);
        } else if (choice == 3) {
            display(&stack);
        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
