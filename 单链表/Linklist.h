//Linklist.h
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int LDataType;
typedef struct Linklist
{
	LDataType data;
	struct Linklist *next;
}Linklist, *pLinklist;

//�ӿں���
pLinklist BuyNewNode(LDataType data);//��̬�����½ڵ�
void InitLinklist(pLinklist *pL);//��ʼ��������
void PushBackLinklist(pLinklist *pL, LDataType data);//β��
void PushFrontLinklist(pLinklist *pL, LDataType data);//ͷ��
void PopBackLinklist(pLinklist *pL);//βɾ
void PopFrontLinklist(pLinklist *pL);//ͷɾ
void PrintLinklist(Linklist *pL);//��ӡ������
pLinklist FindLinklist(pLinklist *pL, LDataType data);//����ָ��Ԫ��,����ָ��Ԫ�ص�λ��
void InsertLinklist(pLinklist *pL, pLinklist p, LDataType data);//ָ��λ�ò���
void RemoveLinklist(pLinklist *pL, LDataType data);//ɾ����һ��ָ��Ԫ��
void RemoveAllLinklist(pLinklist *pL, LDataType data);//ɾ�����е�ָ��Ԫ��
int IsEmptyLinklist(pLinklist pL);//�ж������Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0��
void DestoryLinklist(pLinklist *pL);//���ٵ�����

