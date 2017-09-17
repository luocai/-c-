#include <iostream>
using namespace std;
typedef struct LNode {
	int data;
	struct LNode *next;
}Node, *LinkNode;
class List {
	private :
		LinkNode linklist;
		int length;
	public :
		List ()
		{
			linklist = NULL;
			length = 0; 
		}
		//ָ��λ�ò���һ��Ԫ�� 
		void Insert (int x,int i)
		{
			LinkNode r = linklist;
			LinkNode newnode = new Node;
			if (!newnode)
				return;
			int j = 1;
			if (i == 0)
			{
				newnode->data = x;
				newnode->next = linklist;
				linklist = newnode;
				length++;
				return ;
			}
			while (j < i && r)
			{
				j++;
				r = r->next;
			}
			newnode->data = x;
			newnode->next = r->next;
			r->next = newnode;
			length++;
		}
		//ͷ�巨 
		void Insert (int x)
		{
			
			LinkNode newnode = new Node;
			newnode->data = x;
			newnode->next = linklist->next;
			linklist->next = newnode;
			length++;
		}
		//��ȡ�����и���λ�õ�Ԫ�� 
		int GetData (int i)
		{
			LinkNode r;
			r = linklist;
			int j = 1;
			while (j < i && r)
			{
				j++;
				r = r->next;
			}
			if (r)
				return r->data;
			else
				return -1;
		}
		//��λ����Ԫ���������е�һ�γ��ֵ�λ�� 
		int Location (int x)
		{
			LinkNode r = linklist;
			int i = 0;
			while (r->data != x && r)
			{
				i++;
				r = r->next;
			}
			if (r)
				return i;
			else
				return -1;
		}
		//ɾ��Ԫ�� 
		void Delete (int x)
		{
			LinkNode r = linklist;
			LinkNode q = r->next; 
			while ( q->data != x && q)
			{
				r = r->next;
				q = q->next;
			}
			r->next = q->next;
			length--;
		}
		//��ȡ������ 
		int GetLength ()
		{
			return length;
		}
		//�ж��Ƿ�Ϊ�� 
		bool isEmpty()
		{
			return (linklist->next == NULL);
		}
		//��ת���� 
		void Reverse ()		
		{
			LinkNode r = linklist->next, p = NULL;	
			while (r)
			{
				linklist->next = p;
				p = linklist;
				linklist = r;
				r = r->next;
			}
			linklist->next = p;
		} 
		 //��ĳ��Ԫ�ص�ǰ�� 
		int Pre_Find(int x)
		{
			LinkNode r = linklist, s = linklist->next;
			if (x == r->data)
				return -1;
			while (s->data != x && s)
			{
				s = s->next;
				r = r->next;
			}
			return r->data;
	    }
	    //��ָ��Ԫ�صĺ�� 
	    int Next_Find (int x)
		{
			LinkNode r = linklist, s = linklist->next;
			while (x != r->data && s)
			{
				s = s->next;
				r = r->next;
			}
			if (!s)
				return -1;
			else
				return s->data;
		} 
		//��ӡ���� 
		void print ()
		{
			LinkNode r = linklist;
			while (r)
			{
				cout << r->data  << " "; 
				r = r->next;
			}
			cout << endl;
		}
		
};
int main ()
{
	List list;
	for (int i = 0; i < 10; i++)
	{
		list.Insert(i, i);
	}
	cout << "���������ֵ�ǣ�" << endl; 
	list.print();
	cout << "����ĳ����ǣ�" << list.GetLength()<< endl;
	cout << "Ԫ��9�������е�λ����" << list.Location(9) <<endl;
	list.Delete(7);
	cout << "ɾ��7��������ǣ�" << endl;
	list.print();
	cout << "ɾ������������ǣ�" << list.GetLength() << endl;
	cout << "λ��3��Ԫ���ǣ�" << list.GetData(3) << endl; 
	cout << "Ԫ��4��ǰһ��Ԫ���ǣ�" << list.Pre_Find(4) << endl;
	cout << "Ԫ��4�ĺ�һ��Ԫ���ǣ�" << list.Next_Find(4) << endl; 
	list.Reverse();
	cout << "��ת��������ǣ�" <<endl;
	list.print();
}
