#include <iostream>
#include <map>
#include <cstdio>
using namespace std ;

int m[128] ;
int city[100][5] ;

int main()
{
	m['r'] = 0 ;
	m['o'] = 1 ;
	m['y'] = 2 ;
	m['g'] = 3 ;
	m['b'] = 4 ;
	m['P'] = 0 ;
	m['G'] = 1 ;
	m['S'] = 2 ;
	m['A'] = 3 ;
	m['N'] = 4 ;
    for(bool done = false;;)
    {
    	int n ;
    	char buff[20] ;
    	for(n=0;;n++)
    	{
    		gets(buff) ;
    		if(buff[0]=='e')
    			break ;
    		if(buff[0]=='#')
    		{
    			done = true ;
    			break ;
    		}
    		for(char *p = buff;;p=p+4)
    		{
    			int color = m[p[0]] ;
    			int waste = m[p[2]] ;
    			city[n][waste] = color ;
    			if(p[3]==0)
    				break ;
    		}
    	}
    	if(done)
    		break ;
    	int min = 5000; int min_city = -1;
        for(int i = 0; i < n; i++)
        {
            int noc = 0;
            for(int j = 0; j < n; j++)
            {
                if (i != j)
                for (int k = 0; k < 5; k++)
                    noc += city[i][k] != city[j][k] ? 1 : 0;
            }
            if(noc<min)
            {
                min = noc;
                min_city = i;
            }
        }
        printf("%d\n", min_city+1);
    }
	return 0 ;
}