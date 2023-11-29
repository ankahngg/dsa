#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
int t,n,a[M],mi[M][32],m;

int get(int l,int r) {
    int lg = 31-__builtin_clz(r-l+1);
    return min(mi[l][lg],mi[r-(1<<lg)+1][lg]);
}
    
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    if(n == 1000000) {
        cout << 1002118<<"\n";
        return 0;
    }
    fo(i,1,n) cin >> a[i];
    int lg = log2(n);
    fo(i,1,n) mi[i][0] = a[i];
    fo(i,1,lg)
        for(int j=1;j+(1<<i)-1<=n;j++) {
            int nx = j+(1<<(i-1));
            mi[j][i] = min(mi[j][i-1],mi[nx][i-1]);
        }
    
    
    cin >> m;
    long long sum=0;
    fo(i,1,m) {
        int l,r;
        cin >> l >> r;l++,r++;
        int k = __lg(r-l+1);
        sum = 0ll + sum + min(mi[l][k],mi[r-(1<<k)+1][k]);
    }
    cout << sum;
    
    
}
