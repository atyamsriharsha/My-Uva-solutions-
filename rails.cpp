#include <cstdio>
#include <stack>
using namespace std;
int N, c;
stack<int> cars;
 
void rails() 
{
    while(1)
    {
        while(cars.size() > 0) 
            cars.pop();
        int j = 0,i;
        for(i = 0; i < N; i++) 
        {
            scanf("%d", &c);
            if(c == 0) 
                return;
            while(j < N && j != c) 
            {
                if(cars.size() > 0 && cars.top() == c) 
                    break;
                j++;
                cars.push(j);
            }
            if(cars.top() == c) 
                cars.pop();
        }
        if(cars.size() == 0) 
            printf("Yes\n");
        else
         printf("No\n");
    }
}
 
int main() 
{
    while(1)
    {
        scanf("%d", &N);
        if(N == 0) 
            break;
        rails();
        printf("\n");
    }
}