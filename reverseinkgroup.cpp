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
void print(node *head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
bool check(node* head,int k){
    int count=0;
    node* temp=head;
    while(count<k){
        if(temp!=NULL)
            temp=temp->next;
        else
         return false; 
        count++;    
    }
        return true;    
}
node* reverse(node* head,int k){
    if(head==NULL)
        return NULL;
    node* nextn=NULL,*prev=NULL,*curr=head;
    int count=0;
    while(curr!=NULL && count<k){
        nextn=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextn;
        count++;
    }    
    if(nextn!=NULL && check(nextn,k))
        head->next=reverse(nextn,k);
    else
        head->next=nextn;    
    return prev;    
}
int  main(){
    node *head=NULL;
   
    head= insertlinkedlist(head,10);
    head= insertlinkedlist(head,20);
    head= insertlinkedlist(head,30);
    head= insertlinkedlist(head,40);
    head= insertlinkedlist(head,50);
    head= insertlinkedlist(head,60);
    head= insertlinkedlist(head,70);
    head= insertlinkedlist(head,80);
    cout<<"enter k";
    int k;
    cin>>k;
    head=reverse(head,k);
    print(head);

}

