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
int Dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 }; // Orig: -1,-1,-1,  0, 0,  1, 1, 1
int Dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 }; // Orig: -1, 0, 1, -1, 1, -1, 0, 1

// 4 neighbors
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };

//"Look deep into your soul, into the dark and foggy mist of your memories"

void SADIEM() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
}

/*

 “ I’d like to let you in on a very important secret I learned when I was about your age, boy.
 You see, power, real power doesn’t come to those who were born strongest or fastest or smartest.
 No. It comes to those who will do anything to achieve it.”

 */

int Path[2001][2001], n, m;
queue<pair<int, int>> q;

bool Check(int x, int y) {

	return x > 0 && x <= n && y > 0 && y <= m && Path[x][y] == -1;
}

void BFS_Path() {
	int x, y, mx = 0;
	pair<int, int> ans = q.front();

	while (sz(q)) {
		x = q.front().first, y = q.front().second, q.pop();
		for (int i = 0; i < 4; i++)
			if (Check(x + dx[i], y + dy[i])) {
				
				q.push( { x + dx[i], y + dy[i] });
				
				Path[x + dx[i]][y + dy[i]] = 1 + Path[x][y];
				
				if (Path[x + dx[i]][y + dy[i]] >= mx) {
					mx = Path[x + dx[i]][y + dy[i]];

					ans = { x + dx[i], y + dy[i] };
				}
			}
	}

	cout << ans.first << " " << ans.second;

}

int main() {
	SADIEM();
	MemS(Path, -1);
	int k;
	cin >> n >> m >> k;
	for (int i = 0, x, y; i < k && cin >> x >> y; i++)
		q.push( { x, y }), Path[x][y] = 0;

	BFS_Path();

}
