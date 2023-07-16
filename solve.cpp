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


ll mod(ll x){
  return (x%M + M)%M;
}
ll add(ll a , ll b){
  return mod(mod(a)+mod(b));
}
ll mul(ll a,ll b){
  return mod(mod(a)*mod(b));
}

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
// long long power(long long a,long long b){
//     long long ans=1;
//     while(b>0){
//         if(b&1){ans=(ans*a)%M;}
//                 a=(a*a)%M;
//                 b>>=1;
//         }
//     return ans; 
// }


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


bool checksub(string temp,string t){
    int i = 0;int j = 0;
    while(i<temp.size()&&j<t.size()){
        if(temp[i] == t[j]){
            j++;
        }
        i++;
    }
    if(j == t.size()) return true;
    return false;
}

bool check(vector<int>& temp){
   vector<int> vec = temp;
   sort(vec.begin(),vec.end());
   for(int i = 0;i<vec.size();i++){
       if(vec[i]!= temp[i]) return false;
   }
   return true;
}



int func(vector<vector<int>>& dp,int i,int k,vector<int>& steps,vector<int>& cost){
    if(k<0) return -1e9;
    if(i == 0){
        if(steps[i] <= k){
            return dp[i][k] = cost[i];
        }else return 0;
    }
    int ans = INT_MIN;
    if(steps[i]<=k){
        ans = func(dp,i-1,k-steps[i],steps,cost);
    }
    ans = max(ans,func(dp,i-1,k,steps,cost));
    return dp[i][k] = ans;
}

vector<vector<int>> m(1001);

void solve(){
int n;
cin>>n;
bool flag1 = false;
bool flag2 = false;
ll c0 = 0;
ll c1 = 0;
int d,k;
string s;
while(n--){
    cin>>d>>k;
    string s;
    cin>>s;
    for(int i = 0;i<s.size();i++){
        if(d == 1){
            if(s[i] != 'a') flag1 = true;
            else c0+= k;
        }else{
            if(s[i] != 'a') flag2 = true;
            else c1+= k;
        }
    }
    if(flag2){
        cout<<"YES"<<endl;
    }else if(!flag1 && c0<c1){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
}
}


  



	



int main()
{ 
  int t;
  cin>>t;
  for(int i = 1;i<=1000;i++){
      for(int j = 1;j<=1000;j++){
          if(__gcd(i,j) == 1){
              m[i].push_back(j);
          }
      }
  }
  while(t--){
     solve();
  }
  // solve();
  }