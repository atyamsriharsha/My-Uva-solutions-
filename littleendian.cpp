#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std ;

int fun(int i)
{
    return ((i&0xff)<<24)+((i&0xff00)<<8)+((i&0xff0000)>>8)+((i>>24)&0xff) ;
}
int main()
{
    int i, ans;
    while(cin >> i)
    {
        cout << i << " converts to " << fun(i) << endl ;
    }
	return 0;
}