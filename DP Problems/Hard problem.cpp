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
const ll N = 1e5 + 1, O_O = 1e15, T_T = INT_MAX, V_V = INT_MIN;

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

ll dp[N][2];

vector<pair<string, ll>> v;

ll Min_Cost(int idx, bool reversed) {

	if (idx == sz(v))
		return 0;

	if (dp[idx][reversed] != -1)
		return dp[idx][reversed];

	ll op1, op2;

	op1 = op2 = O_O;

	string rev = v[idx].first, s = (idx ? v[idx - 1].first : "");
	reverse(rev.begin(), rev.end());

	if (reversed)
		reverse(s.begin(), s.end());

	if (!idx || (idx && v[idx].first >= s))
		op1 = Min_Cost(idx + 1, 0);

	if (!idx || (idx && rev >= s))
		op2 = v[idx].second + Min_Cost(idx + 1, 1);

	return dp[idx][reversed] = min(op1, op2);
}
int main() {
	SADIEM();
	MemS(dp, -1);
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n && cin >> v[i].second; i++)
		;
	for (int i = 0; i < n && cin >> v[i].first; i++)
		;

	ll ans = Min_Cost(0, 0);

	cout << (ans < O_O ? ans : -1);

}
