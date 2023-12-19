#include <stdio.h>
#include <stdlib.h>

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
    if(!isfull(stack)){
        return;
    }
    stack->array[++stack->top]=item;
    printf("pushed item:%d",item);
}

int pop(struct Stack* stack){
    if(isempty(stack)){
        return -1;
    }
    int item=stack->array[stack->top];
    return stack->array[stack->top--];
}

int main(){

}