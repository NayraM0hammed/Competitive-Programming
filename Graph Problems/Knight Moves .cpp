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

int Path[10][10];

pair<int, int> Trans(string x) {
	return {x[1]-'0',x[0]-'a'+1};
}

bool valid(int x, int y) {
	return x > 0 && x < 9 && y > 0 && y < 9 && Path[x][y] == -1;
}

int BFS_WAY(pair<int, int> st, pair<int, int> ed) {
	queue<pair<int, int> > q;
	q.push(st);
	Path[st.first][st.second] = 0;
	while (sz(q)) {
		st = q.front(), q.pop();

		if (st == ed)
			break;

		for (int i = 0; i < 8; i++)

			if (valid(st.first + Dx[i], st.second + Dy[i])) {

				q.push( { st.first + Dx[i], st.second + Dy[i] });

				Path[st.first + Dx[i]][st.second + Dy[i]] = 1
						+ Path[st.first][st.second];

			}

	}

	return Path[ed.first][ed.second];
}

int main() {
	SADIEM();
	string x, y;

	while (cin >> x >> y && !(x == "0")) {

		MemS(Path, -1);

		pair<int, int> P1 = Trans(x), P2 = Trans(y);

		cout << "To get from " << x << " to " << y << " takes ";
		cout << BFS_WAY(P1, P2) << " knight moves.\n";
	}

}
