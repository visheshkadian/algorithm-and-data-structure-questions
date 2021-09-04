/*

You are given an array a of n integers. Find the number of pairs (i,j) (1≤i<j≤n) where the sum of ai+aj is greater than or equal to l and less than or equal to r (that is, l≤ai+aj≤r).

For example, if n=3, a=[5,1,2], l=4 and r=7, then two pairs are suitable:

i=1 and j=2 (4≤5+1≤7);
i=1 and j=3 (4≤5+2≤7).

inputCopy
4
3 4 7
5 1 2
5 5 8
5 1 2 4 3
4 100 1000
1 1 1 1
5 9 13
2 5 5 1 1

outputCopy
2
7
0
1

Link: https://codeforces.com/problemset/problem/1538/C
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

int a[maxn];

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> v(n);
	for (int &e : v) {
		cin >> e;
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += upper_bound(v.begin(), v.end(), r - v[i]) - v.begin();
		//cout << ans << endl;
		ans -= lower_bound(v.begin(), v.end(), l - v[i]) - v.begin();
		if (l <= 2 * v[i] && 2 * v[i] <= r) {
			ans--;
		}
	}
	cout << ans / 2 << "\n";
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
	cin >> t;
	while (t--) {
		solve();
	}

}

//using pure binary search

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

int a[maxn];

void solve() {
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	ll res = 0;
	for (int i = 2; i <= n; i++)
	{
		int l = 1;
		int r = i - 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (a[mid] + a[i] >= x)	r = mid;
			else	l = mid + 1;
		}
		int ansl = r;
		l = 1;
		r = i - 1;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (a[mid] + a[i] <= y)	l = mid;
			else	r = mid - 1;
		}
		int ansr = r;
		if (a[i] + a[ansl] >= x && a[i] + a[ansr] <= y)
		{
			res += ansr - ansl + 1;
		}

	}
	cout << res << endl;
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
	cin >> t;
	while (t--) {
		solve();
	}

}