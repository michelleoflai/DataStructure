/*
* 二叉堆的应用 优先队列
* priority_queue	push() pop() top() empty() size()
*/

#include<iostream> 
#include<functional>
#include<string.h>
using namespace std;

class PriorityQueue {
public:
	using Comp = function<bool(int, int)>;


	//PriorityQueue(int cap = 20, Comp comp = greater<int>()) :
	//	size_(0),
	//	cap_(cap),
	//	comp(comp)
	//{
	//	que_ = new int[cap_];
	//}


	PriorityQueue(Comp comp = greater<int>()) :
		size_(0),
		cap_(20),
		comp(comp)
	{
		que_ = new int[cap_];
	}
	~PriorityQueue() {
		delete[]que_;
		que_ = nullptr;
	}
public:
	void push(int val) {
		if (size_ == cap_) {
			int* p = new int[2 * cap_];
			memcpy(p, que_, cap_ * sizeof(int));
			delete[]que_;
			que_ = p;
			cap_ *= 2;
		}
		if (size_ == 0) {
			que_[size_] = val;
		}
		else
		{
			siftUp(size_, val);
		}
		size_++;
	}

	int pop() {
		if (size_ == 0) {
			throw "empty";
		}
		int top = que_[0];

		que_[0] = que_[size_ - 1];
		size_--;

		siftDowm(0, que_[0]);
		return top;

	}

	bool empty() const {
		return size_ == 0;
	}

	int size() const {
		return size_;
	}

private:
	void siftUp(int i, int val) {

		while (i > 0) {
			int father = (i - 1) / 2;
			if (comp(val, que_[father])) {
				que_[i] = que_[father];
				i = father;
			}
			else {
				break;
			}
		}
		que_[i] = val;
	}

	void siftDowm(int i, int val) {
		while (i < size_ / 2)			// 末尾节点的父节点(i<=(size_-1-1)/2)
		{
			int child = i * 2 + 1;
			if ((child + 1) < size_ && comp(que_[child + 1], que_[child])) {
				child += 1;
			}
			if (comp(que_[child], val)) {
				que_[i] = que_[child];
				i = child;
			}
			else
			{
				break;
			}
		}
		que_[i] = val;
	}

private:
	int* que_;
	int size_;
	int cap_;
	Comp comp;
};


int main070() {
	PriorityQueue que;
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		que.push(rand() % 100);
	}

	while (!que.empty()) {
		cout << que.pop() << " ";
	}
	cout << endl;


	//
	//PriorityQueue que_less([](int a, int b) {return a < b; });
	PriorityQueue que_less(static_cast<PriorityQueue::Comp>(less<int>()));

	for (int i = 0; i < 10; i++) {
		que_less.push(rand() % 100);
	}

	while (!que_less.empty()) {
		cout << que_less.pop() << " ";
	}
	cout << endl;

	return 0;
}