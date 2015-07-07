#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std ;

class linesegment
{
public:
	double x1,x2,y1,y2,r ;
	linesegment(double x1,double y1,double x2,double y2,double r)
	{
		this->x1 = x1 ;
		this->y1 = y1 ;
		this->x2 = x2 ;
		this->y2 = y2 ;
		this->r  = r ;
	}
	
};

struct class1
{
bool operator()(const linesegment& a ,const linesegment& b)
{
	return a.x1 <b.x1 ?1 :0 ;
}
}myclass;

int main()
{
	int test,nl,i,y,sz,sz2;
	double result,x1,y1,x2,y2,r ;
	cin >> test ;
	std::vector<linesegment> segments;
	std::vector<double> x;
	while(test--)
	{
		segments.clear() ;
        x.clear() ;
        cin >> nl ;
        for(i=0;i<nl;i++)
        {
          cin >> x1 >> y1 >> x2 >> y2 >> r ;
          x.push_back(x1) ;
          x.push_back(x2) ;
          if(x1 > y1)
          {
          	swap(x1,x2) ;
          	swap(y1,y2) ;
          }
          segments.push_back(linesegment(x1,y1,x2,y2,r));
        }
       std::sort(x.begin(),x.end()) ;
       std::sort(segments.begin(),segments.end(),myclass) ;
        cout << x.size()+1 << endl ;
        for(i = 0, sz = x.size(); i < sz;i++) 
        {
			if(i == 0) 
			{
				printf("-inf %.3f 1.000\n", x[i]);
				continue;
			} 
			result = 1.0;
			for(y = 0, sz2 = segments.size(); y < sz2; y++) 
			{
				if(segments[y].x1 <= x[i-1] && segments[y].x2 >= x[i])
					result *= segments[y].r;
			}
			printf("%.3f %.3f %.3f\n", x[i-1], x[i], result);
			if(i == sz-1) 
			{
				printf("%.3f +inf 1.000\n", x[i]);
			}
		}
	}
	return 0 ;
}