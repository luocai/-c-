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
				cout << "�޷�����" << endl;
				return ;
			}
		    rear = (rear + 1) % MaxSize;
			data[rear] = x;
			
		}
		void DeQueue (int &x)
		{
			if (rear == front)
			{
				cout << "û�����ɵ�" << endl;
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
				cout << "����Ϊ��";
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
	cout << "�������Ԫ���ǣ�" << endl;
	queue.print();
	cout << "�˿̶��к��ж��ٸ�Ԫ�أ�" << endl;
	cout << "����" << queue.QueueSize() << "����" << endl;
	cout << "����������";
	if (queue.isFull())
		cout << "yes" << endl;
	else
		cout << "no" << endl; 
	int x;
	queue.DeQueue(x);
	cout << "���ӵ��ǣ�" << x << endl;
	cout << "�˿̶������Ԫ���ǣ�" << endl;
	queue.print();
	cout << "�˿̶��к��ж��ٸ�Ԫ�أ�" << endl;
	cout << "����" << queue.QueueSize() << "����" << endl;
	cout << "����������";
	if (queue.isFull())
		cout << "yes" << endl;
	else
		cout << "no" << endl; 
	for (int i = 0; i < 3; i++)
	{
		queue.DeQueue(x);
		queue.EnQueue(i);
	}
	cout << "�˿̶����Ԫ���ǣ�" <<  endl;
	queue.print();
	cout << "����Ԫ�أ�" << queue.QueueSize() << "����" << endl; 
	queue.Clear();
	cout << "������" << endl;
	if (queue.isEmpty())
		cout << "yes";
	else
		cout << "�Ǻ�"; 
	
	return 0;
} 
