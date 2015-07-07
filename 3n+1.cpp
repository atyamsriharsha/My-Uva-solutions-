#include <iostream>
#include <cstdio>
using namespace std ;
int main()
{
	long long int i,j,k,max=0,count=1;
    while(scanf("%lld %lld",&i,&j)!=EOF)
    {
        max = 0 ,count = 1 ;
    	printf("%lld %lld",i,j);
    	if(i>j)
    		swap(i,j) ;
        k = i ;
    	while(i<=j)
    	{
    		k = i ;
    		if(count >max)
    			max = count ;
            count = 1 ;
    		while(k!=1)
    		{
    			if(k%2==1)
    			{
                    k = 3*k + 1 ; 
    			}
    			else
    			{
    				k = k/2 ;
    			}
    			count ++ ;
    		}
    		i++ ;
    	}
    	printf(" %lld\n",max);
    }
	return 0 ;
}