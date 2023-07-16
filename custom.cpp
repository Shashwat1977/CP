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

const int M = 1e9+7;


ll mod(ll x){
  return (x%M + M)%M;
}
ll add(ll a , ll b){
  return mod(mod(a)+mod(b));
}

class SegmentTree {
    vector<int> seg; // Segment Tree to be stored in a vector.
public:
    SegmentTree() {}
    SegmentTree(vector<int>& nums) {
        int n = nums.size();
        seg.resize(4 * n, 0);  // Maximum size of a segment tree for an array of size n is 4n
        buildTree(nums, 0, 0, n - 1); // Build the segment tree
    }
    void buildTree(vector<int>& nums, int pos, int left, int right) {
        if (left == right) {
            seg[pos] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(nums, 2 * pos + 1, left, mid);
        buildTree(nums, 2 * pos + 2, mid + 1, right);
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }
    void updateTree(int pos, int left, int right, int idx, int val) {
        // no overlap
        if (idx < left || idx > right) return;
        
        // total overlap
        if (left == right) {
            if (left == idx) seg[pos] = val;
            return;
        }
        // partial overlap
        int mid = left + (right - left) / 2;
        updateTree(2 * pos + 1, left, mid, idx, val);
        updateTree(2 * pos + 2, mid + 1, right, idx, val);
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }
    
    int queryTree(int qleft, int qright, int left, int right, int pos) {
        if (qleft <= left && qright >= right) { // total overlap
            return seg[pos];
        }
        if (qleft > right || qright < left)  {  // no overlap
            return 0;
        }
        // partial overlap
        int mid = left + (right - left) / 2;
        return queryTree(qleft, qright, left, mid, 2 * pos + 1) + queryTree(qleft, qright, mid + 1, right, 2 * pos + 2);
    }
};


class unionFind {
      public:

        // Height of the root is stored as: negative height - 1.
        // Initially all nodes are initialized with height = -1.

        unionFind(int size): root(size), components(size) {
          for (int & i: root) {
            i = -1;
          }
        }

      int find(int x) {
        if (root[x] < 0) {
          return x;
        }
        return root[x] = find(root[x]);
      }

      void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
          if (root[rootX] < root[rootY]) {
            root[rootY] = rootX;
          } else if (root[rootX] > root[rootY]) {
            root[rootX] = rootY;
          } else {
            root[rootX] = rootY;
            --root[rootY];
          }
          --components;
        }
      }

      bool isConnected(int x, int y) {
        return find(x) == find(y);
      }

      int noOfComponents() {
        return components;
      }
      private:
        vector < int > root;
      int components;
    };

long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a)%M;}
                a=(a*a)%M;
                b>>=1;
        }
    return ans; 
}


int fact[1000005],fact_inv[1000005];
void pre(){
    fact[0]=1;
    fact_inv[0]=1;
    for(int i=1;i<1000005;i++){
        fact[i]=(fact[i-1]*i)%mod;
        fact_inv[i]=power(fact[i],mod-2);
    }
}
int ncr(int n,int r){
    return (((fact[n]*fact_inv[n-r])%mod)*fact_inv[r])%mod;
}


int helper(int i,int target,vector<int>& arr,vector<vector<int>>& dp){
	if(i == 0){
		if(target%arr[0] == 0) return target/arr[0];
		else return 1e9;
	}
	if(dp[i][target] != -1) return dp[i][target];
	int notpick = helper(i-1,target,arr,dp);
	int pick = INT_MAX;
	if(arr[i] <= target){
		pick = 1+helper(i,target-arr[i],arr,dp);
	}
	return dp[i][target] = min(notpick,pick);
}

void solve(){
		int n,x;
    cin>>n>>x;
    vi vec(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>vec[i];
    }
    vector<vector<int>> dp(n+1,vector<int> (x+1,0));
    for(int i=1;i<=n;i++){
        for(int j = 0;j<=x;j++){
            if(j == 0){
                dp[i][j] = 1;
            }else{
                int op1 = i>0?dp[i-1][j]:0;
                int op2 = j>=vec[i]?dp[i][j-vec[i]]:0;
                dp[i][j] = add(op1,op2);
            }
        }
    }
    cout<<dp[n][x];
}

class DisjointSet {
    
public: 
    vector<int> parent, size; 
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void Union(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 


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
 