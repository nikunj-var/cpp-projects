#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:
        int arr[100];
        int size=0;
        //insertion in heap
        void insert(int val){
            size=size+1;
            int index=size;
            arr[index]=val;
            while(index>1){
                int parent=index/2;
                if(arr[parent]<arr[index]){
                     swap(arr[parent],arr[index]);
                        index=parent;
                }
                else{
                    return;
                }
            }
        }
        //print heap
        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        void deletefromheap(){
            if(size==0){
                cout<<"nothing to delete"<<endl;
                return;
            }
            //put last element into first index
            arr[1]=arr[size];
            //remove last element
            size--;
            //take root node to its correct position
            int i=1;
            while(i<size){
                int leftindex=2*i;
                int rightindex=2*i+1;
                if(leftindex < size && arr[i]<arr[leftindex]){
                    swap(arr[i],arr[leftindex]);
                    i=leftindex;
                }
                else if(rightindex<size && arr[i]<rightindex){
                    swap(arr[i],arr[rightindex]);
                    i=rightindex;
                }
                else{
                    return;
                }
            }
        }
};
  int kthSmallest(int arr[], int l, int r, int k) {
      
        priority_queue<int> pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        for(int i=k;i<=r;i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans=pq.top();
        return ans;
    }
//isbinarytree heap
 solve(){
     //first check it is a cbt or not and ismax()
     
     if(iscbt() && ismaxorder()){
         return true;
     }
     else
        return false;

    //to check whether it is a cbt or nit
    bool iscbt(node* root,currentnodeoindex,nodecount){
        if(root==NULL)
            return true;
        if(i>=nodecount)
            return false;
        else{
            left=iscbt(root->left,2*i+1,nodecount);
            right=iscbt(root->right,2*i+2,nodecount);
            return left&&right;
        }
    }
    bool ismaxorder(root ){
        //both child exist
        //left node
        //only leaf exist

        //if leaf node 
        //return true

        if(right==NU)
    }    
 }

int main(){
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.insert(60);
    h.deletefromheap();
    heapify(h.arr,,0);
    h.print();
}