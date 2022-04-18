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
const ll N = 1e6 + 1, O_O = LONG_LONG_MAX, T_T = INT_MAX, V_V = INT_MIN;

// 8 neighbors
int Dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 }; // Orig: -1,-1,-1,  0, 0,  1, 1, 1
int Dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 }; // Orig: -1, 0, 1, -1, 1, -1, 0, 1

// 4 neighbors
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

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

ll dp[N][2];
vector<int> v;

void Back_Orig() {
	MemS(dp, -1);
	v.clear();
}

ll Max_Strength(int idx, int op) {
	if (idx == sz(v))
		return 0;
	if (dp[idx][op] != -1)
		return dp[idx][op];
	ll op1 = Max_Strength(idx + 1, op), op2 = V_V, op3 = V_V;
	//1 --  // 0 ++
	if (op)
		op2 = -v[idx] + Max_Strength(idx + 1, 0);
	else
		op3 = v[idx] + Max_Strength(idx + 1, 1);

	return dp[idx][op] = max( { op1, op2, op3 });
}

int main() {
	SADIEM();
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		Back_Orig();
		v.resize(n);
		
    for (int i = 0; i < n && cin >> v[i]; i++)
			;
    
		cout << Max_Strength(0, 0) << (t ? "\n" : "");
	}

}
