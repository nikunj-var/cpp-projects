/*#include<iostream> 
using namespace std;
struct queue{
    int f;
    int r;
    int size;
    int* arr;
};
int isempty(struct queue* q){
    if(q->r==q->f)
        return 1;
    return 0;
}
int isfull(struct queue* q){
    if(q->r==q->size-1)
        return 1;
    return 0;    
}
void enqueue(struct queue* q,int val){
    if(isfull(q))
        return;
    q->r++;
    q->arr[q->r]=val;    
}
int dequeue(struct queue* q){
    int a=-1;
    if(isempty(q))
        return;
    else{
        q->f++;
        a=q->arr[q->f];
    }    
    return a;
}
int main(){
    struct queue q;
    q.size=400;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    //BFS implementation
    int u;
    int i=0;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    cout<<i;
    visited[i]=1;
    enqueue(&q,i);
    while(!isempty(&q)){
        int node=dequeue(&q);
        for(int j=0;j<7;i++){
            if(a[node][j]==1 && visited[j]==0){
                cout<<j<<endl;
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }   
     return 0;
}
*/
#include<iostream>
#include<set> 
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;

void prepareadjlist(unordered_map<int,set<int>> &adjlist, vector<pair<int,int>> edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}
void bfs(unordered_map<int,set<int>>& adjlist,unordered_map<int,bool>& visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        ans.push_back(frontnode);
        for(auto i:adjlist[frontnode]){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

int main(){
    unordered_map<int,set<int>> adjlist;
    vector<int> ans;
    unordered_map<int,bool> visited;
    int vertex;
    vector<pair<int,int>> edges;
    cout<<"enter number of edges and vertex";
    cin>>edges;
    cin>> vertex;
    prepareadjlist(adjlist,edges);
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjlist,visited,ans,i);
        }
    }
}