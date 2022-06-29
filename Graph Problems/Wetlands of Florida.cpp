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
   // freopen("input.txt", "r", stdin);
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

vector<string> arr;
int vis[111][111], ans[111][111], n, m;

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && arr[x][y] == 'W';
}

void BFS(int x, int y)
{
    queue<pair<int, int>> q, Ans;
    q.push({x, y});
    vis[x][y] = 1;
    int cnt = 0;
    while (sz(q))
    {
        cnt++;
        x = q.front().first, y = q.front().second, q.pop();
        Ans.push({x, y});
        for (int i = 0; i < 8; i++)
            if (valid(x + Dx[i], y + Dy[i]))
                vis[x + Dx[i]][y + Dy[i]] = 1, q.push({x + Dx[i], y + Dy[i]});
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
    int t;
    string s;
    cin >> t;
    cin.ignore();
    getline(cin, s);

    while (t--)
    {
        MemS(vis, 0);
        arr.clear();
        vector<pair<int, int>> q;
        while (getline(cin, s) && (s[0] == 'L' || s[0] == 'W'))
            arr.push_back(s);

        n = sz(arr), m = sz(arr[0]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] == 'W' && !vis[i][j])
                    BFS(i, j);

        do
        {
            stringstream ss(s);
            int x, y;
            ss >> x >> y;
            x--, y--;
            cout << ans[x][y] << "\n";
        } while (getline(cin, s) && sz(s));

        cout << (t ? "\n" : "");
    }
}
