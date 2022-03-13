#include<iostream>
#include<stdlib.h>
using namespace std;
int arraysorted(int arr[],int n){
    if(n==1)
        return 1;
    return (arr[n-1]<arr[n-2])?0:arraysorted(arr,n-1);
}
int main(){
    int n,*arr;
    cin>>n;
    arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(arraysorted(arr,n)==1)
        cout<<"\nsorted";
    else
        cout<<"\nunsorted";    
}