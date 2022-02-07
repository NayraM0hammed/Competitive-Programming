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
const ll N = 2e5 + 5, O_O = 1e15, T_T = INT_MAX, V_V = INT_MIN, V = 1e4;

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

ll dp[100][N], k;

vector<pair<ll, ll>> v;

ll Max_Taste(int idx, int rem) {
	if (idx == sz(v))
		return (rem == V ? 0 : -1e9);

	if (dp[idx][rem] != -1)
		return dp[idx][rem];

	ll op1 = Max_Taste(idx + 1, rem);
	ll op2 = v[idx].first
			+ Max_Taste(idx + 1, rem + (v[idx].first - (v[idx].second * k)));

	return dp[idx][rem] = max(op1, op2);
}

int main() {
	SADIEM();
	MemS(dp, -1);
	int n;
	cin >> n >> k;
	v.resize(n);

	for (int i = 0; i < n && cin >> v[i].first; i++)
		;
	for (int i = 0; i < n && cin >> v[i].second; i++)
		;
	ll ans = Max_Taste(0, V);

	cout << (!ans ? -1 : ans);
}
