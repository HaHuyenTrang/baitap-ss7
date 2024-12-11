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

// Lay phan tu ra khoi hang doi (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong!\n");
        return -1; 
    }
    int value = queue->array[queue->front];
    if (queue->front == queue->rear) { 
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
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
	printf("moi ban nhap gia tri: ");
	scanf("%d",&value);
	enqueue(&queue,value);
	displayQueue(&queue);
 	value = dequeue(&queue);
    if (value != -1) {
        printf("Phan tu duoc lay ra: %d\n", value);
    }
}
