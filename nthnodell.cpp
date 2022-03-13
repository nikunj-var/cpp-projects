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
//int findnthnode(node *head,int n){
    // using m-n+1th rule
//     node *temp=head;
//     int count=0;
//     while(temp!=0){
//         count=count+1;
//         temp=temp->next;
//     }
//    int k=count-n+1;
//    int d;
//    temp=head;
//    int i=1;
//    while(i<=k-1){
//        temp=temp->next;
//        i++;
//    }
//     cout<<temp->data;
  
//    //return d;

//}

//using twopointer approach
void findnthnode(node *head,int n){
    node *pnthnode=NULL;
    node* ptemp=head;
    for(int i=1;i<n;i++){
        if(ptemp)
            ptemp=ptemp->next;
    }
    while(ptemp){
        if(pnthnode==NULL){
            pnthnode=head;
        }
        else{
            pnthnode=pnthnode->next;
        }
        ptemp=ptemp->next;
    }
    cout<<pnthnode;
}
void print(node *head){
    node* temp=head;
    while(temp!=NULL){
        cout<<tem>data<<endl;
        temp=temp->next;
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
   // print(head);
    cout<<"enter n";
    cin>>n;
    //cout<<
    findnthnode(head,n);
}
