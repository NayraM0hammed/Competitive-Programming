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
vector<int> a, b, c;
ll dp[N][3];
ll Max_H(int idx, int pre) {
	if (idx > sz(a))
		return 0;
	if (dp[idx][pre] != -1)
		return dp[idx][pre];
	ll op1, op2, op3;
	op1 = op2 = op3 = 0;
	if (!pre)
		op1 = a[idx] + Max_H(idx + 1, 1), op2 = b[idx] + Max_H(idx + 1, 2), op3 =
				c[idx] + Max_H(idx + 1, 3);
	else if (pre == 1)
		op1 = b[idx] + Max_H(idx + 1, 2), op2 = c[idx] + Max_H(idx + 1, 3);
	else if (pre == 2)
		op1 = a[idx] + Max_H(idx + 1, 1), op2 = c[idx] + Max_H(idx + 1, 3);
	else
		op1 = a[idx] + Max_H(idx + 1, 1), op2 = b[idx] + Max_H(idx + 1, 2);
	return dp[idx][pre] = max( { op1, op2, op3 });
}
int main() {
	SADIEM();
	
	MemS(dp, -1);
	int n;
	cin >> n;
	a.resize(n), b.resize(n), c.resize(n);
	for (int i = 0; i < n && cin >> a[i] >> b[i] >> c[i]; i++)
		;

	cout << Max_H(0, 0);

}
