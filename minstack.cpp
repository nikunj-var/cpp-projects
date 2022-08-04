#include<iostream>
using namespace std;
class stack{
    int top;
        public:
    int a[1000];
      stack(){
        top=-1;
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
   
    
     int min(){
         return a[top];
     } 

      bool isempty(){
          return (top<0);
      }

      bool isfull(){
          return (top==1000-1);
      }
};
int main(){
    stack s1;
    s1.push(10);

     s1.push(20);
      s1.push(30);
       s1.push(40);
        s1.push(50);
         s1.push(60);

}