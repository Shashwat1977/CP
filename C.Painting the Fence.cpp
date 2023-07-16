// Problem: C. Painting the Fence
// Contest: Codeforces - Educational Codeforces Round 61 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1132/problem/C
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

void solve(){
	int n,q;
	cin>>n>>q;
	vector<pair<int,int>> interval;
	int temp = q;
	int x,y;
	vector<int> cnt(n,0);
	while(temp--){
		cin>>x>>y;
		x--;y--;
		interval.push_back({x,y});
		for(int i = x;i<=y;i++){
			cnt[i]++;
		}
	}
	int ans = 0;
	for(int A = 0; A < q;A++){
		int l = interval[A].first;
		int r = interval[A].second;
		int cntp = 0;
		for(int i = l;i<=r;i++){
			cnt[i]--;
		}
		vector<int> ones(n,0);
		for(int i =  0;i<n;i++){
			if(cnt[i]>0) cntp++;
			if(cnt[i] == 1){
				ones[i] = 1;
			}
		}
		for(int i = 1;i<n;i++){
			ones[i] += ones[i-1];
		}
		for(int B = A+1 ; B< q;B++){
			int left = interval[B].first;
			int right = interval[B].second;
			int cnt = ones[right] - (left>=1?ones[left-1]:0);
			ans = max(ans,cntp-cnt);
		}
		for(int i = l;i<=r;i++){
			cnt[i]++;
		}
	}
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