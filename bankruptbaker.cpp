#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std ;

typedef pair<string,int> p ;
map<string,int> ingredients;
vector<p> result;
class binder
{
public:
	int m,n,b ;
	string ingredient,binder_name,recipy_name ;
}ans;

bool comparefunc(p a,p b)
{
	if(a.second == b.second)
	{
		return a.first < b.first ;
	}
	return a.second < b.second ;
}

int main(void) 
{
  int t;
  int cost;
  int k;
  int amount;
  cin >> t;
  while(t) 
  {
  	t-- ;
    result.clear();
    ingredients.clear();
    cin.ignore(100, '\n');
    getline(cin, ans.binder_name);
    cin >> ans.m >> ans.n >> ans.b;
    for (int i = 0; i < ans.m; i++) 
    {
      cin >> ans.ingredient >> cost;
      ingredients[ans.ingredient] = cost;
    }
    for(int i = 0; i < ans.n; i++) 
    {
      cin.ignore(100, '\n');
      getline(cin, ans.recipy_name);
      cin >> k;
      cost = 0;
      for(int j = 0; j < k; j++) 
      {
        cin >> ans.ingredient >> amount;
        cost += ingredients[ans.ingredient] * amount;
      }
      if(cost <= ans.b) 
      {
        result.push_back(make_pair(ans.recipy_name, cost));
      }
    }
    sort(result.begin(), result.end(), comparefunc);
    transform(ans.binder_name.begin(), ans.binder_name.end(), ans.binder_name.begin(), ::toupper);
    cout << ans.binder_name << endl;
    for(int i = 0, sz = result.size(); i < sz; i++) 
    {
      cout << result[i].first << endl;
    }
    if(result.size() == 0) 
    {
      cout << "Too expensive!" << endl;
    }
    cout << endl;
  }
  return 0;
}