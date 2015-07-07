#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std ;
int n,m ;
int best ;
std::vector<int> result;
int tracks[30] ;

void dfs(std::vector<int> remember,int sum,int index)
{
	sum+=tracks[index] ;
	remember.push_back(tracks[index]) ;
	if(sum>best || (sum==best && remember.size()>result.size()))
	{
       best = sum ;
       result = remember ;
	}
	for(int i=index+1;i<m;i++)
	{
		if(sum+tracks[i]<=n)
		{
			dfs(remember,sum,i) ;
		}
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=0;i<m;i++)
		{
			cin >> tracks[i] ;
		}
		best = 0 ;
		for(int i=0;i<m;i++)
		{
			std::vector<int> remember;
			dfs(remember,0,i) ;
		}
		for(int i=0;i<result.size();i++)
		{
			cout << result[i] << " " ;
		}
		cout << "sum:" << best << endl ;
	}
	return 0 ;
} 
