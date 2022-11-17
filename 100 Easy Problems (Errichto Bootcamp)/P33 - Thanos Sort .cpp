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

vector<int> v;
int Make_it_Sorted(int l = 0, int r = sz(v) - 1)
{
    if (r < l)
        return 0;

    bool bad = 0;
    for (int i = l; i < r && !bad; i++)
        bad |= (v[i] > v[i + 1]);

    if (!bad)
        return r - l + 1;

    return max(Make_it_Sorted(l + ((r - l) >> 1) + 1, r), Make_it_Sorted(l, l + ((r - l) >> 1)));
}

void Catch_Kadr_fe_ALOLo()
{
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n && cin >> v[i]; i++)
        ;
    cout << Make_it_Sorted();
}

int main()
{
    SADIEM();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        Catch_Kadr_fe_ALOLo();
        cout << (t ? "\n" : "");
    }
}
