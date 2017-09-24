#include <iostream>
using namespace std;
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}Node;
class DoubleList {
	private :
		Node *head;
		int length;
	public :
		DoubleList ()
		{
			head = new Node;
			head->left = NULL;
			head->right = NULL;
			length = 0;
		}
		void Insert (int x, int i)
		{
			Node *newnode = new Node;
			Node *p = head; //指示当前指针 
			newnode->data = x;
			if (head->right == NULL && head->left == NULL)
			{
				newnode->left = head;
				newnode->right = NULL;
				head->right = newnode;
			}
			else
			{
				for (int j = 1; j < i && p; j++)
					p = p->right;
				newnode->left = p;
				newnode->right = p->right;
				if (p->right)
					p->right->left = newnode;
				p->right = newnode;
			}
			length++;
		}
		void Delete (int x, int &y)
		{
			Node *p = head->right;
			while (p->data != x && p)
			{
				p = p->right;
			}
			y = p->data;
			p->left->right = p->right;
			p->right->left = p->left;
			length--;
			delete p; 
		}
		int Search (int x)
		{
			if (head->right == NULL)
			{
				cout << "链表为空，查找失败" ;
				return -1; 
			}
			Node *p = head->right;
			int i = 1;
			while (p->data != x && p)
			{
				p = p->right;
				i++;
			}
			if (p == NULL)
			{
				cout << "无此数" <<endl;
				return -1; 
			}
			return i;
		}
		int GetData (int i)
		{
			if (i <= 0 || i >= length)
			{
				cout << "越界" <<endl;
				return -1;
			}
			Node *p = head->right;
			int j = 1;
			while (j < i && p)
			{
				p = p->right;
				j++;
			}
			return p->data;
		}
		int GetLength ()
		{
			return length;
		}
		bool isEmpty ()
		{
			return head->right == NULL;
		}
		void Clear ()
		{
			
			while (head->right != NULL)
			{
				head = head->right;
				delete head->left;
			}
			length = 0;
		}
		void print ()
		{
			Node* p = head->right;
			while (p->right != NULL)
			{
				cout << p->data << " ";
				p = p->right;
			}
			cout << endl; 
		}
}; 
int main ()
{
	DoubleList list;
	for (int i = 0; i < 10; i++)
		list.Insert(i, i);
	list.print();
	
	return 0;
}
