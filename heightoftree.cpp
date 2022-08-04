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
           stack<int> s;
                             
void postorder(tree* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void display(tree* root){
    queue<tree*> q,q2;
    tree* temp;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q2.push(temp);
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);    
    }
    //q2.push(temp);
    while(!q2.empty()){
        temp=q2.front();
        cout<<temp->data<<endl;
        q2.pop();
        
    }
}
// HEIGHT-->LONGEST PATH BETWEEN ROOT NODE AND LEAF NODE.
// NUMBER OF NODES IN THAT PATH IS HEIGHT OF THE TREE.
int height(tree* root){
    if(root==NULL)
        return 0;
    int left=height(root->left);
    int right=height(root->right);
    int ans=left>right?left:right + 1;
    return ans;    
}

//HEIGHT OF TREE WITHOUT RECURSION
int height2(tree* root){
    int level=0;
    queue<tree*> q;
    if(root==NULL)
        return 0;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            root=q.front();
            q.pop();
            if(root==NULL){
                if(!q.empty())
                    q.push(NULL);
                level++;
            }
            else{
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);    
            }
        }
        return level;
}

//size of binary tree
int size(tree* root){
    if(root==NULL)
        return 0;
    return (size(root->left)+1+size(root->right));    
}
//DEEPEST NODE IN BINARY TREE
tree* deepest(tree* root){
    tree* temp;
    queue<tree*> q;
    if(root==NULL)
        return NULL;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }    
    return temp;
}

//DELETE AN ELEMENT FROM BINARY TREE
tree* find(tree* root,int d){
    tree* temp;
    tree* temp2;
    queue<tree*> q;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp->data==d)
            temp2=temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);    
    }
    int t=temp->data;
    temp->data=temp2->data;
    temp2->data=t;
    free(temp);
    return root;
}
int sumintree(tree* root,int sum){
    if(root==NULL)
        return sum==0;
    int remainingsum=sum-root->data;
    if((root->left&&root->right)||(!root->left && !root->right))
        return (sumintree(root->left,remainingsum)||sumintree(root->right,remainingsum));
    else if(root->left){
        return sumintree(root->left,remainingsum);
    }    
    else
        return sumintree(root->right,remainingsum);
}
void printarray(int arr[],int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void printpath(tree* root,int path[],int pathlen){
    if(root==NULL)
        return;
    path[pathlen]=root->data;
    pathlen++;
    if(root->left==NULL && root->right==NULL)
        printarray(path,pathlen);
    else{
        printpath(root->left,path,pathlen);
        printpath(root->right,path,pathlen);
    }        
}
int sum=0;
int sumoftree(tree* root){
    if(root==NULL)
        return 0;
    sum+=root->data;
    sumoftree(root->left);
    sumoftree(root->right);
    return sum;    
}
tree* mirror(tree* root){
    tree* temp;
    if(root){
        mirror(root->left);
        mirror(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    return root;
}
//DIAMETER-->LONGEST PATH BETWEEN ANY TWO NODES
//NO. OF NODES = WIDTH OF THE TREE 

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
    // cout<<height(root);
    //cout<<size(root);
    // tree* ans=deepest(root);
    // cout<<ans->data;
    // root=find(root,4);
    // display(root);
    // printpath(root,path,0);
    //cout<<sumintree(root,40);
    // cout<<sumoftree(root);
    root=mirror(root);
    postorder(root);
    
}
