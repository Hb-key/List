#include"SeqList.h"

//初始化顺序表
void SeqListInit(SeqList* pList)
{
	assert(pList);
	pList->size = 0;
	pList->array = (SLDataType *)malloc(sizeof(SLDataType)*DEFAULT_SIZE);
	if (!pList->array) 
	{
		perror("malloc");
		return;
	}
	memset(pList->array, 0, sizeof(SLDataType)*DEFAULT_SIZE);
}

//销毁顺序表
void SeqListDestory(SeqList* pList)
{
	free(pList->array);
	pList = NULL;
}

//检查顺序表的容量
void CheckCapacity(SeqList* pList)
{
	assert(pList);
	if (pList->size == pList->capacity)
	{
		SLDataType *ret = (SLDataType *)realloc(pList->array, sizeof(SLDataType)*DEFAULT_SIZE + INC_SIZE);
		if (!ret)
		{
			perror("malloc");
		}
		pList->array = ret;
		pList->capacity += INC_SIZE;
	}
}

//打印顺序表
void SeqListPrint(SeqList* pList)
{
	assert(pList);
	for (size_t i = 0; i < pList->size; i++)
	{
		printf("%d ", pList->array[i]);
	}
	
}

//尾插
void SeqListPushBack(SeqList* pList, SLDataType data)
{
	assert(pList);
	if (pList->size == pList->capacity)
	{
		CheckCapacity(pList);
	}
	pList->array[pList->size] = data;
	pList->size++;
}

//尾删
void SeqListPopBack(SeqList* pList)
{
	assert(pList);
	if (pList->size == 0)
	{
		printf("顺序表内无数据\n");
		return;
	}
	pList->size--;
}

//头插
void SeqListPushFront(SeqList* pList, SLDataType data)
{
	assert(pList);
	if (pList->size == pList->capacity)
	{
		CheckCapacity(pList);
	}
	//注意这里的循环条件是从后向前的，把前一个值赋给后一个值，只能是i-1赋给i
	//而不可以是i赋给i+1，两者本质上是一样的，但后者在赋值的过程中，会出现越界的情况，程序会崩溃
	for (int i = pList->size; i > 0; i--)
	{
		pList->array[i] = pList->array[i - 1];
	}
	pList->array[0] = data;
	pList->size++;
}

//头删
void SeqListPopFront(SeqList* pList)
{
	assert(pList);
	if (pList->size == 0)
	{
		printf("顺序表内无数据\n");
		return;
	}
	for (size_t i = 0; i < pList->size; i++)
	{
		pList->array[i] = pList->array[i + 1];
	}
	pList->size--;
}

//查找
size_t SeqListFind(SeqList* pList, SLDataType data)
{
	assert(pList);
	for (size_t i = 0; i < pList->size; ++i)
	{
		if (pList->array[i] == data)
			return i + 1;
	}
	return -1;
}

//在指定位置插入元素
void SeqListInsert(SeqList* pList, size_t pos, SLDataType data)
{
	assert(pList);
	if (pList->size == pList->capacity)
	{
		CheckCapacity(pList);
	}
	for (size_t i = pList->size; i > pos - 1; --i)
	{
		pList->array[i] = pList->array[i - 1];
	}
	pList->array[pos - 1] = data;
	pList->size++;
}

//删除指定位置的元素
void SeqListErase(SeqList* pList, size_t pos)
{
	assert(pList);
	if (pos>0 && pos<pList->size)
	{
		for (size_t i = pos - 1; i < pList->size; ++i)
		{
			pList->array[i] = pList->array[i + 1];
		}	
		pList->size--;
	}
}

//删除指定元素
void SeqListRemove(SeqList* pList, SLDataType data)
{
	assert(pList);
	size_t pos = SeqListFind(pList, data);
	if (pos)
	{
		SeqListErase(pList, pos);
	}
}

//删除数组中所有指定元素
void SeqListRemoveAll(SeqList* pList, SLDataType data)
{
	assert(pList);
	for (size_t i = 0; i < pList->size; i++)
	{
		size_t i = SeqListFind(pList, data);
		if (i < 0)
		{
			printf("没有找到");
			return;
		}
		SeqListErase(pList, i);
	}
}

//修改指定位置的元素为给定元素
void SeqListModify(SeqList* pList, size_t pos, SLDataType data)
{
	assert(pList);
	if (pos>0 && pos < pList->size)
	{
		for (size_t i = pos - 1; i < pList->size; ++i)
		{
			pList->array[pos] = data;
			return;
		}	
	}
	else
	{
		printf("wrong pos");
	}
}

void Swap(size_t *a, size_t *b)
{
	size_t tmp = *a;
	*a = *b;
	*b = tmp;
}

//逆置顺序表
void Reverse(SeqList* pList)
{
	assert(pList);
	size_t left = 0;
	size_t right = pList->size - 1;
	
	while(left<right)
	{
		Swap(pList->array + left, pList->array + right);
		left++;
		right--;
	}
}

//冒泡排序顺序表
void SeqListBubbleSort(SeqList* pList)
{
	assert(pList);
	for (size_t i = 1; i < pList->size - 1; ++i)
	{
		size_t flag = 0;
		for (size_t j = 0; j < pList->size - i; ++j)
		{
			if (pList->array[j] > pList->array[j + 1])
			{
				Swap(pList->array + j, pList->array + j + 1);
				flag++;
			}
		}
		if (flag == 1)
		{
			return;
		}
	}
}

//二分查找指定元素
size_t SeqListBinaryFind(SeqList* pList, SLDataType data)
{
	assert(pList);
	size_t left = 0;
	size_t right = pList->size - 1;
	SeqListBubbleSort(pList);
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (pList->array[mid] < data)
			left = mid + 1;
		else if (pList->array[mid] > data)
			right = mid - 1;
		else
			return mid + 1;
	}
	return -1;
}