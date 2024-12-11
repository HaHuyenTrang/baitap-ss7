#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Queue {
    int array[MAX]; // Mang luu tru cac phan tu cua hang doi
    int front;      // Chi so phan tu dau hang doi
    int rear;       // Chi so phan tu cuoi hang doi
} Queue;

// Khoi tao hang doi rong
void initalQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Kiem tra hang doi rong
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Kiem tra hang doi day
int isFull(Queue* queue) {
    return queue->rear == MAX - 1;
}

// Them phan tu vao cuoi hang doi (enqueue)
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) { // Kiem tra hang doi da day hay chua
        printf("Hang doi day!\n");
        return;
    }
    if (isEmpty(queue)) { // Neu hang doi rong, cap nhat front
        queue->front = 0;
    }
    queue->rear++; // Tang chi so rear va them phan tu vao
    queue->array[queue->rear] = value;
    printf("Them phan tu %d vao hang doi.\n", value);
}

// Lay phan tu dau tien cua hang doi ma khong xoa (peek)
int peek(Queue* queue) {
    if (isEmpty(queue)) { // Kiem tra neu hang doi rong
        printf("Hang doi rong!\n");
        return -1; // Tra ve gia tri dac biet de bao loi
    }
    return queue->array[queue->front]; // Tra ve phan tu dau
}

// Hien thi cac phan tu trong hang doi
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) { // Neu hang doi rong, thong bao
        printf("Hang doi rong.\n");
        return;
    }
    printf("Hang doi hien tai: ");
    for (int i = queue->front; i <= queue->rear; i++) { // Duyet tu front den rear
        printf("%d\t", queue->array[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initalQueue(&queue); // Khoi tao hang doi rong
    int choice, value;

    do {
        // Menu lua chon thao tac
        printf("\n==============MENU================:\n");
        printf("1. Them phan tu vao hang doi (enqueue)\n");
        printf("2. Hien thi phan tu dau tien (peek)\n");
        printf("3. Hien thi hang doi\n");
        printf("4. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Them phan tu vao hang doi
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                // Goi peek de hien thi phan tu dau
                printf("Phan tu dau tien sau khi them: %d\n", peek(&queue));
                break;
            case 2:
                // Hien thi phan tu dau tien trong hang doi
                value = peek(&queue);
                if (value != -1) {
                    printf("Phan tu dau tien cua hang doi: %d\n", value);
                }
                break;
            case 3:
                // Hien thi toan bo hang doi
                displayQueue(&queue);
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Vui long chon lai.\n");
        }
    } while (choice != 4); // Lap lai den khi nguoi dung chon thoat

    return 0;
}

