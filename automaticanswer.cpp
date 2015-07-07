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
  //clock_t tStart = clock();
  ll test ;
  cin >> test ;
  while(test--)
  {
  	ll n ;
  	cin >> n ;
  	n = n*567 ;
  	n= n/9 ;
  	n+=7492 ;
  	n=n*235 ;
  	n=n/47 ;
  	n =n-498 ;
  	n = n/10 ;
  	cout << abs(n%10) << "\n";
  }
  //exectime();
  return 0 ;
}