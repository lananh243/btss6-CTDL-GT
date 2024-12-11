#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//cau truc ngan xep 
typedef struct {
	int array[MAX];
	int top;
	
}Stack;

//Khoi tao stack rong
void inital(Stack* stack){
	stack->top = -1;
}

//Kiem tra stack co rong hay ko 
int isEmpty(Stack* stack){
	if(stack->top == -1){
		return 1;
	}
	return 0;
}

//Kiem tra ngan xep co bi day hay ko
int isFull(Stack* stack){
	if(stack->top >= MAX - 1){
		return 1;
	}
	return 0;
}

//Them vao stack
void push(Stack* stack, int value){
	if(isFull(stack) == 1){
		printf("Ngan xep da day");
		return;
	}
	stack->array[++(stack->top)] = value;
}

//in ra 
void printStack(Stack* stack){
	for(int i = stack->top ; i >= 0; i--){
		printf("%d\n", stack->array[i]);
	}
	
}

int main() {
	int value;
	Stack stack;
	inital(&stack);
	int n;
	printf("Nhap so luong phan tu : ");
	scanf("%d",&n);
	
	for(int i; i < n; i++){
		printf("a[%d] : ", i + 1);
		scanf("%d",&value);
		push(&stack, value);
	}
		printStack(&stack);
	
	return 0;
	
}

