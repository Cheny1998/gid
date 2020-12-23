#pragma once
//ջ �����ʵ�� ջ��ѹջ���ջ
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node * next;
};
typedef struct Node Node;

struct Stack
{
	Node *node;
	int size;
};
typedef struct Stack Stack;

//����һ���ڵ�
Node *createNode(int value)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->next = NULL;
	node->value = value;
	return node;
}

//����һ����ջ
Stack *createStack()
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->node = NULL;
	stack->size = 0;
	return stack;
}

//���һ��Ԫ��
void push(Stack *stack, Node *node)
{
	node->next = stack->node;
	stack->node = node;
	stack->size++;

}

int isEmpty(Stack *stack)
{
	return stack->size <= 0 ? 1 : 0;
}

//ta����һ��Ԫ��
void pop(Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("this stack is enpty");
		return;
	}
	Node *node = stack->node;
	stack->node = stack->node->next;
	stack->size--;
	free(node);
}

//��ȡջ��Ԫ��
Node * top(Stack * stack)
{
	if (isEmpty(stack)) {
		printf("this stack is enpty");
		return NULL ;
	}
	return stack->node;
}

//huoqu��ȡԪ�ظ���
int size(Stack *stack) 
{
	return stack->size;
}







