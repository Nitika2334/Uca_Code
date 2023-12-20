#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue{
    int front, rear,size;
    int capacity;
    int* array;
};

struct Queue* create(int capacity){
    struct Queue* que=(struct Queue*)malloc(sizeof(struct Queue));
    que->capacity=capacity;
    que->front = que->size=0;
    que->rear=que->capacity-1;
    que->array=(int*)malloc(que->capacity*sizeof(int));
    return que;

}

bool isEmpty(struct Queue* que){
    return que->size==0;
}

bool isFull(struct Queue* que){
    return que->size==que->capacity;
}

void enqueue(struct Queue* que, int item){
    if(isFull(que)){
        printf("empty");
        return;
    }
    que->rear=que->rear+1;
    que->array[que->rear]=item;
    que->size=que->size+1;
    printf("item added%d\n",item);
}

int dequeue(struct Queue* que){
    if(isEmpty(que)){
        return -1;
    }
    int x=que->array[que->front];
    que->front=que->front+1;
    que->size=que->size-1;
    return x;
}

int front(struct Queue* que){
    if(isEmpty(que)){
        return -1;
    }
    return que->array[que->front];
}

int rear(struct Queue* que){
    if(isEmpty(que)){
        return -1;
    }
    return que->array[que->rear];
}

int main(){
    struct Queue* queue = create(1000);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n\n",dequeue(queue));
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
 
    return 0;
}