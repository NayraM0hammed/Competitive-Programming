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
int n, total;
int dp[100][N];
vector<int> v;
void Back_Orig() {
	total = 0;
	MemS(dp, -1);
	v.clear();
	v.resize(n);
}
int Fair(int idx, int val) {
	if (idx == n)
		return abs(abs(total - val) - val);

	if (dp[idx][val] != -1)
		return dp[idx][val];

	int op1 = Fair(idx + 1, val), op2 = Fair(idx + 1, val + v[idx]);

	return dp[idx][val] = min(op1, op2);
}
int main() {
	SADIEM();
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		Back_Orig();
		for (int i = 0; i < n && cin >> v[i]; i++)
			total += v[i];
		cout << Fair(0, 0) << "\n";
	}

}
