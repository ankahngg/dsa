#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define sc second
#define ll long long
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int M = 1e6 + 6;

int t, n, sum[M];
set< pair<int, int> > s[10005];
set<pair<int, int>>::iterator it;

void addTerm(int id, int co, int ex)
{
    it = s[id].lower_bound({ex, 0});
    if (it == s[id].end() || (*it).fi != ex)
        s[id].insert({ex, co});
    else
    {
        pair<int, int> val = *it;
        s[id].erase(it);
        val.sc += co;
        s[id].insert(val);
    }
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while (true)
    {
        string q;
        int id, co, ex, val;
        cin >> q;
        
        if (q == "*")
            break;
        if (q == "AddTerm")
        {
            cin >> id >> co >> ex;
            addTerm(id,co,ex);
        }
        if (q == "EvaluatePoly")
        {
            cin >> id >> val;
            int res = 0;
            for (auto x : s[id])
            {
                ex = x.fi;
                co = x.sc;
                int elmVal = co;
                fo(i, 1, ex) elmVal *= val;
                res += elmVal;
            }
            cout << res << "\n";
        }
        if (q == "AddPoly")
        {
            int id1, id2, idRes;
            cin >> id1 >> id2 >> idRes;
            s[idRes].clear();
            for(auto x : s[id1]) addTerm(idRes,x.sc,x.fi);
            for(auto x : s[id2]) addTerm(idRes,x.sc,x.fi);
        }
        if(q == "PrintPoly")
        { 
            cin >> id;
            stack<pair<int,int>> st;
            for(auto x : s[id]) st.push(x);
            while(!st.empty()) {cout << st.top().sc<<" "<<st.top().fi<<" "; st.pop();}
            cout <<"\n";
        }
        if(q == "Destroy"){
            cin >> id;
            s[id].clear();
        }
    }
}
