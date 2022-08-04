#include<iostream>
#include<string>
using namespace std;
void removeduplicate(string str){
    int stkptr=-1;
    int i=0,l=str.length();
    while(i<l){
        if(stkptr==-1 || str[stkptr]!=str[i]){
            stkptr++;
            str[stkptr]=str[i];
            i++;
        }
        else{
            while(i<l && str[stkptr]==str[i])
            i++;
            stkptr--;
        }
    }
    str[stkptr+1]='\0';
    for(int i=0;str[i]!='\0';i++)
        cout<<str[i];
}
int main(){
    string s;
    cout<<"enter string";
    cin>>s;
    removeduplicate(s);
}