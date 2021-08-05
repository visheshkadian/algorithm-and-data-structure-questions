/*
input:chchokudai
output:3
explanation:We have three valid ways:

ch ch okudai
c hc hokudai
ch chokudai

while the following is invalid:

c hc hokudai
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define rg register
#define In inline
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD 1000000007
 
ll t, n, ans, a[1001000];
string str, pat = "_chokudai";
 
 
void solve() {
 
	cin >> str; n = str.size();
 
	a[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 8; j++)
			if (str[i] == pat[j])
				a[j] = (a[j] + a[j - 1]) % MOD;
	}
	cout << a[8];
 
 
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
	int tt = 1;
	//cin >> tt;
	while (tt--) {
		solve();
	}
}