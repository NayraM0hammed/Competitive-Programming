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
const ll N = 1e5 + 3, O_O = LONG_LONG_MAX, T_T = INT_MAX, V_V = INT_MIN;
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
string dir = "LRDU";
//"Look deep into your soul, into the dark and foggy mist of your memories"

void SADIEM()
{
    //freopen("input.txt", "r", stdin);
    //      freopen("output.txt", "w", stdout);
    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}

/*

 “ I’d like to let you in on a very important secret I learned when I was about your age, boy.
 You see, power, real power doesn’t come to those who were born strongest or fastest or smartest.
 No. It comes to those who will do anything to achieve it.”

*/
int n, m;
vector<vector<int>> v;
bool vis[N];

void DFS(int node)
{
    if (vis[node])
        return;

  vis[node] = 1;
  
  for (auto ch : v[node])
        DFS(ch);
}

int main()
{
    SADIEM();
    int pre = -1;
    vector<pair<int, int>> ans;
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0, x, y; i < m && cin >> x >> y; i++)
        v[x].push_back(y), v[y].push_back(x);

    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            DFS(i);
            if (pre == -1)
                pre = i;
            else
                ans.push_back({pre, i});
        }

    cout << sz(ans) << "\n";
    for (auto it : ans)
        cout << it.first << " " << it.second << "\n";
}
