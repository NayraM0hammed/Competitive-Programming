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

int dp[100][100];
string x, y;
int Cnt_Mutual(int i1, int i2) {
	if (i1 == sz(x) || i2 == sz(y))
		return 0;

	if (dp[i1][i2] != -1)
		return dp[i1][i2];

	int op1, op2, op3;

	op1 = (x[i1] == y[i2]) + Cnt_Mutual(i1 + 1, i2 + 1);
	op2 = Cnt_Mutual(i1 + 1, i2);
	op3 = Cnt_Mutual(i1, i2 + 1);

	return dp[i1][i2] = max( { op1, op2, op3 });
}
int main() {
	SADIEM();
	int r = 1;
	while (getline(cin, x) && x[0] != '#' && getline(cin, y)) {
		MemS(dp, -1);
		cout << "Case #" << r++ << ": you can visit at most "
				<< Cnt_Mutual(0, 0) << " cities.\n";
	}
}
