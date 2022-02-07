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
const ll N = 1e5 + 1, O_O = 1e11, T_T = INT_MAX, V_V = INT_MIN;

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
int dp[N][3];
////       pos, height
vector<pair<ll, ll>> v;
int Max_Cuts(int idx, int prev_c) {
	if (idx == sz(v))
		return 0;

	if (dp[idx][prev_c] != -1)
		return dp[idx][prev_c];

	int op1, op2, op3 = Max_Cuts(idx + 1, 0);

	op1 = op2 = 0;

	if (!idx || (prev_c != 2 && v[idx - 1].first < v[idx].first - v[idx].second) || (prev_c==2&&v[idx - 1].first + v[idx - 1].second < v[idx].first - v[idx].second))
		op1 = 1 + Max_Cuts(idx + 1, 1);

	if (idx == sz(v) - 1 || v[idx + 1].first > v[idx].first + v[idx].second)
		op2 = 1 + Max_Cuts(idx + 1, 2);

	return dp[idx][prev_c] = max( { op1, op2, op3 });
}
int main() {
	SADIEM();
	MemS(dp, -1);
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n && cin >> v[i].first >> v[i].second; i++)
		;

	cout << Max_Cuts(0, 0);
}
