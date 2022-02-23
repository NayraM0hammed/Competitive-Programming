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
const ll N = 1e5 + 1, O_O = 1e10, T_T = INT_MAX, V_V = INT_MIN;

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
ll dp[N][3];
vector<int> a, b;

ll Find_MaxHeight(int idx, int pre) {
	if (idx == sz(a))
		return 0;

	if (dp[idx][pre] != -1)
		return dp[idx][pre];

	ll op1, op2, op3 = Find_MaxHeight(idx + 1, pre);

	op1 = op2 = LONG_LONG_MIN;

	if (!pre || pre == 2)
		op1 = a[idx] + Find_MaxHeight(idx + 1, 1);
	if (!pre || pre == 1)
		op2 = b[idx] + Find_MaxHeight(idx + 1, 2);

	return dp[idx][pre] = max( { op1, op2, op3 });
}
int main() {
	SADIEM();
	MemS(dp, -1);
	
	int n;
	cin >> n;
	
	a.resize(n), b.resize(n);

	for (int i = 0; i < n && cin >> a[i]; i++)
		;
	for (int i = 0; i < n && cin >> b[i]; i++)
		;

	cout << Find_MaxHeight(0, 0);

}
