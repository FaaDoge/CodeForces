
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,x[40010];
		cin>>n>>m;
		for(int i=0;i<n*m;i++) cin>>x[i];
		sort(x,x+n*m);
		cout<<(x[n*m-1]-x[0])*(n*m-min(n,m))+(min(n,m)-1)*max(x[n*m-1]-x[1],x[n*m-2]-x[0])<<endl;
	}
	return 0;
}