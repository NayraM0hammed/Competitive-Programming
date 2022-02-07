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

int dp[1000][32], n;
vector<pair<int, int>> v;

void Back_Orig() {
	v.clear();
	v.resize(n);
	MemS(dp, -1);

}

int Knap_Sack(int idx, int curr) {
	if (idx == sz(v))
		return 0;
	if (dp[idx][curr] != -1)
		return dp[idx][curr];

	int op1 = Knap_Sack(idx + 1, curr), op2 = 0;

	if (v[idx].second <= curr)
		op2 = v[idx].first + Knap_Sack(idx + 1, curr - v[idx].second);

	return dp[idx][curr] = max(op1, op2);
}

int main() {
	SADIEM();
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		Back_Orig();
		for (int i = 0; i < n && cin >> v[i].first >> v[i].second; i++)
			;
		ll total = 0;
		int g;

		cin >> g;

		while (g--) {
			int x;
			cin >> x;
			total += Knap_Sack(0, x);
		}

		cout << total << "\n";
	}

}
