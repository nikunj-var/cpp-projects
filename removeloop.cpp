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
node* makeloop(node* head,int k){
    node* temp=head;
    int count=1;
    while(count<k){
        temp=temp->next;
        count++;
    }
    node* joint=temp;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=joint;
    return head;
}
node* detectloop(node *head){
    node* slow,*fast;
    int loopexists=0;
    int count=0;
    slow=fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            loopexists=1;
            break;
        }
    }
    if(loopexists){
        //slow=head;
        fast=fast->next;
        while(slow!=fast){
            fast=fast->next;
            // slow=slow->next;
            count++;
        }
        return slow;
    }
    return NULL;
}
void findlengthofloop(node *head){
    node* slow,*fast;
    int loopexists=0;
    int count=0;
    slow=fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            loopexists=1;
            break;
        }
    }
    if(loopexists){
        //slow=head;
        fast=fast->next;
        while(slow!=fast){
            fast=fast->next;
            // slow=slow->next;
            count++;
        }
       cout<<count;
    }
}
int  main(){
    node *head=NULL;
    int pos;
    int n;

    head= insertlinkedlist(head,10);
    head= insertlinkedlist(head,20);
    head= insertlinkedlist(head,30);
    head= insertlinkedlist(head,40);
    head= insertlinkedlist(head,50);
    head= insertlinkedlist(head,60);
    head= insertlinkedlist(head,10);
    head= insertlinkedlist(head,20);
    head= insertlinkedlist(head,30);
    head= insertlinkedlist(head,40);
    head= insertlinkedlist(head,50);
    head= insertlinkedlist(head,60);
    head= makeloop(head,4);
    if(detectloop(head))
        cout<<"loop detected";
    else
        cout<<"loop not detected"   ; 
    findlengthofloop(head);
}
