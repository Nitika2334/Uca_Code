#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct CircularQueue{
    int front, rear, size;
    int capacity;
    int* array;
};

struct CircularQueue* create(int capacity){
    struct CircularQueue* que=(struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    que->capacity=capacity;
    que->rear=que->front=-1;
    que->array=(int *)malloc(que->capacity*sizeof(int));
    return que;
}

bool isFull(struct CircularQueue* que){
    return que->front==((que->rear+1)%que->capacity);
}

bool isEmpty(struct CircularQueue* que){
    if(que->front== -1){
        return true;
    }
    return false;
}

void enqueue(struct CircularQueue* que,int value){
    if(isFull(que)){
        printf("queue is full\n");
        return;
    }
    else if(que->front==-1 && que->rear==-1){
        que->front=que->rear=0;
        que->array[que->rear]=value;
    }
    else{
        que->rear=que->rear%que->capacity;
        que->array[que->rear]=value;
    }
}

int dequeue(struct CircularQueue* que){
    int data;
    if(isEmpty(que)){
        return -1;
    }
    else if(que->front==que->rear){
        data=que->array[que->front];
        que->front=que->rear-1;
    }else{
        data=que->array[que->front];
        que->front=que->front%que->capacity;
    }
    return data;
}

int main(){
    struct CircularQueue* queue = create(1000);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n\n",dequeue(queue));
}