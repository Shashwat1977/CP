#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;


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

const int N = 100000;

vector<pair<int,int>> adj[N];



void djikstra(int source,int n){
	vector<int> d(N,INT_MAX);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,source});
	d[source] = 0; 
	while(!pq.empty()){
		auto it = pq.top();
		pq.pop();
		int curr = it.second;
		for(auto it:adj[curr]){
			int child = it.first;
			int w = it.second;
			if(d[curr]+w < d[child]){
				d[child] = d[curr]+w;
				pq.push({d[child],child});
			}
		}
	}
	for(int i = 1;i<=n;i++){
		cout<<i<<' '<<d[i]<<endl;
	}
}

int parent[N];
int rak[N];

void make(int v){
	parent[v] = v;
	rak[v] = 0;
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}
void Union(int a,int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		if(rak[a]<rak[b]){
			parent[a] = b;
		}else if(rak[b]<rak[a]){
			parent[b] = a;
		}else{
			parent[b] = a;
			rak[a]++;
		}
	}
}

void dfs(int node,vector<int> adj[],vector<int>& dp){
	dp[node] = 1;
	int ans = 0;
	for(auto it:adj){
		ans += dp[it];
	}
	dp[node] += ans;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;cin>>n;
	vi vec(n-1);
	forn(i,n-1) cin>>vec[i];
	vector<int> adj[n];
	for(int i = 0;i<n-1;i++){
		adj[vec[i]].push_back(i+1);
	}
	vector<int> dp(n);
	dfs(0,adj,dp);
	print(dp);
}