/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef pair<int,int> pii ;
typedef vector<pii> vii ;

int matrix[105][105] ;
int main()
{
	int m, n;
 
    while(scanf ("%d %d", &m, &n)) 
    {
        if(m == 0 && n == 0) 
        	break;
        int input;
 
        for( int i = 0; i < m; i++ ) 
        {
            for( int j = 0; j < n; j++) 
            {
                scanf ("%d", &input);
                matrix[i][j] = 1 - input;
            }
        }
        for( int i = 1; i < m; i++ ) 
        {
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 1) 
                	matrix[i][j] = matrix[i - 1][j] + 1;
        }
 
        int maxi = -1;
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++ ) 
            {
                int cnt = matrix [i][j];
                for(int k = j + 1; k < n && matrix [i][j] <= matrix[i][k]; k++ )
                    cnt += matrix [i] [j];
                for(int k = j - 1; k >= 0 && matrix [i][j] <= matrix [i] [k]; k-- )
                    cnt += matrix [i] [j];
                if ( cnt > maxi) maxi = cnt;
            }
        }
        printf ("%d\n", maxi);
    }
  return 0 ;
}

