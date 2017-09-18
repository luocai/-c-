#include <iostream>
#define MaxSize 100
using namespace std;
class SqStack {
	private :
		int data[MaxSize];
		int top;
	public :
		SqStack ()
		{
			top = -1;
		}
		void InitStack ()
		{
			top = -1;
		}
		bool isEmpty ()
		{
			return top == -1;
		}
		bool Push (int x)
		{
			if (top == MaxSize - 1)
			{
				cout << "栈已满";
				return false; 
			}
			top++;
			data[top] = x;
			return true;
		}
		bool Pop (int &x)
		{
			if (top == -1)
			{
				cout << "栈为空";
				return false;
			}
			x = data[top];
			top--;
			return true;
		}
		int GetTop ()
		{
			if (top == -1)
			{
				cout << "栈为空";
				return -1; 
			}
			return data[top];
		}
		void print ()
		{
			for (int i = 0; i <= top; i++)
				cout << data[i] << " ";
			cout << endl;
	    } 		
}; 
int main ()
{
	SqStack s;
	for (int i = 0; i < 5; i++)
		s.Push (i);
	cout << "栈中元素是：" << endl;
	s.print();
	int x = 0;
	s.Pop(x);
	cout << "弹出的元素是：" << x << endl;
	cout << "此时的栈顶元素是：" << s.GetTop() << endl; 
	cout << "栈为空吗？" << endl;
	if (s.isEmpty())
		cout << "yes" <<endl;
	else
		cout << "no" << endl;
	
}
