//test.c���Ժ���
#include"Linklist.h"

void test()
{
	pLinklist cur = NULL;//��������FindLinklist�ķ���ֵ
	Linklist *first = NULL;
	InitLinklist(&first);//��ʼ��
	PushFrontLinklist(&first, 6);//ͷ��Ԫ��
	PushFrontLinklist(&first, 7);
	PushFrontLinklist(&first, 8);
	PushFrontLinklist(&first, 9);
	PushFrontLinklist(&first, 10);
	PrintLinklist(first);//��ӡ������
	cur = FindLinklist(&first, 8);
	InsertLinklist(&first, cur, 11);
	printf("��8ǰ�����11��:");
	PrintLinklist(first);//��ӡ������
	//PopBackLinklist(&first);//βɾһ���ڵ�
	//PopFrontLinklist(&first);//ͷɾһ���ڵ�
	//PushBackLinklist(&first, 1);//β��Ԫ��
	//PushBackLinklist(&first, 2);
	//PushBackLinklist(&first, 3);
	//PushBackLinklist(&first, 4);
	//PushBackLinklist(&first, 5);
	DestoryLinklist(&first);
	//PrintLinklist(first);//��ӡ������
	//printf("ɾ��11��:");
	//RemoveLinklist(&first, 11);
	//PrintLinklist(first);
	//PushFrontLinklist(&first, 7);
	//PushFrontLinklist(&first, 7);
	//RemoveLinklist(&first, 7);
	//RemoveAllLinklist(&first, 7);//ɾ�����е�7
	//PrintLinklist(first);

	
}
int main()
{
	test();
	system("pause");
	return 0;
}