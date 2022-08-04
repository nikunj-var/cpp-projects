//previous smaller element
// #include<iostream>
// #include<vector>
// #include<stack>

// using namespace std;
// vector<int> previouselement(int *a,int n){
//     vector<int> res;
//     stack<int> s;
//     s.push(-1);
//     for(int i=0;i<n;i++){
//         while(!s.empty() && s.top()>=a[i]){
//             s.pop();
//         }
//         if(s.empty())
//             res.push_back(-1);
//         else
//             res.push_back(s.top());
//         s.push(a[i]);      
//     }
//     return res;
// }
// int main(){
//     int arr[8]={4,10,5,8,20,15,3,12};
//     int n=8;
//     vector<int> ans;
//     ans=previouselement(arr,n);
//     for(int i=0;i<8;i++)
//         cout<<ans[i]<<" ";
// }

//next smaller element
// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;
// vector<int> reverse(vector<int> res,int n){
//     int l=res.size();
//     for(int i=0;i<n/2;i++){
//         int temp=res[i];
//         res[i]=res[n-i-1];
//         res[n-i-1]=temp;
//     }
//     return res;
// }
// vector<int> previouselement(int *a,int n){
//     vector<int> res;
//     stack<int> s;
//     s.push(-1);
//     for(int i=n-1;i>=0;i--){
//         while(!s.empty() && s.top()>=a[i]){
//             s.pop();
//         }
//         if(s.empty())
//             res.push_back(-1);
//         else
//             res.push_back(s.top());
//         s.push(a[i]);      
//     }
//     res=reverse(res,n);
//     return res;
// }
// int main(){
//     int arr[8]={4,10,5,8,20,15,3,12};
//     int n=8;
//     vector<int> ans;
//     ans=previouselement(arr,n);
//     for(int i=0;i<8;i++)
//         cout<<ans[i]<<" ";
// }

//previous greater element
// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;

// vector<int> previouselement(int *a,int n){
//     vector<int> res;
//     stack<int> s;
//     s.push(-1);
//     for(int i=0;i<n;i++){
//         while(!s.empty() && s.top()<=a[i]){
//             s.pop();
//         }
//         if(s.empty())
//             res.push_back(-1);
//         else
//             res.push_back(s.top());
//         s.push(a[i]);      
//     }
//    // res=reverse(res,n);
//     return res;
// }
// int main(){
//     int arr[8]={3,10,5,1,15,10,7,6};
//     int n=8;
//     vector<int> ans;
//     ans=previouselement(arr,n);
//     for(int i=0;i<8;i++)
//         cout<<ans[i]<<" ";
// }


//nextgreater element
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> reverse(vector<int> res,int n){
    int l=res.size();
    for(int i=0;i<n/2;i++){
        int temp=res[i];
        res[i]=res[n-i-1];
        res[n-i-1]=temp;
    }
    return res;
}

vector<int> previouselement(int *a,int n){
    vector<int> res;
    stack<int> s;
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()<=a[i]){
            s.pop();
        }
        if(s.empty())
            res.push_back(-1);
        else
            res.push_back(s.top());
        s.push(a[i]);      
    }
    res=reverse(res,n);
    return res;
}
int main(){
    int arr[8]={3,10,5,1,15,10,7,6};
    int n=8;
    vector<int> ans;
    ans=previouselement(arr,n);
    for(int i=0;i<8;i++)
        cout<<ans[i]<<" ";
}