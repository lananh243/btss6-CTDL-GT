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

int pop(Stack* stack){
	if (isEmpty(stack)) { 
        printf("Ngan xep rong\n");
        return -1;
    }
    int value = stack->array[(stack->top)--];
    return value;
}

int isValidExpression(const char* expression) {
    Stack stack;
    inital(&stack);
    
    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];
        
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            char top = pop(&stack);
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return 0;
            }
        }
    }
    
    return isEmpty(&stack);
}

int main() {
    char expression[MAX];

    printf("Nhap bieu thuc : ");
    fgets(expression, sizeof(expression), stdin);
    
    expression[strcspn(expression, "\n")] = '\0';

    if (isValidExpression(expression)) {
        printf("Bieu thuc hop le\n");
    } else {
        printf("Bieu thuc khong hop le\n");
    }

    return 0;
}
