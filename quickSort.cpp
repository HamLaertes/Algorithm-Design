#include<stdio.h>
#include<stdlib.h>
void QuickSort(int a[], int left, int right)
{
	int i;
	int j;
	i = left;
	j = right;
	int temp;
	int t;
	temp = a[left];
	if(left > right)
		return;
	while(j > i)
	{
		while(a[j] > temp && j > i)
			j --;
		while(a[i] <= temp && i < j)
			i ++;
		if(j > i)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;
	QuickSort(a, left, (i - 1));
	QuickSort(a, (i + 1), right);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int a[n];
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	QuickSort(a, 0, (n - 1));
	for(i = 0; i < n; i ++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;	
}