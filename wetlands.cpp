/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;


/*debugging*/

#define out1(x)cout<<#x<<" is "<<x<<endl
#define out2(x,y)cout<<#x<<" is "<<x<<" "<<#y <<" is "<<y<<endl
#define out3(x,y,z)cout<<#x<<" is "<<x<<" "<<#y<<" is "<<y<<" "<<#z<<" is "<<z<<endl;
#define out4(a,b,c,d)cout<<#a<<" is "<<a<<" "<<#b<<"  is "<<b<<" "<<#c<<" is "<<c<<" "<<#d<<" is "<<d<<endl;
#define show(i,a,n) for(i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define sz(a) cout<<"size of "<<#a<<" is "<<a.size()
#define exectime() cout<<"execution time "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;

/*standard values*/

#define INF 1e18
#define PI 3.14159265359
#define MAX 1000006


/*Frequent functions*/

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pu putchar
#define gu getchar
#define FastIn std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)
char matrix[100][100];
int row;
int col;
int cnt;
bool vis[100][100];
 
void dfs (int r, int c)
{
    if(r == row || r < 0 || c == col || c < 0 || matrix[r][c] == 'L' || vis[r][c]) 
    	return;
    vis[r][c] = true;
    cnt++;
    int dr[] = {-1, 0, 1, 0, -1, 1, 1, -1};
    int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};
    for(int i = 0; i < 8; i++ )
        dfs(r+dr[i],c+dc[i]);
}
 
int main() 
{ 
    int testCase;
    scanf("%d", &testCase);
    getchar(); 
    getchar();
    bool blank = false;
    while(testCase--) 
    {
        char inp [1000];
        row = col = 0;
        if(blank)
         printf ("\n"); blank = true;
        while(gets(inp) && strlen(inp)>0) 
        {
            if(inp[0] == 'L' || inp [0] == 'W') 
            {
                strcpy(matrix[row],inp);
                col = strlen(inp);
                row++;
            }
            else 
            {
                int r, c;
                sscanf(inp, "%d %d", &r, &c);
                cnt = 0;
                memset(vis,false,sizeof(vis));
                dfs(r - 1, c - 1);
                printf("%d\n", cnt);
            }
        }
    }
    return 0;
}