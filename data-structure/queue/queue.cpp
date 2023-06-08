#include <iostream>
using namespace std;

class Queue {
    public: 
    int head, rear, size;
    unsigned capacity;
    int * array;
};

Queue* createQueue(unsigned capacity) {
    Queue* queue = new Queue();
    queue->capacity = capacity; // length
    queue->head = queue->size = 0;

    queue->rear = capacity - 1; 
    queue->array = new int[queue->capacity]; // length 만큼 배열 할당
    return queue;
}

int isFull(Queue* queue){
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int item) {
    if(isFull(queue)) return;
    queue->rear = (queue->rear + 1)%queue->capacity; // 배열의 끝에 도달한 경우 0 으로 돌아가도록
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << "enqueued~!~!"<< endl;
}

int dequeue (Queue* queue) {
    if(isEmpty(queue)){
        return INT_MIN;
    }
    int item = queue->array[queue->head];
    queue->head = (queue->head + 1) % queue->capacity; 
    queue->size = queue->size - 1;
    return item;
}

int head (Queue* queue) {
    if(isEmpty(queue)){
        return INT_MIN;
    }
    return queue->array[queue->head];
}

int rear(Queue* queue) {
    if(isEmpty(queue)){
        return INT_MIN;
    }
    return queue->array[queue->rear];
}

int main () {
    Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    cout << dequeue(queue) << "dequeued from queue"<< endl;
    cout << "HEAD: " << head(queue) << endl;
    cout << "REAR: " << rear(queue) <<  endl;

    while (!isEmpty(queue)){
        cout << " " << queue->array[queue->head];
        dequeue(queue);

    }
    return 0;
}