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
// void middle(node *head){
//     node *temp=head;
//     int n=0;
//     while(temp!=0){
//         n++;
//         temp=temp->next;
//     }
//     int k=n/2;
//     temp=head;
//     int i=0;
//     while(i<n/2){
//         temp=temp->next;
//         i++;
//     }
//     cout<<temp->data;
// }
node* middle(node* head){
    node* slow,*fast;
    slow=fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
    return slow;
}
node* deletenode(node* head,node* temp){
    node *t;
    t=temp->next;
    temp->data=temp->next->data;
    temp->next=temp->next->next;
    free(t);
    return head;
}
// node* evenodd(node* head){
//     node* temp=head,*temp1=NULL,*temp2=NULL;
//     node* head2=NULL;
//     while(temp!=NULL){
//             if(temp->data%2==0){
//                 temp1=temp;
//                 temp=temp->next;
//             }
//             else{
//                 temp2=temp;
//                 head2=insertlinkedlist(head2,temp->data);
//                 if(temp==head){
//                 head=head->next;
//                 temp=head;
//                 }
//                 else{
//                     temp1->next=temp->next;
//                     temp=temp->next;
//                 }
//                 free(temp2);
//             } 
//     }
//     temp=head2;
//     while(temp!=NULL){
//         head=insertlinkedlist(head,temp->data);
//         temp=temp->next;
//     }
//     return head;
// }
//in space complexity O(1)
node* evenodd(node* head){
    node* evenhead=NULL,*eventail=NULL;
    node* oddhead=NULL,*oddtail=NULL;
    node* temp=head;
    if(head==NULL){
        return head;
    }
    else{
        while(temp!=NULL){
            if(temp->data%2==0){
                if(evenhead==NULL){
                    evenhead=eventail=temp;
                }
                else{
                    eventail->next=temp;
                    eventail=temp;
                }
            }
            else{
                if(oddhead==NULL){
                    oddhead=oddtail=temp;
                }
                else{
                    oddtail->next=temp;
                    oddtail=temp;
                }
            }
            temp=temp->next;
        }
    }
    oddtail->next=NULL;
    eventail->next=oddhead;
    return evenhead;
}
node* modularfrombegin(node* head){
    int k;
    cout<<"enter k";
    cin>>k;
    node* mod;
    int i=0;
    if(k<=0){
        return NULL;
    }
    else{
        for(;head!=NULL;head=head->next){
            if(i%k==0){
                mod=head;
            }
            i++;
        }
    }
    return mod;
}
node* modularfromend(node* head){
    int k;
    cout<<"enter k";
    cin>>k;
    node* mod=NULL;
    int i=0;
    if(k<=0){
        return NULL;
    }
    else{
        for(i=0;i<k;i++){
            if(head){
                head=head->next;
            }
            else{
                return NULL;
            }
        }
        while(head!=NULL){
            mod=mod->next;
            head=head->next;
        }
    }
    return mod;
}
node *sqrt(node* head){
    node *sqr=NULL;
    node *temp=head;
    int i=1,j=1;
    for(;temp!=NULL;temp=temp->next){
        if(i==j*j){
            if(sqr==NULL){
                sqr=head;
            }
            else{
                sqr=sqr->next;
            }
            j++;
        }
        i++;
    }
    return sqr;
}
int main(){
    node *head=NULL;
    int pos;
    head= insertlinkedlist(head,1);
    head= insertlinkedlist(head,23);
   //head= insertlinkedlist(head,25);
    head= insertlinkedlist(head,30);
    head= insertlinkedlist(head,401);
    head= insertlinkedlist(head,501);
    head= insertlinkedlist(head,60);
   // head= deletenode(head,head->next->next);
   // middle(head);
   //head=evenodd(head);
  // head=modularfrombegin(head);
    //   head=modularfromend(head);
    //      cout<<head->data;
    head=sqrt(head);
    cout<<head->data;
   //print(head);
}