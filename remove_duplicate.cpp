#include <unordered_map>
#include <utility>

int* duplicate(int* list)
{
	unordered_map<int, int> M;

	int i = 0;
	while(list[i].next != NULL)
	{
		int curr = list[i].val;
		if(M.find(curr) == M.end())
			M.insert(curr, i);
		else
		{
			int* temp = list[i].next;
			int* double_roll = list[i];
			list[i-1].next = temp;
			list[i].next = NULL;
			delete(double_roll);
			i--;
			//list[i].val = list[i+1].val;
		}
		i++;
	}
}