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
string x, y, ans = "";
int dp[3000][3000];
int LCS(int i, int j) {

	if (i == sz(x) || j == sz(y))
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	int op2 = 0, op3 = 0;

	if (x[i] == y[j])
		return dp[i][j] = 1 + LCS(i + 1, j + 1);

	else {
		op2 = LCS(i + 1, j), op3 = LCS(i, j + 1);
		return dp[i][j] = max( { op2, op3 });
	}
}
string Cons(int i, int j) {
	if (i == sz(x) || j == sz(y))
		return "";

	if (x[i] == y[j])
		return ans = x[i] + Cons(i + 1, j + 1);

	else
		return ans = (dp[i][j + 1] < dp[i + 1][j] ? Cons(i + 1, j) : Cons(i, j + 1));

}
int main() {
	SADIEM();
	MemS(dp, -1);
	cin >> x >> y;
	LCS(0, 0);
	cout << Cons(0, 0);
}
