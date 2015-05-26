#include <stdio.h>
#include <iostream>

int final_amount(char* hands, int amount)
{
	int i = 0;
	int sum = 1;
	while(hands[i] != NULL)
	{
		if(hands[i] == 'H')
			sum = sum*2;
		else
		{
			if(amount - sum/2 > 0)
			{
				sum = sum/2;
			}
			else
			{
				cout << "son, you've lost all your money in " << i << " hands." << endl;
				return;
			}
		}
		i++;
	}

	return (amount + sum);
}