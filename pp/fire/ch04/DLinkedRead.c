#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

int main(void)
{
    int readData;

    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;

    Node *newNode = NULL;
	head = (Node *)malloc(sizeof(Node));
	tail = head;
    while (1)
    {
        printf("양수 입력: ");
        scanf("%d", &readData);
        if (readData < 1)
            break;
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;
		/*
        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;
		*/
		tail->next = newNode;
		tail = newNode;
	}
    printf("\n");
    if (head == tail)
        printf("저장된 수가 존재 X");
    else
    {
		cur = head;

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
    }
	printf("\n");
	if (head == tail)
		return 0;
	else
	{
		Node *delNode = head;
		Node *delNextNode = head->next;

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("%d를 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}
