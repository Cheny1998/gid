#pragma once

#include <stdlib.h>
#include <stdio.h>

struct Node 
{
	int value;
	struct Node *next;
};
typedef struct Node Node;

//����һ���ڵ�
Node * createListNode(int value)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

//����Ҫ��������
Node * createList()
{
	return createListNode(-0x23433);
}

//ɾ��һ���ڵ�
void deleteListNode(Node * list, int index)
{
	Node *temp = list->next;
	Node *node = NULL;
	int count = 1;
	index -= 1;
	if (index == 0)
	{
		node = list->next;
		list->next = list->next->next;
		free(node);
		return;
	}
	while (temp != NULL && count < index)
	{
		temp = temp->next;
		count++;
	}
	list = temp;
	node = list->next;
	list->next = temp->next->next; //��������ɾ��
	free(node);
}

//��������
void destroy(Node *list)
{
	Node *temp = list->next;
	Node *node = NULL;
	int count = 1;
	while (temp != NULL)
	{
		node = temp;
		temp = temp->next;
		free(node);
	}
	free(list);
}

void insert(Node * list, Node * node, int  index)
{
	Node *temp = list->next;
	int count = 1;
	index -= 1;
	if (index == 0)
	{
		list->next = node;
		node->next = temp;
	}
	while (temp!= NULL && count<index)
	{
		temp = temp->next;
		count++;
	}
	list = temp;
	temp = temp->next;
	list->next = node;
	node->next = temp;

}

//��ĩβ׷��Ҫ���ڵ�
void append(Node *list, Node * node)
{
	Node *temp = list->next;
	if (temp == NULL)
	{
		list->next = node;
		return;
	}
	while (temp->next !=NULL)
	{
		temp = temp->next;
	}
	temp->next = node;
}

void showList(Node * list)
{
	Node *temp = list->next;
	if (list == NULL || temp == NULL)
	{
		printf("null\n");
		return;
	}
	printf("%d", temp->value);
	temp = temp->next;
	while (temp !=NULL)
	{
		printf("->d", temp->value);
		temp = temp->next;

	}
	printf("\n");
}

Node *getNode(Node *list, int index)
{
	Node * temp = list->next;
	int count = 1;
	while (temp!= NULL && count<index)
	{
		temp = temp->next;
		count++;
	}
	return count == index ? temp : NULL;
}









