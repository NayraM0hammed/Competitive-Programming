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
	//freopen("input.txt", "r", stdin);
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
struct path {
	int s, e, mnn;
};

vector<vector<pair<int, int>>> v;
bool out_going[N], in_going[N], vis[N];

path GG;

void DFS(int node) {
	vis[node] = 1;

	if (!sz(v[node]))
		GG.e = node;

	for (auto c : v[node])
		if (!vis[c.first])
			GG.mnn = min(GG.mnn, c.second), DFS(c.first);
}

int main() {
	SADIEM();
	int n, p;
	cin >> n >> p;
	v.resize(n + 1);
	vector<path> ans;
  
	for (int i = 0, x, y, z; i < p && cin >> x >> y >> z; i++) {
		v[x].push_back( { y, z });
		out_going[x] = in_going[y] = 1;
	}

	for (int i = 1; i <= n; i++)
		if (out_going[i] && !in_going[i]) {
			GG = { i, -1, T_T };
			DFS(i);
			if (GG.e != -1)
				ans.push_back(GG);

		}

	cout << sz(ans) << (sz(ans) ? "\n" : "");

	for (auto x : ans)
		cout << x.s << " " << x.e << " " << x.mnn << "\n";

}
