#include <stdio.h>
#include <utility>
#include <unordered_map>
#include <vector>

/*
	This method takes an anonymous letter M and text M from a magazine.
	It then return true iff L can be written using M.
	Note: if a letter appears k times in L, it must appear at least k
		  times in M.
*/
bool text(vector<char> L, vector<char> M)
{
	unordered_map<char, vector<int,int>> histo;
	bool possible = true;

	//map all the characters of the letter
	for(int i = 0; i < L.size(); i++)
	{
		char curr = L[i];
		pair<int,vector <int, int>> p;
		if(histo.find(curr) == histo.end())
		{
			vector<int,int> v(0,0);
			p = make_pair(curr, v);
			histo.insert(p);
		}
		else
			histo[curr[0]] = histo[curr[0]] + 1;
	}

	//map all the characters of the magazine
	for(int j = 0; j <  M.size(); j++)
	{
		char curr = M[j];
		if(histo.find(curr) != histo.end())
			histo[curr[1]] = histo[curr[1]] + 1;
	}

	for (histo::iterator it = histo.begin(); it != histo.end(); ++it)
		possible = possible && (it[0] <= it[1]);

	return possible; 
}
