
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
void setup(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

const int M = 1e9+7;
const int N = 1000000;


ll mod(ll x){
  return (x%M + M)%M;
}
ll add(ll a , ll b){
  return mod(mod(a)+mod(b));
}
ll mul(ll a,ll b){
  return mod(mod(a)*mod(b));
}

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

long long nCr(int n,int r)
	{
		if(n==r)	return 1;
		else if (r==0)	return 1;
		else return ((nCr(n-1,r-1)+nCr(n-1,r))%M);
	}



// void dfs(int v,vector<int>& visited,vector<int> adj[],vector<int>& color){
//     visited[v] = 1;
//     for(auto it:adj[v]){
//         if(!visited[it]){
//           color[it] = 1-color[v];
//           dfs(it,visited,adj,color);
//         }
//     }
// }

void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& visited){
  if(r<1 || r>=grid.size() || c<1 || c>=grid[1].size()){
    return;
  }
  if(visited[r][c]) return;
  if(grid[r][c] == '#') return;
  visited[r][c] = 1;
  dfs(r,c+1,grid,visited);
  dfs(r,c-1,grid,visited);
  dfs(r-1,c,grid,visited);
  dfs(r+1,c,grid,visited);
}

int getSum(long long n) {
  int sum = 0;
  int m = n;
  while(n > 0) {    
    m = n % 10;    
    sum = sum + m;    
    n = n / 10;    
  } 
  return sum;
}

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



bool possible(int k,int n,int a,int b,int m){
  if(m>n) return false;
  int cnt = m*a ;
  int rem = max(0,n-m);
  if(cnt+rem*b > k) return false;
  return true;
}


    ll func(int i,int j,vector<ll>& vec,vector<vector<ll>>& dp){
      if(i > j) return 0;
      if(dp[i][j] != -1) return dp[i][j];
      return dp[i][j] = max(vec[i]-func(i+1,j,vec,dp),vec[j]-func(i,j-1,vec,dp));
    }


void solve(){
  int n,m;
	cin>>n>>m;
	char grid[n][m];
	vector<vector<int>> dp(n,vector<int>(m,0));
	for(int i = 0;i<n;i++){
		for(int j  = 0;j<m;j++){
			cin>>grid[i][j];
		}
	}
	dp[0][0] = grid[0][0] == '.'?1:0;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      if(grid[i][j] == '*'){
        dp[i][j] = 0;
      }else{
        dp[i][j] = add(dp[i][j],i-1>=0?dp[i-1][j]:0);
        dp[i][j] = add(dp[i][j],j-1>=0?dp[i][j-1]:0);
      }
    }
  }
   cout<<dp[n-1][n-1]<<endl;
  }
  



	



int main()
{ 
  int t = 1;
  while(t--){
     solve();
  }
  // solve();
  }
