
#include<iostream>
using namespace std;

class Queue
{
public:
	Queue(int size = 10)
		:cap_(size)
		, front_(0)
		, rear_(0)
		, pQue_(new int[cap_])
	{
	}
	~Queue()
	{
		delete[] pQue_;
		pQue_ = nullptr;
	}
	void push(int val)
	{
		if (full())
		{
			expand(2 * cap_);
		}
			pQue_[rear_] = val;
			rear_ = (rear_ + 1) % cap_;
		
	}
	void pop()
	{
		if (empty()) 
			throw " queue is empty";
		else
		{
			front_ = (front_ + 1) % cap_;
		}
	}
	int front() const
	{
		if (empty()) throw "queue is empty";
		else
		{
			return pQue_[front_];
		}
	}
	int back() const
	{
		if (empty()) throw "queue is empty";
		else
		{
			return pQue_[(rear_ - 1 + cap_) % cap_];
			//为了解决访问数组末尾元素
			//当要访问最后一个元素时，rear_位于数组头
		}
	}
	int size()
	{
		int size = 0;
		for (int i = front_; i != rear_; i=((i+1)%cap_))
		{
			size++;
		}
		return size;
	}

	bool full() const
	{
		if ((rear_ + 1)%cap_ == front_)
			return true;
		else
			return false;
	}
	bool empty() const
	{
		if (rear_ == front_)
			return true;
		else
			return false;
	}

private:

	void expand(int size)
	{
		//不可以和栈、数组一样 使用memcpy，来进行内存拷贝
		int* ret = new int[size];
		int num = 0;
		for (int i = front_; i != rear_; num++,i=(i + 1) % cap_)
		{
			ret[num] = pQue_[i];
		}
		delete[] pQue_;
		pQue_ = ret;
		front_ = 0;
		rear_ = num;
		cap_ = size;
	}

	int cap_;
	int* pQue_;
	int front_;
	int rear_;
};
int main()
{
	Queue q(1);
	int arr[] = { 1,2,3,4,50 };
	for (int i : arr)
	{
		q.push(i);
	}
	cout << q.front() << "  " << q.back() << endl;
}
