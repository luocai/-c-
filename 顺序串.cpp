#include <iostream>
#define MAX 100 
using namespace std;
class SqString {
	private :
		char data[MAX];
		int length;
	public :
		SqString ()
		{
			length = 0;
		}
		char* getData ()
		{
			return data;
		}
		void init(char a[])
		{
			for (int i = 0; i < sizeof (a) && a[i] != '\0'; i++)
			{
				data[i] = a[i];
				length++;
			}
				
	    } 
		void strCopy (SqString t)
		{
			for (int i = 0; i < t.length; i++)
			{
				data[i] = t.data[i];
			}
			length = t.length;
		}
		int getLength ()
		{
			return length;
		}
		void setLength (int x)
		{
			length = x;
		}
		void strCat (SqString s)
		{
			for (int i = length , j = 0; j < s.getLength(); j++, i++)
			{
				data[i] = s.getData()[j]; 
			}
			length = length + s.getLength();
		}
		SqString subStr (int m, int j)
		{
			SqString str;
			if (m <= 0 || j >length)
				return str;
			for (int i = m, k = 0; i <= j; i++, k++)
			{
				str.getData()[k] = data[i];
			}
			str.setLength(j - m);
		}
		void insert (SqString s, int i)
		{
			if (i <= 0 || s.getLength() > length)
				return;
			SqString str;
			for (int j = i; j < length ;j++)
			{
				str.getData()[j] = data[j]; 
			}
			for (int j = 0; j < s.getLength(); j++, i++)
			{
				data[i - 1] = s.getData()[j];
			}
			for (int j = 0; j < str.getLength(); j++, i++)
			{
				data[i+length-1] = str.getData()[j];
			}
			length = length + s.getLength();
		}
		void Delete (int i, int j)
		{
			if (i < 0 || j > length)
				return ;
			int temp = j - i;
			for (int k = j - 1; k < length; k++)
			{
				data[k - temp] = data[k];
			} 
			length = length - temp;
		}
		void print ()
		{
			for (int i = 0; i < length; i++)
			{
				cout << data[i];
			}
			cout << endl;
		}
}; 
int main ()
{
	char a[] = "hello";
	char b[] = "nihao";
	SqString str;
	SqString str1;
	str1.init(b);
	str.init(a);
	str.print();
	str1.print();
	cout << str.getData()[0] << endl;
//	str.strCopy(str1);
//	str.strCat(str1);
	str1.strCopy(str.subStr(1,3));
	str1.print();
	str.print();
	cout << str.getLength();
	return 0;
}
