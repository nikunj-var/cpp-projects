#include<iostream>
using namespace std;
void finddepth(int arr[],int n){
    int maxd=-1,currd=-1;
    int j;
    for(int i=0;i<n;i++){
        currd=0,j=i;
        while(arr[j]!=-1){
            currd++;
            j=arr[j];
        }
        if(maxd<currd)
        maxd=currd;
    }
   cout<<maxd;
}
int main(){
    int arr[]={-1,0,1,6,6,0,0,2,7};
    int n=9;
    finddepth(arr,n);
   
}