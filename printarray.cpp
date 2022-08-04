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
void printarray(int path[],int n){
    for(int i=0;i<n;i++)
        cout<<path[i]<<" ";
    cout<<endl;
}
void printpath(tree* root,int path[],int pathlen){
    if(root==NULL)
        return;
    path[pathlen++]=root->data;
    if(root->left==NULL && root->right==NULL)
        printarray(path,pathlen);
    else{
        printpath(root->left,path,pathlen);
         printpath(root->right,path,pathlen);
        
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
    printpath(root,path,0);
}
