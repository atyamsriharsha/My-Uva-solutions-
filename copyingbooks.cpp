#include <string.h>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

typedef pair <int, int > pii;
#define MAX 500
long long int  A[MAX];
int K, M;
vector<pii> group;

bool isPossible(long long int size){
    int curK = 1;
    long long int amountK = 0;
    for(int i = 0; i < M; i++){
        if(amountK + A[i] <= size){
            amountK += A[i];
        }
        else if(curK == K || size < A[i])return false;
        else {
            amountK = A[i];
            curK += 1;
        }
    }
    return true;
}

long long int binarySearch(long long int lo,  long long int hi){
    long long int  mid;
    while(lo < hi && lo + 1 != hi){
        mid = ((hi - lo)/2) + lo;
        if(isPossible(mid))hi = mid;
        else lo = mid;

    }
    if(lo == hi) return lo;
    if(isPossible(lo)) return lo;
    else return hi;
}

void paritition(long long int  ans){
    group.clear();
    long long int  amount = 0;
    int top = M - 1;
    int i;
    for(i = M-1; i >= 0; i-- ){
        if(amount + A[i] <= ans){
            amount += A[i];

        }
        else{
            group.push_back(pii(i+1, top));
            top = i;
            amount = A[i];
        }
    }
    group.push_back(pii(0, top));
    reverse(group.begin(), group.end());
    int curK = group.size();

    for(i = 0; i < group.size(); i++){
        for(int j = group[i].first; j <= group[i].second; j++){
            printf("%lld", A[j]);

            if(curK < K && j < group[i].second){
                curK += 1;
                printf(" / ");
            }
            else if(j != group[i].second) printf(" ");

        }
        if(i+1 < group.size())
            printf(" / ");
    }
    puts("");
}
int main()
{
    int test;
    long long int high, ans;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &M, &K);
        high = 0;
        for(int i = 0; i < M; i++){
            scanf("%lld", &A[i]);
            high += A[i];
        }
    ans = binarySearch(0, high);
    paritition(ans);
    }
	return 0;
}