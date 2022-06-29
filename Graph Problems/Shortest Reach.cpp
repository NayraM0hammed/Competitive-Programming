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
const ll N = 2e5 + 3, O_O = LONG_LONG_MAX, T_T = INT_MAX, V_V = INT_MIN;
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


void SADIEM()
{
 //   freopen("input.txt", "r", stdin);
    //          freopen("output.txt", "w", stdout);
    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}


vector<vector<int>> v;
int vis[N];
void Back_Orig()
{
    v.clear();
    MemS(vis, 0);
}
void BFS(int st)
{
    queue<int> q;
    q.push(st);
    vis[st] = 0;
    while (sz(q))
    {
        st = q.front(), q.pop();
        for (auto ch : v[st])
            if (!vis[ch])
                q.push(ch), vis[ch] = 6 + vis[st];
    }
}

int main()
{
    SADIEM();
    int q;
    cin >> q;
    while (q--)
    {
        Back_Orig();
        int n, m, s;
        cin >> n >> m;
        v.resize(n + 1);
        for (int i = 0, x, y; i < m && cin >> x >> y; i++)
            v[x].push_back(y), v[y].push_back(x);
      
      cin >> s;
      BFS(s);

      for (int i = 1; i <= n; i++)
        {
            if (i == s)
                continue;
            cout << (vis[i] ? vis[i] : -1) << " ";
        }
      
      cout << "\n";
    }
}
