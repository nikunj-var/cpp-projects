#include<iostream>

using namespace std;

#define n 5

int stack1[n],stack[2];
int top1=-1;
int top2=-1;
int count=0;
void push1(int data){
    if(top1==n-1)
        cout<<"stack overflow";
    else{
        top1++;
        stack[top1]=data;
    }    
}
int pop1(){
    if(top1==-1)
        cout<<"stack is empty"
}
int pop2(){
    int element=stack2[top2];
    top2--;
    return element;
}
void enqueue(int x){
    while(top1!=-1){
        push2(pop1());
    }
    push1(x);
    while(top2!=-1){
        push1(pop2());
    }
}
int dequeue(){
    int element=stack1[top1];
    top1--;
    return element;
}
void display(){
    for(int i=top1;i>=0;i--){
        cout<<stack[i];
    }
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    int d=dequeue()
    cout<<"the deleted element is"<<d;
    enqueue(4);
    enqueue(5);
    display();
}