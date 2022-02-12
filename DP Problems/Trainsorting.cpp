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
vector<int> v;

int dpI[2000][2000], dpD[2000][2000], n;
void Back_Orig() {
	MemS(dpD, -1);
	MemS(dpI, -1);
  	v.clear();
	v.resize(n);
}
int LIS(int idx, int pre) {
	if (idx == sz(v))
		return 0;
	if (dpI[idx][pre] != -1)
		return dpI[idx][pre];
	int op1 = 0, op2 = 0;
	if (idx == pre || v[idx] > v[pre])
		op1 = 1 + LIS(idx + 1, idx);
	if (idx != pre)
		op2 = LIS(idx + 1, pre);

	return dpI[idx][pre] = max(op1, op2);
}

int LDS(int idx, int pre) {
	if (idx == sz(v))
		return 0;
	if (dpD[idx][pre] != -1)
		return dpD[idx][pre];
	int op1 = 0, op2 = LDS(idx + 1, pre);

	if (v[idx] < v[pre])
		op1 = 1 + LDS(idx + 1, idx);

	return dpD[idx][pre] = max(op1, op2);
}

int main() {
	SADIEM();
	int t;
	cin >> t;
	while (t--) {
		int mx = 0;
		cin >> n;
		Back_Orig();
		for (int i = 0; i < n && cin >> v[i]; i++)
			;

		for (int i = 0; i < n; i++)
			mx = max(mx, LIS(i, i) + LDS(i, i));

		cout << mx << "\n";
	}
}
