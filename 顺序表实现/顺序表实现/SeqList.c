#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
// 基本增删查改接口 
void SeqListInit(SeqList* psl, size_t capacity)   //初始化：开辟空间且有效个数为0
{
	assert(psl);
	psl->_array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	psl->_size = 0;                                                           
	psl->_capacity = capacity;
}

void SeqListDestory(SeqList* psl)
{
	assert(psl);
	if (psl->_array)
	{
		free(psl->_array );
		psl->_array = NULL;
		psl->_capacity = psl->_size = 0;
	}
	printf("已销毁！\n");
}

void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->_size == psl ->_capacity)
	{
		psl->_capacity *= 2;
		psl->_array = realloc(psl->_array, psl->_capacity*sizeof(SLDataType));//需要传字节数
		assert(psl->_array);                                                        
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->_array[psl->_size++] = x;
	//psl->_size++;    SeqListInsert(psl,psl->_size,x);

}

void SeqListPopBack(SeqList* psl)
{
	assert(psl&&psl->_size>0);

	//psl->_array[psl->_size - 1] = 0;
	psl->_size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	int end = psl->_size - 1;
	//不能用size_t定义end，因为它无符号，故永远不可能<0，循环无法停止
	while (end>=0)
	{
		psl->_array[end + 1] = psl->_array[end];
		end--;
	}
	psl->_array[0] = x;
	psl->_size++;
}

void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	CheckCapacity(psl);
	size_t begain = 0;
	while (begain<  psl->_size-1)
	{
		psl->_array[begain] = psl->_array[begain + 1];
		begain++;
	}
	psl->_size--;
}

//SLDataType SeqListFind(SeqList* psl, SLDataType x)
//{
//	assert(psl);
//	for (size_t i = 0; i < psl->_size ;i++)
//	{
//		if (psl->_array[i] == x)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
int  SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (size_t i = 0; i < psl->_size; i++)
	{
		if (psl->_array[i] == x)
		{
			return 1;
		}
	}
	return 0;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl&&pos<=psl->_size);
	CheckCapacity(psl);
	int end = psl->_size-1;
	while (end>=(int)pos)
	{
		psl->_array[end+1] = psl->_array[end ];
		end--;
	}
	psl->_array[pos] = x;
	psl->_size++;
}

void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl&&pos <= psl->_size);
	size_t begin = pos;
	while (begin<psl->_size)
	{
		psl->_array[begin ] = psl->_array[begin+1];
		begin++;
	}
	psl->_size--;
}

void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);
	size_t cur = 0;
	size_t dst = 0;
	while (cur < psl->_size)
	{
		if (psl->_array[cur] != x)
		{
			psl->_array[dst] = psl->_array[cur];
			dst++;
		}
		cur++;
	}
	psl->_size = dst;
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl&&pos<psl->_size);
	psl->_array[pos] = x;
}

void SeqListPrint(SeqList* psl)
{
	assert(psl);
	for (size_t i = 0; i < psl->_size; i++)
	{
		printf("%d ", psl->_array[i]);
	}
	printf("\n");
}

void SeqListTest1()
{
	SeqList s1;
	SLDataType find = 0;
	SeqListInit(&s1, 10);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPushBack(&s1, 6);
	SeqListPushBack(&s1, 7);
	SeqListPushBack(&s1, 8);
	SeqListPushBack(&s1, 9);
	SeqListPushBack(&s1, 9);
	SeqListPushBack(&s1, 9);
	printf("尾插的结果是：");
	SeqListPrint(&s1);

	SeqListPopBack(&s1);
	printf("尾删的结果是：");
	SeqListPrint(&s1);

	SeqListPushFront(&s1, 0);
	SeqListPushFront(&s1, 9);
	printf("头插的结果是：");
	SeqListPrint(&s1);

	SeqListPopFront(&s1);
	printf("头删的结果是：");
	SeqListPrint(&s1);

	/*printf("找%d 的结果是：",7);
	find=SeqListFind(&s1, 7);
	if (find< 0)
	{
		printf("找不到！\n");
	}
	else
	{
		printf("找到了！\n");
	}*/
	printf("找%d 的结果是：", 11);
    int y=SeqListFind(&s1, 11);
	if (y == 1)
		printf("找到了！\n");
	else printf("找不到！  \n");
	
	
	SeqListInsert(&s1, 4, 1);
	printf("在下标为4位置插入1的结果是：");
	SeqListPrint(&s1);

	SeqListErase(&s1, 4);
	printf("把下标为4位置删除的结果是：");
	SeqListPrint(&s1);

	SeqListRemove(&s1, 9);
	printf("删除所有9的结果是：");
	SeqListPrint(&s1);

	SeqListModify(&s1, 4, 9);
	printf("将第4个位置的值修改为9：");
	SeqListPrint(&s1);

	SeqListBubbleSort(&s1);
	printf("排序后的结果为：");
	SeqListPrint(&s1);

	printf("二分查找5的结果：");
	int s3 = SeqListBinaryFind(&s1, 5);
	if (s3 == 1)
		printf("找到了！  \n");
	else
		printf("找不到！  \n");
	printf("二分查找11的结果：");
	int s2 = SeqListBinaryFind(&s1, 11);
	if (s2 == 1)
		printf("找到了！  \n");
	else
		printf("找不到！  \n");

	SeqListRemoveAll(&s1, 0);
	printf("删除所有0的结果是：");
	SeqListPrint(&s1);

    int f=SeqListEmpty(&s1);
	if (f == 0)
		printf("顺序表已空！  \n");
	else
		printf("顺序表未空！  \n");

	SeqListDestory(&s1);


}

void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);
	size_t end = psl->_size - 1;
	while (end)
	{
		int exchange = 0;
		for (size_t i = 0; i < psl->_size-1; i++)
		{
			if (psl->_array[i]>psl->_array[i + 1])
			{
				SLDataType tmp = psl->_array[i];
				psl->_array[i] = psl->_array[i + 1];
				psl->_array[i + 1] = tmp;
				exchange = 1;
			}
		} 
		if (exchange == 0)
			break;
		end--;
	}
}

int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	size_t left = 0;
	size_t right = psl->_size - 1;
	while (left<=right)
	{
		size_t mid = (left + right) / 2;
		if (psl->_array[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->_array[mid] > x)
		{
			right = mid-1;
		}
		else 
		{
			return 1;
			break;
		}
	}
	return 0;
}

// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	assert(psl);
	size_t i = 0;
	while (i<psl->_size)
	{
		if (psl->_array[i] == x)
		{
			for (size_t j = i; j < psl->_size; j++)
			{
				psl->_array[j] = psl->_array[j + 1];
			}
			psl->_size--;
		}
		else
			i++;
	}
	/*size_t cur = 0;
	size_t dst = 0;
	while (cur < psl->_size)
	{
		if (psl->_array[cur] != x)
		{
			psl->_array[dst] = psl->_array[cur];
			dst++;
		}
		cur++;
	}
	psl->_size = dst;*/
}

int SeqListEmpty(SeqList* psl)
{
	assert(psl);
	if (psl->_size == 0)
	{
		return  0;
	}
	else
		return 1;
}