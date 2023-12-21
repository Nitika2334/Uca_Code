#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
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

int isFull(struct Stack* stack){
    return stack->top==stack->capacity-1;
}
int isEmpty(struct Stack* stack){
    return stack->top== -1;
}
int peek(struct Stack* stack){
    if(isEmpty(stack)){
        return -1;
    }
    return stack->array[stack->top];
}
void push(struct Stack* stack,int item){
    if(isFull(stack)){
        printf("Staack is full");
        return;
    }
    stack->array[++stack->top]=item;
    // printf("pushed item:%d\n",item);
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        return -1;
    }
    return stack->array[stack->top--];
}

char* removeDuplicateLetters(char* s) {
    int count[26] = {0};
    bool added[26] = {false};

    for (int i = strlen(s) - 1; i >= 0; i--) {
        count[s[i] - 'a']++;
    }

    struct Stack* st = create(strlen(s));

    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        if (added[c - 'a']) {
            count[c - 'a']--;
            continue;
        }

        while (!isEmpty(st) && peek(st) > c && count[peek(st) - 'a'] > 0) {
            added[pop(st) - 'a'] = false;
        }

        push(st, c);
        added[c - 'a'] = true;
        count[c - 'a']--;
    }

    char* result = (char*)malloc((st->top + 2) * sizeof(char));
    int i = 0;
    while (!isEmpty(st)) {
        result[i++] = pop(st);
    }
    result[i] = '\0';

    // Reverse the result
    int start = 0, end = i - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}

int main(){
    char s[] = "bcabc";
    char* result = removeDuplicateLetters(s);
    printf("Result: %s\n", result);

    free(result);  
    return 0;
}