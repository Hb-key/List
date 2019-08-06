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
	size_t size;      //��Ч���ݸ���
	size_t capacity;  //��������
 }SeqList;

void SeqListInit(SeqList* pList);//��ʼ��
void SeqListDestory(SeqList* pList);//����
void CheckCapacity(SeqList* pList);//��������Ƿ���Ҫ����

void SeqListPushBack(SeqList* pList, SLDataType data);//β��
void SeqListPopBack(SeqList* pList);//βɾ
void SeqListPushFront(SeqList* pList, SLDataType data);//ͷ��
void SeqListPopFront(SeqList* pList);//ͷɾ

size_t SeqListFind(SeqList* pList, SLDataType data);//��˳����в���ָ��Ԫ��
void SeqListInsert(SeqList* pList, size_t pos, SLDataType data);//��ָ��λ�ò���ָ��Ԫ��
void SeqListErase(SeqList* pList, size_t pos);//ɾ��ָ��λ�õ�Ԫ��
void SeqListRemove(SeqList* pList, SLDataType data);//ɾ��ָ��Ԫ��
void SeqListRemoveAll(SeqList* pList, SLDataType data);	//ɾ��˳���������ָ��Ԫ��
void SeqListModify(SeqList* pList, size_t pos, SLDataType data);//�޸�ָ��λ�õ�Ԫ��Ϊָ��ֵ
void SeqListPrint(SeqList* pList);//��ӡ˳���
void Reverse(SeqList* pList);//����˳���

void SeqListBubbleSort(SeqList* pList);//ð������˳���
size_t SeqListBinaryFind(SeqList* pList, SLDataType data);//��˳����ж��ֲ���ָ��Ԫ��