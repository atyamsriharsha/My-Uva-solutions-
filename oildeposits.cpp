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


#include<iostream>
#include<string>
#include<vector>

using namespace std;

int m,n,cont;
vector<string> v;
string s;
bool visited[100][100];

int di[]={1,1,1,-1,-1,-1,0,0};
int dj[]={1,0,-1,1,0,-1,1,-1};

void dfs(int a, int b){
    
    visited[a][b]=1;    
    int I,J;
    
    for(int i=0;i<8;i++){
        I=a+di[i];
        J=b+dj[i];
        if(I>=0 && I<m && J>=0 && J<n && !visited[I][J]){
            visited[I][J]=1;
            if(v[I][J]=='@') dfs(I,J);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    while(1){
        cin>>m>>n;
        if(m==0) break;  
        
        v.clear();
        
        for(int i=0;i<m;i++)
        {
            cin>>s;
            v.PB(s);
        }
        cont=0;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j])
                {
                    visited[i][j]=1;
                    if(v[i][j]=='@')
                    {
                        cont++;
                        dfs(i,j);
                    }
                }
            }
        }
        cout<<cont<<endl;
    }
}