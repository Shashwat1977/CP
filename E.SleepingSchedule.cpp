// Problem: E. Sleeping Schedule
// Contest: Codeforces - Codeforces Round #627 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1324/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ld = long double;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define endl '\n'
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fora(i, a, n) for(ll i = a; i < n; i++)
#define readi(e) int e; cin >> e
#define readl(e) ll e; cin >> e
#define reads(e) string e; cin >> e
#define T int tt; cin >> tt; while(tt--)
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;

template<typename U>
void print(U arr) {
	for(auto element: arr) {
		cout << element << " ";
	}
	cout << endl;
}

// read and write into files, rather than standard i/o
void setup(string str) {
	freopen((str+".in").c_str(), "r", stdin);
	freopen((str+".out").c_str(), "w", stdout);
}

const int M = 1e9+7;
const int N = 1000000;
// const int mod = 1e9+7;

// ll mod(ll x){
//   return (x%M + M)%M;
// }
// ll add(ll a , ll b){
//   return mod(mod(a)+mod(b));
// }
// ll mul(ll a,ll b){
//   return mod(mod(a)*mod(b));
// }

ll powe(int a,int b){
  int ans = 1;
  while(b){
    if(b&1){
      ans = (ans*a)%M;
    }
    a = (a*a)%M;
  }
  return ans;
}

bool arr[9000001];



int setBitNumber(int n)
{
    if (n == 0)
        return 0;
 
    int msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
 
    return (1 << msb);
}
long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a)%M;}
                a=(a*a)%M;
                b>>=1;
        }
    return ans; 
}


// int fact[2000005],fact_inv[2000005];
// void pre(){
//     fact[0]=1;
//     fact_inv[0]=1;
//     for(int i=1;i<2000005;i++){
//         fact[i]=(fact[i-1]*i)%mod;
//         fact_inv[i]=power(fact[i],mod-2);
//     }
// }
// int ncr(int n,int r){
//     return (((fact[n]*fact_inv[n-r])%mod)*fact_inv[r])%mod;
// }


// void dfs(int v,vector<int>& visited,vector<int> adj[],vector<int>& color){
//     visited[v] = 1;
//     for(auto it:adj[v]){
//         if(!visited[it]){
//           color[it] = 1-color[v];
//           dfs(it,visited,adj,color);
//         }
//     }
// }





long long  gcd(ll a,ll b)
	{
	    if (b==0) return a;
	    return gcd(b,a%b);
	}


bool compare(pair<int,int> &p,pair<int,int> &q){
	if(p.first != q.first){
    return p.first<q.first;
  } return p.second>q.second;
}


bool sign(int x){
  return x>0;
}

ll pairs(ll n){
  return n*(n-1)/2;
}
int pre(int x){
  return (x+M)%M;
}









vector<vector<int>> m(1001);
int n,h,l,r;
int func(int i,int t,vector<vector<int>>& dp,vector<int>& vec){
	if(i >=n) return 0;
	if(dp[i][t] != -1) return dp[i][t];
	
	// Option 1
	int ans = 0;
	int time1 = (t+vec[i])%h;
	int cnt1 = 0;
	if(time1>=l && time1<=r) cnt1++;
	ans = max(ans,func(i+1,time1,dp,vec)+cnt1);
	
	// Option 2
	
	int time2 = (t+vec[i]-1)%h;
	int cnt2 = 0;
	if(time2>=l && time2<=r) cnt2++;
	ans = max(ans,func(i+1,time2,dp,vec)+cnt2);
	return dp[i][t] = ans;
	
	
	// if (ind >= n)
        // return 0;
    // if (dp[ind][t] != -1)
        // return dp[ind][t];
    // int ans = 0;
    // int c1 = (t + vec[ind]) % h;
    // int c2 = (t + vec[ind] - 1) % h;
    // ans = max(ans, (c1 >= l && c1 <= r) + func(ind + 1, c1,dp,vec));
    // ans = max(ans, (c2 >= l && c2 <= r) + func(ind + 1, c2,dp,vec));
    // return dp[ind][t] = ans;
}

void solve(){
	
	cin>>n>>h>>l>>r;
	vi vec(n);
	for(int i = 0;i<n;i++){
		cin>>vec[i];
	}
	vector<vector<int>> dp(n+1,vector<int> (h+2,-1));
	int ans = func(0,0,dp,vec);
	cout<<ans<<endl;
}



  



	



int main()
{ 
  int t=1;
  // cin>>t;
  
  while(t--){
     solve();
  }
  // solve();
  }