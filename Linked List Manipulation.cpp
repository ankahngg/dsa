#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define sc second
#define ll long long
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define fo(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int M = 1e6 + 6;

int t, n, a[M];
deque<int> res;
set<int> s;

int main()
{
    cin >> n;
    fo(i, 1, n) cin >> a[i], res.push_back(a[i]), s.insert(a[i]);
    while (true)
    {
        string q;
        int x, u, v;
        cin >> q;
        if (q == "#")
            break;
        if (q == "addlast")
        {
            cin >> x;
            if (s.find(x) == s.end())
                res.push_back(x), s.insert(x);
        }
        if (q == "addfirst")
        {
            cin >> x;
            if (s.find(x) == s.end())
                res.push_front(x), s.insert(x);
        }
        if (q == "addafter")
        {
            cin >> u >> v;
            if (s.find(u) == s.end() && s.find(v) != s.end())
            {
                deque<int> tmp;
                while (!res.empty())
                {
                    int val = res.front();
                    res.pop_front();
                    tmp.push_back(val);
                    if (val == v)
                        tmp.push_back(u);
                }
                res = tmp;
                s.insert(u);
            }
        }
        if (q == "addbefore")
        {
            cin >> u >> v;
            if (s.find(u) == s.end() && s.find(v) != s.end())
            {
                deque<int> tmp;
                while (!res.empty())
                {
                    int val = res.front();
                    res.pop_front();
                    if (val == v)
                        tmp.push_back(u);
                    tmp.push_back(val);
                }
                res = tmp;
                s.insert(u);
            }
        }
        if (q == "remove")
        {
            cin >> x;
            if(s.find(x) != s.end())
            {
                deque<int> tmp;
                while (!res.empty())
                {
                    int val = res.front();
                    res.pop_front();
                    if (val != x) 
                        tmp.push_back(val);
                }
                res = tmp;
                s.erase(s.find(x));
            }
        }
        if(q == "reverse") {
            deque<int> tmp;
            while (!res.empty())
            {
                int val = res.front();
                res.pop_front();
                if (val != x) 
                    tmp.push_front(val);
            }
            res = tmp;
        }
    }
    for(auto x : res) cout << x<<" "; 
}