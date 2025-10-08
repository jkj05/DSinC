#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char ele) {
    if (top == SIZE - 1)
        printf("\nStack is full, Can't insert value\n");
    else
        stack[++top] = ele;
}

char pop() {
    if (top == -1) {
        printf("\nStack is Empty!! Cannot pop.\n");
        return '\0';
    } else {
        return (stack[top--]);
    }
}


int pr(char symbol) {
    if (symbol == '^')
        return (3);
    else if (symbol == '*' || symbol == '/')
        return (2);
    else if (symbol == '+' || symbol == '-')
        return (1);
    else
        return (0);
}


int main() {

    char infix[50], postfix[50], ch, ele;

    int i = 0, k = 0;

    printf("Enter your infix expression: ");
    scanf("%s", infix);

    push('#');


    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
        else {
            while (pr(stack[top]) >= pr(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }


    while (stack[top] != '#') {
        postfix[k++] = pop();
    }


    postfix[k] = '\0';
    printf("The postfix exp is %s\n", postfix);

    return 0;
}
