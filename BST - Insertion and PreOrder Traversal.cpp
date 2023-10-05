#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
int t,n,o,f[M],root=-1;
set<int> s;
pair<int,int> son[M];

void dfs(int u, int child) {
    if(child < u) {
        if(son[u].fi) dfs(son[u].fi,child);
        else son[u].fi = child;
    }
    else {
        if(son[u].sc) dfs(son[u].sc,child);
        else son[u].sc = child;
    }
}

void dfs2(int u) {
    cout << u<<" ";
    if(son[u].fi) dfs2(son[u].fi);
    if(son[u].sc) dfs2(son[u].sc);

}

int main(){
    while(true) {
        string q;
        cin >> q;
        if(q == "#") break;
        int x;
        cin >> x;
        if(s.find(x) == s.end()) {
            s.insert(x); 
            if(root == -1) root = x;
            else {
                dfs(root,x);
            }
        }
    }

    dfs2(root);
}