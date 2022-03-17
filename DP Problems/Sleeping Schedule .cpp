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
const ll N = 1e6 + 1, O_O = 1e10, T_T = INT_MAX, V_V = INT_MIN;
// 8 neighbors
int Dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int Dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
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

vector<int> v;
int h, l, r, dp[2000][2001];

bool check(int val) {

	return val >= l && val <= r;
}

int MaX_Good(int idx, int curr) {
	if (idx == sz(v))
		return 0;

	if (dp[idx][curr] != -1)
		return dp[idx][curr];

	int op1 = check((curr + v[idx]) % h) + MaX_Good(idx + 1, (curr + v[idx]) % h);

	int op2 = check((curr + v[idx] - 1) % h) + MaX_Good(idx + 1, (curr + v[idx] - 1) % h);

	return dp[idx][curr] = max(op1, op2);
}

int main() {
	SADIEM();
	MemS(dp, -1);

	int n;
	cin >> n >> h >> l >> r;

	v.resize(n);

	for (int i = 0; i < n && cin >> v[i]; i++)
		;

	cout << MaX_Good(0, 0);

}
