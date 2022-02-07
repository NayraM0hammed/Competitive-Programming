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
int h, w;
int dp[100][100];
vector<vector<int>> v;

void Back_Orig() {
	MemS(dp, -1);
	v.clear();
	v.resize(h, vector<int>(w));
}

int Find_Mtiles(int x, int y) {
	if (x == h || y < 0 || y == w)
		return 0;

	if (dp[x][y] != -1)
		return dp[x][y];
	int op1, op2, op3;
	op1 = v[x][y] + Find_Mtiles(x + 1, y);
	op2 = v[x][y] + Find_Mtiles(x + 1, y + 1);
	op3 = v[x][y] + Find_Mtiles(x + 1, y - 1);
	return dp[x][y] = max( { op1, op2, op3 });
}

int main() {
	SADIEM();
	int t;
	cin >> t;
	while (t--) {
		int mx = 0;
		cin >> h >> w;
		Back_Orig();
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w && cin >> v[i][j]; j++)
				;
		for (int c = 0; c < w; c++)
			mx = max(mx, Find_Mtiles(0, c));
		cout << mx << (t ? "\n" : "");
	}
}
