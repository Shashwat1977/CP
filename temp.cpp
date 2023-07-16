#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
int t;
cin>>t;
while(t--)
{ int n,m,x,y,d;
cin>>n>>m>>x>>y>>d;
if((y-1>d&&n-x>d)||(x-1>d&&m-y>d))
cout<<n+m-2<<endl;
else 
cout<<-1<<endl;
 
}
 
}