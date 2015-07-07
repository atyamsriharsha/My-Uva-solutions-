/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;
#define ll long long

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
#define all(v) v.begin(),v.end()
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
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)
#define vi vector<int> v
#define vc vector<char> v 

bool matrix [30 + 3] [30 + 3];
 
void reset ()
{
    for ( int i = 0; i < 33; i++ )
        memset (matrix [i], false, sizeof (matrix [i]));
}
 
int main ()
{
    int edges;
    int cases = 0;
 
    while ( cin >> edges && edges ) {
        reset ();
 
        map <int, int> index;
        int nodeNumber = 1;
 
        for ( int i = 0; i < edges; i++ ) {
            int a, b;
            cin >> a >> b;
            if ( !index [a] ) index [a] = nodeNumber++;
            if ( !index [b] ) index [b] = nodeNumber++;
 
            matrix [index [a]] [index [b]] = matrix [index [b]] [index [a]] = true;
        }
 
        int queryNode;
        int ttl;
        int dist [30 + 3];
 
        while ( cin >> queryNode >> ttl ) {
            if ( queryNode == 0 && ttl == 0 ) break;
 
            memset (dist, -1, sizeof (dist));
 
            dist [index [queryNode]] = 0;
 
            queue <int> q;
            q.push (index [queryNode]);
 
            while ( !q.empty () ) {
                int pop = q.front ();
                q.pop ();
 
                for ( int i = 1; i < nodeNumber; i++ ) {
                    if ( matrix [pop] [i] && dist [i] == -1 ) {
                        dist [i] = dist [pop] + 1;
                        q.push (i);
                    }
                }
            }
 
            int cnt = 0;
 
            for ( int i = 1; i < nodeNumber; i++ ) {
                if ( dist [i] == -1 || dist [i] > ttl ) cnt++;
            }
 
            printf ("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
                    ++cases, cnt, queryNode, ttl);
        }
    }
 
    return 0;
}


		