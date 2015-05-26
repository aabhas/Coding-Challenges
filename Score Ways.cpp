#include <stdio.h>
#include <iostream>
#include <vector>

//int points[] = {2,3,7};

int countCombinations(int score, vector<int> points)
{
	int combinations[score+1];
	combinations[0] = 1;

	for(int i = 0; i < points.size(); i++)
	{
		for(int j = points[i]; j < score; j++)
		{
			combinations[j] = combinations[j] + combinations[j - points[i]];
		}
	}

	return combinations[k];
}
