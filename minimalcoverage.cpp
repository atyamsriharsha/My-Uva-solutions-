#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std ;

typedef pair<int,int> pii ;
typedef vector<pii> vii;
vii coordinates ;

int main(int argc, char const *argv[])
{
	int test,i=0,m ;
	cin >> test ;
	while(test--)
	{
		coordinates.clear() ;
		cin >> m ;
		while(1)
		{
           cin >> coordinates[i].first >> coordinates[i].second;
           if(coordinates[i].first==0 && coordinates[i].second==0)
           	  break ;
        }
        int uncovered_index = 0;
        sort(coordinates.begin(),coordinates.end()) ;
        vii max_cover ;
        

	}
	return 0;
}