#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
int t,n,a[M],k,m;
    
int main(){
// freopen("input.inp","r",stdin);
// freopen("output.out","w",stdout);
  cin >> n >> k >> m;
  fo(i,1,n) cin >> a[i];
  int sum=0,kq=0;
  fo(i,1,n) {
    if(i<=k) sum += a[i];
    else {
      sum += a[i];
      sum -= a[i-k];
    }
    //cout << i<<" "<<sum<<"\n";
    if(i >= k && sum == m) kq ++;
  }  
  cout << kq;
} 