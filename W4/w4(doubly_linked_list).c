#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* ptr;
struct node								//��� ����ü ����
{
	ptr llink;
	ptr rlink;
	int data;
};

void insert(ptr prev, ptr node)			//��� �߰� ���� �Լ�
{
	node->llink = prev;
	node->rlink = prev->rlink;
	prev->rlink->llink = node;
	prev->rlink = node;
}

void delete(ptr head, ptr node)			//���� ��Ʈ ���� �Լ�
{
	if (head == node)
	{
		printf("failed");
	}
	else
	{
		node->rlink->llink = node->llink;
		node->llink->rlink = node->rlink;
		free(node);
		printf("Second Value is gone: ");
	}
}

void edit(ptr head, int bye, int hello)	//��� ��ü �Լ�
{
	ptr first = head->rlink;
	while (first != head)
	{
		if (first->data == bye)
		{
			first->data = hello;
			printf("%d has turned into %d: ", bye, hello);
			break;
		}
		else
		{
			first = first->rlink;
		}
	}
}

void print(ptr head)					//��� �Լ�
{
	ptr first = head->rlink;
	while (first != head)
	{
		printf("%d ", first->data);
		first = first->rlink;
	}
	printf("\n");
}

int main()
{
	int n1, n2, n3, n4, n5;
	int before = 0, after = 0;
	ptr head, node1, node2, node3, node4, tail;

	head = (ptr)malloc(sizeof(struct node));
	node1 = (ptr)malloc(sizeof(struct node));
	node2 = (ptr)malloc(sizeof(struct node));
	node3 = (ptr)malloc(sizeof(struct node));
	node4 = (ptr)malloc(sizeof(struct node));
	tail = (ptr)malloc(sizeof(struct node));

	printf("���� 5���� �Է�: ");
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
	node1->data = n1;
	node2->data = n2;
	node3->data = n3;
	node4->data = n4;
	tail->data = n5;

	head->llink = tail;					//head->node1->node2->node3->node4->tail->head ���� �������� ���� ����
	head->rlink = node1;
	node1->llink = head;
	node1->rlink = node2;
	node2->llink = node1;
	node2->rlink = node3;
	node3->llink = node2;
	node3->rlink = node4;
	node4->llink = node3;
	node4->rlink = tail;
	tail->llink = node4;
	tail->rlink = head;

	printf("\n�ٲٰ� ���� ���ڸ� �Է�: <��ü�� ����> <��ü�� ����> ");
	scanf("%d %d", &before, &after);	//��ü�� ����, ��ü�� ���ڸ� �Է�(��ü�� ���ڴ� �� �Էµ� �� �߿��� ����)

	printf("normal: ");
	print(head);
	
	delete(head, node2);
	print(head);

	//insert(node3, tail);             //��������Ʈ�̱⵵ �ؼ� �Լ��� ��������� ������ ��������ϴ�.
	//print(head);

	edit(head, before, after);
	print(head);

	return 0;
}

