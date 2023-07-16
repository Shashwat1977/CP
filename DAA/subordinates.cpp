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
 
 
template<typename U>
void print(U arr) {
	for(auto element: arr) {
		cout << element << " ";
	}
	cout << endl;
}
 
// read and write into files, rather than standard i/o
void setup(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}
 
const int M = 1e9+7;
const int N = 1000000;
 
ll pow(int a,int b){
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
 
 
 
 
 
 
 
 
 
vector<int> adj[N+1];
vector<int> vec(N+1);
vector<int> cnt(N+1);
int res = 0;
int k;
int dfs(int node,int parent){
	cnt[node] = 0;
	for(auto it:adj[node]){
		if(it != parent){
			cnt[node] += dfs(it,node);
		}
	}
	return 1+cnt[node];
}
void solve(){
    int n;
	cin>>n;
	int x;
	for(int i=1;i<n;i++){
		cin>>x;
		adj[x].push_back(i+1);
		adj[i+1].push_back(x);
	}
	int ans = dfs(1,-1);
	for(int i =1;i<=n;i++){
		cout<<cnt[i]<<" ";
	}cout<<endl;
    }
 
int main()
{ 
    // int t;
    // cin>>t;
    // while(t--){
    //  solve();
    // }
 		solve();
  }