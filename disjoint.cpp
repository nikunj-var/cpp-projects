#include<iostream>
using namespace std;
class disjoint{
    int n,*rank,*parent;
public:
    disjoint(int n){
        rank=new int[n];
        parent=new int[n];
        this->n=n;
        makeset();
    }
    void makeset(){
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    // int find(int x){
    //     if(parent[x]!=x){
    //         parent[x]=find(parent[x]);
    //     }
    //     return parent[x];
    // }
    //find with path compression
    int find(int x){
        if(parent[x]==x)
            return x;
        else
            return (parent[x]=find(parent[x]));
    }
    void Union(int x,int y){
        int xset=find(x);
        int yset=find(y);
        if(xset==yset)
        return;
        if(rank[xset]<rank[yset]){
            parent[xset]=yset;
        }
        else if(rank[yset]<rank[xset]){
            parent[yset]=xset;
        }
        else{
            parent[yset]=xset;
            rank[xset]=rank[xset]+1;
        }
    }
};
int main(){
    disjoint j(5);
    j.Union(0,2);
    j.Union(4,2);
    j.Union(3,1);
    if(j.find(4)==j.find(0))
    cout<<"yes\n";
    else
    cout<<"no\n";
    return 0;
}