#include <iostream>


using namespace std;

class deque
{
	private:
		int deque_size;
		int head;
		int tail;
		int *dq;
		int dq_size;
		int back_cur;
		int front_cur;

	public:
		deque(int num)
		{
			deque_size = num * 10;
			back_cur = 0;
			front_cur = 0;
			head = 0;
			tail = 0;
			dq_size = 0;
			dq = new int [deque_size];
		}

		void push_front(int num);
		void push_back(int num);
		int pop_front();
		int pop_back();
		int size();
		int empty();
		int front();
		int back();
};

void deque::push_front(int num)
{
	dq[head] = num;
	head++;
	dq_size++;
}

void deque::push_back(int num)
{
	dq[tail] = num;
	tail++;
	dq_size++;
}

int deque::pop_front()
{

	if(dq_size == 0)
	{
		return -1;
	}
	head--;
	dq_size--;
	
	return dq[head];
}

int deque::pop_back()
{
	if(dq_size == 0)
	{
		return -1;
	}
	dq_size--;

	return dq[tail--];
}

int deque::size()
{
	return dq_size;
}

int deque::empty()
{
	if(dq_size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int deque::front()
{
	return dq[head];
}

int deque::back()
{
	return dq[tail - 1];
}

int main()
{
	deque dque(10);
	dque.push_front(10);
	dque.push_front(9);
	dque.push_front(8);
	dque.push_front(7);
	dque.push_back(111);
	cout<< dque.pop_front() <<"\n";
	cout<< dque.pop_back() <<"\n";
}