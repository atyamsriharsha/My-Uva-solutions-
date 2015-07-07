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

int main()
{
	cout << "SHIPPING ROUTES OUTPUT" << endl << endl;
    int num_test_cases;
    cin >> num_test_cases;
    for (int test_case_number = 1; test_case_number <= num_test_cases; test_case_number++)
    {
        cout << "DATA SET  " << test_case_number << endl << endl;
        int num_warehouses,num_legs,num_requests;
        cin >> num_warehouses >> num_legs >> num_requests;
        map<string, int> numbering;
        for(int w = 0; w < num_warehouses; w++)
        {
            string name;
            cin >> name;
            int number = numbering.size();
            numbering[name] = number ;
        }
        vector<vector<int>  > adjacency_list;
        adjacency_list.resize(num_warehouses);
        for(int l = 0; l < num_legs; l++)
        {
            string w1;
            string w2;
            cin >> w1;
            cin >> w2;
            adjacency_list[numbering[w1]].PB(numbering[w2]);
            adjacency_list[numbering[w2]].PB(numbering[w1]);
        }
        for(int r = 0; r < num_requests; r++)
        {
            int size;
            string w1,w2;
            cin >> size >> w1 >> w2;
            int wn1 = numbering[w1];
            int wn2 = numbering[w2] ;
            vector<int> distance;
            queue<int> bfs_queue;
            distance.resize(num_warehouses);
            for(int w = 0; w < num_warehouses; w++)
            {
                distance[w] = -1;
            }
            distance[wn1] = 0;
            bfs_queue.push(wn1);
            while(bfs_queue.size() > 0)
            {
                int visiting = bfs_queue.front();
                bfs_queue.pop();
                for(vector<int>::iterator ni = adjacency_list[visiting].begin(); ni != adjacency_list[visiting].end(); ni++)
                {
                    int neighbor = *ni;
                    if (distance[neighbor] == -1)
                    {
                        distance[neighbor] = distance[visiting] + 1;
                        bfs_queue.push(neighbor);
                    }
                }
            }
            if(distance[wn2] == -1)
            {
                cout << "NO SHIPMENT POSSIBLE" << endl;
            }
            else
            {
                cout << "$" << size * distance[wn2] * 100 << endl;
            }
        }
        cout << endl;
    }
    cout << "END OF OUTPUT" << endl;
	return 0 ;
}