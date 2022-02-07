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

ll w, n, dp[1001][1001], vis[1001][1001];
void Back_Orig() {
	MemS(dp, -1);
	MemS(vis, 0);
}
bool valid(int x, int y) {
	return ( x < w &&  y < n && !vis[x][y]);
}

ll Num_Of_SPaths(int i, int j) {
	if (!valid(i, j))
		return 0;

	if (i == w - 1 && j == n - 1)
		return 1;

	if (dp[i][j] != -1)
		return dp[i][j];

	ll op1 = Num_Of_SPaths(i, j + 1), op2 = Num_Of_SPaths(i + 1, j);

	return dp[i][j] = op1 + op2;
}
int main() {
	SADIEM();
	int t;
	cin >> t;
	while (t--) {

		cin >> w >> n;
		Back_Orig();
		string s;
		cin.ignore();

		for (int i = 0; i < w; i++) {
			int x, y;
			getline(cin, s);
			stringstream ss(s);
			ss>>x;
			while (ss >> y)
				vis[x - 1][y - 1] = 1;
		}

		cout << Num_Of_SPaths(0, 0) << "\n" << (t ? "\n" : "");
	}
}
