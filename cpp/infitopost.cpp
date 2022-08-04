#include <iostream>
#include<stdlib.h>
using namespace std;

struct node{
    char data;
    node*next;
}*top=0;
void push(char ch){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ch;
    newnode->next=top;
    top=newnode;
}
void pop(){
    struct node*temp;
    temp=top;
    if(top==0)
        cout<<"overflow";
    else{
        top=top->next;
        free(temp);
    }    
}
int empty(){
    if(top==-1)
    return 0;

    return 1;
}

int prec(char c){
    if(c=='^')
        return 3;
    else if(c=='/'|| c=='*')
        return 2;
    else if(c=='+'||c=='-')
    return 1;
    else
        return -1;        
}
void infixtopostfix(string s){
struct node *st;
string result;
for(int i=0;i<s.length();i++){
    char c=s[i];
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        result+=c;
    else if(c=='(')
        push(c);
    else if(c==')'){
        while(top->data!='('){
            result+=top->data;
            pop();
        }
        pop();
    }    
    else{
        while(!empty()&& prec(s[i])<=prec(top->data)){
            result+=top->data;
            pop();

        }
        push(c);
    }
}
while(!empty()){
    result+=top->data;
    pop();
}
cout<<result;
}

void infixtopostfix()
int main(){
    string s="a+b*(c^d-e)^(f+g*h)-i";
    infixtopostfix(s);
}