#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
using namespace std ;

std::vector<string> words;
string rules;

int n,rules1;

void solve(string output,int i)
{
	if(i==rules.size())
	{
		cout << output << endl ;
		return ;
	}
	if(rules[i]=='#')
	{
		for(int j=0;j<words.size();j++)
		{
			solve(output+words[j],i+1) ;
		}
	}
	else
	{
		for(int j=0;j<10;j++)
		{
		  solve(output+char('0'+j),i+1) ;
		}
	}
}
int main()
{
	string temp ;
	while(cin>>n)
	{
		cout << "--" << endl ;
		while(n--)
		{
          cin >> temp ;
          words.push_back(temp) ;
        }
        cin >> rules1 ;
        while(rules1--)
        {
        	cin >> rules ;
         //	rules.push_back(temp) ;
        	solve("",0) ;
        }
        words.clear() ;
	}
	return 0 ;
}
