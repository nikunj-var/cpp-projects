#include<iostream>
#include<queue>
#include<stack>
#include<deque>
using namespace std;
int main(){
    // queue<int> q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // q.push(70);
    // q.push(80);
    // q.push(90);
    // q.push(100);
    // int l=q.size()/2;
    // stack<int> s;
    // for(int i=0;i<l;i++){
    //     s.push(q.front());
    //     q.pop();
    // }
    // while(!s.empty()){
    //     q.push(s.top());
    //     s.pop();
    // }
   
    // for(int i=0;i<l;i++){
    //     q.push(s.top());
    //     s.pop();
    //     q.push(q.front());
    //     q.pop();
    // }
    // for(int i=0;i<10;i++){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    deque<int> dq;
    dq.push_front(10);
    dq.push_back(20);
    cout<<dq.back();
}