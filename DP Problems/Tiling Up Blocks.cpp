//"Perhaps..,we 're asking the wrong questions .." -Agent Brown
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <iomanip>
#include <unordered_map>
#define sz(s) (int(s.size()))
#define MemS(s, x) memset(s, x, sizeof(s))
#define PI acos(-1)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll Mod = 1e9 + 7, INF = 1e18;
const ll N = 2e5 + 1, O_O = LONG_LONG_MAX, T_T = INT_MAX, V_V = INT_MIN;

void SADIEM()
{
    freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);

    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}


struct GG
{
    int idx, l, m;

    bool operator<(const GG &x) const
    {
        if (idx != x.idx)
            return idx > x.idx;
        
        if (l != x.l)
            return l > x.l;

        return m > x.m;
    }
};

vector<pair<int, int>> v;
map<GG, int> dp;
int Long(GG st)
{
    if (st.idx == sz(v))
        return 0;

    if (dp.find(st) != dp.end())
        return dp[st];

    int op = Long({st.idx + 1, st.l, st.m});

    if (v[st.idx].first <= st.l && v[st.idx].second <= st.m)
        op = max(op, 1 + Long({st.idx + 1, v[st.idx].first, v[st.idx].second}));

    return dp[st] = op;
}

void Catch_Kadr_fe_ALOLo()
{
    int n;
    while (cin >> n && n)
    {
        dp.clear(), v.clear(), v.resize(n);
        for (int i = 0; i < n && cin >> v[i].first >> v[i].second; i++)
            ;
        sort(v.rbegin(), v.rend());
        cout << Long({0, 101, 101}) << "\n";
    }
    cout << "*\n";
}

int main()
{
    SADIEM();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        Catch_Kadr_fe_ALOLo();
        cout << (t ? "\n" : "");
    }
}
