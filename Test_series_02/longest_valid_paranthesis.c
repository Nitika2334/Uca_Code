#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct Stack{
    int top;
    int capacity;
    int* array; 
};

struct Stack* create(int capacity){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->top=-1;
    stack->capacity=capacity;
    stack->array=(int*)malloc(stack->capacity*sizeof(int));
    return stack;
}

void push(struct Stack* stack, int value){
    if(stack->top == (stack->capacity-1)){
        printf("stack is full");
        return;
    }
    stack->array[++stack->top]=value;
    // printf("push element%d\n",value);
}

int pop(struct Stack* stack){
    int x;
    if(stack->top==-1){
        return -1;
    }
    return stack->array[stack->top--];
}

bool isEmpty(struct Stack* stack){
    return stack->top==-1; 
}

int validParanthesis(char* str){
    int result=0;
    struct Stack* stack=create(strlen(str));

    for(int i=0 ; i<strlen(str) ; i++){
        if(str[i]=='('){
            push(stack,i);
        }
        else{
            if(!isEmpty(stack)){
                pop(stack);
            }
            if(!isEmpty(stack)){
                result= (result > i - stack->array[stack->top]) ? result : (i - stack->array[stack->top]);
            }else{
                push(stack,i);
            }
        }
    }
    return result;
}

int main(){
    char str[] = ")()";
    printf("Length of max valid parenthesis is: %d\n", validParanthesis(str));
    return 0;
}
