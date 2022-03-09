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
vector<vector<int>> v;
vector<int> ans;

void Dfs(int u, int par) {

	ans[u] = par;

	for (auto c : v[u])
		if (c != par)
			Dfs(c, u);

}

int main() {
	SADIEM();
	int n, r1, r2, curr = 1;
	cin >> n >> r1 >> r2;
	ans.resize(n + 5);
	v.resize(n + 5);
	for (int i = 0, x; i < n - 1 && cin >> x; i++)
		curr += (r1 == curr), v[curr].push_back(x), v[x].push_back(curr), curr++;

	Dfs(r2, -1);

	for (int i = 1; i <= n; i++)
		if (i != r2)
			cout << ans[i] << " ";

}
