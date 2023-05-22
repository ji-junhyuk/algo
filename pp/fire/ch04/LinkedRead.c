#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} Node;

int main(void)
{
	Node *head = NULL;
//	Node *tail = NULL;
	Node *cur = NULL;

	Node *newNode = NULL;
	int readData;

	while (1)
	{
		printf("양수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;
		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;
//		if (head == NULL)
//			head = newNode;
//		else
//			tail->next = newNode;
//		tail = newNode;
		if (head == NULL)
			head = newNode;
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}
	printf("\n");
	if (head == NULL)
		printf("저장된 자연수가 존재하지 않습니다.\n");
	else
	{
		cur = head;
		printf("%d ", cur->data);
		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n");
	if (head == NULL)
		return 0;
	else
	{
		Node *delNode;
		delNode = head;
		Node *delNextNode = head->next;

		printf("%d를 삭제합니다.\n", head->data);
		free(delNode);
		while (delNextNode != NULL)
		{
			delNode = delNextNode; // head->next
			delNextNode = delNextNode->next; // head->next->next

			printf("%d를 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}
}
// free를 한다고해서, 사용했던 주소가 NULL로 바뀌는 것이 아니다.
// free함수를 호출하고, 그 주소를 NULL로 바꿔주는 것이 더 안정성을 높이는 방법이라 생각한다.
// 접근할 수 없는 주소가 분명 없음에도, 이에 접근하여 segfault error가 생기니깐.
