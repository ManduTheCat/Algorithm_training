#include <iostream>

using namespace std;

bool f_is_prinm(int n)
{
	for(int i = 2; i*i <= n; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int input;
	int first_num;
	int second_num;
	int status;

	while (1)
	{
		first_num = 3;
		status = 1;
		scanf("%d",&input);
		second_num = input - first_num;

		if(input == 0)
		{
			return 0;
		}

		while(!(f_is_prinm(first_num) && f_is_prinm(second_num)))
		{
			if(first_num >= input)
			{
				status = 0;
				break;
			}
			first_num +=2;
			second_num -=2;
		}

		if(status == 0)
		{
			printf("Goldbach's conjecture is wrong.\n") ;
		}
		else
		{
			printf("%d = %d + %d\n", input, first_num, second_num);
		}

	}
}
