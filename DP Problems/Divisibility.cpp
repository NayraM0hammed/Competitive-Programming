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
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> Or_Set;
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}

/*

 “ I’d like to let you in on a very important secret I learned when I was about your age, boy.
 You see, power, real power doesn’t come to those who were born strongest or fastest or smartest.
 No. It comes to those who will do anything to achieve it.”

*/
vector<int> v;

int dp[10000][100], n, k;

void Back_Orig()
{
    v.clear(), v.resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            dp[i][j] = -1;
}

int Fix(int val)
{
    return ((val % k) + k) % k;
}

bool Divisible(int idx, int curr_mod)
{
    if (idx == n)
        return curr_mod == 0;

    if (dp[idx][curr_mod] != -1)
        return dp[idx][curr_mod];

    bool op1 = Divisible(idx + 1, Fix(curr_mod + v[idx]));
    op1 |= Divisible(idx + 1, Fix(curr_mod - v[idx]));

    return dp[idx][curr_mod] = op1;
}

int main()
{
    SADIEM();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        Back_Orig();

        for (int i = 0; i < n && cin >> v[i]; i++)
            ;

        cout << (Divisible(1, Fix(v[0])) ? "Divisible" : "Not divisible") << "\n";
    }
}
