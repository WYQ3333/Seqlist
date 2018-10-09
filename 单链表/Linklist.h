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

//接口函数
pLinklist BuyNewNode(LDataType data);//动态生成新节点
void InitLinklist(pLinklist *pL);//初始化单链表
void PushBackLinklist(pLinklist *pL, LDataType data);//尾插
void PushFrontLinklist(pLinklist *pL, LDataType data);//头插
void PopBackLinklist(pLinklist *pL);//尾删
void PopFrontLinklist(pLinklist *pL);//头删
void PrintLinklist(Linklist *pL);//打印单链表
pLinklist FindLinklist(pLinklist *pL, LDataType data);//查找指定元素,返回指定元素的位置
void InsertLinklist(pLinklist *pL, pLinklist p, LDataType data);//指定位置插入
void RemoveLinklist(pLinklist *pL, LDataType data);//删除第一个指定元素
void RemoveAllLinklist(pLinklist *pL, LDataType data);//删除所有的指定元素
int IsEmptyLinklist(pLinklist pL);//判断链表是否为空，为空返回1；不为空返回0；
void DestoryLinklist(pLinklist *pL);//销毁单链表

