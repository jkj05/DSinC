#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void inserttoleft(int value, int pos) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != pos)
        temp = temp->next;
    if (temp == NULL)
        return;

    struct Node *newNode = createNode(value);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;
    temp->prev = newNode;
}

void deleteNode(int value) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

void display() {
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert to Left of Value\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(value);
        }
        else if (choice == 2) {
            printf("Enter value and position value: ");
            scanf("%d%d", &value, &pos);
            inserttoleft(value, pos);
        }
        else if (choice == 3) {
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
        }
        else if (choice == 4) {
            display();
        }
        else if (choice == 5) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
