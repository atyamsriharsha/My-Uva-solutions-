#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std ;

int grid[20][20] ;
bool visited[20][20] ;
int rows,cols ;
int start_row_index,start_col_index ;
int no_of_beepers ;
int count1 =  0 ;

int solve(int x,int y)
{
	if(count1==no_of_beepers)
	{
		return 0;
	}
   int up=0,down=0,left=0,right= 0 ;
   if(x!=0)
   {
   		visited[x][y] = 1  ;
   	 if(grid[x-1][y]==1 && visited[x-1][y]==0)
   	 {
   	 	visited[x-1][y] = 1 ;
   	 	//grid[x-1][y] = -1 ;
   	 	count1++ ; 
   	 }
   	 if(visited[x][y]!=1)
   	 {
   	 	visited[x][y] = 1  ;
   	    up = solve(x-1,y) +1 ;
   	    cout << up << endl ;
   	    //grid[x-1][y] = 1 ;
   	  	visited[x][y] = 0  ;
   	  }
   }
   if(x!=rows)
   {
   	 if(grid[x+1][y]==1 && visited[x+1][y]==0)
   	 {
   	 	visited[x+1][y] = 1  ;
   	 	//grid[x+1][y] = -1 ;
   	 	count1++ ; 
   	 }
   	 if(visited[x][y]!=1)
   	 {
   	 	visited[x][y] = 1  ;
   	  down = solve(x+1,y) +1;
   	  cout << down << endl ;
   	  //grid[x+1][y] = 1 ;
   	  	visited[x][y] = 0  ;
   	  }
   }
   if(y!=0)
   {
   	 //visited[x][y] = 1  ;
   	 if(grid[x][y+1]==1 && visited[x][y+1]==0)
   	 {
   	 	visited[x][y+1] = 1 ;
   	 	count1++ ; 
   	 }
   	 if(visited[x][y]!=1)
   	 {
   	 	visited[x][y] = 1  ;
   	    right = solve(x,y+1) +1;
   	    cout << right << endl ;
   	  	visited[x][y] = 0  ;
   	  }
   }
   if(y!=cols)
   {
   	 //	visited[x][y] = 1  ;
   	 if(grid[x][y-1]==1 && visited[x][y-1]==0)
   	 {
   	 	visited[x][y-1] = 1  ;
   	 	//grid[x][y-1] = -1 ;
   	 	count1++ ; 
   	 }
   	 if(visited[x][y]!=1)
   	 {
   	 	visited[x][y] = 1 ;
   	    left = solve(x,y-1) +1;
   	    cout << left << endl ;
   	    //grid[x][y-1] = 1 ;
   	  	visited[x][y] = 0  ;
   	  }
   }
   return  min(up,max(down,max(right,left)));
}

int main()
{
	int test,row_index,col_index ;
	cin >> test ;
	memset(grid,-1,sizeof(grid)) ;
	memset(visited,false,sizeof(visited)) ;
	while(test--)
	{
      cin >> rows >> cols ;
      cin >> start_row_index >> start_col_index ;
      cin >> no_of_beepers ;
      for(int i=0;i<no_of_beepers;i++)
      {
         cin >> row_index >> col_index ;
         grid[row_index][col_index] = 1 ;
      }
     cout << solve(start_row_index,start_col_index) ;
	}
	return 0 ;
}