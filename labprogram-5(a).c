
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list
void createList(struct Node** head) {
    int n, data;
    struct Node* temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// Function to delete the first element
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. No element to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First element deleted.\n");
}

// Function to delete a specified element
void deleteSpecified(struct Node** head, int element) {
    if (*head == NULL) {
        printf("List is empty. No element to delete.\n");
        return;
    }

    struct Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == element) {
        *head = temp->next;
        free(temp);
        printf("Element %d deleted.\n", element);
        return;
    }

    while (temp != NULL && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", element);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Element %d deleted.\n", element);
}

// Function to delete the last element
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. No element to delete.\n");
        return;
    }

    struct Node *temp = *head, *prev = NULL;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("Last element deleted.\n");
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last element deleted.\n");
}

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specified Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                deleteFirst(&head);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                deleteSpecified(&head, element);
                break;
            case 4:
                deleteLast(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
