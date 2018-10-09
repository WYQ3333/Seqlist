//Linklist.c
#include"Linklist.h"
pLinklist BuyNewNode(LDataType data)//生成新节点
{
	pLinklist NewNode = (pLinklist)malloc(sizeof(Linklist));
	if (NewNode == NULL)
	{
		printf("动态开辟内存空间失败\n");
		return;
	}
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
void InitLinklist(pLinklist *pL)//初始化
{
	assert(pL != NULL);
	(*pL) = NULL;
}
void PushBackLinklist(pLinklist *pL, LDataType data)//尾插
{
	assert(pL != NULL);
	pLinklist NewNode = BuyNewNode(data);
	if (*pL == NULL)
	{
		*pL = NewNode;
		return;
	}
	pLinklist cur = *pL;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = NewNode;
}
void PushFrontLinklist(pLinklist *pL, LDataType data)//头插
{
	assert(pL != NULL);
	pLinklist NewNode = BuyNewNode(data);
	if (*pL == NULL)
	{
		*pL = NewNode;
		return;
	}
	NewNode->next = *pL;
	*pL = NewNode;
}
int IsEmptyLinklist(pLinklist pL)//判断是否为空链表
{
	if (pL == NULL)
		return 1;
	return 0;
}
void PopBackLinklist(pLinklist *pL)//尾删
{
	assert(pL != NULL);
	if (IsEmptyLinklist(*pL))//链表为空，没有节点
	{
		printf("链表为空，删除操作失败\n");
		return;
	}
	pLinklist cur = *pL;
	pLinklist pre = NULL;//保存cur的前一个节点
	if (cur->next == NULL)//有一个节点
	{
		*pL = NULL;
		free(cur);
		cur = NULL;
		return;
	}
	while (cur->next)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = NULL;
	free(cur);
	cur = NULL;
}
void PopFrontLinklist(pLinklist *pL)//头删
{
	assert(pL != NULL);
	if (*pL == NULL)
	{
		printf("链表为空，删除操作失败\n");
		return;
	}
	pLinklist cur = *pL;
	*pL = cur->next;
	free(cur);
	cur = NULL;
}
pLinklist FindLinklist(pLinklist *pL, LDataType data)//查找指定元素,返回指定元素的位置
{
	assert(pL != NULL);
	pLinklist cur = *pL;
	while (cur)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void InsertLinklist(pLinklist *pL, pLinklist p, LDataType data)//指定位置前面插入
{
	assert(pL != NULL);
	pLinklist NewNode = BuyNewNode(data);
	pLinklist cur = *pL;
	while (cur->next != p)
	{
		cur = cur->next;
	}
	NewNode->next = p;
	cur->next = NewNode;
}
void RemoveLinklist(pLinklist *pL, LDataType data)//删除第一个指定元素
{
	assert(pL != NULL);
	pLinklist cur = NULL;
	pLinklist p = *pL;
	pLinklist pre = NULL;
	cur = FindLinklist(pL, data);//找到要删除的指定元素
	if (cur == NULL)
	{
		printf("没找到要删除的指定元素，删除失败\n");
		return;
	}
	if (*pL == cur)//位于第一个节点
	{
		*pL= cur->next;
		free(cur);
		cur = NULL;
		return;
	}
	while (p!= cur)
	{
		pre = p;
		p = p->next;
	}
	pre->next = cur->next;
	free(cur);
	cur = NULL;
}
void RemoveAllLinklist(pLinklist *pL, LDataType data)//删除所有的指定元素
{
	assert(pL != NULL);
	pLinklist cur = NULL;
	pLinklist p = *pL;
	pLinklist pre = *pL;
	while (p)
	{
		
		if (p->data == data && (*pL) == p)
		{
			pre = p;
			p = p->next;
			*pL = p;
			free(pre);
			pre = NULL;
		}
		else if (p->data == data)
		{
			cur = p;
			p = p->next;
			pre->next = p;
			free(cur);
			cur = NULL;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}

}
void PrintLinklist(Linklist *pL)//打印单链表
{
	pLinklist cur = pL;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void DestoryLinklist(pLinklist *pL)//销毁单链表，放置内存溢出
{
	assert(pL != NULL);
	pLinklist cur = *pL;
	pLinklist pre = NULL;//保存cur的前一个节点
	if (*pL == NULL)
	{
		printf("链表为空\n");
		return;
	}
	if (cur->next == NULL)//只有一个节点
	{
		*pL = NULL;
		free(cur);
		cur = NULL;
		return;
	}
	while (cur)
	{
		pre = cur;
		cur = cur->next;
		free(pre);
		pre = NULL;
	}
}
