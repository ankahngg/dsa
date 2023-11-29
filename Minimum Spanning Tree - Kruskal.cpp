#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
struct data {
    int u,v,w;
};

int t,n,f[M],m,cha[M],rak[M],res;
vector<data> vec;


int findd(int o) {
    if(cha[o] != o) return cha[o] = findd(cha[o]);
    return o;
}

bool cmp (data a, data b) {
    return a.w < b.w;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    fo(i,1,m) {
        int u,v,w;
        cin >> u >> v >> w;   
        vec.push_back({u,v,w});
    }
    sort(vec.begin(),vec.end(),cmp);
    fo(i,1,n) cha[i] = i, rak[i] = 1;
    for(auto x : vec) {
        int w = x.w;
        int u = x.u;
        int v = x.v;

        u = findd(u), v = findd(v);
        if(u == v) continue;
        res += w;
        if(rak[u] > rak[v]) cha[v] = cha[u], rak[u] += rak[v];
        else cha[u] = cha[v], rak[v] += rak[u];
    }

   cout << res;
}
