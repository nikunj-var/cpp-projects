class Nstack{

    int *arr,*top,*next;
    int n,s;
    int freespot;

    public:
        //initialize your data structure
        Nstack(int N,int S){

            n=N;
            s=S;
            arr=new int[s];
            next=new int[s];
            top=new int[n];

            //top initialize
            for(int i=0;i<n;i++){
                top[i]=-1;
            }            

            //next initialize
            for(int i=0;i<s;i++){
                next[i]=i+1;
            }
            //update last index value to -1
            next[s-1]=-1;
            //initialize freespot
            freespot=0;
    }

    //pushes 'x' into the mth stack.return true if element is pushed    
    bool push(int x,int n){
        
        //check for overflow
        if(frespot==-1)
            return false;
        
        //find index
        int index=freespot;
        
        //update frespot
        freespot=next[i];

        //insertelement into array
        arr[index]=x;

        //update index
        next[index]=top[m-1];

        //update top
        top[m-1]=index;

        return true;
    }

    //pop top element from mth index
    int pop(int m){

        //check underflow condition
        if(top[m-1]==-1)
            return -1;

        int index=top[m-1];

        top[m-1]=next[index];

        next[index]=freespot;
 
        freespot=index;

        return arr[index];    
    }
}                                                                    