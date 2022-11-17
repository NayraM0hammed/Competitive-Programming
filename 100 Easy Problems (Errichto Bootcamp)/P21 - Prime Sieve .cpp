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
int sieve[N];
void SIEVE(int n)
{
    MemS(sieve, 1);
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i <= n / i; i++)
        if (sieve[i])
            for (int j = i * i; j <= n; j += i)
                sieve[j] = 0;

    for (int i = 2; i <= n; i++)
        if (sieve[i])
            v.push_back(i);
}
void Catch_Kadr_fe_ALOLo()
{
    int n;
    cin >> n;
    SIEVE(n);
    cout << sz(v) << "\n";
    for (auto it : v)
        cout << it << " ";
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
