#include <iostream>
#define MaxSize 100
using namespace std;
class SqList {
	private :
		int data[MaxSize];
		int length;
	public :
		SqList (){
			length = 0;
		}
		//清空 
		void Clear (){
			length = 0;
		}
		//插入 
		int Insert (int x, int j){
			if (j < 0 || j > length)
			return 0;
			int i = length;
			while (i > j){
				data[i] = data[i - 1];
				i--;
			}
			data[i] = x; 
			length++;
			return 1;
		}
		//按值查找 
		int Search (int x){
			for (int i = 0; i < length; i++){
				if (data[i] == x)
					return i;
			}
			return -1;
		}
		//顺序表的大小 
		int GetLength (){
			return length;
		}
		//删除 
		int Delete (int j){
			if (j < 0 || j > length - 1)
				return 0;
			int i = 0;
			while ( i < j)
				i++;
			while (i < length - 1){
				data[i] = data[i+1]; 
				i++; 
			}
			length--;
			return 1;
		}
		void print (){
			for (int i = 0; i < length; i++){
				cout << data[i] << " ";
			}
			cout << endl;
		}
};

int main ()
{
	SqList list;
	list.Insert(1, 0);
	list.Insert(4, 1);
    list.Insert(5, 2);
    list.Insert(9, 1);
    cout << "顺序表的值为：" << endl;
	list.print();
	list.Delete(1);
	cout << "删除下标为 1 的数后："  <<endl; 
	list.print();
	int len = list.GetLength();
	cout << "顺序表的长度为：" << len << endl;
	int pos = list.Search(9); 
	cout << "查找数字9的下标是:" << pos << endl; 
	list.Clear();
	cout << "清空后 顺序表的长度是：" << list.GetLength() << endl;
	return 0;
}
