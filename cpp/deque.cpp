#include<iostream>
using namespace std;
#define n 5
int deque[n];
int f=-1;
int r=-1;
void enqueuefromfront(int x){
    if((f==0 && r==n-1)||f==r+1) {
        cout<<"queue is full!!";
 }
 else if(f==-1 && r==-1){
     f=0;
     r=0;
     deque[f]=x;
 }
 else if(f==0){
     f=n-1;
     deque[f]=x; 
 }
 else{
      f--;
      deque[f]=x;                                                                    
 }
}
void enqueuerear(int x){
    if((f==0 && r==n-1)||f==r+1)
        cout<<"queue is full";
    else if(f==-1 && r==-1){
        f=r=0;
        deque[r]=x;

    }   
    else if(r==n-1){
        r=0;
        deque[r]=x;
    } 
    else{
        r++;
        deque[r]=x;
    }
}
void dequeuefromfront(){
        if(f==-1&&r==-1)
        cout<<"stack is empty";
        else if(f==n-1){
            cout<<deque[f]<<" "<<endl;
            f=0; 
        }
        else{
            cout<<deque[f]<<" "<<endl;
            f++;

        }
}
void dequefromrear(){
    if(f==-1 && r==-1)
    cout<<"queue is empty";
    else if(f==r)
        f=r=-1;
    else if(r==0){
        cout<<"deleted element is"<<deque[r]<<" "<<endl;
        r=n-1;
    }    
    else{
        cout<<"deleted element is"<<deque[r]<<" "<<endl;
        r=r-1;

    }
}
void display(){
    int i=f;
    cout<<"queue elements are :"<<endl;
    while(i!=r){
        cout<<deque[i]<<" "<<endl;
        i=(i+1)%n;
        }
            cout<<deque[r]<<" "<<endl;
}
void getfront(){
    cout<<"front of the queue is"<<deque[f]<<endl;
}
int main(){
int x;
int ch;
for(int i=0;i<5;i++){
    cout<<"enter data";
    cin>>x;
cout<<"enter choice.. 1-enqueue front  2.enqueue rear";
cin>>ch;
switch(ch){
    case 1:enqueuefromfront(x);
            break;
    case 2:enqueuerear(x);
            break;
    default:{cout<<"wrong choice";
                i--;}
}
}
dequefromrear();
getfront();
display();


}