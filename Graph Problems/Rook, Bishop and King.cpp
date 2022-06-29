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

int Dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int Dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 4 neighbors

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

//"Look deep into your soul, into the dark and foggy mist of your memories"

void SADIEM()
{
    freopen("input.txt", "r", stdin);
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
int vis[9][9], r1, r2, c1, c2;

struct SS
{
    int s, f, c;
};

bool valid(int x, int y)
{
    return x > 0 && x < 9 && y > 0 && y < 9 && !vis[x][y];
}

int BFS_King(int x, int y, int cost)
{
    queue<SS> q;
    q.push({x, y, cost});
    vis[x][y] = 1;
    while (sz(q))
    {
        x = q.front().s, y = q.front().f, cost = q.front().c;
        q.pop();

        if (x == r2 && y == c2)
            return cost;

        for (int i = 0; i < 8; i++)
            if (valid(x + Dx[i], y + Dy[i]))
                q.push({x + Dx[i], y + Dy[i], cost + 1}), vis[x + Dx[i]][y + Dy[i]] = 1;
    }

    return 0;
}

int BFS_Bishop(int x, int y, int cost)
{
    queue<SS> q;
    q.push({x, y, cost});
    vis[x][y] = 1;
    while (sz(q))
    {
        x = q.front().s, y = q.front().f, cost = q.front().c;
        q.pop();
        if (x == r2 && y == c2)
            return cost;
        for (int i = 1; i < 8; i++)
        {
            if (valid(x + i, y + i))
                vis[x + i][y + i] = 1, q.push({x + i, y + i, cost + 1});
            if (valid(x - i, y - i))
                vis[x - i][y - i] = 1, q.push({x - i, y - i, cost + 1});
            if (valid(x + i, y - i))
                vis[x + i][y - i] = 1, q.push({x + i, y - i, cost + 1});
            if (valid(x - i, y + i))
                vis[x - i][y + i] = 1, q.push({x - i, y + i, cost + 1});
        }
    }
    return 0;
}

int main()
{
    SADIEM();
    cin >> r1 >> c1 >> r2 >> c2;

    cout << (r1 == r2 || c1 == c2 ? 1 : 2) << " "; // rook
    
    cout << BFS_Bishop(r1, c1, 0) << " ";
    
    MemS(vis, 0);

    cout << BFS_King(r1, c1, 0);
}
