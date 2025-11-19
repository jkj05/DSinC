#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head_ref, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) exit(1);
    newNode->data = data;
    newNode->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void build(struct Node** head_ref, int n) {
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &data) != 1) {
            printf("Invalid input. Stopping.\n");
            while(getchar() != '\n');
            break;
        }
        insert(head_ref, data);
    }
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("Empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}


struct Node* deleteFront(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}


struct Node* push(struct Node* top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}


struct Node* enqueue(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}


void concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return;
    struct Node* temp = head1;
    while (temp->next != NULL) temp = temp->next;
    temp->next = head2;
}

void sort(struct Node* head) {
    if (head == NULL) return;
    for (struct Node* i = head; i->next != NULL; i = i->next) {
        for (struct Node* j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n1, n2, value;
    int choice;

    printf("--- Combined Linked List Operations ---\n");


    printf("\nList 1: Enter number of nodes: ");
    if (scanf("%d", &n1) != 1 || n1 < 0) n1 = 0;
    build(&head1, n1);

    printf("List 2: Enter number of nodes: ");
    if (scanf("%d", &n2) != 1 || n2 < 0) n2 = 0;
    build(&head2, n2);

    printf("\n--- Initial Lists ---\n");
    printf("List 1: "); display(head1);
    printf("List 2: "); display(head2);

    do {
        printf("\n---- Menu ----\n");
        printf("1. Concatenate List 2 to List 1\n");
        printf("2. Sort List 1\n");
        printf("3. Reverse List 1\n");
        printf("4. Stack Push (to List 1 head)\n");
        printf("5. Stack/Queue Pop (from List 1 head)\n");
        printf("6. Queue Enqueue (to List 1 tail)\n");
        printf("7. Display List 1\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) { while(getchar() != '\n'); choice = 0; }

        switch (choice) {
            case 1:
                concatenate(head1, head2);
                head2 = NULL;
                printf("Concatenated List: "); display(head1);
                break;
            case 2:
                sort(head1);
                printf("Sorted List: "); display(head1);
                break;
            case 3:
                head1 = reverse(head1);
                printf("Reversed List: "); display(head1);
                break;
            case 4:
                printf("Value to Push: "); scanf("%d", &value);
                head1 = push(head1, value);
                printf("Pushed to head.\n");
                break;
            case 5:
                if (head1 == NULL) { printf("List empty (Pop/Dequeue failed).\n"); }
                else {
                    printf("Popped/Dequeued: %d\n", head1->data);
                    head1 = deleteFront(head1);
                }
                break;
            case 6:
                printf("Value to Enqueue: "); scanf("%d", &value);
                head1 = enqueue(head1, value);
                printf("Enqueued to tail.\n");
                break;
            case 7:
                printf("Current List 1: "); display(head1);
                break;
            case 8:
                freeList(head1);
                freeList(head2);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}
