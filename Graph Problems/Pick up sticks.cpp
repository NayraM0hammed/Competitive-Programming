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
int n, m;
vector<vector<int>> v;
vector<int> ans;
int vis[N];
bool U_U;

void Back_Orig() {
	v.clear(), v.resize(n + 1);
	ans.clear();
	MemS(vis, 0);
	U_U = 0;
}

void DFS(int node) {

	vis[node] = 1;

	for (auto c : v[node]) {
		if (!vis[c])
			DFS(c);
		else if (vis[c] == 1)
			U_U = 1;
	}
	vis[node] = 2;
	ans.push_back(node);
}

int main() {
	SADIEM();

	while (cin >> n >> m && !(n == m && !m)) {
		Back_Orig();

		for (int i = 0, x, y; i < m && cin >> x >> y; i++)
			v[y].push_back(x);

		for (int i = 1; i <= n; i++)
			if (!vis[i])
				DFS(i);


		if (U_U)
			cout << "IMPOSSIBLE\n";

		else
			for (auto x : ans)
				cout << x << "\n";
	}

}
