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
string s;
ll dp[1000][1000], r = 1;
void Back_Orig() {
	MemS(dp, -1);
	cout << "Case " << r++ << ": ";
}
ll S_to_P(int i, int j) {
	if (j <= i)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	ll op1 = T_T, op2 = T_T, op3 = T_T, op4 = T_T;

	if (s[i] == s[j])
		op1 = S_to_P(i + 1, j - 1);
	else
		//add ,                              delete                  replace
		op2 = 1 + S_to_P(i, j - 1), op4 = 1 + S_to_P(i + 1, j), op3 = 1+ S_to_P(i + 1, j - 1);

	return dp[i][j] = min( { op1, op2, op3, op4 });
}
int main() {
	SADIEM();
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		Back_Orig();
		cout << S_to_P(0, sz(s) - 1) << "\n";
	}
}
