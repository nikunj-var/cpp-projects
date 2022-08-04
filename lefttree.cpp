#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int data)
    {
        key = data;
    }
};

vector<int> leftview(Node* root)
{
    vector<int> ans;
    queue<Node *> q;
    Node *temp;
    q.push(root);
    q.push(NULL);
    ans.push_back(root->key);
   
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp==NULL){
            if(q.size()>0)
                q.push(NULL);
            if(!q.empty()){
              temp=q.front();
              ans.push_back(temp->key);
              q.pop();
              }
        }
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
     return ans;
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->right->right = new Node(11);
    vector<int> a;
    a= leftview(root,a);
    cout<<a.size();
    for(int i=0;i<a.size();i++)
       cout<<a[i]<<endl;
    return 0;
}