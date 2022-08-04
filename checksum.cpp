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
int checksum(tree* root,int sum){
    if(root==NULL)
        return (sum==0);
    else{
        int remainsum=sum-root->data;
        if((root->left&&root->right)||(!root->left&&!root->right))
            return (checksum(root->left,remainsum)||checksum(root->right,remainsum));
        else if(root->left)
            return checksum(root->left,remainsum);
        else
            return checksum(root->right,remainsum);
    }    
}
int main(){
    int path[20];
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
    cout<<checksum(root,13);
}
