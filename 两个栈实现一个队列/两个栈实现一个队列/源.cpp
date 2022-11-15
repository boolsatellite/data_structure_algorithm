//����ʵ��һ������
#include<iostream>
#include <stack>
using namespace std;
class queue
{
public:
	void push(int val)
	{
		s1.push(val);
	}
	void pop()
	{
		if (s2.empty())
		{
			while (!s1.empty())  //��s1�е�Ԫ�� dump ��s2��
			{
				s2.push(s1.top());
				s1.pop();
			}
			s2.pop();
		}
		else
		{
			s2.pop();
		}
	}
	int peek()
	{
		if (s2.empty())
		{
			while (!s1.empty())  //��s1�е�Ԫ�� dump ��s2��
			{
				s2.push(s1.top());
				s1.pop();
			}
			return s2.top();
		}
		else
		{
			return s2.top();
		}
		
	}
	bool empty()
	{
		if (s1.empty() && s2.empty())
		{
			return true;
		}
		return false;
	}
private:
	stack<int> s1;
	stack<int> s2;
};