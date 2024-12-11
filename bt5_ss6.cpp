#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char array[MAX]; 
    int top;
} Stack;

void inital(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top >= MAX - 1;
}

void push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Ngan xep da day\n");
        return;
    }
    stack->array[++(stack->top)] = value;
}

void printReversed(Stack* stack) {
    printf("Chuoi dao nguoc: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%c", stack->array[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    inital(&stack);
    char str[MAX];

    printf("Nhap vao chuoi : ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    printReversed(&stack);

    return 0; 
}
