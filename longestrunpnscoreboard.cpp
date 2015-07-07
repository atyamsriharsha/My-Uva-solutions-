#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std ;

int a[100][100] ;
int result1[100][100] ;
string name ;
int rows,cols ;
int solve(int row_index,int col_index)
{
    if(a[row_index][col_index]!=-1)
    	return a[row_index][col_index] ;
    int up=0,down=0,right=0,left= 0 ;
    if(row_index!= 0 && result1[row_index - 1][col_index] < result1[row_index][col_index])
        up = solve(row_index - 1, col_index) + 1;
    if(row_index != rows - 1 && result1[row_index + 1][col_index] < result1[row_index][col_index]) 
        down = solve(row_index + 1, col_index)+1;
    if( col_index!= 0 && result1[row_index][col_index-1] < result1[row_index][col_index]) 
        left = solve(row_index,col_index-1) + 1;
    if( col_index != cols - 1 && result1[row_index][col_index + 1] < result1[row_index][col_index] ) 
        right = solve(row_index, col_index +1) + 1; 
    return a[row_index][col_index] = max (up, max (down, max (right, left)));
}

int main(int argc, char const *argv[])
{
    int test,max1,len ;
    cin >> test ;
    while(test--)
    {
    	len = 0 ;
      max1 = -1 ;
      cin >> name >> rows >> cols ;
      for(int i=0;i<rows;i++)
      {
      	for(int j=0;j<cols;j++)
      	{
      		cin >> result1[i][j] ;
      		a[i][j] = -1 ;
      	}
      }
      for (int i = 0; i < rows;i++)
      {
      	for (int j = 0; j < cols;j++)
      	{
      	   len = solve(i,j) ; 
      	   if(len>max1)
      	   	max1 = len ;
      	}
      }
      cout << name<<": " << max1+1 << endl;
    }
	return 0;
}
