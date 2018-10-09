//test.c测试函数
#include"Linklist.h"

void test()
{
	pLinklist cur = NULL;//用来接收FindLinklist的返回值
	Linklist *first = NULL;
	InitLinklist(&first);//初始化
	PushFrontLinklist(&first, 6);//头插元素
	PushFrontLinklist(&first, 7);
	PushFrontLinklist(&first, 8);
	PushFrontLinklist(&first, 9);
	PushFrontLinklist(&first, 10);
	PrintLinklist(first);//打印单链表
	cur = FindLinklist(&first, 8);
	InsertLinklist(&first, cur, 11);
	printf("在8前面插入11得:");
	PrintLinklist(first);//打印单链表
	//PopBackLinklist(&first);//尾删一个节点
	//PopFrontLinklist(&first);//头删一个节点
	//PushBackLinklist(&first, 1);//尾插元素
	//PushBackLinklist(&first, 2);
	//PushBackLinklist(&first, 3);
	//PushBackLinklist(&first, 4);
	//PushBackLinklist(&first, 5);
	DestoryLinklist(&first);
	//PrintLinklist(first);//打印单链表
	//printf("删除11得:");
	//RemoveLinklist(&first, 11);
	//PrintLinklist(first);
	//PushFrontLinklist(&first, 7);
	//PushFrontLinklist(&first, 7);
	//RemoveLinklist(&first, 7);
	//RemoveAllLinklist(&first, 7);//删除所有的7
	//PrintLinklist(first);

	
}
int main()
{
	test();
	system("pause");
	return 0;
}