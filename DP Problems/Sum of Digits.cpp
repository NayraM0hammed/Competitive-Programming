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
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<pair<int, int>, null_type, greater_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> Or_Set;
*/
// 8 neighbors

int Dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // Knight_mov:2, 1, -1, -2, -2, -1, 1, 2
int Dy[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // 1, 2, 2, 1, -1, -2, -2, -1

// 4 neighbors

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

string dir = "LRDU";
//"Look deep into your soul, into the dark and foggy mist of your memories"

void SADIEM()
{
 //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);

    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}

/*

 “ I’d like to let you in on a very important secret I learned when I was about your age, boy.
 You see, power, real power doesn’t come to those who were born strongest or fastest or smartest.
 No. It comes to those who will do anything to achieve it.”

*/
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
    ll aa, bb;
    while (cin >> aa >> bb && aa != -1)
    {
        MemS(dp, -1);
        aa--;
        a = to_string(aa), b = to_string(bb);
        cout << Get_Total(0, 0, 0, 1) - (aa > 0 ? Get_Total(0, 0, 0, 0) : 0) << "\n";
    }
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
