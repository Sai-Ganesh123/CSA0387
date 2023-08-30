#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};


struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // Initialize rear as -1, as we'll increment it before enqueueing
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}


int isQueueEmpty(struct Queue* queue) {
    return queue->size == 0;
}


int isQueueFull(struct Queue* queue) {
    return queue->size == queue->capacity;
}


void enqueue(struct Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("Queue is full.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}


int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}


void push(struct Queue* q1, struct Queue* q2, int item) {
    enqueue(q1, item);
}

int pop(struct Queue* q1, struct Queue* q2) {
    if (isQueueEmpty(q1)) {
        printf("Stack is empty.\n");
        return -1;
    }

    
    while (q1->size > 1) {
        enqueue(q2, dequeue(q1));
    }

    
    int popped_item = dequeue(q1);

    
    struct Queue* temp = q1;
    q1 = q2;
    q2 = temp;

    return popped_item;
}

int main() {
    unsigned capacity = 10;
    struct Queue* q1 = createQueue(capacity);
    struct Queue* q2 = createQueue(capacity);

    push(q1, q2, 1);
    push(q1, q2, 2);
    push(q1, q2, 3);

    printf("Popped: %d\n", pop(q1, q2));
    printf("Popped: %d\n", pop(q1, q2));

    return 0;
}
