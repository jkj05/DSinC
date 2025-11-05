#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head = NULL;

void createList(int n);
void insertAtBeginning(int data);
void insertAtPosition(int data, int position);
int insertAtEnd(int data);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int position);
void displayList();

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void createList(int n) {
    int data, i;
    struct Node *newNode, *temp;

    if (n <= 0) {
        printf("No nodes to create.\n");
        return;
    }
    struct Node *current = head;
    struct Node *next;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;

    for(i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        if (scanf("%d", &data) != 1) {
             printf("Invalid data input. Stopping list creation.\n");
             while(getchar() != '\n');
             break;
        }

        newNode = createNode(data);

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;

    printf("Node inserted at the beginning successfully.\n");
}

int insertAtEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        printf("Node inserted at the end successfully.\n");
        return 1;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Node inserted at the end successfully.\n");
    return 1;
}

void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Position must be 1 or greater.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at position 1 (Beginning) successfully.\n");
        return;
    }

    struct Node* temp = head;
    int i;

    for (i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of range. Node not inserted.\n", position);
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d successfully.\n", position);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    printf("Node with data %d deleted from the beginning.\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head->next == NULL) {
        printf("Node with data %d deleted from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("Node with data %d deleted from the end.\n", temp->data);
    free(temp);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node *temp = head;

    if (position == 1) {
        head = head->next;
        printf("Node with data %d deleted from position 1.\n", temp->data);
        free(temp);
        return;
    }

    struct Node *prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of range. Nothing deleted.\n", position);
        return;
    }

    prev->next = temp->next;
    printf("Node with data %d deleted from position %d.\n", temp->data, position);
    free(temp);
}

void displayList() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

int main(){
    int choice,data,n,position;
    printf("Singly Linked List Implementation in C\n");
    printf("\n---Create Linked List---\n");
    printf("Enter total number of nodes to create: ");
    if(scanf("%d",&n)!=1 || n<0)
    {
        printf("Invalid input or number of nodes.\n");
        return 1;
    }

    createList(n);
    printf("List Created successfully\n");
    displayList();

    do{
        printf("\n---Operations Menu---\n");
        printf("1. Insert Node at Beginning\n");
        printf("2. Insert Node at the Specific Position\n");
        printf("3. Insert Node at End\n");
        printf("4. Delete Node at Beginning\n");
        printf("5. Delete Node at End\n");
        printf("6. Delete Node at Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter Your Choice: ");

        if(scanf("%d",&choice)!=1)
        {
            while(getchar()!='\n');
            choice=0;
        }

        switch(choice){
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d",&data);
            insertAtBeginning(data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d",&data);
            printf("Enter the position(1 for first node): ");
            scanf("%d",&position);
            insertAtPosition(data,position);
            break;
        case 3:
            printf("Enter data to insert at the end: ");
            scanf("%d",&data);
            insertAtEnd(data);
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("Enter the position(1 for first node): ");
            scanf("%d",&position);
            deleteAtPosition(position);
            break;
        case 7:
            displayList();
            break;
        case 8:
            printf("Exiting program Goodbye!\n");
            struct Node *current=head;
            struct Node*next;
            while(current!=NULL){
                next=current->next;
                free(current);
                current=next;
            }
            head=NULL;
            break;
        default:
            printf("INVALID CHOICE. Try Again\n");
        }
    } while(choice!=8);

    return 0;
}
