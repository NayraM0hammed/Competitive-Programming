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
vector<string> v;
int cnt;
bool vis[25][25];

void Back_Orig() {
	v.clear(), MemS(vis, 0), cnt = 0;
}

bool valid(int x, int y) {
	return x >= 0 && x < sz(v) && y >= 0 && y < sz(v[x]) && v[x][y] == '1';
}

void DFS(int i, int j) {
	if (!valid(i, j) || vis[i][j])
		return;

	cnt++;

	vis[i][j] = true;

	for (int b = 0; b < 8; b++)
		DFS(i + Dx[b], j + Dy[b]);

}

int main() {
	SADIEM();
	int t;
	string s;
	cin >> t;
	cin.ignore();
	getline(cin, s);
  
	while (t--) {
		int mx = 0;
		Back_Orig();

		getline(cin, s);

		if (sz(s))
			v.push_back(s);

		while (getline(cin, s) && sz(s))
			v.push_back(s);

		for (int i = 0; i < sz(v); i++)
			for (int j = 0; j < sz(v[i]); j++)
				if (v[i][j] == '1' && !vis[i][j])
					cnt = 0, DFS(i, j), mx = max(mx, cnt);

		cout << mx << "\n" << (t ? "\n" : "");
	}

}
