#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define sc second
#define ll long long
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int M=1e6+6;
    
    
int t,n,m;

int hashh(string x) {
    int sum=0;
    int expo=1;
    fr(i,x.length()-1,0) {
        int num = x[i];
        sum = (0ll + sum + 1ll*expo*num%m) % m;
        expo = 1ll * expo * 256 % m;
    }
    return sum;

}
    
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    fo(i,1,n) {
        string x;
        cin >> x;
        cout << hashh(x)<<"\n";
    }
    
}
