//creation of linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
//void print(node* head);
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
//iterative solution
/*node *mergelist(node* head1 ,node* head2){
    node* newnode=new node(0);
    node* temp;
    temp=newnode;
    while(head1!=NULL && head1!=NULL){
        if(head1->data <= head2->data){
             temp->next=head1;
             head1=head1->next;
        }
        else{
            temp->next=head2;
            head2=head2->next;
         }
        temp=temp->next;
    }
    if(head1!=NULL){
        temp->next=head1;
    }
    else{
        temp->next=head2;
    }
    temp=newnode->next;
    free(newnode);
   // print(temp);
    return temp;
}
*/

// node* mergelist(node *a,node* b){
//     node* result=NULL;
//     if(a==NULL)
//         return NULL;
//     if(b==NULL)
//         return NULL;
//     if(a->data <= b->data){
//         result=a;
//         result->next=mergelist(a->next,b);
//     }        
//     else{
//         result=b;
//         result->next=mergelist(b->next,a);
//     }
//     return result;
// }
//to print common element of both linked list
node* commonelement(node* head1,node* head2){
    node *temp=new node(0);
    node* head=temp;
    node *temp1;
    while(head1!=NULL && head2!=NULL){
        if(head1->data==head2->data){
            // temp1=new node(head1->data);
            // head->next=temp1;
            head->next=new node(head1->data);
            head1=head1->next;
            head2=head2->next;
            head=head->next;
        }
        else if(head1->data > head2->data){
            head2=head2->next;
        }
        else{
            head1=head1->next;
        }
    }
    return temp->next;
}
node* alternatemerge(node* head1,node* head2){
    node* newnode=new node(0);
    node* temp=newnode;
    while(head1!=NULL && head2!=NULL){
        temp->next=head1;
        head1=head1->next;
        temp=temp->next;
        temp->next=head2;
        temp=temp->next;
        head2=head2->next;
    }
    if(head1!=NULL){
        temp->next=head1;
    }
    else{
        temp->next=head2;
    }
    temp=newnode->next;
    free(newnode);
    return temp;
}
int  main(){
    node *head1=NULL,*head2=NULL;
    int pos;
    node* head=NULL;
   // cout<<"\nfirstlinked list\n";
    head1= insertlinkedlist(head1,1);
    head1= insertlinkedlist(head1,2);
    head1= insertlinkedlist(head1,3);
    head1= insertlinkedlist(head1,4);
    head1= insertlinkedlist(head1,5);
    head1= insertlinkedlist(head1,6);
   //  print(head1);
   // cout<<"\nsecond linked list\n";
    head2= insertlinkedlist(head2,1);
    head2= insertlinkedlist(head2,3);
    head2= insertlinkedlist(head2,5);
    head2= insertlinkedlist(head2,40);
    head2= insertlinkedlist(head2,50);
    head2= insertlinkedlist(head2,60);
   // print(head2);
    //cout<<"\nmerged list\n";
    // node* head=mergelist(head1,head2);
 //   head=commonelement(head1,head2);
    head=alternatemerge(head1,head2);
    print(head);
}