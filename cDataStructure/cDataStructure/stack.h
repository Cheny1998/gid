#pragma once
//栈 链表的实现 栈顶压栈或出栈
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

//建立一个节点
Node *createNode(int value)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->next = NULL;
	node->value = value;
	return node;
}

//建立一个空栈
Stack *createStack()
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->node = NULL;
	stack->size = 0;
	return stack;
}

//添加一个元素
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

//ta弹出一个元素
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

//获取栈顶元素
Node * top(Stack * stack)
{
	if (isEmpty(stack)) {
		printf("this stack is enpty");
		return NULL ;
	}
	return stack->node;
}

//huoqu获取元素个数
int size(Stack *stack) 
{
	return stack->size;
}







