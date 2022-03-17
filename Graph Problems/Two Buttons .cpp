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

int Path[N];

bool Check(int x) {

	return x > 0 && x < N && Path[x] == -1;
}

int BFS_Path(int st, int ed) {
	queue<int> q;
	q.push(st);
	Path[st] = 0;
	while (sz(q)) {
		st = q.front(), q.pop();
		if (st == ed)
			break;

		int val1 = st * 2, val2 = st - 1;

		if (Check(val1))
			q.push(val1), Path[val1] = 1 + Path[st];

		if (Check(val2))
			q.push(val2), Path[val2] = 1 + Path[st];

	}
	return Path[ed];
}

int main() {
	SADIEM();
	MemS(Path, -1);
	int n, m;
	cin >> n >> m;
	cout << BFS_Path(n, m);

}
