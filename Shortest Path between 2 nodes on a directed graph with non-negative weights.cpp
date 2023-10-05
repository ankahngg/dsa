#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
int t,n,f[M],m;
vector<pair<int,int>> dsk[M];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void djk(int s) {
    fo(i,1,n) f[i] = INT_MAX;
    f[s] = 0;
    pq.push({f[s],s});
    while(!pq.empty()) {
        pair<int,int> o = pq.top(); pq.pop();
        int u = o.sc;
        for(auto o : dsk[u]) {
            int v = o.fi;
            int w = o.sc;
            if(f[v] > f[u] + w) f[v] = f[u] + w, pq.push({f[v],v});
        }
    }
}


    
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    fo(i,1,m) {
        int u,v,w;
        cin >> u >> v >> w;
        dsk[u].push_back({v,w});
    }
    int s,t;
    cin >> s >> t;
    djk(s);
    cout << f[t];
}