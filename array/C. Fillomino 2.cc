/*
input:
3
2 3 1
output:
2
2 3
3 3 1

input:
5
1 2 3 4 5
output:
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5

Link:https://codeforces.com/contest/1517/problem/C
*/
/*
	     ▄▀▀▀▄
	▄███▀░◐░░░▌
	    ▌░░░░░▐
	    ▐░░░░░▐
	    ▌░░░░░▐▄▄
	    ▌░░░░▄▀▒▒▀▀▀▀▄
	   ▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
	   ▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
	    ▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
	      ▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
	           ▌▌░▌▌
	         ▄▄▌▌▄▌▌
	*/
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("inline")

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
#define all(a) a.begin(),a.end()
#define MOD 1000000007
const int maxn = 2e5 + 100;
using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	vector<vector<int>> ans(n, vector<int>(n, 0));
	vector<int> a(n);
	generate(all(a), nxt);
	for (int t = 1; t <= n; ++t) {
		for (int i = 0; i < (int)a.size(); ++i) {
			ans[t - 1 + i][i] = a[i];
			//cout << a[i] << "->";
		}
		a.erase(find(all(a), t));
		//cout << *find(all(a), t) << " ";
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
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
	ll t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}
//ORRR
//
//
//

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
#define all(a) a.begin(),a.end()
#define MOD 1000000007
const int maxn = 2e5 + 100;
using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	vector<vector<int>> ans(n, vector<int>(n, 0));
	vector<int> a(n);
	generate(all(a), nxt);
	for (int t = 1; t <= n; ++t) {
		for (int i = 0; i < (int)a.size(); ++i) {
			ans[t - 1 + i][i] = a[i];
			//cout << a[i] << "->";
		}
		a.erase(find(all(a), t));
		//cout << *find(all(a), t) << " ";
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
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
	ll t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}