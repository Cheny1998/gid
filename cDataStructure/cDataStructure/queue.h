#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node* next;
};
typedef struct Node Node;

struct Queue
{
	Node *front;
	Node *rear;
	int size;
};
typedef struct Queue Queue;

// 建立一个节点
Node *createQueueNode(int value) 
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

//create a empty queue
Queue *createQueue()
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->front = (Node *)malloc(sizeof(Node));
	queue->front->next = NULL;
	queue->rear = queue->front;
	queue->size = 0;

}

void push(Queue * queue, Node * node)
{
	queue->rear->next = node;
	queue->rear = queue->rear->next;
	queue->size++;
}
void pop(Queue * queue)
{
	if (queue->size <= 0)
	{
		printf("this queue is empty!");
		return;

	}
	Node * node = queue->front;
	queue->front = queue->front->next;
	queue->size--;
	free(node);
}

Node * front(Queue * queue)
{
	if (queue->size <= 0)
	{
		printf("this queue is empty!");
		return NULL;

	}
	return queue->front->next;
}

// 得到队尾的节点
Node *back(Queue *queue)
{
	if (queue->size <= 0)
		return NULL;
	return queue->rear;
}


// 得到当前的队列元素个数
int size(Queue *queue)
{
	return queue->size;
}

// 检查队列是否为空
int isEmpty(Queue *queue)
{
	return queue->size <= 0;
}

// 清空队列
void clear(Queue *queue)
{
	Node *node = NULL;
	while (!isEmpty(queue))
	{
		node = queue->front;
		queue->front = queue->front->next;
		free(node);
	}
	free(queue->front); // 释放最后一个节点的内存
	free(queue);
}

