//SHORTEST PATH IN GRAPH using BFS
//create adjacency list
//SABKE PARENT STORE KARA DO EK ARRAY ME USKE BAD DESTINATION NODE SE SOURCE NODE TAK PAHUCH JAO
//TC-O(n+e)
//SC-O(n+e)

#include<unordered_map>
#include<list>
#include<stack>
#include<queue>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(s);
    parent[s]=-1;
    visited[s]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        }
    }
    //prepare shortest path
    vector<int> ans;
    int currentnode=t;
    ans.push_back(currentnode);
    while(currentnode!=s){
        currentnode=parent[currentnode];
        ans.push_back(currentnode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

//SHORTEST PATH IN ACYCLIC DIRECTED GRAPH
//STEP1-FIND TOPOLOGICAL SORT
//STEP2-
