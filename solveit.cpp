#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
 
float solve(float x,int p,int q,int r,int s,int t,int u)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2.0f) + u;
}
 
int main() 
{ 
    int p, q, r, s, t, u;
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) 
    {
        double low = 0.0f, mid = 0.5f, high = 1.0f, mid_ans, high_ans;
        while(high - low > 0.0000001f) 
        {
            mid = (low + high) / 2.0f;
            mid_ans = solve(mid,p, q, r, s, t, u);
            high_ans = solve(high,p, q, r, s, t, u);
            if((high_ans < 0 && mid_ans > 0) || 
                    (high_ans >= 0 && mid_ans > high_ans) || 
                    (high_ans <= 0 && high_ans > mid_ans)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if(abs(mid_ans) <= 0.0001f)
            printf("%1.4f\n", mid);
        else
            printf("No solution\n");
    }
 
    return 0;
}