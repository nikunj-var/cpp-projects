//creation of linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
   
    public:
         int data;
        node* next=0;
        node* prev=0;
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
        head->prev=head;
        head->next=head;
    }
    else{
        node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->prev=newnode;
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next=head;
       
    }
    return head;
}
//funtion to insertatbeginning
node* insertatbeginning(node* head, int data){
    node *newnode;
    newnode=new node(data);
    newnode->next=0;
    if(head==NULL){
        head=newnode;
        head->next=head;
        head->prev=head;
    }
    else{
        node* temp=head;
        head->prev=newnode;
        newnode->next=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        head=newnode;
    }
    return head;
}
//funtion to insertatend
node* insertatend(node* head, int data){
     node *newnode;
    newnode=new node(data);
    newnode->next=0;
    if(head==NULL){
        head=newnode;
        head->next=head;
        head->prev=head;
    }
    else{
        node* temp;
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newnode->prev=temp;
        newnode->next=head;
        temp->next=newnode;
        head->prev=newnode;
    }
    return head;
 }
//funtion to insertatpos
node* insertatpos(node*head,int data,int pos){
    node *newnode;
    newnode=new node(data);
    newnode->next=0;
    if(head==NULL){
        head=newnode;
    }
    else{
        int i=1;
        node* temp;
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
    return head;
}
//function to delete from beginning
node* deletefrombeg(node* head){
    if(head==NULL){
        return NULL;
    }
    else if(head->next==NULL){
        return NULL;
        free(head);
    }
    else{
        node *temp=head,*temp1;
        temp1=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        head->next->prev=temp;
        temp->next=head->next;
        head=head->next;
        free(temp1);
    }
    return head;
}
// function to delete node from end
node* deletefromend(node* head){
    if(head==NULL){
        return NULL;
    }
    else if(head->next==NULL){
        free(head);
        return NULL;
    }
    else{
        node *temp=head,*prev;
        while(temp->next->next!=head){
            temp=temp->next;
        }
        prev=temp->next;
        temp->next=head;
        head->prev=temp;
        free(prev);
    }
    return head;
}
//function to delete from pos
node* deletefrompos(node* head,int pos){
    if(head==NULL){
        return NULL;
    }
    else if(head->next==NULL){
        free(head);
        return NULL;

    }
    else{
        int i=1;
        node *temp=head,*prev;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        
        prev=temp->next;
        temp->next=temp->next->next;
        temp->next->next->prev=temp;
        free(prev);
    }
    return head;
}

void print(node *head){
    node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<temp->data;
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
    // head=insertatbeginning(head,100);
    // head=insertatend(head,200);
    // cout<<"enter position where you want to add node";
    // cin>>pos;
    // head=insertatpos(head,500,pos);
    // head=deletefrombeg(head);
    // head=deletefromend(head);
    // cout<<"enter position where you want to delete node";
    // cin>>pos;
    // head=deletefrompos(head,pos);
    reverse(head);
    print(head);

}