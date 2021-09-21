/*
INput:
5
1
100
0
1
0
100
4
20 30 40 50
100 100 100 100
4
10 20 30 40
100 100 100 100
7
7 59 62 52 27 31 55
33 35 50 98 83 80 64

output:
0
1
3
4
2

Link: https://codeforces.com/problemset/problem/1530/C

great use of binary search

*/

#include<bits/stdc++.h>
using namespace std;
#define rg register
#define In inline
#define ll long long
#define ld long double
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
#define allr(a) a.rbegin(),a.rend()
#define MOD 1000000007
const int mod = 998244353;
using namespace std;

//using ll = long long;
int score(vector<int>& a) {
    int n = a.size();
    int x = n - n / 4;
    sort(allr(a));
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += a[i];
    }
    return sum;
}

void solve() {
    int n; cin >> n;
    vector<int>a(n), b(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    if (score(a) >= score(b)) {
        cout << 0 << endl;
        return;
    }
    int l = 0;
    int r = 2 * a.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        auto a1 = a;
        for (int i = 0; i < m; i++)a1.pb(100);
        auto b1 = b;
        for (int i = 0; i < m; i++)b1.pb(0);
        if (score(a1) >= score(b1))r = m;
        else l = m;
    }

    cout << r << endl;


}

signed main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout<<"Case #"<<tc<<": ";
        solve();
    }
}