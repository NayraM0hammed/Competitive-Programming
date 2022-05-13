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

// 8 neighbors
int Dx[] = {2, 1, -1, -2, -2, -1, 1, 2}; // Orig: -1,-1,-1,  0, 0,  1, 1, 1
int Dy[] = {1, 2, 2, 1, -1, -2, -2, -1}; // Orig: -1, 0, 1, -1, 1, -1, 0, 1

// 4 neighbors
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

//"Look deep into your soul, into the dark and foggy mist of your memories"

void SADIEM()
{
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
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
string s;
int ans;

int DFS(int node, int pr)
{
    int cnt = 0;
    cnt += (s[node - 1] == 'B' ? 1 : -1);

    for (auto ch : v[node])
        if (ch != pr)
            cnt += DFS(ch, node);

    ans += (cnt == 0);

    return cnt;
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
        v.clear(), v.resize(n + 2), ans = 0;
        
        for (int i = 1, x; i < n && cin >> x; i++)
            v[x].push_back(i + 1), v[i + 1].push_back(x);
        
        cin >> s;

        DFS(1, -1);

        cout << ans << (t ? "\n" : "");
    }
}
