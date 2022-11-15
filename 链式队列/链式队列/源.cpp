#include<iostream>
using namespace std;

class listQueue
{
public:
	listQueue()
	{
		head_ = new Node();
		head_->next_ = head_;
		head_->pre_ = head_;
	}
	~listQueue()
	{
		while (head_->next_ != head_)
		{
			Node* t = head_->next_;
			head_->next_ = head_->next_->next_;
			t->next_->pre_ = head_;
			delete t;
		}
		delete head_;
		head_ = nullptr;
	}
	void  push(int val)
	{
		Node* p = head_->pre_;
		Node* node = new Node(val);
		node->next_ = head_;
		node->pre_ = p;
		head_->pre_ = node;
		p->next_ = node;
	}
	void pop()
	{
		Node* p = head_->next_;
		head_->next_ = head_->next_->next_;
		p->next_->pre_ = head_;
		delete p;
	}
	int front()
	{
		if (head_->next_ != head_)
		{
			return head_->next_->data_;
		}
		else throw "is empty";
	}
	int back()
	{
		if (head_->pre_ != head_)
		{
			return head_->pre_->data_;
		}
		else throw "is empty";
	}
private:

	struct Node
	{
		Node(int data = 0)
			:data_(data)
			,pre_(nullptr)
			,next_(nullptr)
		{ }
		int data_;
		Node* pre_;
		Node* next_;
	};
	Node* head_; //指向头节点
};
int main()
{
	listQueue q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.front() << "  " << q.back() << endl;

}
