#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std ;
int timearrive[10004] ;
int timeleave[10004] ;
queue<int> q[2] ;
int main()
{
	int test,n,t,m,i,arrivaltime ;
	string side ;
	cin >> test ;
	while(test--)
	{
        cin >> n >> t >> m ;
        for(i=0;i<m;i++)
        {
          cin >> arrivaltime >> side ;
          timearrive[i] = arrivaltime ;
          if(side=="left")
          {
          	q[0].push(i) ;
          }
          else
          {
          	q[1].push(i) ;
          }
        }
        int actualTime = 0;
        int actualSide = 0;
        while(!q[0].empty() || !q[1].empty())
        {
            int next = q[0].empty() ? timearrive[q[1].front()] :
                       q[1].empty() ? timearrive[q[0].front()] :
                       min( timearrive[q[0].front()], timearrive[q[1].front()] );
            actualTime = max(actualTime, next);
            int cnt = 0;
            while(!q[actualSide].empty() && timearrive[q[actualSide].front()]<=actualTime && cnt<n)
            {
                timeleave[q[actualSide].front() ] = actualTime + t;
                cnt++;
                q[actualSide].pop();
            }
            actualTime += t;
            actualSide = (actualSide + 1) % 2;
        }
        for(int i=0; i<m; i++) cout << timeleave[ i ] << endl;
        if(test) cout << endl;
	}
	return 0 ;
}