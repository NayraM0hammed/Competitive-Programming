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
const ll N = 1 << 21, O_O = 1e15, T_T = INT_MAX, V_V = INT_MIN;

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
vector<vector<int>> v;
ll dp[21][N];

ll Find_Poss(int idx, int taken) {

	if (idx == sz(v))
		return 1;

	if (dp[idx][taken] != -1)
		return dp[idx][taken];

	ll op = 0;

	for (int i = 0; i < sz(v); i++)
		if (v[i][idx] && !(taken & (1 << i)))
			taken |= (1 << i), op += Find_Poss(idx + 1, taken), op %= Mod, taken ^=(1 << i);

	return dp[idx][taken] = op % Mod;
}

int main() {
	SADIEM();

	MemS(dp, -1);

	int n;
	cin >> n;
	v.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n && cin >> v[i][j]; j++)
			;

	cout << Find_Poss(0, 0);
}
