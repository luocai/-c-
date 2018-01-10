#include <iostream>
#include <vector>
#define max 1000
#define INF 32767 //����� 
using namespace std; 
typedef struct node{
	int edges[max][max];
	int n;
	int e;
	node(){
		for (int i = 0; i < max; i++)
		{
			for (int j = 0; j < max; j++)
			{
				if (i != j)
			 		edges[i][j] = INF;
			 	else
			 		edges[i][j] = 0;
			}
		}
	}
}Mgraph;
Mgraph g;
void creatGraph()
{
	int n,m = 0;
	cout << "��������Ҫ����ıߵ���Ŀ��" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int s, e, v;
		cout << "�������" << i+1 << "���ߵ���� �յ� Ȩֵ���м�ո������" << endl;
		cin >> s >> e >> v;
		if (s > m)// m ����ͼ�����е�����ţ�������ĸ��� 
			m = s;
		if (e > m)
			m = e;
		g.edges[s][e] = v;
		g.edges[e][s] = v;
	}
	g.e = n*2;
	g.n = m + 1; 
}
void print()
{
	cout << endl;
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			if(g.edges[i][j] == INF)
				cout << "N "; 
			else cout << g.edges[i][j] << " ";
		}
		cout <<endl;
	}
}
void prim(int v)//����Ϊ��ʼ�Ľڵ��� 
{
	int lowcost[max]; // �����㵽�Ѿ�����ĵ����Сֵ 
	int closest[max]; // �Ѿ��������ĵ㼯��
//	closest[0] = v;
	int k = 0;//  ��¼��������ĵ� 
	int min ;// ��Сֵ 
	for (int i = 0; i < g.n; i++)
	{
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for (int i = 1; i < g.n; i++)
	{
		min = INF;
		for (int j = 0 ; j < g.n; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;  // ����һ��������С�������ĵ� 
			}
		} 
		lowcost[k] = 0;
		cout << "��(" << closest[k] << ", " << k << ")Ȩֵ��" << min <<endl; 
		for (int j = 0; j < g.n; j++)
		{
			if(g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])
			{
				lowcost[j] = g.edges[k][j];  // ���������㵽�������ľ��� 
				closest[j] = k;  // ���������ĵ� 
			}
		} 
	}
	
}
int main ()
{
	creatGraph();
	cout << "�ڽӾ������£�" <<endl;
	print();
	cout << endl;
	cout << "���������£�" <<endl <<endl; 
	prim(0);
	
	return 0;
}
//10
//0 1 6
//0 2 1
//0 3 5
//1 2 5
//3 2 5
//1 4 3
//4 2 6
//4 5 6
//5 2 4
//5 3 2

