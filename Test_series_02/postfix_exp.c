#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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
    // printf("pushed item:%d\n",item);
}

int pop(struct Stack* stack){
    if(isempty(stack)){
        return -1;
    }
    int item=stack->array[stack->top];
    return stack->array[stack->top--];
}

int Evaluation(char* str){
    struct Stack* stack=create(strlen(str));
    int i;

    if(!stack){
        return -1;
    }

    for(int i=0 ; i<str[i] ; i++){
        if(isdigit(str[i])){
            push(stack,str[i]-'0');
        }else{
            int val1=pop(stack);
            int val2=pop(stack);
            
            if(str[i]=='+'){
                push(stack,val2+val1);
            }
            else if(str[i]=='-'){
                push(stack,val2-val1);
            }
            else if(str[i]=='*'){
                push(stack,val2*val1);
            }
            else if(str[i]=='/'){
                push(stack,val2/val1);
            }
        }
    }
    return pop(stack);
}

int main(){
    char exp[] = "231*+9-";
    printf("postfix evaluation: %d", Evaluation(exp));
    return 0;
}