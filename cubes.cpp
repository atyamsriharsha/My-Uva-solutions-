/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;
#define SpeedUp std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MI INT_MAX
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
#define exectime() cout<<"execution time "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
#define LB(a,x) (lower_bound(all(a),x)-a.begin())
#define UB(a,x) (upper_bound(all(a),x)-a.begin())

/*loops and initialisation*/
#define ll long long int
#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repi(i,a,b) for(ll i=a;i<=b;i--)
#define vi vector<ll> 
#define vc vector<char>
#define pii pair<ll,ll> 


int dx[4] ={-1,1,0,0} ;
int dy[4] ={0,0,1,-1} ;
/**************************************************************  	
  	          Main Code
**************************************************************/

int cube[100000];

int main()
{
    int i, j, lim;
    int found;
    ll miny, minx, x, y, n;
    for(ll x=0, i=0 ; x*x*x<=MI ; x++, i++)
    {
        cube[i]=x*x*x;
        lim = i;
    }
    while(cin >> n && n!=0)
    {
        miny = minx = MI + 1;
        for(i=1,found=false ; i<lim && !found ; i++)
        {
            for(j=lim-1 ; j>=1 && !found ; j--)
            {
                if((cube[j]-cube[i])==n && i!=j)
                {
                    found++;
                    x = j;
                    y = i;
                }
                if(found>1)
                {
                    if(miny>y)
                    {
                        miny=y;
                        minx=x;
                    }
                } 
                else
                {
                    miny = y;
                    minx = x;
                }
            }
        }
        if(found)
        {
            cout << minx << " " << miny << endl;
        } 
        else 
        {
            printf("No solution\n");
        }
    }
    return 0;
}