//Linklist.c
#include"Linklist.h"
pLinklist BuyNewNode(LDataType data)//�����½ڵ�
{
	pLinklist NewNode = (pLinklist)malloc(sizeof(Linklist));
	if (NewNode == NULL)
	{
		printf("��̬�����ڴ�ռ�ʧ��\n");
		return;
	}
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
void InitLinklist(pLinklist *pL)//��ʼ��
{
	assert(pL != NULL);
	(*pL) = NULL;
}
void PushBackLinklist(pLinklist *pL, LDataType data)//β��
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
void PushFrontLinklist(pLinklist *pL, LDataType data)//ͷ��
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
int IsEmptyLinklist(pLinklist pL)//�ж��Ƿ�Ϊ������
{
	if (pL == NULL)
		return 1;
	return 0;
}
void PopBackLinklist(pLinklist *pL)//βɾ
{
	assert(pL != NULL);
	if (IsEmptyLinklist(*pL))//����Ϊ�գ�û�нڵ�
	{
		printf("����Ϊ�գ�ɾ������ʧ��\n");
		return;
	}
	pLinklist cur = *pL;
	pLinklist pre = NULL;//����cur��ǰһ���ڵ�
	if (cur->next == NULL)//��һ���ڵ�
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
void PopFrontLinklist(pLinklist *pL)//ͷɾ
{
	assert(pL != NULL);
	if (*pL == NULL)
	{
		printf("����Ϊ�գ�ɾ������ʧ��\n");
		return;
	}
	pLinklist cur = *pL;
	*pL = cur->next;
	free(cur);
	cur = NULL;
}
pLinklist FindLinklist(pLinklist *pL, LDataType data)//����ָ��Ԫ��,����ָ��Ԫ�ص�λ��
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
void InsertLinklist(pLinklist *pL, pLinklist p, LDataType data)//ָ��λ��ǰ�����
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
void RemoveLinklist(pLinklist *pL, LDataType data)//ɾ����һ��ָ��Ԫ��
{
	assert(pL != NULL);
	pLinklist cur = NULL;
	pLinklist p = *pL;
	pLinklist pre = NULL;
	cur = FindLinklist(pL, data);//�ҵ�Ҫɾ����ָ��Ԫ��
	if (cur == NULL)
	{
		printf("û�ҵ�Ҫɾ����ָ��Ԫ�أ�ɾ��ʧ��\n");
		return;
	}
	if (*pL == cur)//λ�ڵ�һ���ڵ�
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
void RemoveAllLinklist(pLinklist *pL, LDataType data)//ɾ�����е�ָ��Ԫ��
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
void PrintLinklist(Linklist *pL)//��ӡ������
{
	pLinklist cur = pL;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void DestoryLinklist(pLinklist *pL)//���ٵ����������ڴ����
{
	assert(pL != NULL);
	pLinklist cur = *pL;
	pLinklist pre = NULL;//����cur��ǰһ���ڵ�
	if (*pL == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	if (cur->next == NULL)//ֻ��һ���ڵ�
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
