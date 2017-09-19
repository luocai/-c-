#include <iostream>
using namespace std;
typedef struct Node{
	int data;
	struct Node *next;
}Node,*ListNode;
class LiStack {
	private :
		ListNode Stack_top;
	public :
		LiStack ()
		{
			Stack_top = NULL;
		}
		void ClearStack ()
		{
			ListNode temp ;
			while (Stack_top)
			{
				temp = Stack_top;
				Stack_top = Stack_top->next;
				delete temp;  // ע���ڴ�Ļ���; 
			}
		}
		void Push (int x)
		{
			ListNode newnode = new Node;
			if (!newnode)
				return;
			newnode->data = x;
			newnode->next = Stack_top;
			Stack_top = newnode; 
		}
		void Pop (int &x)
		{
			if (Stack_top == NULL)
			{
				cout << "ջΪ��";
				return ;
			}
			ListNode temp = Stack_top;
			x = temp->data;
			Stack_top = Stack_top->next;
			delete temp;  //�ڴ�Ļ��գ� 
		}
		int Stack_size()
		{
			int length = 0;
			ListNode p = Stack_top;
			while (p)
			{
				length++;
				p = p->next;
			}
			return length;
		}
		int GetTop ()
		{
			if (Stack_top == NULL)
			{
				cout << "ջΪ��";
				return -1;
			}
			else
				return Stack_top->data;
	    } 
	    bool isEmpty ()
		{
			return Stack_top == NULL;
		} 
		void print ()
		{
			ListNode p = Stack_top;
			while (p)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
		~LiStack()
		{
			ListNode temp ;
			while (Stack_top)
			{
				temp = Stack_top;
				Stack_top = Stack_top->next;
				delete temp;
			}
	    }
};
int main ()
{
	LiStack stack;
	for (int i = 0; i < 10; i++)
		stack.Push(i);
	cout << "ջ��Ԫ���ǣ�" << endl;
	stack.print();
	cout << "ջ�ĳ����ǣ�" << stack.Stack_size() << endl; 
	int x;
	stack.Pop(x);
	cout << "������Ԫ���ǣ�" << x << endl;
	cout << "��ʱջ�Ĵ�С�ǣ�" << stack.Stack_size() << endl;
	cout << "��ʱ��ջ��Ԫ���ǣ�" << stack.GetTop() << endl;
	cout << "��ʱջΪ����" <<endl;
	if (stack.isEmpty()) 
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	stack.ClearStack();
	cout << "�����أ�" <<endl;
	if (stack.isEmpty()) 
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0; 
}
