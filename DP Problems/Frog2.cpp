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
const ll N = 1e5 + 1, O_O = LONG_LONG_MAX, T_T = INT_MAX;

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
int k;
vector<int> h;
ll dp[N];
ll MIN_Cost(int idx) {
	if (idx == sz(h) - 1)
		return 0;
	if (dp[idx] != -1)
		return dp[idx];

	ll op, mn = O_O;
	for (int i = 1; i <= k; i++) {
		op = O_O;
		if (idx + i < sz(h))
			op = abs(h[idx] - h[idx + i]) + MIN_Cost(idx + i);
		mn = min(mn, op);
	}

	return dp[idx] = mn;
}
int main() {
	SADIEM();
	MemS(dp, -1);
	int n;
	cin >> n >> k;
	h.resize(n);
	for (int i = 0; i < n && cin >> h[i]; i++)
		;

	cout << MIN_Cost(0);

}
