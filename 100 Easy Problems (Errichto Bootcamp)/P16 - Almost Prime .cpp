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
const ll N = 1e6 + 1, O_O = LONG_LONG_MAX, T_T = INT_MAX, V_V = INT_MIN;

//"Look deep into your soul, into the dark and foggy mist of your memories"

void SADIEM()
{
    freopen("input.txt", "r", stdin);
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
bool Almost_prime(int x)
{
    int p = 2, cnt = 0;
    while (p * p <= x)
    {
        bool ok = 0;
        while (!(x % p))
            x /= p, ok = 1;
        cnt += ok, p++;
    }
    cnt += (x > 1);
    return cnt == 2;
}

void Catch_Kadr_fe_ALOLo()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 2; i <= n; i++)
        cnt += Almost_prime(i);
    cout << cnt;
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
