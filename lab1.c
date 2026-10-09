#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max];
int top=-1;

void push(){
    int item;
    printf("Enter an element to be push onto the stack: ");
    scanf("%d",&item);
    if(top==max-1)
        printf("Stack is overflow\n");
    else{
        top++;
        stack[top]=item;
        printf("%d is pushed onto the stack\n",item);
    }
}
void pop(){
    int item;
    if(top==-1)
        printf("Stack is underflow\n");
    else{
        stack[top]=item;
        top--;
        printf("%d is popped from the stack\n",item);
    }
}
void display(){

    if(top==-1)
        printf("Stack is underflow\n");
    else{
        printf("The elements in stack are:\n");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
void main(){
    while(1){
        int choice;
        printf("Choice 1.PUSH , 2.POP , 3.DISPLAY , 4.EXIT\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
        }

    }
}
