#include<iostream>
using namespace std;
class stack{
    int top;
    
    public:
    char a[1000];
      stack(){
        top=-1;
      }
      bool push(char x){
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
bool ispalindrome(string s){
    int l=s.length();

    int begin=0;
    int end=l-1;
    while(begin<end && s[begin]!='X' && s[end]!='X'){
        if(s[begin]==s[end]){
            begin++;
            end--;
        }
        else
            return false;
    }
    return true;
}
int main(){
    string s;
    cout<<"enter string";
    cin>>s;
    stack s1;
    int i=0;
    while(s[i]!='X'){
    s1.push(s[i]);
    i++;
    }
    int l=s.length();
    while(i++<l && !s1.isempty()){
        if(s1.peek()==s[i]){
            s1.pop();
        }
        else{
            cout<<"string is not palindrome";
            break;
        }
    }
    cout<<"string is palindrome";
    // if(ispalindrome(s))
    //     cout<<"string is palindrome";
    // else
    //     cout<<"string is not palindrome";    
}