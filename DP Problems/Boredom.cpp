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
int mx;
ll dp[N];
unordered_map<int, int> mp;

ll Find_Max(ll val) {
	if (val > mx)
		return 0;

	if (dp[val] != -1)
		return dp[val];

	ll op1 = Find_Max(val + 1), op2 = (val * mp[val]) + Find_Max(val + 2);

	return dp[val] = max(op1, op2);
}

int main() {
	SADIEM();
	MemS(dp, -1);
	int n, mn = T_T;
	cin >> n;
	for (int i = 0, x; i < n && cin >> x; i++)
		mn = min(x, mn), mx = max(mx, x), mp[x]++;

	cout << Find_Max(mn);

}
