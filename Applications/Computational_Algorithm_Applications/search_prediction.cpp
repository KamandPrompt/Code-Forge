/*
The following code is an implementation of Trie Data Structure. 

The aim of the code is to first store the words given by the user.

Once that is done it asks for a prompt from the user, it returns all the words with the same prefix as the one given by the user in order 
of the frequency of occurance of the words

NOTE: Code only accepts lowercase letters

Time Complexity => O(L(Prefix) + 26*L(longest word with same prefix - prefix length)) + O(N*logN) - for sorting in order of frequency
                => In worst case time complexity is O(26*L(Prefix)) + O(N*logN) = O(N*logN)
=> Time Complexity in worst case is O(N*logN)

*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> counter;

// Node Definition
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal=0;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=0;
    }
};

// Class Functions
class Trie{
    public:
    TrieNode* root;

    Trie(){
        root=new TrieNode('\0');
    }

    void InsertUtil(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        int index= word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        InsertUtil(child,word.substr(1)); 
    }

    void InsertWord(string word){
        InsertUtil(root,word);
    }

    void inorderTravel(TrieNode* root, vector<string> &found, string current){
        if(root == NULL){
            return;
        }

        current.push_back(root->data);

        if(root->isTerminal){
            found.push_back(current);
        }

        for(int i=0;i<26;i++){
            inorderTravel(root->children[i], found, current);
        }
        current.pop_back();
        return;
    }

    void SearchUtill(TrieNode* root,string word, vector<string> &found, string currentStr=""){
        if(word.length()==0){
            if(currentStr.length()>=1) currentStr.pop_back();
            inorderTravel(root, found, currentStr);
            return;
        }

        int index=word[0]-'a';
        TrieNode* child;

        currentStr.push_back(word[0]);
        if(root->children[index]!=NULL){
            child = root -> children[index];
        }
        else{
            return;
        }

        return SearchUtill(child, word.substr(1), found, currentStr);
    }

    vector<string> Search(string word){
        vector<string> found; 
        SearchUtill(root,word,found);
        return found;
    }

    void RemoveUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=false;
            return;
        }

        int index= word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return;
        }

        RemoveUtil(child,word.substr(1)); 
    }

    void Remove(string word){
        RemoveUtil(root,word);
    }
};

// Freq Comparision
bool comparator(string a,string b){
    return counter[a]>counter[b];
}

int main(){
    // Size
    cout<<"Number of Words: ";
    int n;
    cin>>n;

    // Insertion
    cout<<"Enter Words:\n";
    Trie* T=new Trie();
    for(int i=0;i<n;i++){
        string inp;
        cin>>inp;

        counter[inp]+=1;
        T->InsertWord(inp);
    }

    // Search
    cout<<"\nWord to find: ";
    string tocheck;
    cin>>tocheck;    
    vector<string> found = T -> Search(tocheck);
    sort(found.begin(),found.end(),comparator);

    // Printing
    cout<<"\nSearch Result: \n";
    for(auto i:found){
        cout<<i<<endl;
    }

    return 0;
}
