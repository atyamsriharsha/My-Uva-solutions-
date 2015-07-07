#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <list>
#include <cmath>
using namespace std ;

int solve(int starting_index,int depth,int ball_no,int total_nodes)
{
   int left_index = 2*starting_index ;
   int right_index = 2*starting_index + 1 ;
   if(left_index<=total_nodes && right_index<=total_nodes)
   {
   	  if(ball_no%2!=0)
   	  {
   	  	return solve(left_index,depth,ball_no/2+1,total_nodes) ;
   	  }
   	  else
   	  {
   	  	return solve(right_index,depth,ball_no/2,total_nodes) ;
   	  }
   }
   else
   {
   	return starting_index ;
   }
}
int main()
{
    int test,end1 ;
    int starting_index = 1 ;
    int depth,ball_no,total_nodes ;
      cin >> test ;
     // if(test==-1)
      //	return 0 ;
      while(test--)
      {
    	 cin >> depth >> ball_no ;
    	 total_nodes = pow(2,depth) - 1 ;
    	 cout << solve(starting_index,depth,ball_no,total_nodes) << endl ;
      }
      cin >> end1 ;
	return 0 ;
}