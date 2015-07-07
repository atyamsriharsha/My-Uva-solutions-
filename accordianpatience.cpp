#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <stack>
using namespace std ;

int main()
{
	map<char,int>stats ;
	stats['2'] = 2;
	stats['3'] = 3;
	stats['4'] = 4;
	stats['5'] = 5;
	stats['6'] = 6;
	stats['7'] = 7;
	stats['8'] = 8;
	stats['9'] = 9;
	stats['T'] = 10;
	stats['J'] = 11;
	stats['Q'] = 12;
	stats['K'] = 13;
	stats['A'] = 14;
	stats['S'] = 20;
	stats['H'] = 30;
	stats['D'] = 40;
	stats['C'] = 50;
	string input ;
	std::vector<pair<int,int> cards;
    std::stack<pair<int,int> piles[52] ;
	while(cin >> input)
	{
         if(input=="#")
         	break ;
         cards.clear() ;
          for (int i = 0; i < 52; i++) {
			while (!piles[i].empty())
				piles[i].pop();
		}
		cards.push_back (pair<int,int>(stats[input[0]], stats[input[1]]));
		for (int i = 0; i < 51; i++) {
			cin >> input;
			cards.push_back (pair<int,int>(stats[input[0]], stats[input[1]]));
		}
	}

	return 0 ;
}
