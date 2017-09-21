#include <iostream>
using namespace std;
typedef struct node{
	int data;
	struct node* next;  // ע�⣡�� "*"��Ҫ��struct ����һ�𣬶�����next��   !!!һ��Ҫ��tag��node)!! 
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
		//���� 
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
		//���� 
		void DeQueue (int &x)
		{
			Qnode temp;
			if (rear == NULL)
				return;
			temp = front;
			if (rear == front)
			{
				rear = front = NULL;  //��Ҳ��Ϊ���п� rear == NULL ���̵� 
			}
			else
			{
				front = front->next;
			}
			length--;
			x = temp->data;
			delete temp;
		} 
		//��ȡ���� 
		int GetLength ()
		{
			return length;
		}
		//�п� 
		bool isEmpty ()
		{
			return rear == NULL;
		}
		//��� 
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
		//��ӡ 
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
	cout << "���ڶ��е�Ԫ���ǣ�" << endl;
	q.print();	
	cout << "�����е�Ԫ���Ƕ���ѽ��" << q.GetLength() << "����" <<endl;
	cout << "���п���" << endl;
	if (q.isEmpty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	int x = 1; //���ڴ�����µĵ���������O 
	for (int i = 0; i < 4; i++)
		q.DeQueue(x);
	cout << "�ոյ�����ɶ��" << " " << x << endl;
	cout << "���ڶ����е�Ԫ����:" << endl;
	q.print();
	q.Clear();
	cout << "������?" << endl;
	if (q.isEmpty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
    return 0;
}
