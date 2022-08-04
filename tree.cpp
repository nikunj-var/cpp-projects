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
void postorder(tree* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
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
   postorder(root);
}