#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    node* next;
};
node *top=NULL;
void push(int val){
    node *temp=new node();
    if(!temp){
        cout<<"error";
        return;
    }
    temp->data=val;
    temp->next=top;
    top=temp;
}
int isempty(){
    return top==NULL;
}
int peek(){
    if(!isempty()){
        return top->data;
    }
    else{
        exit(1);
    }
}
void pop(){
    node* temp;
    if(top==NULL){
        cout<<"stack underflow";
    }
    else{
        temp=top;
        top=top->next;
        free(temp);        
    }
}
void display(node *head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int main(){
    push(11);
    push(22);
    push(33);
    push(44);
    push(55);
    push(66);
    display(top);
    cout<<"\npeek element of the stack"<<peek();
    pop();
    pop();
    cout<<endl;
    display(top);
    cout<<"\npeek element of the stack"<<peek();
}