#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

bool isValidPararnthesis(char *str){
    char stack[100];
    int top=-1;

    while(*str){
        if(*str=='[' || *str=='{' || *str=='('){
            stack[++top]=*str;
        }else if(*str==']'){
            if(top==-1 || stack[top]!='['){
                return false;
            }
            else{
                top--;
            }
        }else if(*str=='}'){
            if(top==-1 || stack[top]!='{'){
                return false;
            }
            else{
                top--;
            }
        }else if(*str==')'){
            if(top==-1 || stack[top]!='('){
                return false;
            }
            else{
                top--;
            }
        }
        str++;
    }
    return (top==-1) ? true : false;
}

int main(){
    //input1
    char str1[]="{}{}[]";
    printf("%d",isValidPararnthesis(str1));

    //input2
    char str2[]="({[})";
    printf("%d",isValidPararnthesis(str1));
}