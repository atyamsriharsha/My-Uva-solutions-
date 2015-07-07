/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;
#define SpeedUp std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

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

int main()
{
  //SpeedUp ;
 ll tests = 0 ;
  //clock_t tStart = clock();
while(1)
{
  ll r,n ;
  bool flag = 0 ;
  cin >> r >> n ;
  if(r==0 && n==0)
  	break ;
  ll res = r-n ;
  cout << "Case " << ++tests << ": " ;
  if(res<=0)
  {
  	cout << 0 << "\n" ;
  }
  else
  {
  	for(int i=1;i<=26;i++)
  	{
  		if(res<=n*i)
  		{
  			cout << i <<"\n" ;
  			flag = 1 ;
  			break ;
  		}
  	}
  	if(flag==0)
  	{
  		cout << "impossible\n" ;

  	}
  }
  //exectime();
}
  return 0 ;
}