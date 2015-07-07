/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef pair<int,int> pii ;
typedef vector<pii> vii ;

#define inf 100000
int change[]={5,10,20,50,100,200} ;
int result[1000]={10000} ;
int av[6] ;
result[0] = 0 ;

void minimumchange(int n,int first)
{
	if(n<-500||n>500)
        return inf;
    if(n<=0&&first<0)
        return result[-n];
    else if(first<0)
        return inf;
    else if(!av[first])
        return minimumChange(n,first-1);
    else
    {
        av[first]--;
        int a = minimumChange(n-change[first],first);
        av[first]++;
        int b = minimumChange(n,first-1);
        return min(1+a,b);
    }
}

int main()
{
	int a,b,c,d,e,f,r,q ;
   for (int i = 0; i < 6; ++i)
   {
   	  for (int j = change[i]; j < 1000; ++j)
   	  {
         result[j] = min(result[j],1+result[j-change[i]]) ; 
   	  } 
   }

   while(1)
   {
   	  cin >> av[0] >> av[1] >> av[2] >> av[3] >> av[4] >> av[5] ;
   	  if(av[0]==0 && av[2]==0 && av[3]==0 && av[4] ==0 && av[5] ==0 && av[6] ==0)
   	  {
           break ;
   	  }
   	  scanf("%d.%d",&r,&q) ;
   	  r = r*100 + q ;
      minimumchange(r,5) ;
   }
  return 0 ;
}

