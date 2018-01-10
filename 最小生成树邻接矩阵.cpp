#include <iostream>
#include <vector>
#define max 1000
#define INF 32767 //无穷大 
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
	cout << "请输入您要输入的边的数目：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int s, e, v;
		cout << "请输入第" << i+1 << "条边的起点 终点 权值（中间空格隔开）" << endl;
		cin >> s >> e >> v;
		if (s > m)// m 就是图的行列的最大编号，即顶点的个数 
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
void prim(int v)//参数为开始的节点编号 
{
	int lowcost[max]; // 各个点到已经处理的点的最小值 
	int closest[max]; // 已经加入树的点集合
//	closest[0] = v;
	int k = 0;//  记录即将加入的点 
	int min ;// 最小值 
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
				k = j;  // 找下一个加入最小生成树的点 
			}
		} 
		lowcost[k] = 0;
		cout << "边(" << closest[k] << ", " << k << ")权值是" << min <<endl; 
		for (int j = 0; j < g.n; j++)
		{
			if(g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])
			{
				lowcost[j] = g.edges[k][j];  // 更新其他点到生成树的距离 
				closest[j] = k;  // 更新依附的点 
			}
		} 
	}
	
}
int main ()
{
	creatGraph();
	cout << "邻接矩阵如下：" <<endl;
	print();
	cout << endl;
	cout << "生成树如下：" <<endl <<endl; 
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

