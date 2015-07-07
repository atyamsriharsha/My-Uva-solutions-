#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std ;


char a[4][4] ;
int b[4][4] ;
int n ;

int result(int index)
{
	int ret = index;
 
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            if(b[i][j] == 0) 
            {
                for(int k = j; k >= 0 && a[i][k]!= 'X'; k--) // < current row
                    b[i][k]++;
                for(int k = j + 1; k < n && a [i] [k] != 'X'; k++) // current row >
                    b[i][k]++;
                for(int k = i - 1; k >= 0 && a [k] [j] != 'X'; k--) // current col ^
                    b[k][j]++;
                for( int k = i + 1; k < n && a [k] [j] != 'X'; k++)  // current col
                    b[k][j]++;
                int val = result(index + 1);
                if ( val > ret ) ret = val;
                for ( int k = j; k >= 0 && a [i] [k] != 'X'; k--) // < current row
                    b[i][k]--;
                for ( int k = j + 1; k < n && a [i] [k] != 'X'; k++) // current row >
                    b[i][k]--;
                for ( int k = i - 1; k >= 0 && a [k] [j] != 'X'; k-- ) // current col ^
                    b[k][j]--;
                for ( int k = i + 1; k < n && a [k] [j] != 'X'; k++ ) // current col
                    b[k][j]--;
            }
        }
    }
        return ret ;
}
int main()
{
	while(1)
	{
        cin >> n ;
        if(n==0)
        	break ;
      //  char a[4][4] ;
        memset(b,0,sizeof(b)) ;
        for(int i=0;i<n;i++)
        {
    	   for(int j=0;j<n;j++)
    	   {
    		  cin >> a[i][j] ;
    		  if(a[i][j]=='X')
    		  	b[i][j] = 100000 ;
    	   }
       }
       cout << result(0) << endl ;
   }
	return 0 ;
}