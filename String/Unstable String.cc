/*
input:
3
0?10
???
?10??1100

output:
8
6
25

Link:https://codeforces.com/contest/1535/problem/C


*/
#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = 1000000007;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        string s;
        cin >> s;
        int n = s.size();

        long long ans = 0, max0 = 0, max1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                max0++;
                max1 = 0;
                ans += max0;
            }
            else if (s[i] == '1')
            {
                max1++;
                max0 = 0;
                ans += max1;
            }
            else
            {
                max0++;
                max1++;
                ans += max(max0, max1);
            }
            swap(max0, max1);
        }

        cout << ans << "\n";
    }
#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
    return 0;
}
//orrr
//
//
//

//Check out my youtube channel: https://www.youtube.com/c/QuarantineEngineers
//Join me on discord to discuss: https://discord.com/invite/6kcmVQx8Fx
#include<bits/stdc++.h>
using namespace std;

//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp>
//namespace
using namespace __gnu_pbds;
#define int long long

//macro definition
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ld long double
#define endl "\n"
const int mod=998244353;
const int MAX=100005;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int bit=31;
//1.DP se soch
//2.DP se soch
//3.DP se soch
//graph, gcd, BS, seive
//if NOTA,then
//brute force hi optimal h

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int tot=(n*(n+1))/2;
    int st=0;
    // vector<pair<int,int>>v;
    // for(int i=0;i<n-1;i++){
    //   char ch1=s[i];
    //   char ch2=s[i+1];
    //   if(ch1!='?' and ch2!='?'){
    //     if(ch1!=ch2){

    //     }
    //     else{
    //       v.push_back({i,i+1});
    //       // tot-=(n-i-1)*(i+1-st);
    //       // st=i+1;
    //     }
    //   }
    // }
    // st=0;
    // for(int i=1;i<n-1;i++){
    //   if(s[i]=='?'){
    //     if(s[i-1]!=s[i+1] and s[i-1]!='?' and s[i+1]!='?'){
    //       v.push_back({i-1,i+1});
    //       // tot-=(i-st)*(n-(i+1));
    //       // st=i;
    //     }
    //   }
    // }
    // sort(v.begin(),v.end());
    // // int st=0;
    // int ans=0;
    // for(auto x:v){
    //   // cout<<x.first<<" "<<x.second<<endl;
    //   // cout<<((x.second-1-st+1)*(x.second-1-st+1+1))/2<<endl;
    //   if(x.first+2==x.second)
    //   ans-=1;
    //   ans+=((x.second-1-st+1)*(x.second-1-st+1+1))/2;
    //   st=x.first+1;
    //   // tot-=(x.first+1-st)*(n-x.second);
    //   // st=x.first+1;
    // }
    // ans+=((n-1-st+1)*(n-1-st+1+1))/2;
    // cout<<ans;
    vector<pair<int,int>>v;
    for(int i=0;i<n;){
      int j=i;
      if(i+1<n and s[i]!='?'){
        if(s[i+1]==s[i]){
          v.push_back({i,i+1});
        }
        i++;
        continue;
      }
      else if(i+1==n){
        i++;
        continue;
      }
      while(j<n and s[j]=='?'){
        j++;
      }
      // int save=j;
      if(i-1<0 or j==n){
        i=j;
        continue;
      }
      int st=i-1;
      int en=j;
      int cnt=j-i;
      if(cnt&1){
        if(s[st]!=s[en]){
          v.push_back({st,en});
        }
      }
      else{
        if(s[st]==s[en]){
          v.push_back({st,en});
        }
      }
      i=j;
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(auto x:v){
      // cout<<x.first<<" "<<x.second<<endl;
      // cout<<((x.second-1-st+1)*(x.second-1-st+1+1))/2<<endl;
      ans-=((x.second-x.first-1)*(x.second-x.first))/2;
      ans+=((x.second-1-st+1)*(x.second-1-st+1+1))/2;
      st=x.first+1;
      // tot-=(x.first+1-st)*(n-x.second);
      // st=x.first+1;
    }
    ans+=((n-1-st+1)*(n-1-st+1+1))/2;
    cout<<ans;
    cout<<endl;
}
int32_t main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      // srand(time(0));
      // seive(10000000);
      int t;
      cin>>t;
        // t=1;
      while(t--){
        // cout<<"Case #"<<tt<<": ";
            solve();
            // tt++;
      }
      return 0;
}