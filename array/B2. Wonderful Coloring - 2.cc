/*
input:
6
10 3
3 1 1 1 1 10 3 10 10 2
4 4
1 1 1 1
1 1
1
13 1
3 1 4 1 5 9 2 6 5 3 5 8 9
13 2
3 1 4 1 5 9 2 6 5 3 5 8 9
13 3
3 1 4 1 5 9 2 6 5 3 5 8 9

output:
1 1 0 2 3 2 2 1 3 3
4 2 1 3
1
0 0 1 1 0 1 1 1 0 1 1 1 0
2 1 2 2 1 1 1 1 2 1 0 2 2
1 1 3 2 1 3 3 1 2 2 3 2 0

Link:https://codeforces.com/contest/1551/problem/B2

*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i, f, t) for(int i = f; i <= t; ++i)
#define rg register
#define In inline
#define ll long long
#define pb push_back
#define mp make_pair
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mine(a)    (*min_element((a).begin(), (a).end()))
using namespace std;
#define MAX 505
#define pi pair <int, int>
#define ff first
#define ss second
#define MOD 1000000007
const int maxn = 2e5 + 100;
using namespace std;

//vector<int> a(INT_MAX);
int a[maxn];
char n[1000];
int ans[maxn];
map<int, vector<int>> indices;

void solve() {
	int n, k;
	cin >> n >> k;
	indices.clear();
	memset(ans, 0, n * sizeof(ans[0]));
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (indices[x].size() < k)
			indices[x].push_back(i);
	}
	/*for (auto& it : indices) {
		cout << it.ff << "->";
		for (auto& it1 : it.ss) {
			cout << it1 << " ";
		}
		cout << endl;
	}*/
	//cout << endl;
	int m = 0;
	for (auto e : indices) {
		m += e.second.size();
		//cout << e.second.size() << " ";
	}
	//cout << endl;
	m -= m % k;
	//cout << m << endl;
	int color = 0;
	for (auto e : indices)
		for (auto i : e.second)
		{
			//cout << i << " ";
			ans[i] = ++color;
			color %= k;
			if (--m == 0) goto _output;
		}
_output:
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}




signed main() {
#ifndef ONLINE_JUDGE
// for getting input from input.txt
	freopen("input.txt", "r", stdin);
// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}

}