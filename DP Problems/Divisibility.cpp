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
const ll N = 1e4 + 1, O_O = LONG_LONG_MAX, T_T = INT_MAX;

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
vector<int> v;

ll dp[N][101];

int pos_mod(int val) {
	return ((val % k) + k) % k;
}

int DIVISIBLE(int idx, int mod) {
	if (idx == sz(v))
		return (mod == 0);
	if (dp[idx][mod] != -1)
		return dp[idx][mod];

	int op1 = DIVISIBLE(idx + 1, pos_mod(mod + v[idx]));
	int op2 = DIVISIBLE(idx + 1, pos_mod(mod - v[idx]));

	return dp[idx][mod] = op1 | op2;
}

int main() {
	SADIEM();
	int t;
	cin >> t;
	while (t--) {
		MemS(dp, -1);
		int n;
		cin >> n >> k;
		v.clear();
		v.resize(n);
		for (int i = 0; i < n && cin >> v[i]; i++)
			;

		cout << (DIVISIBLE(0, 0) ? "Divisible" : "Not divisible") << "\n";
	}
}
