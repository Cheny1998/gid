// cDataStructure.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//#include "stack.h"
#include "list.h"

int main()
{
	//ջ �����ʵ�ֵ�ʹ��
	//Stack *stack = createStack();
	//Node * node = createNode(10);
	//push(stack, node);
	//node = createNode(20);
	//push(stack, node);
	//while (!isEmpty(stack))
	//{
	//	node = top(stack);
	//	printf("%d", node->value);
	//	pop(stack);
	//}
	/////////////

	Node *list = createList();
	Node *pNode = NULL;
	int i;
	for (i = 1; i <= 3; i++)
	{
		pNode = createListNode(i * 10);
		append(list, pNode);
	}
	showList(list);
	deleteListNode(list, 1);
	showList(list);
	pNode = createListNode(40);
	insert(list, pNode, 1);
	showList(list);
	pNode = getNode(list, 1);
	printf("%d\n", pNode->value);
	destroy(list);


    return 0;
}

