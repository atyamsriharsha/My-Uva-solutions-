/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef pair<int,int> pii ;
typedef vector<pii> vii ;

int k,n ;
string v[30] ;
bool rea[30] ;
int count1=0,max1=-1 ;
void solve(string s,int index)
{
	int j ;
	   do
	    {
	    	for(j = 0; j < k ; ++j)
	    	{
	    		if(s>v[j] && rea[j]!=1)
	    		{
	    			count1++ ;
	    			rea[j] = 1 ;
	    			solve(v[j],index) ;
	    		}
	    		if(max1<count1)
	            {
                   max1 = count1 ;
	            }
	    	}
	    	if(j==k-1)
	    		solve(v[index+1],index+1);
	    }while(next_permutation(s.begin(),s.end())); 
	cout << max1 << endl ;
}
int main()
{
	while(cin >> k >> n)
	{
		memset(rea,0,sizeof(k)) ;
	   for (int i = 0; i < k; ++i)
	   {
		   cin >> v[i] ;
		  // cout << v[i] ;
	   }
	   solve(v[0],0) ;
	}
  return 0 ;
}

