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
const ll Mod = 1e9 + 7, INF = 1e18;
const ll N = 1e7 + 1, O_O = LONG_LONG_MAX, T_T = INT_MAX, V_V = INT_MIN;

//"Look deep into your soul, into the dark and foggy mist of your memories"

void SADIEM()
{
    freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);

    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}

void Catch_Kadr_fe_ALOLo()
{
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b)
        swap(a, b);

    if (c < a)
    {
        if (c + r >= b)
            cout << 0;
        else if (c + r >= a)
            cout << b - (c + r);
        else
            cout << b - a;
    }
    else if (c > b)
    {
        if (c - r <= a)
            cout << 0;
        else if (c - r < b)
            cout << (c - r) - a;
        else
            cout << b - a;
    }
    else if (c >= a && c <= b)
        cout << max(0, (c - r) - a) + max(0, b - (c + r));
}

int main()
{
    SADIEM();
    int t = 1;
    cin >> t;
    while (t--)
    {
        Catch_Kadr_fe_ALOLo();
        cout << (t ? "\n" : "");
    }
}
