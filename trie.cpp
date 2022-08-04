#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isterminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<20;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};
class trie{
    public:
        TrieNode* root;
        void insertatutil(TrieNode* root,string word){
            if(word.length()==0)
                root->isterminal=true;

            //assumption word will be in CAPS
            int index=word[0]-'A';
            TrieNode* child;

            //present
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{
                //absent
                child=new TrieNode(word[0]);
                root->children[index]=child;
            }
            insertatutil(child,word.substr(1));
        }
        void insertword(string word){
            insertatutil(root,word);
        }
        bool searchutil(TrieNode* root,string word){
                if(word.length()==0){
                    return root->isterminal;
                }
                int index=word[0]-'A';
                TrieNode* child;
                if(root->children[index]!=NULL)
                    child=root->children[index];
                else{
                    return false;
                }
                return searchutil(child,word.substr(1));
        }
        bool search(string word){
            return searchutil(root,word);
        }
};
int main(){
    trie *t= new trie();
    t->insertword("abcd");
    cout<<t->search("abcd");
    return 0;
}