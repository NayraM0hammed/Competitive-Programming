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
const ll N = 2e5 + 3, O_O = LONG_LONG_MAX, T_T = INT_MAX, V_V = INT_MIN;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> Or_Set;
*/
// 8 neighbors

int Dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int Dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 4 neighbors

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

//"Look deep into your soul, into the dark and foggy mist of your memories"

void SADIEM()
{
//    freopen("input.txt", "r", stdin);
    //           freopen("output.txt", "w", stdout);
    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}

/*

 “ I’d like to let you in on a very important secret I learned when I was about your age, boy.
 You see, power, real power doesn’t come to those who were born strongest or fastest or smartest.
 No. It comes to those who will do anything to achieve it.”

*/

int vis[400];
vector<vector<int>> swaps;
vector<int> v;

void DFS(int st)
{
    set<int> val, idx;
    queue<int> q;
    q.push(st);
    vis[st] = 1;
    while (sz(q))
    {
        st = q.front(), q.pop();
        idx.insert(st), val.insert(v[st]);
        for (auto ch : swaps[st])
            if (!vis[ch])
                q.push(ch), vis[ch] = 1;
    }
    while (sz(val))
    {
        v[*idx.begin()] = *val.begin();
        val.erase(val.begin()), idx.erase(idx.begin());
    }
}

int main()
{
    SADIEM();
    int n;
    char x;
    cin >> n;

    v.resize(n + 1), swaps.resize(n + 1);
    for (int i = 1; i <= n && cin >> v[i]; i++)
        ;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n && cin >> x; j++)
            if (x == '1')
                swaps[i].push_back(j);

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            DFS(i);

    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
}
