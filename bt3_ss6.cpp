#include<stdio.h>
#include<stdlib.h> 
#define MAX 100

typedef struct {
	int array[MAX];
	int top;
}Stack;

//Khoi tao stack rong
void inital(Stack* stack){
	stack->top = -1;
}

//Kiem tra xem ngan xep co rong hay ko
int isEmpty(Stack* stack){
	return stack->top == -1;
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
int main() {
	int value;
	Stack stack;
	inital(&stack);
	int n;
	printf("Nhap so luong phan tu : ");
	scanf("%d",&n);
	if (n > MAX) {
        printf("So luong phan tu khong duoc vuot qua 100.\n");
        return 1;
    }
	for(int i; i < n; i++){
		printf("a[%d] : ", i + 1);
		scanf("%d",&value);
		push(&stack,value);
	}
	
	if (isEmpty(&stack)) {
        printf("Ngan xep rong\n");
    } else {
        printf("Ngan xep khong rong\n");
    }
	
	return 0;
}

