#include<stdio.h>
#include<stdlib.h>
#define MAX 5


typedef struct Queue {
	int array[MAX];
	int front;
	int rear;
}Queue; 

//Khoi tao hang doi

void initalQueue(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}

//Kiem tra hang doi rong
int isEmpty(Queue* queue){
	if(queue->front == -1){
		return 1;
	}
	return 0;
}

//Kiem tra hang doi day
int isFull(Queue* queue){
	if(queue->rear == MAX -1){
		return 1;
	}
	return 0;
} 

//	Enqueue(them phan tu vao cuoi hang doi)
void enqueue(Queue* queue, int value){
	if(isFull(queue) == 1){
		printf("hang doi day");
		return;
	}
	if(isEmpty(queue) == 1){
		queue->front = 0;
	}
	queue->rear++;
	queue->array[queue->rear] = value;
}


void displayQueue(Queue* queue){
	for(int i = queue->front; i<= queue->rear; i++ ){
		printf("%d\t", queue->array[i]);
	}
}


int main() {
	Queue queue;
	initalQueue(&queue);
	int value;
	do{
		printf("\n==========================MENU========================\n");
		printf("0. thoat\n");
		printf("1. them phan tu vao cuoi hangg doi\n");
		printf("2. hien thi hang doi\n");
		printf("moi ban chon 0-2: ");
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 0:
				exit(0);
			case 1:
				printf("moi ban nhap gia tri: ");
				scanf("%d",&value);
				enqueue(&queue,value);
				break;
			case 2:
				displayQueue(&queue);
				break;
			default:
				printf("moi chon lai: ");
		} 
	}while (1 == 1);
}
