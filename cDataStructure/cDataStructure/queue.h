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

// ����һ���ڵ�
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

// �õ���β�Ľڵ�
Node *back(Queue *queue)
{
	if (queue->size <= 0)
		return NULL;
	return queue->rear;
}


// �õ���ǰ�Ķ���Ԫ�ظ���
int size(Queue *queue)
{
	return queue->size;
}

// �������Ƿ�Ϊ��
int isEmpty(Queue *queue)
{
	return queue->size <= 0;
}

// ��ն���
void clear(Queue *queue)
{
	Node *node = NULL;
	while (!isEmpty(queue))
	{
		node = queue->front;
		queue->front = queue->front->next;
		free(node);
	}
	free(queue->front); // �ͷ����һ���ڵ���ڴ�
	free(queue);
}

