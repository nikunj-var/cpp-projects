//creation of linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
   
    public:
         int data;
        node* next=0;
        node(int data){
            this->data=data;
        }
};
node* insertlinkedlist( node *head,int data){
    
    node *newnode;
    newnode=new node(data);
    if(!newnode){
        cout<<"node not created"<<endl;
        return head;
    }
    newnode->next=0;
    if(head==NULL){
        head=newnode;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}
node* insertsortedlist(node* head,int data){
    node* newnode;
    newnode=new node(data);
   // newnode->data=val;
    node* current,*temp=NULL;
    current=head;
    while(current!=NULL && current->data<newnode->data){
        temp=current;
        current=current->next;
    }
    newnode->next=current;
    temp->next=newnode;
    return head;

}
void print(node *head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int  main(){
    node *head=NULL;
    int pos;
    head= insertlinkedlist(head,10);
    head= insertlinkedlist(head,20);
    head= insertlinkedlist(head,30);
    head= insertlinkedlist(head,40);
    head= insertlinkedlist(head,50);
    head= insertlinkedlist(head,60);
    head=  insertsortedlist(head,25);
    print(head);
}