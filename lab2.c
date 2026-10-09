#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
int top=-1;
char stack[MAX];

void push(char ch){
    top++;
    stack[top] = ch;
}
char pop(){
    return stack[top--];
}
int precedence(char ch){
    if(ch=='*' || ch=='/')
        return 2;
    if(ch=='-' || ch=='+')
        return 1;
    return 0;
}

int main(){
    char infix[100] , postfix[100];
    int i=0,j=0;
    char ch;
    printf("Enter the expression:\n");
    scanf("%s",&infix);
    for(i=0;infix[i]!='\0';i++){
        ch=infix[i];
        if(isalnum(ch))
            postfix[j++]=ch;
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(top!=-1 && stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else{
            while(top!=-1 && stack[top]!='(' && precedence(stack[top]) >= precedence(ch)){
                postfix[j++]=pop();
            }
            push(ch);
        }
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j] = '\0';
    printf("The postfix expression is: %s\n",postfix);
    return 0;
}
