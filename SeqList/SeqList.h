#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef size_t SLDataType;
#define DEFAULT_SIZE 5
#define INC_SIZE 2

typedef struct SeqList {
	SLDataType* array;
	size_t size;      //有效数据个数
	size_t capacity;  //数据容量
 }SeqList;

void SeqListInit(SeqList* pList);//初始化
void SeqListDestory(SeqList* pList);//销毁
void CheckCapacity(SeqList* pList);//检查容量是否需要增容

void SeqListPushBack(SeqList* pList, SLDataType data);//尾插
void SeqListPopBack(SeqList* pList);//尾删
void SeqListPushFront(SeqList* pList, SLDataType data);//头插
void SeqListPopFront(SeqList* pList);//头删

size_t SeqListFind(SeqList* pList, SLDataType data);//在顺序表中查找指定元素
void SeqListInsert(SeqList* pList, size_t pos, SLDataType data);//在指定位置插入指定元素
void SeqListErase(SeqList* pList, size_t pos);//删除指定位置的元素
void SeqListRemove(SeqList* pList, SLDataType data);//删除指定元素
void SeqListRemoveAll(SeqList* pList, SLDataType data);	//删除顺序表中所有指定元素
void SeqListModify(SeqList* pList, size_t pos, SLDataType data);//修改指定位置的元素为指定值
void SeqListPrint(SeqList* pList);//打印顺序表
void Reverse(SeqList* pList);//逆置顺序表

void SeqListBubbleSort(SeqList* pList);//冒泡排序顺序表
size_t SeqListBinaryFind(SeqList* pList, SLDataType data);//在顺序表中二分查找指定元素