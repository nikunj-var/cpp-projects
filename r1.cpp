#include<iostream>
#include<string.h>
using namespace std;
int count=0;
int stringcon(string s,int l){
  if(l==0){
      return count;
  }
    if(s[l]!='e' && s[l]!='a' && s[l]!='i'&& s[l]!='o'&&s[l]!='u'){
        count++;
    }

    return stringcon(s,--l);
}
int main(){
    string s;
    cout<<"enter string ";
    cin>>s;
    cout<<stringcon(s,s.length());

}