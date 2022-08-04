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
void insertatbottom(stack *s,int data){
    int temp;
    if(s.isempty())
    {
        s.push(data);
        return;
    }    
    temp=s.pop();
    insertatbottom(s,data);
    s.push(temp);
}
void reversestack(stack *s){
    int data;
    if(!s.isempty())
        return;
    data=s.pop();
    reversestack(s);
    insertatbottom(s,data);    
}
int main(){
    stack s1;
     s1.push(1);
     s1.push(2);
     s1.push(3);
     s1.push(4);
     s1.push(5);
    reversestack(s1);
    while(!s1.isempty()){
        cout<<s1.peek();
        s1.pop();
    }
}