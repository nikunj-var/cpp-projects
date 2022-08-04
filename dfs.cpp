//step1 prepare adjacencylist
//step2 

void dfs(int node,unordered_map<int,set<int>>& adjlist,unordered_map<int,bool>& visited,vector<int>& component){
    component.push_back(node);
    visited[node]=i;
    for(auto i:adjlist[node]){
            if(!visited[i]){
                dfs(i,adjlist,visited,component);
            }
    }
}
void prepareadjlist(unordered_map<int,set<int>> &adjlist, vector<pair<int,int>> edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}

vector<vector<int>> depthfirstsearch(int v,int e,vector<vector<int>> edges){
    unordered_map<int,set<int>> adjlist;
    prepareadjlist(adjlist,edges);
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
     for(int i=0;i<v;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,adjlist,visited,component);
            ans.push_back(component);
        }
    }

}