
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


// ll fact[2000005],fact_inv[2000005];
// void pre(){
//     fact[0]=1;
//     fact_inv[0]=1;
//     for(int i=1;i<2000005;i++){
//         fact[i]=(fact[i-1]*i)%M;
//         fact_inv[i]=power(fact[i],M-2);
//     }
// }
// int ncr(int n,int r){
//     return (((fact[n]*fact_inv[n-r])%M)*fact_inv[r])%M;
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



int query(int l, int r)
{
	cout << "? " << l << " " << r << endl;
	int x; cin >> x;
	return x;
}
void output(int x)
{
	cout << "! " << x << endl;
	return;
}

vector<int> adj[200001];
int up[200001][20];
int lvl[200001];

void dfs(int node,int par,int level){
	lvl[node] = level;
	for(auto it:adj[node]){
		if(it!=par){
			dfs(it,node,level+1);
		}
	}
}

void binary_lifting(int src, int par)
{
    up[src][0] = par;
    for(int i = 1; i < 20; i++)
    {
        if(up[src][i-1] != -1)
            up[src][i] = up[up[src][i-1]][i-1];
        else up[src][i] = -1;
    }
 
    for(int child : adj[src])
    {
        if(child != par)
            binary_lifting(child, src);
    }
}
 
int ans_query(int node, int jump_required)
{
    for(int i = 19; i >= 0; i--){
    	if(node == -1 || jump_required == 0)
	        break;
        if(jump_required >= (1<<i)){
        	jump_required -= (1<<i);
            node = up[node][i];
        }
    }
    return node;
}

int lca(int u,int v){
	if(lvl[u]<lvl[v]) swap(u,v);
	u = ans_query(u,lvl[u]-lvl[v]);
	if(u == v){
		return u;
	}
	for(int i = 19;i>=0;i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}

vector<vector<int>> m(1001);

void solve(){
	int n,q;
	cin>>n>>q;
	int x,y;
	n--;
	while(n--){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,-1,0);
	// for(auto it:lvl) cout<<it<<" ";
	binary_lifting(1,-1);
	int n1,n2;
	while(q--){
		cin>>n1>>n2;
		int l = lca(n1,n2);
		cout<<lvl[n1]-lvl[l] + lvl[n2]-lvl[l]<<endl;
	}
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