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

//"Look deep into your soul, into the dark and foggy mist of your memories"

void SADIEM()
{
    freopen("jumping.in", "r", stdin);
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
int vis[N];
void BFS(int st)
{
    queue<int> q;
    q.push(st);
    vis[st] = 0;
    while (sz(q))
    {
        st = q.front(), q.pop();

        for (auto ch : v[st])
            if (vis[ch] == -1 )
                q.push(ch), vis[ch] = 1 + vis[st];
    }
}

int main()
{
    SADIEM();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        MemS(vis, -1);
        v.clear(), v.resize(n + 1);

        for (int i = 1, x; i <= n && cin >> x; i++)
        {
            if (i + x <= n)
                v[i + x].push_back(i);
            if (i - x > 0)
                v[i - x].push_back(i);
        }

        BFS(n);

        for (int i = 1; i <= n; i++)
            cout << vis[i] << "\n";
    }
}
