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

set<pair<int, int>> s;

map<pair<int, int>, int> path;

pair<int, int> st, ed;

int BFS() {
	queue<pair<int, int>> q;

	q.push(st);

	while (sz(q)) {
		st = q.front(), q.pop();

		if (st == ed)
			return path[ed];

		for (int i = 0; i < 8; i++) {

			pair<int, int> GG = { st.first + Dx[i], st.second + Dy[i] };
			
			if (s.find(GG) != s.end())
				q.push(GG), path[GG] = 1 + path[st], s.erase(GG);
		}

	}

	return -1;
}

int main() {
	SADIEM();
	int n;

	cin >> st.first >> st.second >> ed.first >> ed.second >> n;

	for (int i = 0, r, a, b; i < n && cin >> r >> a >> b; i++)
		for (int j = a; j <= b; j++)
			s.insert( { r, j });

	cout << BFS();

}
