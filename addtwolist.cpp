#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
       public:
         int data;
        node* next=0;
        node(){            
        }
        node(int data){
            this->data=data;
        }
};
class stack{
public:
    node *top=NULL; 
    void push(int val){
    node *temp=new node();
    if(!temp){
        cout<<"error";
        return;
    }
    temp->data=val;
    temp->next=top;
    top=temp;
}
int isempty(){
    return top==NULL;
}
int peek(){
    if(!isempty()){
        return top->data;
    }
    else{
        exit(1);
    }
}
void pop(){
    node* temp;
    if(top==NULL){
        cout<<"stack underflow";
    }
    else{
        temp=top;
        top=top->next;
        free(temp);        
    }
}
int length(){
    node* temp=top;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
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
node* insertatbeginning(node* head, int data){
     node *newnode;
    newnode=new node(data);
    newnode->next=0;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    return head;
}
void print(node *head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
}
node* addtwolist(node* head1,node* head2){
    stack s1,s2;
    int carry=0;
    int val1=0,val2=0,sum;
    node* temp1=head1,*temp2=head2;
    node* head3=NULL;
    while(temp1!=NULL){
        s1.push(temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        s2.push(temp2->data);
        temp2=temp2->next;
    }
    temp1=s1.top;
    temp2=s2.top;
    int l1=s1.length();
    int l2=s2.length();
    if(l1<l2){
        stack s3=s1;
        s1=s2;
        s2=s3;
    }
    while(!s1.isempty() && !s2.isempty()){
        val1=s1.peek();
        s1.pop();
        val2=s2.peek();
        s2.pop();
        sum=val1+val2+carry;
        if(sum>=10){
            carry=sum/10;
            sum=sum%10;
        }
        else{
            carry=0;
        }
        head3=insertatbeginning(head3,sum);
    }
    while(!s1.isempty()){
        val1=s1.peek()+carry;
        s1.pop();
        if(val1>=10){
            carry=val1/10;
            val1=val1%10;
        }
        else{
            carry=0;
        }
        head3=insertatbeginning(head3,val1);
    }
    while(!s2.isempty()){
        val1=s2.peek()+carry;
        s2.pop();
        if(val2>=10){
            carry=val2/10;
            val2=val2%10;
        }
        else{
            carry=0;
        }
        head3=insertatbeginning(head3,val2);
    }
    if(carry!=0){
        head3=insertatbeginning(head3,carry);
    }
    return head3;
}
int  main(){
    node *head1=NULL,*head2=NULL;
    int pos;
    node* head=NULL;
    // head1= insertlinkedlist(head1,9);
    // head1= insertlinkedlist(head1,9);
    // head1= insertlinkedlist(head1,9);
    head1= insertlinkedlist(head1,4);
    head1= insertlinkedlist(head1,5);
    head1= insertlinkedlist(head1,6);
    head2= insertlinkedlist(head2,9);
    head2= insertlinkedlist(head2,9);
    head2= insertlinkedlist(head2,3);
    head2= insertlinkedlist(head2,4);
    head2= insertlinkedlist(head2,5);
    head2= insertlinkedlist(head2,6);
    head=addtwolist(head1,head2);
    print(head);
    
}