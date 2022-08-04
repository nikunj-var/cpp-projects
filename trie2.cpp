#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

#define ALPHABET_SIZE 26

class TrieNode {
  public:
    TrieNode * children[ALPHABET_SIZE];
    bool isEndWord;

    TrieNode(){
         this -> isEndWord = false;
         for (int i = 0; i < ALPHABET_SIZE; i++) {
         this -> children[i] = NULL;
         }
    }
    //Function to mark the currentNode as Leaf
    void markAsLeaf() {
    this -> isEndWord = true;
    }

    //Function to unMark the currentNode as Leaf
    void unMarkAsLeaf() {
    this -> isEndWord = false;
    }

};

class Trie {
  public:
    TrieNode * root;
    Trie() {
    root = new TrieNode();
    }
    //Function to get the index of a character 't'
    int getIndex(char t) {
    return t - 'a';
    }

    //Function to insert a key,value pair in the Trie
    void insertNode(string key) {
    //Empty string is not allowed
    if (key.empty())
        return;

    //using transform() function and ::tolower in STL to convert 'key' to lowercase
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    TrieNode * currentNode = root;
    int index = 0;

    //Iterate the trie with the given character index,
    //If the index points to NULL
    //simply create a TrieNode and go down a level
    for (int level = 0; level < key.length(); level++) {
        index = getIndex(key[level]);

    if (currentNode -> children[index] == NULL) {
      currentNode -> children[index] = new TrieNode();
    }
    currentNode = currentNode -> children[index];
    }

    //Mark the end character as leaf node
    currentNode -> markAsLeaf();
}

    //Function to search given key in Trie
    bool searchNode(string key) {
    if (key.empty())
        return false;

    //using transform() function and ::tolower in STL to convert 'key' to lowercase
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    TrieNode * currentNode = root;
    int index = 0;

    //Iterate the Trie with given character index,
    //If it is NULL at any point then we stop and return false
    //We will return true only if we reach leafNode and have traversed the
    //Trie based on the length of the key
    for (int level = 0; level < key.length(); level++) {
    index = getIndex(key[level]);

    if (currentNode -> children[index] == NULL)
      return false;
    currentNode = currentNode -> children[index];
    }
     if (currentNode != NULL and currentNode -> isEndWord)
        return true;
    return false;
}

bool hasNoChildren(TrieNode * currentNode) {
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if ((currentNode -> children[i]) != NULL)
      return false;
  }
  return true;
}
//Recursive function to delete given key
bool deleteHelper(string key, TrieNode * currentNode, int length, int level) {
  bool deletedSelf = false;

  if (currentNode == NULL) {
    cout << "Key does not exist\n";
    return deletedSelf;
  }

  //Base Case: If we have reached at the node which points to the alphabet at the end of the key.
  if (level == length) {
    //If there are no nodes ahead of this node in this path
    //Then we can delete this node
    
    if (hasNoChildren(currentNode)) {
      delete currentNode; //free the memory 
      currentNode = NULL; //clear the pointer by pointing it to NULL
      deletedSelf = true;
    }
    //If there are nodes ahead of currentNode in this path 
    //Then we cannot delete currentNode. We simply unmark this as leaf
    else {
      currentNode -> unMarkAsLeaf();
      deletedSelf = false;
    }
  } 
  else {
    TrieNode * childNode = currentNode -> children[getIndex(key[level])];
    bool childDeleted = deleteHelper(key, childNode, length, level + 1);
    if (childDeleted) {
      //Making children pointer also null: since child is deleted
      currentNode -> children[getIndex(key[level])] = NULL;
      //If currentNode is leaf node that means currntNode is part of another key
      //and hence we can not delete this node and it's parent path nodes
      if (currentNode -> isEndWord) {
        deletedSelf = false;
      }
      //If childNode is deleted but if currentNode has more children then currentNode must be part of another key.
      //So, we cannot delete currenNode
      else if (!hasNoChildren(currentNode)) {
        deletedSelf = false;
      }
      //Else we can delete currentNode
      else {
        currentNode = NULL;
        deletedSelf = true;
      }
    }
    else {
      deletedSelf = false;
    }
  }
  return deletedSelf;
}

//Function to delete given key from Trie
void deleteNode(string key) {
  if ((root == NULL) || (key.empty())) {
    cout << "Null key or Empty trie error\n";
    return;
  }
  cout<<deleteHelper(key, root, key.length(), 0);
}
};

int totalWords(TrieNode * root){
 
 int result = 0;
  // Leaf denotes end of a word
  if (root->isEndWord)
    result++;

  for (int i = 0; i < 26; i++)
    if (root->children[i] != NULL)
      result += totalWords(root->children[i]);
  return result;
}
int main(){
    Trie *t= new Trie();
    string keys[9] = {"the", "a", "there", "answer", "any", "by", "bye", "their","abc"};
    // t->insertNode("bar");
    // //cout<<t->searchNode("abcd");
    // t->deleteNode("bar");
    for (int i = 0; i < 9 ; i++)
  {
    t->insertNode(keys[i]);
  }

  cout << totalWords(t->root);
    return 0;
}