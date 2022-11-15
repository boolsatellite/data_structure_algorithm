#include <iostream>
using namespace std;

class LinsStack
{
public:
	LinsStack()
	{
		head_ = new Node;
	}

	~LinsStack()
	{
		Node* tem = head_;
		while(tem != nullptr)
		{
			head_ = tem->next;
			delete tem;
			tem = head_;
		}
	}
	void push(int val)   //��ջ��������������˵����ͷ�巨
	{
		Node* p = new Node(val);
		p->next = head_->next;
		head_->next = p;
		size_++;
	}
	void pop()    //��ջ����������������˵��ʹɾ����һ���ڵ�
	{
		if (head_->next == nullptr)
			throw "stack is empty";
		Node* p = head_->next;              //ɾ����һ���ڵ�
		head_->next = head_->next->next;
		delete p;
		size_--;
	}
	int top() const  //��ȡջ��Ԫ��
	{
		if (head_->next == nullptr)
			throw "stack is empty";
		return head_->next->data;

	}
	bool empty() const 
	{
		if (head_->next == nullptr) return true;
		else
		{
			return false;
		}
	}
	int size()  //��ǰջ�д��ڵ�Ԫ��
	{
		return size_;   
	}
private:
	struct Node
	{
		Node(int d = 0) :data(d), next(nullptr) {}
		int data;
		Node* next;
	};
	Node* head_;
	int size_;
};
int main()
{
	LinsStack q;
	q.push(1);
	q.push(2);
	cout << q.size() << endl;

}