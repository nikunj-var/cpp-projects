/*CIRCULAR QUEUE USING ARRAY*/
// #include<iostream>
// using namespace std;

// #define n 5
// int cqueue[n];
// int front=-1;
// int rear=-1;
// void enqueue(int x){
//     if(front==-1 && rear==-1)
//         {front=rear=0;
//             cqueue[rear]=x;
//         }
//     else if((rear+1)%n==front)
//     cout<<"queue is full!!"<<endl;
//     else{
//         rear=(rear+1)%n;
//         cqueue[rear]=x;
//     }    
// }
// void dequeue(){
//     if(front==-1 && rear==-1){
//         cout<<"queue is empty";
//     }
//     else if(front == rear)
//         front=rear=-1;
//     else{
//         cout<<"deleted item is"<<cqueue[front]<<endl;
//         front=(front+1)%n;
//     }    
// }
// void peek(){
//     if(front==-1 && rear==-1)
//         cout<<"queue is empty";
//     else{
//         cout<<"peek element is"<<cqueue[front]<<endl;

//     }    
// }
// void display(){
//     if(front==-1 && rear==-1)
//     cout<<"queue is empty";
//     else{
//         cout<<"queue elements are: ";
//         int i=front;
//         while(i!=rear){
//             cout<<cqueue[i]<<" ";
//             i=(i+1)%n;
//         }
//         cout<<cqueue[rear];
//     }
// }
// int main(){
// int x;
// for(int i=0;i<5;i++){
//     cout<<"enter data";
//     cin>>x;
//     enqueue(x);

// }
// dequeue();
// peek();
// display();
// }

/*CIRCULAR QUEUE USING LINKED LIST*/

/*#include<iostream>
using namespace std;

struct node{
    int data;
    node *next=0;
};
struct node* front=0;
struct node*rear=0;
struct node *newnode;
void enqueue(int x){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(rear==0){
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void dequeue(){
    struct node *temp;
    temp=front;
    if(front==0 && rear==0){
        cout<<"queue is empty";
    }
    else if(front==rear){
        front=rear=0;
        cout<<"deleted element is"<<temp->data<<endl;
        free(temp);
    }
    else{
        front=front->next;
        rear->next=front;
        cout<<"deleted element is"<<temp->data<<endl;
        free(temp);
    }
}
void peek(){
    if(front==0 && rear==0)
    cout<<"queue is empty";
    else{
        cout<<"peek element is "<<front->data<<endl;
    }
}
void display(){
    struct node *temp;
    temp=front;
    if(front==0 && rear==0)
        cout<<"queue is empty"<<endl;
    else{
        cout<<"circular queue is ";
        while(temp->next!=front){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<" ";
    }    
}
int main(){
    int x;
    char c='y';
    do{
        cout<<"enter data";
        cin>>x;
        enqueue(x);
        cout<<"do u want to more(y/n)";
        cin>>c;
    }while(c!='n');
    dequeue();
    peek();
    display();
}*/

/*CIRCULAR QUEUE USING STACK*/
#include<iostream>
using namespace std;
void push1(int x );
#define n 5
int s1[n],s2[n];
int top1=-1,top2=-1;
int count=0;
void enqueue(int x){
    push1(x);
    count++;
}
void push1(int x){
if(top1==n-1)
    cout<<"stack is full";
    else{
        top++;
        s1[top1]=x;
    }
}
void dequeue(){
    if(top==-1 && top2==-1)
    cout<<"queue is empty";
    else{
        for(int i=0;i<count;i++){
            a=pop();
            push2(a);
        }    
        b=pop2();
        cout<<b;                
        count--;
