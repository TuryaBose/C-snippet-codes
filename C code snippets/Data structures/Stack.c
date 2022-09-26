/* This is a simple implementation of a stack where a stack is created and data is pushed and popped */
//Author: Turya Bose
//Version: 1.0
//Date: 25.09.22

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* link;
}Node;

struct Node* top = NULL;

void push(int data){
    struct Node* temp = malloc(sizeof(Node));

    if(temp != NULL){
        temp->data = data;
        temp->link = top;
        top = temp;
    }
}

int isEmpty(){
    return top == NULL;
}

void pop() {
    struct Node* temp;

    if(top!= NULL){
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

void display(){
    struct Node* temp;

    if(top != NULL){
        temp = top;

        while(temp!=NULL){
            printf("%d:\n", temp->data);
            temp = temp->link;
        }
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);

    display();

    pop();
    pop();

    display();

    return 0;
}
