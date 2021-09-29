/*
input:
3
5
3 5 2 1 4
1
1
4
4 3 1 2

output:
1 0 2 3 1 
0 
0 1 3 2 

link: https://codeforces.com/problemset/problem/1490/D

*/


#include <bits/stdc++.h>

using namespace std;

void build(int l, int r, vector<int> const &a, vector<int> &d, int curD = 0) {
  if (r < l) {
    return;
  }
  if (l == r) {
    d[l] = curD;
    return;
  }
  int m = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[m] < a[i]) {
      m = i;
    }
  }
  d[m] = curD;
  build(l, m - 1, a, d, curD + 1);
  build(m + 1, r, a, d, curD + 1);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  vector<int> d(n);
  build(0, n - 1, a, d);
  for (int x :d) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}