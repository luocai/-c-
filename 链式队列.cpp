#include <iostream>
using namespace std;
typedef struct node{
	int data;
	struct node* next;  // 注意！！ "*"号要和struct 挨在一起，而不是next；   !!!一点要有tag（node)!! 
}Node, *Qnode;
class ListQueue {
	private :
		Qnode front;
		Qnode rear;
		int length;
	public :
		ListQueue ()
		{
			front = rear = NULL;
			length = 0;
		}
		//进队 
		void EnQueue (int x)
		{
			Qnode newnode = new Node;
			newnode->data = x;
			newnode->next = NULL;
			if (rear == NULL)
				front = rear = newnode;
			else
			{
				rear->next = newnode;
				rear = newnode;
			}
			length++; 
		}
		//出队 
		void DeQueue (int &x)
		{
			Qnode temp;
			if (rear == NULL)
				return;
			temp = front;
			if (rear == front)
			{
				rear = front = NULL;  //这也是为队列空 rear == NULL 做铺垫 
			}
			else
			{
				front = front->next;
			}
			length--;
			x = temp->data;
			delete temp;
		} 
		//获取长度 
		int GetLength ()
		{
			return length;
		}
		//判空 
		bool isEmpty ()
		{
			return rear == NULL;
		}
		//清空 
		void Clear ()
		{
			Qnode temp;
			for (int i = 0; i < length; i++)
			{
				temp = front;
				front = front->next;
				delete temp;
			}
			length = 0;
		}
		//打印 
		void print ()
		{
			if (rear == NULL)
				return;
			Qnode temp;	
			for (temp = front; temp < rear; temp = temp->next)
			{
				cout << temp->data << " ";
			}
			cout << temp->data ;
			cout << endl;
		}
};
int main ()
{
	ListQueue q;
	for (int i = 0; i < 10; i++)
		q.EnQueue(i);
	cout << "现在队中的元素是：" << endl;
	q.print();	
	cout << "队列中的元素是多少呀？" << q.GetLength() << "个呢" <<endl;
	cout << "队列空吗？" << endl;
	if (q.isEmpty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	int x = 1; //用于存放最新的弹出的数据O 
	for (int i = 0; i < 4; i++)
		q.DeQueue(x);
	cout << "刚刚弹出了啥？" << " " << x << endl;
	cout << "现在队列中的元素是:" << endl;
	q.print();
	q.Clear();
	cout << "空了吗?" << endl;
	if (q.isEmpty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
    return 0;
}
