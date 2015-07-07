/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef pair<int,int> pii ;
typedef vector<pii> vii ;

int main()
{
   double s ;
   long result[30010] = {0} ;
   long change[] = {5,10,20,50,100,200,500,1000,2000,5000,10000} ;
   result[0] = 1 ;
   for (int i = 0; i < 11; ++i)
   {
   	for(int j = change[i];j<=30000;j++)
   	{
       result[j] += result[j-change[i]] ;
   	}
   }
   while(1)
   {
     cin >> s ;
     if(s==0)
     	break ;
     printf("%6.2f%17ld\n", s, result[(int) round(s * 100)]);
    }


  return 0 ;
}

