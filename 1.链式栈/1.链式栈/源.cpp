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
	void push(int val)   //入栈操作对于链表来说就是头插法
	{
		Node* p = new Node(val);
		p->next = head_->next;
		head_->next = p;
		size_++;
	}
	void pop()    //出栈操作，对于链表来说即使删除第一个节点
	{
		if (head_->next == nullptr)
			throw "stack is empty";
		Node* p = head_->next;              //删除第一个节点
		head_->next = head_->next->next;
		delete p;
		size_--;
	}
	int top() const  //获取栈顶元素
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
	int size()  //求当前栈中存在的元素
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