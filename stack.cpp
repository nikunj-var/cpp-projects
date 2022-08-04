#include<iostream>
using namespace std;
class stack{
    int top;
    
    public:
    int a[1000];
      stack(){
        top=-1;
      }
      bool push(int x){
          if(top>=1000-1){
              cout<<"stack overflow";
              return false;
          }
          else{
              a[++top]=x;
              return true;
          }
      }
      int pop(){
          if(top<0){
              cout<<"Stack underflow";
              return 0;
          }
          else{
              int x=a[top--];
              return x;
          }
      }
      int peek(){
          if(top<0){
              cout<<"stack underflow";
              return 0;
          }
          else{
              return a[top];
          }
      }
      bool isempty(){
          return (top<0);
      }
      bool isfull(){
          return (top==1000-1);
      }
};
int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<"element present in stack are";
    while(!s.isempty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
    if(s.isfull())
        cout<<"stack is full";
    else
        cout<<"stack is not full";    
}