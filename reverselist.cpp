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
//reverse full linked list
// node* reverse(node *head){
//     node* temp,*nextnode;
//     nextnode=NULL;
//     temp=NULL;
//     while(head){
//         nextnode=head->next;
//         head->next=temp;
//         temp=head;
//         head=nextnode;
//     }
//     return temp;
// }
void print(node *head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
// void split(node* head){
//     int count=0,i=1;
//     node* head1=NULL,*head2=NULL;
//     node* temp=head;
//     node* temp2=NULL;
//     while(temp->next!=head){
//         count++;
//         temp=temp->next;
//     }
//     count++;
//     temp=head;
//     while(i<count/2){
//         temp=temp->next;
//         i++;
//     }
//     temp2=temp->next;
//     temp->next=head;
//     head1=head;
//     // print(head1);
//     node *temp3=head1;
   
//     temp=temp->next;
//     head2=temp2;
//     while(temp2->next!=head){
//         temp2=temp2->next;
//     }
//     temp2=temp2->next;
//     temp2->next=head2;
//      cout<<"first split linked list\n";
//     while(temp3->next!=head1){
//         cout<<temp3->data<<" ";
//         temp3=temp3->next;
//     }
//      cout<<temp3->data<<" ";
// }

void split(node *head,node **head1,node **head2){
    node* slow=head;
    node* fast=head;
    if(head==NULL){
        return;
    }
    //if fast->next=head then elements are odd
    //if fast->next->next==head then no of elementa are even
    while(fast->next!=head && fast->next->next!=head){
        fast=fast->next->next;
        slow=slow->next;
    }
    //if no of elements are even
    if(fast->next->next == head){
            fast=fast->next;
    }

    *head1=head;
    if(head->next!=head){
        *head2=slow->next;
    }
    fast->next=slow->next;
    slow->next=head;
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
    //print(head);
    //head= reverse(head);
    //cout<<"after reversal of linked list\n";
    //print(head);
    node *head1=NULL;
    node* head2=NULL;
    split(head,&head1,&head2);
    print(head1);
    print(head2);
}