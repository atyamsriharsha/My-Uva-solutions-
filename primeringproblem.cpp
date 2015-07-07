#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std ;

int n ;
std::vector<int> odd;
std::vector<int> even;
std::vector<int> result;
std::vector<bool> rem;

int check(int prime)
{
	for(int i=3;i*i<=prime;i=i+2)
	{
		if(prime%i==0)
			return 0 ;
	}
	//cout << prime << endl ;
	return 1 ;
}

void solve(int temp)
{
	int flag=0 ;
    if(temp%2==1)
    {
       for(int i=0;i<even.size();i++)
       {
       	  if(check(temp+even[i]) && rem[even[i]])
       	  {
             result.push_back(even[i]) ;
             rem[even[i]] = 1 ;
             flag = 1 ;
             solve(even[i]) ;
             rem[even[i]] = 0 ;
       	  }
       }
       if(flag==0)
       {
       	 result.pop_back() ;
       }
    }
    else
    {
       for(int i=0;i<odd.size();i++)
       {
       	  if(check(temp+odd[i]) && rem[odd[i]]==0)
       	  {
             result.push_back(odd[i]) ;
             rem[odd[i]] = 1 ;
             flag = 1 ;
             solve(odd[i]) ;
       	  }
       }
       if(flag==0)
       {
       	 result.pop_back() ;
       }
    }
     
}

int main()
{
	while((scanf("%d",&n))!=EOF) 
	{
		cout << "atyam" ;
		even.clear() ;
		odd.clear() ;
		result.clear() ;
		cout << "atyam" ;
		for(int i = 0; i < n; ++i)
		{
			rem[i] = 1 ;
		}
	   for(int i=1;i<=n;i++)
	   {
          if(i%2==0)
          {
      	    even.push_back(i) ;
          }
          else
          {
      	    odd.push_back(i)  ;
          }
	   }
	   cout << "atyam" ;
	   result.push_back(1) ;
	   rem.push_back(0) ;
	  // cout << "atyam" ;
	   solve(1) ;
	}
	return 0 ;
}