#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
int t,n,a[M],c;
    
bool check(int d) {
  
  int cnt=1;
  fo(i,1,n) {
    //if(d==3) cout << i<<" ";
    int j=i+1;
    while(j <= n && a[j]-a[i] < d) j ++;
    if(j <= n) cnt ++;
    i=j-1;
  }
  if(cnt >= c) return true;
  else return false;
}

int main(){
// freopen("input.inp","r",stdin);
// freopen("output.out","w",stdout);
ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> c;
    int mx = -1;
    fo(i,1,n) cin >> a[i], mx = max(mx,a[i]);
    sort(a+1,a+1+n);
    int l=0,r=mx,mid,res;
    while(l<=r) {
      mid = (l+r)/2;
      if(check(mid)) l = mid+1, res = mid;
      else r = mid-1;
    }
    cout << res<<"\n";
  }
    
}