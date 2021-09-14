#include <iostream>

using namespace std;

int pop(int *q, int &start, int &end)
{
	int &temp = start;
	int size;

	size = end - start;

	if(size != 0)
	{
		start++;
		return q[temp - 1];
	}

	return -1;

}

void push(int *q, int &start, int &end, int num)
{
	q[end] = num;
	end++;
}

int size(int &start, int &end)
{
	int size;

	size = end - start;
	return size;

}

int front(int *q, int &start, int &end)
{
	int size;
	int &temp = start;
	size = end - start;
	if(size != 0)
	{
		return q[temp];
	}

	return -1;
}

int back(int *q, int &start, int &end)
{
	int size;
	int &temp = end;
	size = end - start;
	if(size != 0)
	{
		return q[temp - 1];
	}
	return -1;

}

int empty(int start, int end)
{
	int size;

	size = end - start;
	if(size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int *que;
	int cmd_num;
	string cmd;
	int num;
	// int i;
	int start = 0;
	int end = 0;

	cin >>cmd_num;
	que = new int[cmd_num *10];
	while(cmd_num--)
	{

		cin >> cmd ;

		if (cmd == "push")
		{
			cin >> num;
			push(que, start, end, num);
			num = 0;
		}
		else if(cmd == "pop")
		{
			cout << pop(que,start,end) << "\n";

		}
		else if(cmd == "size")
		{
			cout << size(start,end) << "\n";
		}

		else if(cmd == "front")
		{
			cout << front(que, start, end) << "\n";
		}

		else if(cmd  == "back")
		{
			cout << back(que, start, end) << "\n";
		}

		else if(cmd == "empty")
		{
			cout << empty( start, end) << "\n";
		}
	}

	// i = 0;
	// while(i < end)
	// {
	// 	cout << que[i] << "\n";
	// 	i++;
	// }
	return 0;
}
