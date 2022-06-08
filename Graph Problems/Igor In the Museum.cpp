//"Perhaps..,we 're asking the wrong questions .." -Agent Brown
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <iomanip>
#include <unordered_map>
#define sz(s) (int(s.size()))
#define MemS(s, x) memset(s, x, sizeof(s))
#define PI acos(-1)
typedef unsigned long long ll;
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
    freopen("input.txt", "r", stdin);
    //        freopen("output.txt", "w", stdout);
    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}

/*

 “ I’d like to let you in on a very important secret I learned when I was about your age, boy.
 You see, power, real power doesn’t come to those who were born strongest or fastest or smartest.
 No. It comes to those who will do anything to achieve it.”

*/

int n, m, k, ans[1000][1000], vis[1000][1000];
char v[1000][1000];

bool valid(int x, int y, bool op)
{

    if (op)
        return x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '*';

    return x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '.' && !vis[x][y];
}

void Bfs(int x, int y)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    queue<pair<int, int>> Ans;
    q.push({x, y});
    vis[x][y] = 1;

    while (sz(q))
    {
        Ans.push(q.front());
        x = q.front().first, y = q.front().second, q.pop();

        // check walls
        for (int i = 0; i < 4; i++)
            if (valid(x + dx[i], y + dy[i], 1))
                cnt++;

        // move to other places
        for (int i = 0; i < 4; i++)
            if (valid(x + dx[i], y + dy[i], 0))
                q.push({x + dx[i], y + dy[i]}), vis[x + dx[i]][y + dy[i]] = 1;
    }
    while (sz(Ans))
    {
        x = Ans.front().first, y = Ans.front().second, Ans.pop();
        ans[x][y] = cnt;
    }
}

int main()
{
    SADIEM();
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m && cin >> v[i][j]; j++)
            ;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == '.' && !vis[i][j])
                Bfs(i, j);

    while (k--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << ans[x][y] << (k ? "\n" : "");
    }
}
