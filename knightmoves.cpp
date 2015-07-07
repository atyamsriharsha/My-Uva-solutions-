/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;
#define ll long long

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
#define all(v) v.begin(),v.end()
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
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)
#define vi vector<int> v
#define vc vector<char> v
#define pii pair<int,int>  

bool visited[10][10] ;
int a[10][10] ;
int dx[8] = {-2,-1, 1, 2, 2,1,-1,-2} ;
int dy[8] = {-1,-2,-2,-1, 1,2, 2, 1} ;

int bfs(int x1,int y1,int x2,int y2)
{
	visited[x1][y1] = 1 ;
    queue<pii > q ;
    pii p ;
    p.first = x1 ;
    p.second = y1 ;
    q.push(p) ;
    a[x1][y1] = 0 ;
    init(visited,0) ;
    while(!q.empty())
    {
    	p = q.front() ;
    	q.pop() ;
    	if(p.first==x2 && p.second==y2)
    	{
            return a[x2][y2] ;
    	}
    	for(int i=0;i<8;i++)
    	{
    		int newpos_x = p.first + dx[i] ;
    		int newpos_y = p.second + dy[i] ;
    		if(newpos_x>=1 && newpos_x<=8 && newpos_y>=1 && newpos_y<=8 && !visited[newpos_x][newpos_y])
    		{
    			visited[newpos_x][newpos_y] = 1 ;
    			a[newpos_x][newpos_y] = a[p.first][p.second]+1 ;
    			q.push(MP(newpos_x,newpos_y)) ;
    		}
    	}
    }
}

int main()
{
	string s1,s2 ;
	int pos_x1,pos_y1,pos_x2,pos_y2,ans ;
	while(cin>>s1>>s2)
	{
		pos_x1 = s1[0] - 96 ;
		pos_y1 = s1[1] - '0';
		pos_x2 = s2[0] - 96 ;
		pos_y2 = s2[1] - '0';
		ans = bfs(pos_x1,pos_y1,pos_x2,pos_y2);
		cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<ans<<" knight moves.\n";
	}


  return 0 ;
}