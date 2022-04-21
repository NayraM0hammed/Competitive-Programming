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
const ll N = 1e6 + 2, O_O = LONG_LONG_MAX, T_T = INT_MAX, V_V = INT_MIN;

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

int dp[52][52][3000][3], n, s, k, ans;
vector<int> v, c;

int Find_Min(int idx, int pre, int val, int op) {

	if (idx == sz(v) || idx < 0) {
		if (val >= k)
			return 0;
		return 3000;
	}

	if (dp[idx][pre][val][op] != -1)
		return dp[idx][pre][val][op];

	int op1, op2, op4, op3;
	op1 = op2 = op4 = op3 = 3000;
	
  if (!op || op == 2)
		op1 = 1 + Find_Min(idx - 1, pre, val, 0);
	
  if (op)
		op2 = 1 + Find_Min(idx + 1, pre, val, 1);

	if (pre == 51 || (v[idx] > v[pre] && c[idx] != c[pre])) {
		if (val + v[idx] >= k)
			return 0;
	
    op4 = 1 + Find_Min(idx + 1, idx, val + v[idx], 1);
		op3 = 1 + Find_Min(idx - 1, idx, val + v[idx], 0);

	}

	return dp[idx][pre][val][op] = min( { op1, op2, op3, op4 });

}

int main() {
	SADIEM();
	MemS(dp, -1);
	char color;
	cin >> n >> s >> k;
	v.resize(n), c.resize(n);
	for (int i = 0; i < n && cin >> v[i]; i++)
		;

	for (int i = 0; i < n && cin >> color; i++)
		c[i] = (color == 'R' ? 1 : color == 'B' ? 2 : 3);

	ans = Find_Min(s - 1, 51, 0, 2);

  cout << (ans > 2500 ? -1 : ans);

}

