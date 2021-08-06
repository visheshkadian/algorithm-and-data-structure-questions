/*Sample Input 1 
4 5
2 4
1 2
2 3
1 3
3 4
Sample Output 1 
2The shortest time needed to get from City 
1to City 4 is 2
 hours, which is achieved by two paths: 
1→2→4 and 1→3→4
*/

#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
//using namespace atcoder;
 
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
 
using Graph = vector<vector<int>>;
 
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
 
 
ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a/g*b;
}
ll repow(ll n,ll x){
    if(x==0) return 1;
    if(x%2==0){
        ll t=repow(n,x/2)%mod;
        return t*t%mod;
    }
    return n*repow(n,x-1)%mod;
}
 
 
 
int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
 
    queue<ll> q;
    vl dist(n, inf);
    dist[0] = 0;
 
    q.push(0);
    //vector<ll> vs;
    vl ans(n);
    ans[0] = 1;
 
    while(!q.empty()) {
        ll now = q.front(); q.pop();
        //vs.push_back(now);
        for(ll to : G[now]) {
            cout<<to<<"->"<<now<<endl;
            if(dist[to] != inf) {
                if(dist[to] == dist[now] + 1) {
                    ans[to] += ans[now];
                    ans[to] %= mod;
                    
                    //q.push(to);
                }
            } else {
                dist[to] = dist[now] + 1;
                ans[to] = ans[now];
                q.push(to);
            }
 
        }
    }
 
    //for(int i=0;i<n;i++)cout << ans[i] << endl;
    cout<<ans[n-1];
 
 
 
    return 0;
}