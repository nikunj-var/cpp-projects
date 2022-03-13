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
            if()
        }
    }   
     return 0;
}