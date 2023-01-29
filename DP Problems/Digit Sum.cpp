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
 //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);

    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}


ll dp[16][200][2][2];
string a, b;

bool valid(int d, int st, bool pre)
{
    return (!pre ? (d <= st) : 1);
}

ll Get_Total(int idx, int tot, bool pre, bool op)
{
    if (idx == (op ? sz(b) : sz(a)))
        return tot;

    if (dp[idx][tot][pre][op] != -1)
        return dp[idx][tot][pre][op];

    ll ans = 0;

    for (int i = 0; i <= 9; i++)
        if (valid(i, (op ? b[idx] : a[idx]) - '0', pre))
        {
            bool ok = pre | (op ? (i < b[idx] - '0') : (i < a[idx] - '0'));
            ans += Get_Total(idx + 1, i + tot, ok, op);
        }

    return dp[idx][tot][pre][op] = ans;
}

void Catch_Kadr_fe_ALOLo()
{
    MemS(dp, -1);
    ll aa, bb;
    cin >> aa >> bb;
    aa--;
    a = to_string(aa), b = to_string(bb);
    cout << Get_Total(0, 0, 0, 1) - (aa > 0 ? Get_Total(0, 0, 0, 0) : 0);
}

int main()
{
    SADIEM();
    int t = 1;
    cin >> t;
    while (t--)
    {
        Catch_Kadr_fe_ALOLo();
        cout << (t ? "\n" : "");
    }
}
