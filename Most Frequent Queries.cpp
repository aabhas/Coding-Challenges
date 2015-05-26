/*
	Compute the k most frequent queries
		You are given an array A of n strings. Compute the K strings that appear most frequently in A.
*/

#include <stdio.h>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <string>

string query(string* A)(
{
	unordered_map<string, int> hist;
	int max_freq;
	string q;

	int i = 0;
	while(A[i] != NULL)
	{
		string curr = A[i];
		pair<string, int> p;
		if(hist.find(curr) == hist.end())
		{
			p = make_pair(curr, 0);
			hist.insert(p);
		}
		else
		{
			hist[curr]->second = hist[curr]->second + 1;
			if(hist[curr]->second > max) 
			{
				max = hist[curr]->second;
				q = curr;
			}
		}
		i++;
	}
	return q;
}