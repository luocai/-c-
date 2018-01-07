#include <iostream>
using namespace std;
void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void insertsort(int a[], int n)
{
	int i, j;
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		j = i - 1;
		while (temp < a[j] && j >= 0)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}
void selectsort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void bubblesort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
void bubblesort1(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;
 			}
 			
		}
		if (flag == 0)
		{
			return;
		}
	}
}
void merge(int a[], int low,int mid, int high)
{
	int i = low, j= mid + 1, k = 0;
	int *temp = new int[high - low];
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= high) 
		temp[k++] = a[j++];
//	k = 0; 
//	for (i = low; i < low + k; i++, k++)
//		a[i] = temp[k];
	for (i = 0; i < k; i++)
	{
		a[low+i] = temp[i];
	}
}
void mergesort(int a[], int low, int high)
{
	
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid+1, high);
		merge(a, low,mid,high);
	}
	
}

int adjust(int a[], int low, int high)
{
	int i = low, j = high;
	int x = a[i];
	while (i < j)
	{
		while (a[j] >= x && i < j)
			j--;
		a[i] = a[j];
		while (a[i] <= x && i < j)
			i++;
		a[j] = a[i];
	}
	a[i] = x;
	return i;
}
void quicksort(int a[], int low, int high)
{
	if (low < high)
	{
		int i = adjust(a, low ,high);
		quicksort(a, low, i-1);
		quicksort(a, i+1, high);
	}
}
void quick_sort(int a[], int low, int high)  
{  
	int i = low, j = high;
	int x = a[i];
    if (low < high)
    {
    	while (i < j)
    	{
    		while (i < j && a[j] >= x)
	    		j--;
	    	a[i] = a[j];
	    	while (i < j && a[i] <= x)
	    		i++;
	    	a[j] = a[i];
		}
    	a[i] = x;
    	quick_sort(a, low, i-1);
    	quick_sort(a, i+1, high);
	}
}  
void shellsort(int a[], int n)
{
	int i, j , k,temp, gap;
	for (gap = n/2; gap > 0; gap /= 2)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i +gap; j < n; j += gap)
			{
				temp = a[j];
				k = j - gap;
				while ( a[k] > temp && k >= 0)
				{
					a[k+gap] = a[k];
					k = k - gap;
				}
				a[k+gap] = temp;
			}
		}
	}
}
void heapadjust(int a[], int s, int n)
{
	int j, t;
	while (2*s+1 < n)
	{
		j = 2*s + 1;
		if (j+1 < n)
		{
			if (a[j] < a[j+1])
				j++;
		}
		if (a[s] < a[j])
		{
			t = a[s];
			a[s] = a[j];
			a[j] = t;
			s = j;
		}
		else
			break;
	}
}
void heapsort(int a[], int n)
{
	int t;
	for (int i = n / 2 - 1; i >= 0; i--)
		heapadjust(a, i, n);
	for (int i = n - 1; i > 0; i--)
	{
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		heapadjust(a, 0, i);
	}
}
int main ()
{
	int a[10] = {4,1,9,8,2,3,5,6,7,10};
//	insertsort(a, 10);
//	selectsort(a, 10);
//	bubblesort(a, 10);
//	bubblesort1(a, 10);
//	mergesort(a, 0, 9);
//	quicksort(a, 0, 9);
//	quick_sort(a, 0, 9);
//	shellsort(a,10);
	heapsort(a, 10);
	print(a, 10); 
	
	return 0;
}
