#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std ;
int main()
{
	int n,k1,k2,temp,temp1,temp2,count1=0;
	cin >> n ;
	int flag = 0 ;
	std::vector<int> soldier1;
	std::vector<int> soldier2;
	soldier1.clear() ;
	soldier2.clear() ;
    cin >> k1 ;
	for (int i = 0; i < k1; ++i)
	{
		/* code */
		cin >> temp ;
		soldier1.push_back(temp) ;
	}
	cin >> k2 ;
	for (int i = 0; i < k2; ++i)
	{
		cin >> temp;
	    soldier2.push_back(temp) ;
	}

    while((soldier1.size()>0) && (soldier2.size())>0)
    {
    	temp1 = soldier1.front() ;
    	temp2 = soldier2.front() ;
    	if(temp1>temp2)
    	{
    		soldier1.erase(soldier1.begin()) ;
    		soldier2.erase(soldier2.begin()) ;
    		soldier1.push_back(temp2) ;
    		soldier1.push_back(temp1) ;
    	}
    	else
    	{
    		soldier2.erase(soldier2.begin()) ;
    		soldier1.erase(soldier1.begin()) ;
    		soldier2.push_back(temp1) ;
    		soldier2.push_back(temp2) ;
    	}
    	count1++ ;
    	if(count1>1000)
    	{
    	 // cout << "-1" ;
    	  flag = 1 ;
    	  break ;
    	}
    }
    if(flag==1)
    {
    	cout << "-1 " ;
    	return 0 ;
    }
    else if(flag==0)
    {
    	cout << count1 << " " ;
      if((soldier1.size())>0 && (soldier2.size())==0)
      {
    	cout << "1" ;
    	//cout << "atyam" ;
      }
      else if((soldier1.size())==0 && (soldier2.size())>0)
      {
     	cout << "2" ;
       // cout << "hello" ;
       }
     }

	return 0;
}