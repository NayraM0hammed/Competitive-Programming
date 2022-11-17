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
    //freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);

    std::ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}

void Catch_Kadr_fe_ALOLo()
{
    string s, h;
    cin >> s >> h;

    for (int i = 0; i + sz(s) <= sz(h); i++)
    {
        int frq[26] = {0};
        for (int j = i; j < i + sz(s); frq[h[j] - 'a']++, j++)
            ;
        
        bool bad = 0;

        for (int j = 0; j < sz(s); frq[s[j] - 'a']--, j++)
            ;

        for (int j = 0; j < 26 && !bad; j++)
            bad |= (frq[j] != 0);
        
        if (!bad)
            return void(cout << "YES");
    }
    cout << "NO";
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
