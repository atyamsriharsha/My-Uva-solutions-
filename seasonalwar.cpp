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

//this is nothing but the finding number of connected components in the image having 1s adjacently or atleast a single binary one

int n;
char a[26][26] ;
bool visited[26][26] ;

void dfs(int x,int y)
{
	//if(x<1 || y<1 || x>n || y>n || a[x][y]!=1 || visited[x][y]!=0)
	//	return ;
	visited[x][y] =  1 ;
	int dr[] = {-1,-1,-1,0,0,1,1,1};
	int dc[] = {-1,0,1,-1,1,-1,0,1};
	for(int i=0;i<8;i++)
	{
		if(a[x+dr[i]][y+dc[i]]=='1' && visited[x+dr[i]][y+dc[i]]==0 && x+dr[i]>0 && y+dc[i]>0 && x+dr[i]<=n && y+dc[i]<=n)
		 dfs(x+dr[i],y+dc[i]) ;
	}
}
int main()
{
	int cases = 1,count1=0 ;
	while(cin >>n)
	{
		count1 = 0;
		memset(visited,0,sizeof(visited)) ;
        for(int i=1;i<=n;i++)
        {
           for(int j=1;j<=n;j++)
           {
          		cin >> a[i][j] ;
           }
        }
        for(int i=1;i<=n;i++)
        {
        	for(int j=1;j<=n;j++)
        	{
        		//cout << a[i][j] << " " ;
        		//cout << visited[i][j] << " " ;
        		if(a[i][j]=='1' && visited[i][j]==0)
        		{
        		//	cout << "atyam" << endl ;
        			count1++ ;
        			dfs(i,j) ;
        		}
        	}
        	//cout << endl ;
        }
         cout << "Image number " << cases << " contains " << count1 << " war eagles." << endl ;
        cases++ ;
	}
  return 0 ;
}