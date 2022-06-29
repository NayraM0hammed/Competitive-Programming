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

int cnt[N], cost[N], vis[N];

void BFS(int st, int move, int curr)
{
    queue<pair<int, int>> q;
    q.push({st, move});

    vis[st] = curr;
    cnt[st]++;

    while (sz(q))
    {
        st = q.front().first, move = q.front().second, q.pop();

        if (st / 2 >= 0 && vis[st / 2] != curr)
            vis[st / 2] = curr, cost[st / 2] += move + 1, cnt[st / 2]++, q.push({st / 2, move + 1});

        if (st * 2 < N && vis[st * 2] != curr)
            vis[st * 2] = curr, cost[st * 2] += move + 1, cnt[st * 2]++, q.push({st * 2, move + 1});
    }
}

int main()
{
    SADIEM();
    int n, mn = T_T;
    cin >> n;
    for (int i = 0, x; i < n && cin >> x; i++)
        BFS(x, 0, i + 1);

    for (int i = 0; i < N; i++)
        if (cnt[i] == n)
            mn = min(mn, cost[i]);

    cout << mn;
}
