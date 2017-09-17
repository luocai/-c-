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
		//指定位置插入一个元素 
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
		//头插法 
		void Insert (int x)
		{
			
			LinkNode newnode = new Node;
			newnode->data = x;
			newnode->next = linklist->next;
			linklist->next = newnode;
			length++;
		}
		//获取链表中给定位置的元素 
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
		//定位给定元素在链表中第一次出现的位置 
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
		//删除元素 
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
		//获取链表长度 
		int GetLength ()
		{
			return length;
		}
		//判断是否为空 
		bool isEmpty()
		{
			return (linklist->next == NULL);
		}
		//翻转链表 
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
		 //找某个元素的前驱 
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
	    //找指定元素的后继 
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
		//打印链表 
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
	cout << "当年链表的值是：" << endl; 
	list.print();
	cout << "链表的长度是：" << list.GetLength()<< endl;
	cout << "元素9在链表中的位置是" << list.Location(9) <<endl;
	list.Delete(7);
	cout << "删除7后的链表是：" << endl;
	list.print();
	cout << "删除后的链表长度是：" << list.GetLength() << endl;
	cout << "位置3的元素是：" << list.GetData(3) << endl; 
	cout << "元素4的前一个元素是：" << list.Pre_Find(4) << endl;
	cout << "元素4的后一个元素是：" << list.Next_Find(4) << endl; 
	list.Reverse();
	cout << "翻转后的链表是：" <<endl;
	list.print();
}
