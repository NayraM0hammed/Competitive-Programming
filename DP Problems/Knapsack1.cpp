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
vector<pair<int, int>> v;
ll dp[100][N];
ll Knap_Sack(int idx, int reminder) {
	if (idx >= sz(v))
		return 0;
	if (dp[idx][reminder] != -1)
		return dp[idx][reminder];
	ll op1, op2 = 0;
	op1 = Knap_Sack(idx + 1, reminder);
	if (v[idx].first <= reminder)
		op2 = v[idx].second + Knap_Sack(idx + 1, reminder - v[idx].first);
	return dp[idx][reminder] = max(op1, op2);
}

int main() {
	SADIEM();
	MemS(dp, -1);
	int n, W;
	cin >> n >> W;
	v.resize(n);
	for (int i = 0; i < n && cin >> v[i].first >> v[i].second; i++)
		;

	cout << Knap_Sack(0, W);

}
