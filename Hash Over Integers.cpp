#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
int n;
map<string,bool> m;
    
int main(){
// freopen("input.inp","r",stdin);
// freopen("output.out","w",stdout);    
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(true) {
        string q;
        int x;
        cin >> q;
        if(q == "*") break;
        m[q] = true;
    }
    while(true) {
        string q,x;
        cin >> q;
        if(q == "***") break;
        cin >> x;
        bool ans;
        if(q == "find") ans = m.count(x);
        if(q == "insert") {
            if(m.count(x)) ans = 0;
            else ans = 1, m[x] = true;
        }
        cout << ans<<"\n";
    }
    
}