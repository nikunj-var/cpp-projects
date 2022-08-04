#include<iostream>
#include<limits.h>
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
int findmax(tree* root){
    int rval,l,r,max=INT_MIN;
    if(root!=NULL){
        rval=root->data;
        l=findmax(root->left);
        r=findmax(root->right);
        if(l>r)
            max=l;
        else
            max=r;
        if(rval>max){
            max=rval;
        }        
    }
    return max;
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
    cout<<findmax(root);
}
  