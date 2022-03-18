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
int n, m, k, cnt = 0;
vector<string> v;
int vis[500][500];

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '.' && !vis[x][y];
}

void BFS(pair<int, int> st) {
	queue<pair<int, int>> q;

	q.push(st);
	
	vis[st.first][st.second] = 1;
	
	while (sz(q)) {
	
		st = q.front(), q.pop();
		vis[st.first][st.second] = 2;
		cnt--;
		
		if (!cnt)
			return;
		
		for (int i = 0; i < 4; i++) {
			pair<int, int> GG = { st.first + dx[i], st.second + dy[i] };
		
			if (valid(st.first + dx[i], st.second + dy[i])) {
				vis[st.first + dx[i]][st.second + dy[i]] = 1;
				q.push(GG);
			}
	
		}
	}

}

int main() {
	SADIEM();

	pair<int, int> st;
	
	cin >> n >> m >> k;
	v.resize(n);

	for (int i = 0; i < n && cin >> v[i]; i++)
		for (int j = 0; j < sz(v[i]); j++)
			if (valid(i, j))
				st = { i, j }, cnt++;
	
	cnt -= k;
	
	BFS(st);
	
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++)
			cout << (v[i][j] == '.' && vis[i][j] != 2 ? 'X' : v[i][j]);

		cout << (i == n - 1 ? "" : "\n");
	}
	
}
