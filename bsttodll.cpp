#include<iostream>
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
tree* head;
void inorder(tree* root,tree* &prev){
    if(root==NULL)
        return;
    inorder(root->left,prev);
    if(prev==NULL){
        head=root;
    }
    else{
        prev->left=NULL;
        prev->right=root;
        root->left=prev;
    }
    prev=root;
    inorder(root->right,prev);
}
tree* flatten(tree* root){
    tree* dummy=new tree(-1);
    tree* prev=NULL;
    inorder(root,prev);
    return head;
}
int main(){
    tree* root=NULL;
    root=new tree(5);
    root->left=new tree(3);
    root->right=new tree(7);
    root->left->left=new tree(2);
    root->left->right=new tree(4);
    root->right->left=new tree(6);
    root->right->right=new tree(8);
    tree* dll=flatten(root);
    while(dll){
        cout<<dll->data<<" ";
        dll=dll->right;
    }
}