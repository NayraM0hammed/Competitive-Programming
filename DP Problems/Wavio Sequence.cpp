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
// N log N solution
int n;
vector<int> v, L_I, L_D;
void Back_Orig() {
	v.clear(), L_I.clear(), L_D.clear();
	v.resize(n), L_I.resize(n), L_D.resize(n);
}
void LS(bool op) {
	vector<int> list;
	for (int i = 0; i < n; i++) {
		int f = lower_bound(list.begin(), list.end(), v[i]) - list.begin();
		if (f == sz(list))
			list.push_back(v[i]);
		else
			list[f] = v[i];

		(!op ? L_I[i] = f + 1 : L_D[i] = f + 1);
	}
	
	if (op)
		reverse(L_D.begin(), L_D.end());
}
int main() {
	SADIEM();
	while (cin >> n && n) {
		int mx = 0;
		Back_Orig();
		for (int i = 0; i < n && cin >> v[i]; i++)
			;
		LS(0);
		reverse(v.begin(), v.end());
		LS(1);
		for (int i = 0; i < n; i++)
			mx = max(mx, min(L_D[i], L_I[i]));

		cout << 2 * (mx - 1) + 1 << "\n";

	}

}
