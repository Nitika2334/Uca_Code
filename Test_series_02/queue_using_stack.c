#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Stack{
    int top;
    int capacity;
    int* array;
};

struct Stack* create(int capacity){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int *)malloc(stack->capacity*sizeof(int));
    return stack;
}

int isfull(struct Stack* stack){
    return stack->top==stack->capacity-1;
}
int isempty(struct Stack* stack){
    return stack->top== -1;
}
int peek(struct Stack* stack){
    if(isempty(stack)){
        return -1;
    }
    return stack->array[stack->top];
}
void push(struct Stack* stack,int item){
    if(isfull(stack)){
        printf("Staack is full");
        return;
    }
    stack->array[++stack->top]=item;
    printf("pushed item:%d\n",item);
}

int pop(struct Stack* stack){
    if(isempty(stack)){
        return -1;
    }
    return stack->array[stack->top--];
}

struct Queue{
    struct Stack* stack1;
    struct Stack* stack2;
};

struct Queue* createQueue(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = create(1000);  
    queue->stack2 = create(1000);
    return queue;
}

void enQueue(struct Queue* que,int value){
    push(que->stack1,value);
}

int deQueue(struct Queue* que){
    int x;
    if(isempty(que->stack1) && isempty(que->stack2)){
        return -1;
    }
    if(isempty(que->stack2)){
        while(!isempty(que->stack1)){
            push(que->stack2, pop(que->stack1));
        }
    }
    x = pop(que->stack2);
    return x;
}

int main()
{
    
    struct Queue* q = createQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
 
    /* Dequeue items */
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
 
    return 0;
}