//"Perhaps..,we 're asking the wrong questions .." -Agent Brown
#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<iomanip>
#include<unordered_map>
#define sz(s) (int(s.size()))
#define MemS(s,x) memset(s,x,sizeof(s))
#define PI acos(-1)
typedef long long ll;
using namespace std;
const ll Mod = 1e9 + 7;
const ll N = 1e4 + 1, O_O = 1e15, T_T = INT_MAX, V_V = INT_MIN;

//"Look deep into your soul, into the dark and foggy mist of your memories"

void SADIEM() {
	//freopen("mex.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
}
/*

 “ I’d like to let you in on a very important secret I learned when I was about your age, boy.
 You see, power, real power doesn’t come to those who were born strongest or fastest or smartest.
 No. It comes to those who will do anything to achieve it.”

 */

ll x, y, n, m, dp[1001][1001][2], vis_Hash[1001];

ll Min_Conv(int idx, int w, int p) {
	if (idx == m)
		return (w >= x && w <= y) ? 0 : T_T;

	if (dp[idx][w][p] != -1)
		return dp[idx][w][p];

	ll op1 = T_T, op2 = T_T;
	// # -> .

	if (!idx || (!p && w + 1 <= y) || (p && w >= x))
		op1 = vis_Hash[idx] + Min_Conv(idx + 1, (!p ? w + 1 : 1), 0);

	// . -> #

	if (!idx || (!p && w >= x) || (p && w + 1 <= y))

		op2 = n - vis_Hash[idx] + Min_Conv(idx + 1, (p == 1 ? w + 1 : 1), 1);

	return dp[idx][w][p] = min(op1, op2);
}

int main() {
	SADIEM();
	MemS(dp, -1);
	char c;
	cin >> n >> m >> x >> y;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m && cin >> c; j++)
			vis_Hash[j] += (c == '#');

	cout << Min_Conv(0, 0, 0);
}
