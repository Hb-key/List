#include"SeqList.h"

void test()
{
	SeqList pList;
	SeqListInit(&pList);//≥ı ºªØ

	SeqListPushBack(&pList, 1);
	SeqListPushBack(&pList, 2);
	SeqListPushBack(&pList, 2);
	SeqListPushBack(&pList, 2);
	SeqListPushBack(&pList, 2);
	SeqListPushBack(&pList, 5);
	SeqListPushBack(&pList, 2);
	SeqListPushBack(&pList, 3);
	SeqListPushBack(&pList, 4);
	SeqListPushBack(&pList, 5);
	SeqListPushBack(&pList, 6);

	SeqListPrint(&pList);
	printf("\n");
	SeqListPopBack(&pList);
	SeqListPopBack(&pList);
	SeqListPrint(&pList);
	printf("\n");

	SeqListInsert(&pList, 2, 9);
	SeqListPrint(&pList);
	printf("\n");

	SeqListRemoveAll(&pList, 2);
	SeqListPrint(&pList);
	printf("\n");


	/*SeqListErase(&pList, 3);
	SeqListPrint(&pList);
	printf("\n");

	printf("%d", SeqListFind(&pList, 4));
	printf("\n");

	SeqListRemove(&pList, 1);
	SeqListPrint(&pList);
	printf("\n");

	SeqListModify(&pList, 2, 6);
	SeqListPrint(&pList);
	printf("\n");

	SeqListBubbleSort(&pList);
	SeqListPrint(&pList);
	printf("\n");

	printf("%d", SeqListBinaryFind(&pList, 6));
	printf("\n");

	Reverse(&pList);
	SeqListPrint(&pList);
	printf("\n");*/
	
	/*SeqListPushFront(&pList, 4);
	SeqListPushFront(&pList, 5);
	SeqListPushFront(&pList, 6);
	SeqListPrint(&pList);
	printf("\n");
	SeqListPopFront(&pList);
	SeqListPopFront(&pList);
	SeqListPrint(&pList);
	printf("\n");*/

	SeqListDestory(&pList);
}

int main()
{
	test();
	return 0;
}

