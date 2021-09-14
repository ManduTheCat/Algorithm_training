#include <iostream>

using namespace std;

class circled_que
{
	private:
		int max_size;
		int head;
		int tail;
		int *que;
		int size_que;
	public:
		void set_circle_que(int intpu_max_size);
		void print_que();
		int pop();
		void push(int num);
		int size();
		int empty();
};

void circled_que::set_circle_que(int input_max_size)
{
	head = 0;
	tail = 0;
	max_size = input_max_size;
	que = new int[input_max_size];
}

void circled_que::print_que()
{
	int i = 0;
	while(i < max_size)
	{
		cout << "num: "<<circled_que::que[i] << "\n";
		cout << "i :"<<i << "\n";
		i++;
	}
}

void circled_que::push(int num)
{
	int index = head;

	if(head > max_size - 1)
	{
		index = max_size % head;
	}
	que[index] = num;
	head+=1;
}

int circled_que::pop()
{
	int output;
	output = que[tail];
	tail +=1;
	return output;
}

int circled_que::size()
{
	size_que = head - tail;
	return size_que;
}

int circled_que::empty()
{
	if(size_que == 0)
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
	circled_que queue;
	queue.set_circle_que(3);
	queue.push(6);
	queue.push(8);
	queue.push(9);
	queue.push(10);
	queue.print_que();
	cout << queue.empty() << "\n";
	cout <<queue.size() <<  "\n";
}
