
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

void insert(struct Node** head, int data) {
    struct Node* temp = *head, *newNode = createNode(data);
    if (!*head) { *head = newNode; return; }
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    if (!head) return;
    struct Node *i, *j;
    for (i = head; i; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data; i->data = j->data; j->data = temp;
            }
        }
    }
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concatenate(struct Node** head1, struct Node* head2) {
    if (!*head1) { *head1 = head2; return; }
    struct Node* temp = *head1;
    while (temp->next) temp = temp->next;
    temp->next = head2;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int n, m, data;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n);
    printf("Enter elements for List 1: ");
    while (n--) { scanf("%d", &data); insert(&list1, data); }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &m);
    printf("Enter elements for List 2: ");
    while (m--) { scanf("%d", &data); insert(&list2, data); }

    printf("\nOriginal List 1: "); printList(list1);
    printf("Original List 2: "); printList(list2);

    sortList(list1);
    printf("Sorted List 1: "); printList(list1);

    reverseList(&list1);
    printf("Reversed List 1: "); printList(list1);

    concatenate(&list1, list2);
    printf("Concatenated List: "); printList(list1);

    return 0;
}
