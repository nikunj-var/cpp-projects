#include<iostream>
using namespace std;
void swapal(int arr[6],int n){
    for(int i=0;i<n;i+=2){
        if(i==n-1)
           break;
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
int main(){
    int arr[6]={1,2,3,4,5,6};
    swapal(arr,6);
}