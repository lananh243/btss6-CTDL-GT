#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

// Con tro top cua ngan xep -> NULL
Node* top = NULL;

//kiem tra ngan xep co rong hay ko
int isEmpty(){
	if(top == NULL){
		return 1;
	}
	return 0;
}

//Them phan tu
void push(int value){
	// tao node moi 
	Node* newNode = (Node *) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = top;
	top = newNode; 
}

//xoa phan tu
void pop(){
	if(isEmpty() == 1){
		printf("Ngan xep rong");
		return;
	}
	Node *temp = top;
	printf("Lay ra phan tu: %d\n", top->data);
	top = top->next;
	free(temp);
}

int peek(){
	if(isEmpty() == 1){
		printf("Ngan xep rong");
		return -1;
	}
	printf("Phan tu dau cua ngan xep: %d\n", top->data);
	return top->data;
}

// In ra 
void printStack() {
    Node* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
	int value;

	do{
		printf("***********************MENU******************************\n");
		printf("1. Them phan tu vao ngan xep\n");
		printf("2. In ra ngan xep\n");
		printf("3. Lay phan tu ra khoi ngan xep\n");
		printf("4. Lay phan tu dau\n"); 
		printf("0. Thoat\n");
		printf("Moi ban chon tu 0 - 4: ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 0 :
				exit(0);
			case 1 :
				printf("Nhap vao gia tri can them : ");	
				scanf("%d",&value);
				push(value);
				break;
			case 2 :
				printStack();
				break;
			case 3 :
				pop();
				break; 
			case 4 :
				peek();
				break;	 
			default :
				printf("Vui long chon lai");
		}
		
	}while(1==1);
	return 0; 
}

