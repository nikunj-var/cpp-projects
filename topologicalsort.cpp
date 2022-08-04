//it(TS) works only on DAG(Directed Acyclic Graph)

//it(TS) is a linear ordering of vertices such that for every edge u->v ,u always appear before v in that ordering

//A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.
//Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

//TOPOLOGICAL SORTING USING DFS

//TC-O(N+E)
//SC-O(N)

#include<unordered_map>
#include<list>
#include<stack>
void toposort(int node, vector<bool>& visited,stack<int> &s,unordered_map<int,list<int>>& adj){
    visited[node]=1;
    for(auto i:adj[node]){
        if(!visited[i]){
            toposort(i,visited,s,adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
  //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
  //call dfs topological sort util function for all components
    vector<bool> visited(v);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i])
            toposort(i,visited,s,adj);    
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

//TOPOLOGICAL SORTING USING BFS

//STEP1-FIND INDEGREE OF AL NODES
//STEP2-JISKI INDEGREE ZERO HO USE QUEUE KE ANDAR DAAL DO
//STEP3- DO BFS
// USKE BAD QUEUE KE FRONT KO NIKALKE POP KARO OR ANSWER ME STORE KRO
//1->2,3
//2->5
//3->5
//5->4
//4->

#include<unordered_map>
#include<list>
#include<stack>
#include<queue>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
  //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    //FIND ALL INDEGREE
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //dp bfs
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    return ans;
}


