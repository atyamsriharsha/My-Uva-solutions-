#include<bits/stdc++.h>

using namespace std;

/*typedef's for frequently used*/

typedef long long int ll;
typedef vector<int>VI;
typedef vector<ll>VLI;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
typedef unsigned long long int ull;

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

/*For variables*/	

#define LET(a) __typeof(a) x(a) 
#define ALL(a) a.begin(),a.end()

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
#define swap(VAR1,VAR2) VAR1=VAR1^VAR2;VAR2=VAR1^VAR2;VAR1=VAR1^VAR2
#define UB(x,a) (upper_bound(ALL(a),x)-a.begin())
#define LB(a,x) (lower_bound(ALL(a),x)-a.begin())
#define NP(a) next_permutation(ALL(a))

/*exponentiation*/


ll inline ipow(ll a,ll b,ll m){ll val=1;a%=m;while(b){if(b&01)val=(val*a)%m;b>>=1;a=(a*a)%m;};return val%m;}
ll inline ipow(ll a,ll b){ll val=1;while(b){if(b&01)val=(val*a);b>>=1;a=(a*a);};return val;}

/* Seive */


/*
#define LIM1 1000001
bitset<LIM1> isp;
vi primes;
inline void seive(){isp.set();isp.reset(0);isp.reset(1);for(int i=2;i*i<LIM1;i++)if(isp[i]){for(int j=i<<1;j<LIM1;j+=i)isp.reset(j);}repl(i,2,LIM1)if(isp[i]){primes.pb(i);}}
*/

/* Totient */

/*
#define LIM4 1000001
int phi[LIM4];
void totient(){repl(i,1,LIM4)phi[i]=i;tr(primes,it)for(int i=*it;i<LIM4;i+=*it)phi[i]-=phi[i]/(*it);}
*/

/* Inverse Modulo */

/*inline ll invmod(ll a, ll b){return (isp[b])?ipow(a,b-2,b):ipow(a,phi[b]-1,b);}*/

/* Combinatorics */

/*
#define LIM2 1000001
ll fact[LIM2];
inline void Fact(){fact[0]=1;repl(i,1,LIM)fact[i]=(i*fact[i-1])%MOD;}
inline ll inv(ll x,ll mod){return ipow(x,mod-2,mod);}
inline ll comb(ll a, ll b){return ((fact[a]*inv(fact[b],MOD)%MOD)*inv(fact[a-b],MOD))%MOD;}
*/

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repi(i,a,b) for(ll i=a;i>=b;i--)
#define repdf(i,a,b,d) for(ll i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(ll i=a;i>=b;i-=d)
#define repl(i,a,b) for (ll i=a;i<b;i++)
#define repil(i,a,b) for (ll i=a;i>b;i--)
#define tr(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define rtr(v,it) for( LET(it,v.rbegin()) ; it != v.rend() ; it++)
#define TC() int t;cin>>t;while(t--)

/*space for global variables*/

set<ipair> s;
set<int> xc;
set<int> yc;
int dx[4] ={-1,1,0,0} ;
int dy[4] ={0,0,1,-1} ;

/**************************************************************  	
  	          Main Code
**************************************************************/
/*ll maxdivide(ll a,ll b)
{
	while(a%b==0)
	{
		a = a/b ;
	}
	return a ;
}

 
 ll uglynumber(ll a)
 {
 	ll count1 = 0 ;
 	repl(i,0,INT_MAX)
 	{
        
 	  ll s = i+1 ;
 	  ll div1 = maxdivide(s,2) ;
 	  ll div2 = maxdivide(div1,3) ;
 	  ll div3 = maxdivide(div2,5) ;
 	  if(div3==1)
 	  {
 	  	if(count1==a)
 	  		return i ;
 	  	count1++ ;
 	  }
 	}
}*/

ll uglynumber(ll n)
{
	ll v[1500] ;
	//v.resize(1500) ;
	v[0] = 1;
	ll index1,index2,index3,ans1 ;
	index1 = 0 ;
	index2 = 0 ;
	index3 = 0 ;
	//cout << v[0] << "\n" ;
	ll value1 = v[index1]*2 ;
	ll value2 = v[index2]*3 ;
	ll value3 = v[index3]*5 ; 
	repl(i,1,n)
	{
		ans1 = min(value1,min(value2,value3)) ;
		//cout << ans1 << " " ;
		v[i] = ans1 ;
        if(ans1 == value1)
        {
        	index1++ ;
        	value1 = v[index1]*2 ;
        }
        if(ans1 == value2)
        {
        	index2++ ;
        	value2 = v[index2]*3 ;
        }
        if(ans1 == value3)
        {
        	index3++ ;
        	value3 = v[index3]*5 ;
        }
	}
	return v[1499] ;
}


int main()
{
    //FastIn;
    clock_t tStart = clock();/* for execution time caluclation*/
    cout << "The 1500'th ugly number is " <<uglynumber(1500) << ".\n" ;
 return 0 ;
}
