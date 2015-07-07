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
#define repi(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector<ll> 
#define vc vector<char>
#define pii pair<ll,ll> 
int dx[4] ={-1,1,0,0} ;
int dy[4] ={0,0,1,-1} ;
/*******************************************************************************  	
        	Main Code
*******************************************************************************/

int main()
{
  SpeedUp ;
  //clock_t tStart = clock();
  while(1)
  {
  	ll n,count1[5]={0,0,0,0,0} ;
  	cin >> n ;
  	if(n==0)
  		break ;
  	repi(i,1,n)
  	{
  		int ref = i ;
  		bool flag= 0 ;
  		if(ref==100)
  		{
  			count1[4]+=1 ;
  		}
  		else
  		while(ref!=0)
  		{
  			int num1 = ref%10 ;
  			if(num1==1 && flag==0)
  			{
  				count1[0]++ ;
  				//flag = 1 ;
  			}
  			else if(num1==2 && flag==0)
  			{
  				count1[0] += 2 ;
  			//	flag =1 ; 
  			}
  			else if(num1==3 && flag==0)
  			{
  				count1[0]+=3 ;
  			//	flag = 1 ;
  			}
  			else if(num1==4 && flag==0)
  			{
  				count1[0]+=1 ;
  				count1[1]+=1 ;
  			//	flag = 1 ;
  			}
  			else if(num1==5 && flag==0)
  			{
  				count1[1]+=1 ;
  			//	flag = 1 ;
  			}
  			else if(num1==6 && flag==0)
  			{
  				count1[0]+=1 ;
  				count1[1]+=1 ;
  			//	flag = 1 ;
  			}
  			else if(num1==7 && flag==0)
  			{
  				count1[0]+=2 ;
  				count1[1]+=1 ;
  			//	flag = 1 ;
  			}
  			else if(num1==8 && flag==0)
  			{
  				count1[0]+=3 ;
  				count1[1]+=1 ;
  			//	flag = 1 ;
  			}
  			else if(num1==9 && flag==0)
  			{
  				count1[0]+=1 ;
  				count1[2]+=1 ;
  			//	flag = 1 ;
  			}
  			if(num1==1 && flag==1)
  			{
  				count1[2]++ ;
  			}
  			else if(num1==2 && flag==1)
  			{
  				count1[2] += 2 ;
  			}
  			else if(num1==3 && flag==1)
  			{
  				count1[2]+=3 ;
  			}
  			else if(num1==4 && flag==1)
  			{
  				count1[3]+=1 ;
  				count1[2]+=1 ;
  			}
  			else if(num1==5 && flag==1)
  			{
  				count1[3]+=1 ;
  			}
  			else if(num1==6 && flag==1)
  			{
  				count1[3]+=1 ;
  				count1[2]+=1 ; 
  			}
  			else if(num1==7 && flag==1)
  			{
  				count1[3]+=1 ;
  				count1[2]+=2 ;
  			}
  			else if(num1==8 && flag==1)
  			{
  				count1[3]+=1 ;
  				count1[2]+=3 ;
  			}
  			else if(num1==9 && flag==1)
  			{
  				count1[4]+=1 ;
  				count1[2]+=1 ;
  			}
  			ref = ref/10 ;
  			flag = 1 ;
  		}
  	}
  	cout << n << ": " << count1[0] << " i, " << count1[1] << " v, " << count1[2] << " x, " << count1[3] << " l, " << count1[4] << " c" << endl ;  
  }
  //exectime();
  return 0 ;
}