#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
using namespace std ;
int main()
{
	int test,n,h ;
	string result ;
	cin >> test ;
	while(test--)
	{
	    result ="";
        cin >> n ;
        cin >> h  ;
        cin.ignore(100,'\n') ;
        for (int i = 0; i < n-h; ++i)
        {
        	result = result + char('0') ;
        }
        for(int i=0;i<h;i++)
        {
             result = result + char('0'+1) ; 
        }
        do
        {
            cout << result << endl;
        }while(next_permutation(result.begin(),result.end())) ;
        if(test)
          cout << endl ;
	}
	return 0 ;
}