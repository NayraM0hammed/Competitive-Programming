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
const ll Mod = 1e9 + 7;
const ll N = 1e6 + 3, O_O = LONG_LONG_MAX, T_T = INT_MAX, V_V = INT_MIN;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> Or_Set;
*/
// 8 neighbors
int Dx[] = {2, 1, -1, -2, -2, -1, 1, 2}; // Orig: -1,-1,-1,  0, 0,  1, 1, 1
int Dy[] = {1, 2, 2, 1, -1, -2, -2, -1}; // Orig: -1, 0, 1, -1, 1, -1, 0, 1

// 4 neighbors
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

//"Look deep into your soul, into the dark and foggy mist of your memories"

void SADIEM()
{
    //freopen("input.txt", "r", stdin);
    //          freopen("output.txt", "w", stdout);
    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}

/*

 “ I’d like to let you in on a very important secret I learned when I was about your age, boy.
 You see, power, real power doesn’t come to those who were born strongest or fastest or smartest.
 No. It comes to those who will do anything to achieve it.”

*/
vector<vector<int>> v;
map<pair<int, int>, int> mp;
string ans;
int vis[N], color[N], ok;
void BI_color(int node)
{
    vis[node] = 1;
    for (auto ch : v[node])
    {
        if (!vis[ch])
        {
            color[ch] = 1 - color[node];
            BI_color(ch);
        }
        ok |= (vis[ch] && color[ch] == color[node]);
    }
}

void Dfs(int node)
{
    vis[node] = 1;
    for (auto ch : v[node])
    {
        if (color[node] == 1 && mp.find({ch, node}) != mp.end())
            ans[mp[{ch, node}]] = '1';
        else if (color[node] == 0 && mp.find({node, ch}) != mp.end())
            ans[mp[{node, ch}]] = '1';

        if (!vis[ch])
            Dfs(ch);
    }
}

int main()
{
    SADIEM();
    int n, m;
    cin >> n >> m;

    v.resize(n + 1);
    ans.assign(m, '0');

    for (int i = 0, x, y; i < m && cin >> x >> y; i++)
    {
        mp[{x, y}] = i;
        v[x].push_back(y), v[y].push_back(x);
    }

    color[1] = 1;
    BI_color(1);
    if (ok)
        return cout << "NO", 0;

    cout << "YES\n";

    MemS(vis, 0);
    Dfs(1);
    
    cout << ans;
}
