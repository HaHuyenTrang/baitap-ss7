#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Cau truc luu phan tu cua hang doi uu tien
typedef struct {
    int priority; // Muc do uu tien
    int data;     // Du lieu cua phan tu
} Element;

// Cau truc hang doi uu tien
typedef struct {
    Element array[MAX]; // Mang luu tru cac phan tu
    int front;          // Chi so phan tu dau hang doi
    int rear;           // Chi so phan tu cuoi hang doi
} PriorityQueue;

// Khoi tao hang doi rong
void initQueue(PriorityQueue* queue) {
    queue->front = -1; // Dat front o trang thai rong
    queue->rear = -1;  // Dat rear o trang thai rong
}

// Kiem tra hang doi rong
int isEmpty(PriorityQueue* queue) {
    return queue->front == -1;
}

// Kiem tra hang doi day
int isFull(PriorityQueue* queue) {
    return queue->rear == MAX - 1;
}

// Them phan tu vao hang doi voi muc uu tien
void enqueue(PriorityQueue* queue, int priority, int data) {
    if (isFull(queue)) { // Neu hang doi day, bao loi
        printf("Hang doi day!\n");
        return;
    }

    // Tao phan tu moi
    Element newElement;
    newElement.priority = priority;
    newElement.data = data;

    if (isEmpty(queue)) { // Neu hang doi rong, khoi tao front va rear
        queue->front = 0;
        queue->rear = 0;
        queue->array[queue->rear] = newElement;
    } else {
        // Chen phan tu vao vi tri phu hop de dam bao thu tu uu tien
        int i = queue->rear;
        while (i >= queue->front && queue->array[i].priority < priority) {
            queue->array[i + 1] = queue->array[i]; // Dich chuyen phan tu
            i--;
        }
        queue->array[i + 1] = newElement; // Chen phan tu moi vao vi tri dung
        queue->rear++;                    // Tang rear len
    }

    printf("Da them phan tu: data = %d, priority = %d\n", data, priority);
}

// Lay phan tu co uu tien cao nhat ra khoi hang doi
void dequeue(PriorityQueue* queue) {
    if (isEmpty(queue)) { // Neu hang doi rong, bao loi
        printf("Hang doi rong!\n");
        return;
    }

    // Lay phan tu dau (co uu tien cao nhat)
    Element removedElement = queue->array[queue->front];
    printf("Da lay phan tu: data = %d, priority = %d\n", removedElement.data, removedElement.priority);

    if (queue->front == queue->rear) {
        // Neu chi co mot phan tu, dat hang doi ve trang thai rong
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++; // Tang front len de loai bo phan tu dau
    }
}

// Hien thi cac phan tu trong hang doi
void displayQueue(PriorityQueue* queue) {
    if (isEmpty(queue)) { // Neu hang doi rong, thong bao
        printf("Hang doi rong.\n");
        return;
    }

    printf("Cac phan tu trong hang doi:\n");
    for (int i = queue->front; i <= queue->rear; i++) { // Duyet qua cac phan tu tu front den rear
        printf("Data = %d, Priority = %d\n", queue->array[i].data, queue->array[i].priority);
    }
}

int main() {
    PriorityQueue queue;
    initQueue(&queue); // Khoi tao hang doi

    int choice, priority, data;

    do {
        printf("\n====================MENU=====================:\n");
        printf("1. Them phan tu vao hang doi (enqueue)\n");
        printf("2. Lay phan tu co uu tien cao nhat (dequeue)\n");
        printf("3. Hien thi hang doi\n");
        printf("4. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Them phan tu vao hang doi
                printf("Nhap gia tri data: ");
                scanf("%d", &data);
                printf("Nhap muc do uu tien: ");
                scanf("%d", &priority);
                enqueue(&queue, priority, data);
                break;
            case 2:
                // Lay phan tu co uu tien cao nhat
                dequeue(&queue);
                break;
            case 3:
                // Hien thi cac phan tu trong hang doi
                displayQueue(&queue);
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf(" Vui long chon lai.\n");
        }
    } while (choice != 4); // Lap lai den khi nguoi dung chon thoat

    return 0;
}

