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
const ll N = 1e4 + 1, O_O = LONG_LONG_MAX, T_T = INT_MAX;

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
int dp[100][4];
vector<int> v;
int Max_Dwork(int idx, int prev) {
	if (idx == sz(v))
		return 0;
	if (dp[idx][prev] != -1)
		return dp[idx][prev];

	int op1 = Max_Dwork(idx + 1, 0), op2 = 0, op3 = 0;

	if (v[idx] == 1 && prev != 1)
		op2 = 1 + Max_Dwork(idx + 1, 1);

	else if (v[idx] == 2 && prev != 2)
		op2 = 1 + Max_Dwork(idx + 1, 2);

	else if (v[idx] == 3) {

		if (prev == 2 || prev == 1) // if prev == 1 that means we cant write a contest so we only do sport
									// if prev == 2 ****************** do sport so we only write a contest
			op2 = 1 + Max_Dwork(idx + 1, (prev == 1 ? 2 : 1));
		else
			// prev neither 1 nor 2 so we try what will be our options if we do sport or write a contest
			op2 = 1 + Max_Dwork(idx + 1, 1), op3 = 1 + Max_Dwork(idx + 1, 2);

	}
	return dp[idx][prev] = max( { op1, op2, op3 });
}
int main() {
	SADIEM();
	MemS(dp, -1);
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n && cin >> v[i]; i++)
		;
	cout << n - Max_Dwork(0, 0);

}
