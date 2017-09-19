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
				delete temp;  // 注意内存的回收; 
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
				cout << "栈为空";
				return ;
			}
			ListNode temp = Stack_top;
			x = temp->data;
			Stack_top = Stack_top->next;
			delete temp;  //内存的回收； 
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
				cout << "栈为空";
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
	cout << "栈中元素是：" << endl;
	stack.print();
	cout << "栈的长度是：" << stack.Stack_size() << endl; 
	int x;
	stack.Pop(x);
	cout << "弹出的元素是：" << x << endl;
	cout << "此时栈的大小是：" << stack.Stack_size() << endl;
	cout << "此时的栈顶元素是：" << stack.GetTop() << endl;
	cout << "此时栈为空吗？" <<endl;
	if (stack.isEmpty()) 
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	stack.ClearStack();
	cout << "现在呢？" <<endl;
	if (stack.isEmpty()) 
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0; 
}
