#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    bool isWord;
    node *alpha[26];
    node()
    {
        isWord = false;
        for (int i = 0; i < 26; i++)
        {
            alpha[i] = NULL;
        }
    }
};
class Trie
{
public:
    node *root;
    Trie()
    {
        root = new node();
    }
    void insert(string s)
    {
        node *p = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (p->alpha[s[i] - 'a'] == NULL)
            {
                p->alpha[s[i] - 'a'] = new node();
                p = p->alpha[s[i] - 'a'];
            }
            else
            {
                p = p->alpha[s[i] - 'a'];
            }
        }
        p->isWord = true;
    }
    void dfs(node* p,string prefix){
        if(p->isWord==true)
            cout<<prefix<<endl;
        for(int i=0;i<26;i++){
            if(p->alpha[i]!=NULL){
                dfs(p->alpha[i],prefix+char('a'+i));
            }
        }
    }
    void autosuggestion(string prefix)
    {
        int unknown = false;
        node* p = root;
        for(int i=0;i<prefix.size();i++){
            if(p->alpha[prefix[i]-'a']!=NULL){
                p=p->alpha[prefix[i]-'a'];
            }else{
                unknown = true;
                break;
            }
        }
        if(unknown){
            cout<< "0"<<endl;
            return ;
        }
        dfs(p,prefix);
    }
};
int main()
{
    int t,n;
    string s,prefix;
    freopen("input.txt","r",stdin);
    cin >> t;
    while (t--)
    {
        cin>>n;        
        Trie * root = new Trie();
        for(int i=0;i<n;i++){
            cin>>s;
            root->insert(s);
        }
        cin>>prefix;
        root->autosuggestion(prefix);
    }
    return 0;
}
