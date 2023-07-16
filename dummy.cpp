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

const ll MOD = 1e9 + 7;  // 998244353
int N=1e5+1; 
ll power(ll x, ll y, ll p = MOD) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;  //! important
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

struct DSU {
    int N;
    vector<int> par, siz;
    int components;
    DSU(int n) : N(n), par(N), siz(N, 1), components(N) {
        for (int i = 0; i < N; i++) par[i] = i;
    }
    int root(int X) {
        if (par[X] != X) par[X] = root(par[X]);
        return par[X];
    }
    bool same(int X, int Y) { return root(X) == root(Y); }
    void unite(int X, int Y) {
        X = root(X), Y = root(Y);
        if (X == Y) return;
        if (siz[Y] < siz[X]) swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
        --components;
    }
    int get_size(int X) { return siz[root(X)]; }
};

vector<int> adj[N];

vector<int> depth(N);
vector<int> height(N);

void dfs(int node,vector<int>& visited){
    visited[node] = 1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,visited);
        }
    }
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
        int n,m;
        cin>>n>>m;
        int a;
        vector<pair<int,int>> vec(n+1);
        for(int i = 1;i<=n;i++){
            cin>>a;
            vec[i] = make_pair({a,i});
        }
        sort(vec.begin(),vec.end());
        vector<int> visited(n+1,0);
        int x,y;
        while(m--){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int sum = 0;
        for(int i=1;i<=n;i++){
            if(!visited[vec[i].second]){
                sum+=vec[i].first;
                dfs(vec[i].second,visited);
            }
        }
        cout<<sum<<endl;
}