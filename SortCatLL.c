#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data);
void insertAtEnd(struct Node** head_ref, int data);
void displayList(struct Node *head);
void concatenateLists(struct Node* head1, struct Node* head2);
void sortList(struct Node* head);
void buildList(struct Node** head_ref, int count, const char* listName);
void freeList(struct Node* head);

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) exit(1);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

void concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

void sortList(struct Node* head) {
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    if (head == NULL) return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void buildList(struct Node** head_ref, int count, const char* listName) {
    int data, i;
    printf("Enter %d elements for %s:\n", count, listName);
    for (i = 0; i < count; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &data) != 1) {
            printf("Invalid input. Stopping.\n");
            while(getchar() != '\n');
            break;
        }
        insertAtEnd(head_ref, data);
    }
}

int main() {
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    int n1, n2;

    printf("--- Linked List Concatenation & Sorting ---\n");


    printf("\nList 1: Enter number of nodes: ");
    if (scanf("%d", &n1) != 1 || n1 < 0) n1 = 0;
    if (n1 > 0) buildList(&head1, n1, "List 1");
    printf("List 1 created: ");
    displayList(head1);


    printf("\nList 2: Enter number of nodes: ");
    if (scanf("%d", &n2) != 1 || n2 < 0) n2 = 0;
    if (n2 > 0) buildList(&head2, n2, "List 2");
    printf("List 2 created: ");
    displayList(head2);


    printf("\n--- Concatenation ---\n");
    if (head1 != NULL) {
        concatenateLists(head1, head2);
        head2 = NULL;
        printf("Merged List: ");
        displayList(head1);
    } else if (head2 != NULL) {

        head1 = head2;
        head2 = NULL;
        printf("Merged List: ");
        displayList(head1);
    } else {
        printf("No nodes to merge.\n");
    }

    if (head1 != NULL) {
        printf("\n--- Sorting ---\n");
        sortList(head1);
        printf("Sorted List: ");
        displayList(head1);
    }


    freeList(head1);

    return 0;
}
