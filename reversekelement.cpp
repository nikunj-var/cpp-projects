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
/*
node* reversekpair(node* head){
    int k,i;
    
    node* temp1=NULL;
    node* prev,*current,*nextnode;
    prev=NULL;
    // if(head==NULL && head->next==NULL)
    //     return NULL;
    while(current!=NULL && current->next!=NULL){
        k=3;
        i=0;
    node* temp=head; 
    current=nextnode=head;
    while(i<k-1){
        temp=temp->next;
        i++;
    }
    prev->next=temp;
    prev=temp->next;
    i=0;
    while(i<k){
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
        i++;
    }
    if(temp1==NULL)
        temp1=prev;
    head=prev;
    }
    return temp1;;
}
*/
node* getkplusone(int k,node* head){
    node* temp;
    int i=0;
    if(!head)
        return head;
    for(i=0,temp=head;(i<k) && temp;i++,temp=temp->next);
    if(i==k && temp!=NULL)    
        return temp;
    return head->next;    
}
int hasknodes(node *head,int k){
    int i=0;
    for(i=0;head && (i<k);i++,head=head->next);
    if(i==k)
        return 1;
    return 0;    
}

node* reverse(node* head,int k){
    node* cur=head,*temp,*nextn,*newhead;
    int i;
    if(k==0 || k==1)
        return head;
    if(hasknodes(cur,k-1))
        newhead=getkplusone(k-1,cur);
    else
        newhead=head;
    while(cur && hasknodes(cur,k)){
        temp=getkplusone(k,cur);
        i=0;
        while(i<k){
            nextn=cur->next;
            cur->next=temp;
            temp=cur;
            cur=next;
            i++;
        }
    }    
    return newhead;
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
    head= reversekpair(head);
    print(head);
}
