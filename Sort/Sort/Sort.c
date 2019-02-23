#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack *ps, STDataType x);
void StackPop(Stack* ps);
STDataType  StackTop(Stack* ps);
int StackEmpty(Stack* ps);

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	ps->_capacity = 0;
	ps->_top = 0;
	free(ps->_a);
	ps->_a = NULL;
}

void StackPush(Stack *ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = (ps->_capacity == 0 ? 4 : ps->_capacity * 2);
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	ps->_top--;
}

STDataType  StackTop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	return ps->_a[ps->_top - 1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return 0;
	else return 1;
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void sortPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end>=0)
		{
			if (a[end]>tmp)
			{
				a[end + 1] = a[end];
				end -= 1;
			}
			else break;
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap - 1; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end]>tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else break;
			}
			a[end + gap] = tmp;
		}
	}
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin<end)
	{
		int min = begin;
		int max = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[min] >a[i])
				min = i;
			if (a[max]<a[i])
				max = i;
		}
		Swap(&a[begin], &a[min]);
		if (begin == max)
			max = min;
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int son = 2 * parent + 1;
	while (son<n)
	{
		if (son + 1 < n&&a[son + 1] > a[son])
			son++;
		if (a[parent] < a[son])
		{
			Swap(&a[parent], &a[son]);
			parent = son;
			son = 2 * parent + 1;
		}
		else break;
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void BubbleSort(int* a, int n)
{
	int end = n - 1;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1]>a[i])
				Swap(&a[i - 1], &a[i]);
			    exchange = 1;
		}
		if (exchange == 0)
		{
			break;
		}
		end--;
	}
}

//直接快速排序
int PartSort1(int* a, int begin, int end)
{
	int key = begin;
	while (begin < end)
	{
		while (begin<end&&a[end] >= a[key])
			end--;
		while (begin<end&&a[begin] <= a[key])
			begin++;
		Swap(&a[end], &a[begin]);
	}
	Swap(&a[end], &a[key]);
	return end;
}

//三数取中法
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + (end - begin)/2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])  return mid;
		else if (a[begin]>a[end])  return begin;
		else   return  end;
	}
	//a[begin]>a[mid]
	else
	{
		if (a[mid]>a[end])  return mid;
		else if (a[end] > a[begin])  return begin;
		else return end;
	}
}
int PartSort2(int* a, int begin, int end)
{
	int key = begin;
	int mid = GetMidIndex(a,begin,end);
	Swap(&a[begin], &a[mid]);
	while (begin < end)
	{
		while (begin<end&&a[end] >= a[key])
			end--;
		while (begin<end&&a[begin] <= a[key])
			begin++;
		Swap(&a[end], &a[begin]);
	}
	Swap(&a[end], &a[key]);
	return end;
}

//挖坑法
int PartSort3(int* a, int begin, int end)
{
	int k = a[begin];
	while (begin < end)
	{
		while (begin<end&&a[end]>=k)
			end--;
		a[begin] = a[end];
		while (begin < end&&a[begin] <= k)
			begin++;
		a[end] = a[begin];
	}
	a[end] = k;
	return begin;
}
 
//前后指针法
int PartSort4(int* a, int begin,int end)
{
	int cur = begin + 1;
	int prev = begin;
	while (cur<=end)
	{
		if (a[cur] < a[begin]&&prev++!=cur)
			Swap(&a[cur], &a[prev]);
		cur++;
	}
	Swap(&a[prev], &a[begin]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	else
	{
		//int div = PartSort1(a, left, right);
		//int div = PartSort2(a, left, right);
		int div = PartSort3(a, left, right);
		//int div = PartSort4(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}

void QuickSort1(int* a, int left, int right)
{
	if (left - right < 1)
	{
		int div = PartSort3(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
	
}

//非递归的快速排序
void QSort(int* a, int left, int right)
{
	Stack st; 
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (StackEmpty(&st) != 0)
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int div = PartSort4(a, begin, end);
		//划分区间
		if (begin < (div-1))
		{
			StackPush(&st, div-1);
			StackPush(&st, begin);
		}
		if ((div + 1) < end)
		{
			StackPush(&st, end);
			StackPush(&st, div+1);
		}
	}
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)  return;
	int mid = begin + ((end - begin) >> 1);
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1,end, tmp);
	int b1 = begin, e1 = mid;
	int b2 = mid + 1, e2 = end;
	int index = begin;
	while (b1<=e1&&b2<=e2)
	{
		if (a[b1] < a[b2])  tmp[index++] = a[b1++];
		else  tmp[index++] = a[b2++];
	}
	while (b1 <= e1)
		tmp[index++] = a[b1++];
	while (b2 <= e2)
		tmp[index++] = a[b2++];
	index = begin;
	while (begin<=end)
		a[begin++] = tmp[index++];
}
void MergeSort(int* a, int n)
{ 
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
} 

void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i]>max)     max = a[i];
		if (a[i] < min)   min = a[i];
	}
	int range = max - min + 1;
	int *count = (int*)malloc(sizeof(int)*range);
	memset(count, 0, sizeof(int)*range);
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
			a[j++] = i + min;
	}
}

void sortTest()
{
	int a[] = {9,4,5, 3, 4, 5, 1, 2, 7, 6, 9, 8 };
	int size = sizeof(a) / sizeof(a[0]);
	printf("插入排序的结果是： ");
	InsertSort(a, size);
	sortPrint(a, size);
	int b[] = { 9, 4, 5, 3, 4, 5, 1, 8 };
	int size1 = sizeof(b) / sizeof(b[0]);
	printf("希尔排序的结果是： ");
	ShellSort(b, size1);
	sortPrint(b, size1);
	int c[] = { 1, 2, 5,6,9,3, 4 };
	int size2 = sizeof(c) / sizeof(c[0]);
	printf("选择排序的结果是： ");
	SelectSort(c, size2);
	sortPrint(c, size2);
	int d[] = { 1, 2,3,7, 6, 9, 3, 4 };
	int size3 = sizeof(c) / sizeof(c[0]);
	printf("堆排序的结果是：   ");
	HeapSort(d, size3);
	sortPrint(d , size3);
	int e[] = { 6,5,7,9,2,1,0 };
	int size4 = sizeof(e) / sizeof(e[0]);
	printf("冒泡排序的结果是： ");
	BubbleSort(e , size4);
	sortPrint(e , size4);
	int f[] = { 6, 5,3,5, 2, 1, 0 };
	int size5 = sizeof(f) / sizeof(f[0]);
	printf("快速排序的结果是：   ");
	QuickSort(f , 0, size5 - 1);
	//QuickSort1(f, 0, size5 - 1);
	//QSort(f, 0, size5 - 1);
	sortPrint(f , size5);
	int g[] = { 6, 5, 3, 5, 2, 1, 0 };
	int size6 = sizeof(g) / sizeof(g[0]);
	printf("计数排序的结果是：   ");
	CountSort(g, size6);
	sortPrint(g, size6);
	int h[] = { 6, 5, 3, 5, 2,7,8, 1, 0 };
	int size7 = sizeof(h) / sizeof(h[0]);
	printf("归并排序的结果是：   ");
	MergeSort(h, size7);
	sortPrint(h, size7);

}
