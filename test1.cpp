#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b ;
}

int main()
{
	ll cnt1,cnt2,x,y ;
	cin >> cnt1 >> cnt2 >> x >> y ;
	ll d=lcm(x,y);
	ll v1=x*(cnt1/(x-1))+cnt1%(x-1);
	if(cnt1%(x-1)==0)
		v1--;
	ll v2=y*(cnt2/(y-1))+cnt2%(y-1);
	if(cnt2%(y-1)==0)
		v2--;
	ll v3=d*((cnt1+cnt2)/(d-1))+(cnt1+cnt2)%(d-1);
	if((cnt1+cnt2)%(d-1)==0)
		v3--;
	ll m=max(max(v1,v2),v3);
	cout << m ;
	return 0 ;
}