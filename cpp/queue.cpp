#include<iostream>
using namespace std;

#define n 5
int queue[5];
int front=-1;
int rear=-1;

void enqueue(int x){
    if(rear==n-1)
        cout<<"overflow";
    else if(front==-1 && rear==-1)
        {
            front=rear=0;
            queue[rear]=x;
        }    
    else{
        rear++;
        queue[rear]=x;
    }    

}
void dequeue(){
    if(front==-1 && rear==-1)
        cout<<"underflow";
    else if(front==rear){
        front=rear=-1;
    }    
    else{
        cout<<"deleted item is "<<queue[front]<<endl;
        front++;
    }
}
void peek(){
     if(front==-1 && rear==-1)
        cout<<"underflow";
     else{
         cout<<"peek element is "<<queue[front]<<endl;
     }   
}
void display(){
    if(front==-1 && rear==-1){
        cout<<"queue is empty";

    }
    else{
        cout<<"queue elements r :";
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
    }
}
int main(){

int x;
    for(int i=0;i<5;i++){
        cout<<"enter data";
        cin>>x;
        enqueue(x);
    }
    dequeue();
    peek();
    display();
    enqueue(5);
}