/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;


/*debugging*/

#define out1(x)cout<<#x<<" is "<<x<<endl
#define out2(x,y)cout<<#x<<" is "<<x<<" "<<#y <<" is "<<y<<endl
#define out3(x,y,z)cout<<#x<<" is "<<x<<" "<<#y<<" is "<<y<<" "<<#z<<" is "<<z<<endl;
#define out4(a,b,c,d)cout<<#a<<" is "<<a<<" "<<#b<<"  is "<<b<<" "<<#c<<" is "<<c<<" "<<#d<<" is "<<d<<endl;
#define show(i,a,n) for(i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define sz(a) cout<<"size of "<<#a<<" is "<<a.size()
#define exectime() cout<<"execution time "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;

/*standard values*/

#define INF 1e18
#define PI 3.14159265359
#define MAX 1000006

#define dfs_white 0 
#define dfs_black 1
#define dfs_grey 2
/*Frequent functions*/

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pu putchar
#define gu getchar
#define FastIn std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)

int n;
char a [200 + 5] [200 + 5];
bool vis [200 + 5] [200 + 5];
char output;

void dfs (int x, int y, char curr)
{
	if ( x < 0 || y < 0 || x == n || y == n || a [x] [y] != curr || vis [x] [y] ) return;
	if( y == n - 1 && a [x] [y] == 'w') 
	{ 
		output = 'W'; 
		return; 
	}
	if( x == n - 1 && a [x] [y] == 'b' ) 
	{
	 output = 'B';
	  return;
	 }

	vis [x] [y] = true;

	int dr [] = {-1, -1, 0, 0, 1, 1};
	int dc [] = {-1, 0, -1, 1, 0, 1};

	for( int i = 0; i < 6; i++ )
		dfs (x + dr [i], y + dc [i], curr);
}

int main()
{
	int cases = 0;
	while(scanf("%d", &n) && n)
	{
		for(int i = 0; i < n; i++)
		 scanf ("%s", a [i]);
		cout << cases << " " ;
		memset(vis, false, sizeof (vis));
		for(int i = 0; i < n; i++)
			if(!vis[0][i] && a[0][i] == 'b')
			 dfs(0, i, 'b');
		for(int i = 0; i < n; i++)
			if(!vis [i] [0] && a [i] [0] == 'w') 
				dfs (i, 0, 'w');

		printf ("%d %c\n", ++cases, output);
	}

	return 0;
}
