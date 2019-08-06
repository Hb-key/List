#include"SeqList.h"

//��ʼ��˳���
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

//����˳���
void SeqListDestory(SeqList* pList)
{
	free(pList->array);
	pList = NULL;
}

//���˳��������
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

//��ӡ˳���
void SeqListPrint(SeqList* pList)
{
	assert(pList);
	for (size_t i = 0; i < pList->size; i++)
	{
		printf("%d ", pList->array[i]);
	}
	
}

//β��
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

//βɾ
void SeqListPopBack(SeqList* pList)
{
	assert(pList);
	if (pList->size == 0)
	{
		printf("˳�����������\n");
		return;
	}
	pList->size--;
}

//ͷ��
void SeqListPushFront(SeqList* pList, SLDataType data)
{
	assert(pList);
	if (pList->size == pList->capacity)
	{
		CheckCapacity(pList);
	}
	//ע�������ѭ�������ǴӺ���ǰ�ģ���ǰһ��ֵ������һ��ֵ��ֻ����i-1����i
	//����������i����i+1�����߱�������һ���ģ��������ڸ�ֵ�Ĺ����У������Խ����������������
	for (int i = pList->size; i > 0; i--)
	{
		pList->array[i] = pList->array[i - 1];
	}
	pList->array[0] = data;
	pList->size++;
}

//ͷɾ
void SeqListPopFront(SeqList* pList)
{
	assert(pList);
	if (pList->size == 0)
	{
		printf("˳�����������\n");
		return;
	}
	for (size_t i = 0; i < pList->size; i++)
	{
		pList->array[i] = pList->array[i + 1];
	}
	pList->size--;
}

//����
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

//��ָ��λ�ò���Ԫ��
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

//ɾ��ָ��λ�õ�Ԫ��
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

//ɾ��ָ��Ԫ��
void SeqListRemove(SeqList* pList, SLDataType data)
{
	assert(pList);
	size_t pos = SeqListFind(pList, data);
	if (pos)
	{
		SeqListErase(pList, pos);
	}
}

//ɾ������������ָ��Ԫ��
void SeqListRemoveAll(SeqList* pList, SLDataType data)
{
	assert(pList);
	for (size_t i = 0; i < pList->size; i++)
	{
		size_t i = SeqListFind(pList, data);
		if (i < 0)
		{
			printf("û���ҵ�");
			return;
		}
		SeqListErase(pList, i);
	}
}

//�޸�ָ��λ�õ�Ԫ��Ϊ����Ԫ��
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

//����˳���
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

//ð������˳���
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

//���ֲ���ָ��Ԫ��
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