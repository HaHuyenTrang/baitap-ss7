#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Cau truc cua hang doi hai dau
typedef struct {
    int array[MAX]; // Mang luu tru cac phan tu
    int front;      // Chi so dau hang doi
    int rear;       // Chi so cuoi hang doi
} Deque;

// Khoi tao hang doi rong
void initDeque(Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Kiem tra hang doi rong
int isEmpty(Deque* deque) {
    return deque->front == -1;
}

// Kiem tra hang doi day
int isFull(Deque* deque) {
    return (deque->rear + 1) % MAX == deque->front;
}

// Them phan tu vao dau hang doi
void addFront(Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Hang doi day!");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX) % MAX;
    }

    deque->array[deque->front] = data;
    printf("Da them %d vao dau hang doi\n", data);
}

// Them phan tu vao cuoi hang doi
void addRear(Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Hang doi day!");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX;
    }

    deque->array[deque->rear] = data;
    printf("Da them %d vao cuoi hang doi\n", data);
}

// Lay phan tu o dau hang doi
void removeFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong!\n");
        return;
    }

    int removedData = deque->array[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX;
    }

    printf("Da lay %d ra khoi dau hang doi\n", removedData);
}

// Lay phan tu o cuoi hang doi
void removeRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong!\n");
        return;
    }

    int removedData = deque->array[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + MAX) % MAX;
    }

    printf("Da lay %d ra khoi cuoi hang doi\n", removedData);
}

// Hien thi cac phan tu trong hang doi
void displayDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Cac phan tu trong hang doi: ");
    int i = deque->front;
    while (1) {
        printf("%d ", deque->array[i]);
        if (i == deque->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque deque;
    initDeque(&deque);

    int choice, data;

    do {
        printf("\n======================MENU=================\n");
        printf("1. Them vao dau hang doi\n");
        printf("2. Them vao cuoi hang doi\n");
        printf("3. Lay phan tu o dau hang doi\n");
        printf("4. Lay phan tu o cuoi hang doi\n");
        printf("5. Hien thi hang doi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri de them vao dau: ");
                scanf("%d", &data);
                addFront(&deque, data);
                break;
            case 2:
                printf("Nhap gia tri de them vao cuoi: ");
                scanf("%d", &data);
                addRear(&deque, data);
                break;
            case 3:
                removeFront(&deque);
                break;
            case 4:
                removeRear(&deque);
                break;
            case 5:
                displayDeque(&deque);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf(" vui long chon lai!\n");
        }
    } while (choice != 6);

    return 0;
}
