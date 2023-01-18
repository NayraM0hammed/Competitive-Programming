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
using namespace std;
const ll Mod = 1e9 + 7, INF = 1e18;
const ll N = 1e5 + 1, O_O = LONG_LONG_MAX, T_T = INT_MAX, V_V = INT_MIN;

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


int m, d, dp[2000][2000][2][2];
string a, b;

bool Check(int idx, int digit, bool aa, bool bb)
{
    if (!aa && !bb)
        return (digit >= a[idx] - '0' && digit <= b[idx] - '0');

    if (!aa)
        return digit >= a[idx] - '0';

    if (!bb)
        return digit <= b[idx] - '0';

    return 1;
}

int Count(int idx, int rem, bool a_state, bool b_state)
{
    if (idx == sz(b))
        return (rem == 0);

    if (dp[idx][rem][a_state][b_state] != -1)
        return dp[idx][rem][a_state][b_state];

    int op = 0;

    if (idx & 1)
    {
        if (Check(idx, d, a_state, b_state))
        {
            op += Count(idx + 1, ((rem * 10) + d) % m, a_state | (d > a[idx] - '0'), b_state | (d < b[idx] - '0'));
            op %= Mod;
        }
    }
    else
        for (int i = 0; i < 10; i++)
            if (i != d && Check(idx, i, a_state, b_state))
            {
                op += Count(idx + 1, ((rem * 10) + i) % m, a_state | (i > a[idx] - '0'), b_state | (i < b[idx] - '0'));
                op %= Mod;
            }

    return dp[idx][rem][a_state][b_state] = op;
}

void Catch_Kadr_fe_ALOLo()
{
    MemS(dp, -1);
    cin >> m >> d >> a >> b;
    cout << Count(0, 0, 0, 0);
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
