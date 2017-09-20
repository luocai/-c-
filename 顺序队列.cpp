#include <iostream>
#define MaxSize 10
using namespace std; 
class SqQueue {
	private :
		int data[MaxSize];
		int rear, front;
	public :
		SqQueue ()
		{
			rear = 0;
			front = 0;
		}
		void EnQueue (int x)
		{
			if ((rear + 1) % MaxSize == front)
			{
				cout << "无法插入" << endl;
				return ;
			}
		    rear = (rear + 1) % MaxSize;
			data[rear] = x;
			
		}
		void DeQueue (int &x)
		{
			if (rear == front)
			{
				cout << "没东西可弹" << endl;
				return; 
			}
			front = (front + 1) % MaxSize;
			x = data[front];
	    } 
	    bool isEmpty ()
		{
			return rear == front;
		} 
		bool isFull ()
		{
			return ((rear + 1) % MaxSize == front);
		}
		void Clear ()
		{
			rear = 0;
			front = 0;
		}
		int GetFront()
		{
			if (rear == front)
			{
				cout << "队列为空";
				return -1; 
			}
			
			return data[(front + 1) % MaxSize];
		}
		int QueueSize ()
		{
			if (rear > front)
				return rear - front;
			else
				return (MaxSize - (front - rear));
	    }
		void print ()
		{
			int i;
			for (i = front + 1; i != rear; i = (i + 1) % MaxSize)
			{
				cout << data[i] << " ";
			}
			cout << data[i] << " ";
			cout << endl;
		} 		
};
int main ()
{
	SqQueue queue;
	for (int i = 0; i < 9; i++)
		queue.EnQueue(i);
	cout << "队列里的元素是：" << endl;
	queue.print();
	cout << "此刻队列含有多少个元素？" << endl;
	cout << "含有" << queue.QueueSize() << "个呢" << endl;
	cout << "队列满了吗？";
	if (queue.isFull())
		cout << "yes" << endl;
	else
		cout << "no" << endl; 
	int x;
	queue.DeQueue(x);
	cout << "出队的是：" << x << endl;
	cout << "此刻队列里的元素是：" << endl;
	queue.print();
	cout << "此刻队列含有多少个元素？" << endl;
	cout << "含有" << queue.QueueSize() << "个呢" << endl;
	cout << "队列满了吗？";
	if (queue.isFull())
		cout << "yes" << endl;
	else
		cout << "no" << endl; 
	for (int i = 0; i < 3; i++)
	{
		queue.DeQueue(x);
		queue.EnQueue(i);
	}
	cout << "此刻队里的元素是：" <<  endl;
	queue.print();
	cout << "含有元素：" << queue.QueueSize() << "个呢" << endl; 
	queue.Clear();
	cout << "空了吗？" << endl;
	if (queue.isEmpty())
		cout << "yes";
	else
		cout << "呵呵"; 
	
	return 0;
} 
