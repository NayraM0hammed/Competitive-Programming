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
ll dp[100][N];

vector<pair<int, int>> v;

ll Knap_Sack(int idx, ll val) {
	if (idx == sz(v))
		return (!val ? 0 : O_O);

	if (dp[idx][val] != -1)
		return dp[idx][val];

	ll op1 = Knap_Sack(idx + 1, val), op2 = O_O;

	if (v[idx].second <= val)
		op2 = v[idx].first + Knap_Sack(idx + 1, val - v[idx].second);

	return dp[idx][val] = min(op1, op2);
}

int main() {
	SADIEM();
	MemS(dp, -1);
	int n, w;
	ll total = 0;
	cin >> n >> w;
	v.resize(n);

	for (int i = 0; i < n && cin >> v[i].first >> v[i].second; i++)
		total += v[i].second;

	for (int i = total; i >= 0; i--)
		if (Knap_Sack(0, i) <= w)
			return cout << i, 0;

}
