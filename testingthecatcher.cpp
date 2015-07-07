/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef pair<int,int> pii ;
typedef vector<pii> vii ;

int main()
{
	int test = 1, LIS[100000],num,Max1;
	vector<int> height;
    while(1) 
    {
    	Max1 = 0 ;
        height.clear() ;
        scanf("%d", &num);
        if(num == -1) 
        	return 0;
        height.push_back(num);
        while(scanf("%d", &num) && num != -1)
            height.push_back(num);
        for(int i = height.size() - 1; i >= 0; --i) 
        {
            LIS[i] = 1;
            for(int j = height.size() - 1; j > i; --j)
            {
                if(height[j] < height[i] && LIS[i] < LIS[j]+1)
                    LIS[i] = LIS[j]+1;
            }
            if(LIS[i] > Max1)
             Max1 = LIS[i];
        }
        if(test!= 1)
        	cout << endl ;
        printf("Test #%d:\n", test++);
        printf("  maximum possible interceptions: %d\n", Max1);
    }
  return 0 ;
}

