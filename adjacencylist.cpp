#include<iostream>
#include<map>
#include<list>
using namespace std;

class graph{
    public:
        map<int,list<int>> ad;
        void addedge(int u,int v,bool direction){
            //create an edge from u to v
            ad[u].push_back(v);
            if(direction==0)
                ad[v].push_back(u);

        }
        void printlist(){
            for(auto i:ad){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<" ,";
                }
            cout<<endl;
            }   
        }
};

int main(){
    int n;
    cout<<"enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"enter the number of edges"<<endl;
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,0);
    }
    g.printlist();
}