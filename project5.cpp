#include<bits/stdc++.h>
using namespace std;

const int M = 1e3+6;
int n,m,a,b,c,d,r;
int f[M][M];
pair<int,int> pre[M][M];
vector<pair<int,int>> dsk[M];

void djiktra(int st) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({f[st][st],st});
    
    while(!pq.empty()) {
        int u = pq.top().second, c = pq.top().first;
        pq.pop();
        for(auto v : dsk[u]) {
            if(f[st][v.first] > c + v.second) 
                f[st][v.first] = c + v.second,
                pq.push({f[st][v.first],v.first});
        }
    }
}

void solv() {
    for(int i=0;i<=n-1;i++) 
        for(int j=0;j<=n-1;j++) pre[i][j] = {-1,-1};

    queue<pair<int,int>> q;
    q.push({a,b});

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        // move x
        for(auto o : dsk[x]) {
            int v = o.first;
            if(pre[v][y].first == -1 && f[v][y] > r) q.push({v,y}), pre[v][y] = {x,y};
        }
        // move y
        for(auto o : dsk[y]) {
            int v = o.first;
            if(pre[x][v].first == -1 && f[x][v] > r) q.push({x,v}), pre[x][v] = {x,y};
        }
    }

    if(pre[c][d].first == -1) cout <<"Khong the !";
    else {
        stack<pair<int,int>> st;
        int ii = c, jj = d;
        st.push({ii,jj});
        while(ii != a || jj != b) {
            pair<int,int> xx = pre[ii][jj];
            st.push(xx);
            ii = xx.first;
            jj = xx.second;    
        }

        while(!st.empty()) {
            int u = st.top().first;
            int v = st.top().second;
            cout << u<<" "<<v<<" "<<f[u][v]<<"\n";
            st.pop();
        }
    }

}

int main()
{
    freopen("project5_inp.inp","r",stdin);
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin >> u >> v >> c;
        dsk[u].push_back({v,c});
        dsk[v].push_back({u,c});
    }
    cin >> a >> b >> c >> d >> r;

    for(int i=0;i<=n-1;i++)
        for(int j=0;j<=n-1;j++) 
            if(i != j) f[i][j] = INT_MAX;
            else f[i][j] = 0;
    for(int i=0;i<=n-1;i++) {
        djiktra(i);
    }

    solv();
}