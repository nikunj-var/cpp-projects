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

int isevenorodd(node* head){
    while(head && head->next){
        head=head->next->next;
    }
    if(!head)
        return 0;
    return 1;    
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
    head= insertlinkedlist(head,70);
    if(isevenorodd(head)) cout<<"odd";
    else cout<<"even";

}