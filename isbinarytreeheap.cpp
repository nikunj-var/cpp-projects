class Solution {
  public:
  
int countnode(struct Node* root){
    if(root==NULL)
        return 0;
    int ans=1+countnode(root->left)+countnode(root->right);
    return ans;
}
bool iscbt(struct Node* root,int index,int cnt){
    if(root==NULL)
        return true;
    if(index>=cnt)
        return false;
    else{
        bool left=iscbt(root->left,2*index+1,cnt);
        bool right=iscbt(root->right,2*index+2,cnt);
        return (left&&right);
    }    
}
bool ismaxorder(struct Node* root){
    if(root->left==NULL && root->right==NULL)
        return true;
    if(root->right==NULL)
        return (root->data > root->left->data);
    else{
        bool left=ismaxorder(root->left);
        bool right=ismaxorder(root->right);
        if(left && right && (root->data>root->left->data) && (root->data>root->right->data))
            return true;
    }
    return false;
}
bool isHeap(struct Node* root) {
    
    int index=0;
    int totalcount=countnode(root);
    if(iscbt(root,index,totalcount) && ismaxorder(root))
        return true;
    else
        return false;
    
}

};