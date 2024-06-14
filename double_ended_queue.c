#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct CircularDeque {
    int front, rear;
    int arr[SIZE];
};

void initialize(struct CircularDeque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isFull(struct CircularDeque* deque) {
    return (deque->front == 0 && deque->rear == SIZE - 1) || (deque->front == deque->rear + 1);
}

int isEmpty(struct CircularDeque* deque) {
    return deque->front == -1;
}

void enqueueFront(struct CircularDeque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot enqueue.\n");
    } else {
        if (deque->front == -1) {
            deque->front = deque->rear = 0;
        } else if (deque->front == 0) {
            deque->front = SIZE - 1;
        } else {
            deque->front = deque->front - 1;
        }
        deque->arr[deque->front] = value;
        printf("%d enqueued at the front.\n", value);
    }
}

void enqueueRear(struct CircularDeque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot enqueue.\n");
    } else {
        if (deque->front == -1) {
            deque->front = deque->rear = 0;
        } else if (deque->rear == SIZE - 1) {
            deque->rear = 0;
        } else {
            deque->rear = deque->rear + 1;
        }
        deque->arr[deque->rear] = value;
        printf("%d enqueued at the rear.\n", value);
    }
}

void dequeueFront(struct CircularDeque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued from the front.\n", deque->arr[deque->front]);
        if (deque->front == deque->rear) {
            deque->front = deque->rear = -1;
        } else if (deque->front == SIZE - 1) {
            deque->front = 0;
        } else {
            deque->front = deque->front + 1;
        }
    }
}

void dequeueRear(struct CircularDeque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued from the rear.\n", deque->arr[deque->rear]);
        if (deque->front == deque->rear) {
            deque->front = deque->rear = -1;
        } else if (deque->rear == 0) {
            deque->rear = SIZE - 1;
        } else {
            deque->rear = deque->rear - 1;
        }
    }
}

void display(struct CircularDeque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
    } else {
        int i = deque->front;
        printf("Deque elements: ");
        do {
            printf("%d ", deque->arr[i]);
            if (i == deque->rear) {
                break;
            }
            i = (i + 1) % SIZE;
        } while (i != deque->front);
        printf("\n");
    }
}

int main() {
    struct CircularDeque deque;
    initialize(&deque);

    enqueueRear(&deque, 10);
    enqueueRear(&deque, 20);
    enqueueFront(&deque, 5);

    display(&deque);

    dequeueFront(&deque);
    dequeueRear(&deque);

    display(&deque);

    return 0;
}
