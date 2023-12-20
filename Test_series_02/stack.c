#include <stdio.h>
#include <stdlib.h>
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

int main(){
    struct Stack* str=create(10);
    push(str,10);
    push(str,20);
    push(str,30);
    printf("poped item %d",pop(str));
    return 0;
}