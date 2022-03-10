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
vector<bool> vis;
int n, m;
void Back_Orig() {
	v.clear(), v.resize(n + 1);
	vis.clear();
	vis.resize(n + 1);
}

void BFS(int u) {
	queue<int> q;
	stack<int> s;
	q.push(u);
	vis[u] = true;
	while (sz(q)) {
		u = q.front(), q.pop();
		s.push(u);
		for (auto c : v[u])
			if (!vis[c])
				q.push(c), vis[c] = true;
	}
	while (sz(s))
		cout << s.top() << " ", s.pop();

}

int main() {
	SADIEM();

	while (cin >> n >> m && !(n == m && m == 0)) {
		Back_Orig();

		for (int i = 0, x, y; i < m && cin >> x >> y; i++)
			v[y].push_back(x);

		for (int u = 1; u <= n; u++)
			if (!vis[u])
				BFS(u);

		cout << "\n";

	}

}
