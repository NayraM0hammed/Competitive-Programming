//"Perhaps..,we 're asking the wrong questions .." -Agent Brown
#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<iomanip>
#include<unordered_map>
#define sz(s) (int(s.size()))
#define MemS(s,x) memset(s,x,sizeof(s))
#define PI acos(-1)
typedef  long long ll;
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
ll dp[61][61];
string s;
ll Palin_cnt(int i, int j) {

	if (i == j)
		return 1;

	if (i + 1 == j) //AA
		return 2 + (s[i] == s[j]); //

	if (dp[i][j] != -1)
		return dp[i][j];

	ll ans = 0;

	if (s[i] == s[j])
		ans = 1 + Palin_cnt(i + 1, j - 1);

	ans += Palin_cnt(i + 1, j);
	ans += Palin_cnt(i, j - 1);
	ans -= Palin_cnt(i + 1, j - 1); // Remove duplicated result from Palin_cnt(i+1,j) and Palin_cnt(i,j-1)
	return dp[i][j] = ans;
}

int main() {
	SADIEM();
	int t;
	cin >> t;

	while (t--) {
		MemS(dp, -1);

		cin >> s;

		cout << Palin_cnt(0, sz(s) - 1) << "\n";
	}

}
