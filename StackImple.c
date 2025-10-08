#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void push(int n);
void pop();
void display();

int stack[SIZE], top = -1;


int main() {
    int value, choice;
    while (1) {
        printf("\n****MENU****\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong Selection, Try again!!\n");
        }
    }
    return 0;
}


void push(int n) {
    if (top == SIZE - 1)
        printf("\nStack is full, Can't insert value\n");
    else {
        top++;
        stack[top] = n;
        printf("\nInsertion Successful!!\n");
    }
}


void pop() {
    if (top == -1) {
        printf("\nStack is Empty!! Can't pop anything\n");
    } else {
        printf("\nDeleted: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1)
        printf("\nStack is Empty!!\n");
    else {
        int i;
        printf("\nStack Elements (Top to Bottom):\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}
