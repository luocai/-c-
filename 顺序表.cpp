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
		//��� 
		void Clear (){
			length = 0;
		}
		//���� 
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
		//��ֵ���� 
		int Search (int x){
			for (int i = 0; i < length; i++){
				if (data[i] == x)
					return i;
			}
			return -1;
		}
		//˳���Ĵ�С 
		int GetLength (){
			return length;
		}
		//ɾ�� 
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
    cout << "˳����ֵΪ��" << endl;
	list.print();
	list.Delete(1);
	cout << "ɾ���±�Ϊ 1 ������"  <<endl; 
	list.print();
	int len = list.GetLength();
	cout << "˳���ĳ���Ϊ��" << len << endl;
	int pos = list.Search(9); 
	cout << "��������9���±���:" << pos << endl; 
	list.Clear();
	cout << "��պ� ˳���ĳ����ǣ�" << list.GetLength() << endl;
	return 0;
}
