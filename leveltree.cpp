#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class tree{
    public:
        int data;
         tree* left;
         tree* right;
         tree(int val){
             data=val;
             left=NULL;
             right=NULL;
        }   
};
//   queue<tree*> q1,q2;
//   stack<tree*> s;
// void levelorder(tree* root){
//     tree* temp;
//     if(root==NULL)
//         return;
//     q1.push(root);
//     while(!q1.empty()){
//         temp=q1.front();
//         q1.pop();
//         if(temp->right)
//             q1.push(temp->right);
//         if(temp->left)
//             q1.push(temp->left);
       
//         s.push(temp);        
//     }
//     while(!s.empty()){
//         temp=s.top();
//         cout<<temp->data<<endl;
//         s.pop();
//     }
// }
queue<int> q;
void deleten(tree* root){
    q.push(root->data);
    if(root==NULL)
        return;
    delete(root->left);
    delete(root->right);
    cout<<root->data;
    free(root);    
}
int main(){
    tree* root=NULL;
    root=new tree(1);
    root->left=new tree(2);
    root->right=new tree(3);
    root->left->left=new tree(4);
    root->left->right=new tree(5);
    root->left->left->left=new tree(6);
    root->right->left=new tree(7);
    root->right->right=new tree(8);
    root->right->right->left=new tree(9);
    root->right->right->right=new tree(10);
    //  levelorder(root);   
    deleten(root);
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
}