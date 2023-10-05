#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
int t,n,a[M],root;
bool exist[M];
vector<int> dsk[M];
    
void InOrder(int u) {
    if(dsk[u].size() > 1) InOrder(dsk[u][0]);
    cout << u<<" ";
    for(int i=1;i<dsk[u].size();i++){
        int v = dsk[u][i];
        InOrder(v);
    }
}

void PreOrder(int u) {
   cout << u<<" ";
    for(int i=0;i<dsk[u].size();i++){
        int v = dsk[u][i];
        PreOrder(v);
    }
}

void PostOrder(int u) {
    for(int i=0;i<dsk[u].size();i++){
        int v = dsk[u][i];
        PostOrder(v);
    }
    cout << u<<" ";
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    fo(i,1,1000000) exist[i] = false;
    while(true) {
        string q;
        int u,v;
        cin >> q;
        if(q == "*") break;
        if(q == "MakeRoot") cin >> root, exist[root] = true;
        if(q == "Insert") {
            cin >> u >> v;
            if(exist[v] == false || exist[u] == true) continue;
            dsk[v].push_back(u);
            exist[u] = true;
            
        }
        if(q == "PreOrder") PreOrder(root), cout<<"\n";
        if(q == "InOrder") InOrder(root), cout<<"\n";
        if(q == "PostOrder") PostOrder(root), cout<<"\n";

    }
    
}