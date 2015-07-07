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
#define dfs_white 0
#define dfs_black 1
#define dfs_grey 2
/* global variables*/
int n,m,src,dst ;
std::vector<vector<int> > adjacencylists;
std::vector<int> colors;
std::vector<int> dfs_num;
std::vector<int> dfs_low;
int dfs_current_num ;

/*functions*/
void dfs(int parent,int current)
{
	colors[current] = 1; // gray
    dfs_num[current] = dfs_current_num;
    dfs_low[current] = dfs_current_num;
    dfs_current_num++;
    int num_children = 0;
    for(vector<int>::iterator ni = adjacencylists[current].begin(); ni != adjacencylists[current].end(); ni++)
    {
        int neighbor = *ni;
        if(colors[neighbor] == 0)
        {
            cout << (current + 1) << " " << (neighbor + 1) << endl;
            num_children++;
            dfs(current,neighbor);
            if (dfs_low[neighbor] > dfs_num[current])
            {
                cout << (neighbor + 1) << " " << (current + 1) << endl;
            }
            dfs_low[current] = min(dfs_low[current], dfs_low[neighbor]);
        }
        else
        {
            if (neighbor != parent)
            {
                if (colors[neighbor] == 1)
                {
                    dfs_low[current] = min(dfs_low[current], dfs_num[neighbor]);
                    cout << (current + 1) << " " << (neighbor + 1) << endl;
                }
            }
        }
    }
    colors[current] = 2; 
}


int main()
{
	int test = 0 ;
	while(1)
	{
		adjacencylists.clear() ;
		colors.clear();
		dfs_low.clear() ;
		dfs_num.clear() ;
		test++ ;
        cin >> n >> m ;
        if(n==0 && m==0)
        	break ;
        cout << test << endl << endl ;
        adjacencylists.resize(n) ;
        colors.resize(n) ;
        dfs_num.resize(n) ;
        dfs_low.resize(n) ;
        for(int i=0;i<m;i++)
        {
        	cin >> src >> dst ;
        	adjacencylists[src-1].PB(dst-1) ;
        	adjacencylists[dst-1].PB(src-1) ;
        }
        //bridge algorithm
        std::fill(colors.begin(),colors.end(),dfs_white) ;
        std::fill(dfs_low.begin(),dfs_low.end(),-1) ;
        std::fill(dfs_num.begin(),dfs_num.end(),-1) ;
        dfs_current_num = 0;
        dfs(-1,0);
        cout << "#" << endl ;
	}
  return 0 ;
}