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
pair<int,int> dsk[M];
    
void InOrder(int u) {
    if(dsk[u].fi) InOrder(dsk[u].fi);
    cout << u<<" ";
    if(dsk[u].sc) InOrder(dsk[u].sc);

}   

void PreOrder(int u) {
    cout << u<<" ";
    if(dsk[u].fi) PreOrder(dsk[u].fi);
    if(dsk[u].sc) PreOrder(dsk[u].sc);

}

void PostOrder(int u) {
    if(dsk[u].fi) PostOrder(dsk[u].fi);
    if(dsk[u].sc) PostOrder(dsk[u].sc);
    cout << u<<" ";

}


int main(){
    //ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    fo(i,1,1000000) exist[i] = false;
    while(true) {
        string q;
        int u,v;
        cin >> q;
        if(q == "*") break;
        if(q == "MakeRoot") cin >> root, exist[root] = true;
        if(q == "AddLeft") {
            cin >> u >> v;
            if(exist[v] == false || exist[u] == true || dsk[v].fi) continue;
            dsk[v].fi = u;
            exist[u] = true;
        }
        if(q == "AddRight") {
            cin >> u >> v;
            if(exist[v] == false || exist[u] == true || dsk[v].sc) continue;
            dsk[v].sc = u;
            exist[u] = true;

        }
        if(q == "PreOrder") PreOrder(root), cout<<"\n";
        if(q == "InOrder") InOrder(root), cout<<"\n";
        if(q == "PostOrder") PostOrder(root), cout<<"\n";
       
    }
    
}
