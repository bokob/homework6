#include <stdio.h>
#include <stdlib.h>

typedef struct Node // ����ü Node ����
{
	int key;		   // int�� ���� key
	struct Node *link; // ����ü Node�� ���� ������ link
} listNode;			   // ������ ����ü Node�� listNode�� �����Ѵ�.

typedef struct Head // ����ü Head ����
{
	struct Node *first; // ����ü Node�� ���� ������ first
} headNode;				// ������ ����ü Head�� headNode�� �����Ѵ�.

headNode *initialize(headNode *h);	   // h�� ����Ű�� ���Ḯ��Ʈ �ʱ�ȭ�ϴ� �Լ�
int freeList(headNode *h);			   // h�κ��� ������ �� �ִ� ���� �����ϴ� �Լ�
int insertFirst(headNode *h, int key); //  ���Ḯ��Ʈ �� �տ� �Է¹��� key�� ���� ��� �߰��ϴ� �Լ�
int insertNode(headNode *h, int key);  // ���� �߿��� �Է��� key���� ū ���� ������ ��� �ٷ� �տ� �����ϴ� �Լ�
int insertLast(headNode *h, int key);  // ���Ḯ��Ʈ�� �� �ڿ� �Է¹��� key�� ���� ��� �߰��ϴ� �Լ�

int deleteFirst(headNode *h);		  // ���Ḯ��Ʈ�� �� �տ� �ִ� ��� ����
int deleteNode(headNode *h, int key); // �Է¹��� key�� ���� ��� ����
int deleteLast(headNode *h);		  // ���Ḯ��Ʈ�� �� �ڿ� �ִ� ��� ����
int invertList(headNode *h);		  // ���Ḯ��Ʈ�� �������� ����

void printList(headNode *h); // ���Ḯ��Ʈ ���

int main()
{
	char command;			   // ��ɾ �Է¹��� char�� ���� command
	int key;				   // int�� ���� key
	headNode *headnode = NULL; // �޸��� Stack ������ headnode�� ����� Null�� ����Ű���� �Ѵ�.

	int flag = 0; // initialize() �Լ��� ����ϰ� �ٸ� �Լ��� ������� �� �Ǵ��� ����

	printf("[------------------- [����â] [2021040021] -------------------]\n");

	do
	{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); // ��ɾ �Է¹޴´�.

		switch (command)
		{
		case 'z':
		case 'Z':							 // z �Ǵ� Z �Է� ���� ���
			headnode = initialize(headnode); // headnode�� �ʱ�ȭ�Ѵ�.
			flag=1;							 // initialize() �Լ��� ����ߴ�
			break;
		case 'p':
		case 'P':				 // p �Ǵ� P�� �Է� ���� ���
			printList(headnode); // ���Ḯ��Ʈ ���
			break;
		case 'i':
		case 'I': // i �Ǵ� I�� �Է� ���� ���
			if(flag == 0)		// initialize() �Լ��� ������� �ʾ�����
			{
				printf("Please initialize.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key); // key �Է�
			insertNode(headnode, key);
			// ���� �߿��� �Է��� key���� ū ���� ������ ��� �ٷ� �տ� ����
			break;
		case 'd':
		case 'D': // d �Ǵ� D �Է� ���� ���
			if(flag == 0)		// initialize() �Լ��� ������� �ʾ�����
			{
				printf("Please initialize.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);		   // key �Է�
			deleteNode(headnode, key); // �Է¹��� key�� ���� ��� ����
			break;
		case 'n':
		case 'N': // n �Ǵ� N �Է� ���� ���
			if(flag == 0)		// initialize() �Լ��� ������� �ʾ�����
			{
				printf("Please initialize.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);		   // key �Է�
			insertLast(headnode, key); // ���Ḯ��Ʈ�� �� �ڿ� �Է¹��� key�� ���� ��� ����
			break;
		case 'e':
		case 'E':				  // e �Ǵ� E �Է� ���� ���
			if(flag == 0)		// initialize() �Լ��� ������� �ʾ�����
			{
				printf("Please initialize.\n");
				break;
			}
			deleteLast(headnode); // ���Ḯ��Ʈ�� �� ���� ��� ����
			break;
		case 'f':
		case 'F': // f �Ǵ� F �Է� ���� ���
			if(flag == 0)		// initialize() �Լ��� ������� �ʾ�����
			{
				printf("Please initialize.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);			// key �Է�
			insertFirst(headnode, key); // ���Ḯ��Ʈ�� �� �տ� �Է¹��� key�� ���� ��� ����
			break;
		case 't':
		case 'T':				   // t �Ǵ� T �Է� ���� ���
			if(flag == 0)		// initialize() �Լ��� ������� �ʾ�����
			{
				printf("Please initialize.\n");
				break;
			}
			deleteFirst(headnode); // ���Ḯ��Ʈ�� �� �տ� �ִ� ��� ����
			break;
		case 'r':
		case 'R':				  // r �Ǵ� R �Է� ���� ���
			if(flag == 0)		// initialize() �Լ��� ������� �ʾ�����
			{
				printf("Please initialize.\n");
				break;
			}
			invertList(headnode); // ���Ḯ��Ʈ�� �������� ����
			break;
		case 'q':
		case 'Q':				// q �Ǵ� Q �Է� ���� ���
			freeList(headnode); // ���Ḯ��Ʋ�� �����Ѵ�.
			break;
		default:													   // �� ���� ��ɾ �Է¹��� ���
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); // �����϶�� ���� ���
			break;
		}

	} while (command != 'q' && command != 'Q'); // q �Ǵ� Q�� �Է¹��� ���� ������ �ݺ�

	return 1;
}

headNode *initialize(headNode *h)
{
	if (h != NULL)	 // h�� NULL�� ������� �ʴٸ�
		freeList(h); // freeList�� ȣ���Ͽ� �����Ѵ�.

	/* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
	headNode *temp = (headNode *)malloc(sizeof(headNode));
	// �޸��� Heap ������ headNode ��ŭ�� ũ�⸦ ���� ������ �����
	// �װ��� �ּҸ� temp�� �Ҵ��Ѵ�.
	temp->first = NULL; // temp�� ����Ű�� ���� first�� NULL�� �ִ´�.

	return temp; // temp�� ��ȯ�Ѵ�.
}

int freeList(headNode *h)
{
	/* h�� ����� listNode �޸� ����
	 * headNode�� �����Ǿ�� ��.
	 */
	listNode *p = h->first;
	// �޸��� Stack ������ p�� �����
	// h�� ����Ű�� ���� first�� ����ִ� �ּҸ� p�� �ִ´�.

	listNode *prev = NULL;
	// �޸��� Stack ������ prev�� �����
	// prev�� NULL�� �ִ´�.
	while (p != NULL)
	{
		prev = p;	 // prev�� p�� ����ִ� �ּҸ� �ִ´�.
		p = p->link; // p�� p�� ����Ű�� ����  link�� ����ִ� �ּҸ� �ִ´�.
		free(prev);	 // prev�� �����Ѵ�.
	}
	free(h); // h�� �����Ѵ�.

	return 0;
}

/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode *h, int key)
{

	listNode *node = (listNode *)malloc(sizeof(listNode));
	// �޸��� Heap ������ listNode ��ŭ�� ũ�⸦ ���� ������ �����
	// �װ��� �ּҸ� �޸��� Stack ������ node�� �Ҵ��Ѵ�.

	node->key = key; // node�� ����Ű�� ���� key�� �Է¹��� key�� �ִ´�.

	node->link = h->first;
	// h�� ����Ű�� ���� first�� ����ִ� �ּҸ� node�� ����Ű�� ���� link�� �ִ´�.
	h->first = node; // h�� ����Ű�� ���� first�� node�� ����ִ� �ּҸ� �ִ´�.

	return 0;
}

/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode *h, int key)
{

	listNode *node = (listNode *)malloc(sizeof(listNode));
	// �޸��� Heap ������ listNode ��ŭ�� ũ�⸦ ���� ������ �����
	// �װ��� �ּҸ� Stack ������ node�� �Ҵ��Ѵ�.
	node->key = key;   // node�� ����Ű�� ���� key�� �Է¹��� key�� ���� �ִ´�.
	node->link = NULL; // node�� ����Ű�� ���� link�� NULL�� �ִ´�.

	if (h->first == NULL)
	// h�� ����Ű�� ���� first�� ����Ű�� ���� NULL�̶��
	{
		h->first = node;
		// h�� ����Ű�� ���� first�� node�� ����Ű�� ���� �ּҸ� �ִ´�.
		return 0;
	}

	listNode *n = h->first;
	// �޸��� Stack ������ n�� �����,
	// h�� ����Ű�� ���� first�� ����Ű�� ���� �ּҸ� n�� �ִ´�.
	listNode *trail = h->first;
	// �޸��� Stack ������ trail�� �����,
	// h�� ����Ű�� ���� first�� ����Ű�� ���� �ּҸ� trail�� �ִ´�.

	while (n != NULL) // n�� �ƹ��͵� ����Ű�� ���� ������ �ݺ�
	{
		if (n->key >= key)
		// n�� ����Ű�� ���� key�� �Է¹��� key���� ũ�ų� ���ٸ�
		{
			if (n == h->first)
			// n�� ����Ű�� ���� h�� ����Ű�� ���� firstr�� ����Ű�� ���̶��
			{
				h->first = node; // h�� ����Ű�� ���� first�� node�� ����ִ� �ּҸ� �ִ´�.
				node->link = n;	 // node�� ����Ű�� ���� link�� n�� ����ִ� �ּҸ� �ִ´�.
			}
			else // n�� ����Ű�� ���� h�� ����Ű�� ���� first�� �ƴ϶��
			{
				node->link = n;		// node�� ����Ű�� ���� link�� n�� ����ִ� �ּҸ� �ִ´�.
				trail->link = node; // trail�� ����Ű�� ���� link�� node�� ����ִ� �ּҸ� �ִ´�.
			}
			return 0;
		}

		//	n�� ����Ű�� ���� key�� �Է¹��� key���� ���� ��� ����Ǵ� �κ�

		trail = n;	 // trail�� n�� ����ִ� �ּҸ� �ִ´�.
		n = n->link; // n�� n�� ����Ű�� ���� link�� ����ִ� �ּҸ� �ִ´�.
	}

	// n�� �ƹ��͵� ����Ű�� ���� �� ����Ǵ� �κ�

	trail->link = node; // trail�� ����Ű�� ���� link�� node�� ����ִ� �ּҸ� �ִ´�.
	return 0;
}

/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode *h, int key)
{
	listNode *node = (listNode *)malloc(sizeof(listNode));
	// �޸��� Heap ������ listNode ��ŭ�� ũ�⸦ ���� ������ �����
	// �װ��� �ּҸ� �޸��� Stack ������ node�� �Ҵ��Ѵ�.
	node->key = key;   // node�� ����Ű�� ���� key�� �Է¹��� key�� �ִ´�.
	node->link = NULL; // node�� ����Ű�� ���� link�� NULL�� �ִ´�.

	if (h->first == NULL)
	// h�� ����Ű�� ���� first�� ����Ű�� ���� NULL�̶��
	{
		h->first = node;
		// h�� ����Ű�� ���� first�� node�� ����Ű�� �ִ� ���� �ּҸ� �ִ´�.
		return 0;
	}

	listNode *n = h->first;
	// �޸��� Stack ������ n�� �����
	// h�� ����Ű�� ���� first�� ����Ű�� ���� �ּҸ� n�� �ִ´�.
	while (n->link != NULL)
	// n�� ����Ű�� ���� link�� ����Ű�� ���� NULL�� �ƴ� ������ �ݺ�
	{
		n = n->link; // n�� n�� ����Ű�� ���� link�� ����Ű�� ���� �ּҸ� �ִ´�.
	}
	n->link = node; // n�� ����Ű�� ���� link�� node�� ����Ű�� ���� �ּҸ� �ִ´�.

	return 0;
}

/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode *h)
{
	if (h->first == NULL) // h�� ����Ű�� ���� first�� ����Ű�� ���� NULL�̶��
	{
		printf("nothing to delete.\n"); // ������ ���� ���ٴ� ���� ���
		return 0;
	}
	listNode *n = h->first;
	// �޸��� Stack ������ n�� �����,
	// h�� ����Ű�� ���� first�� ����Ű�� ���� �ּҸ� n�� �ִ´�.

	h->first = n->link;
	// n�� ����Ű�� ���� link�� ����ִ� �ּҸ� h�� ����Ű�� ���� first�� �ִ´�.

	free(n); // n�� �����Ѵ�.

	return 0;
}

/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode *h, int key)
{

	if (h->first == NULL) // h�� ����Ű�� ���� first�� ����Ű�� ���� NULL�̶��
	{
		printf("nothing to delete\n"); // ������ ���� ���ٰ� ���
		return 0;
	}

	listNode *n = h->first;
	// �޸��� Stack ������ n�� �����
	// h�� ����Ű�� ���� first�� ����Ű�� ���� �ּҸ� n�� �ִ´�.
	listNode *trail = NULL;
	// �޸��� Stack ������ trail�� �����
	// trail�� NULL�� �ִ´�.

	while (n != NULL) // n�� ����Ű�� ���� NULL�� �ƴ� ������ �ݺ�
	{
		if (n->key == key) // n�� ����Ű�� ���� key�� �Է¹��� key�� ���ٸ�
		{
			if (n == h->first)
			// n�� ����Ű�� ���� h�� ����Ű�� ���� first�� ����Ű�� ���� ���ٸ�
			{
				h->first = n->link;
				// h�� ����Ű�� ���� first�� n�� ����Ű�� ���� link�� ����ִ� �ּҸ� �ִ´�.
			}
			else
			// n�� ����Ű�� ���� h�� ����Ű�� ���� first�� ����Ű�� ���� ���� �ʴٸ�
			{
				trail->link = n->link;
				// trail�� ����Ű�� ���� link�� n�� ����Ű�� ���� link�� ����ִ� �ּҸ� �ִ´�.
			}
			free(n); // n�� �����Ѵ�.
			return 0;
		}
		trail = n;	 // trail�� n�� ����ִ� �ּҸ� �ִ´�.
		n = n->link; // n�� n�� ����Ű�� ���� link�� ����Ű�� ���� �ּҸ� �ִ´�.
	}

	// ������ ��带 ��ã�� ���
	printf("cannot find the node for key = %d\n", key);
	return 0;
}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode *h)
{

	if (h->first == NULL) // h�� ����Ű�� ���� first�� ����Ű�� ���� NULL�̶��
	{
		printf("nothing to delete.\n"); // ������ ��尡 ���ٴ� ���� ���
		return 0;
	}

	listNode *n = h->first;
	// �޸��� Stack ������ n�� �����,
	// h�� ����Ű�� ���� first�� ����Ű�� ���� �ּҸ� n�� �ִ´�.
	listNode *trail = NULL;
	// �޸��� Stack ������ trail�� ����� NULL�� �ִ´�.

	if (n->link == NULL) // n�� ����Ű�� ���� link�� NULL�� ����ִٸ�
	{
		h->first = NULL; // h�� ����Ű�� ���� first�� NULL�� �ִ´�.
		free(n);		 // n�� �����Ѵ�.
		return 0;
	}

	while (n->link != NULL)
	// n�� ����Ű�� ���� link�� NULL�� ����Ű�� ���� ������ �ݺ�
	{
		trail = n;	 // trail�� n�� ����ִ� �ּҸ� �ִ´�.
		n = n->link; // n�� n�� ����Ű�� ���� link�� ����ִ� �ּҸ� �ִ´�.
	}

	trail->link = NULL; // trail�� ����Ű�� ���� link�� NULL�� �ִ´�.
	free(n);			// n�� �����Ѵ�.

	return 0;
}

/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode *h)
{
	if (h->first == NULL) // h�� ����Ű�� ���� first�� ����Ű�� ���� NULL�̶��
	{
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->first;
	// �޸��� Stack ������ n�� �����,
	// h�� ����Ű�� ���� first�� ����Ű�� ���� �ּҸ� n�� �ִ´�.
	listNode *trail = NULL;
	listNode *middle = NULL;

	while (n != NULL) // n�� ����Ű�� ���� NULL�� �ƴ� ������ �ݺ�
	{
		trail = middle; // trail�� middle�� ����ִ� �ּҸ� �ִ´�.
		middle = n;		// middle�� n�� ����ִ� �ּҸ� �ִ´�.
		n = n->link;	// n�� n�� ����Ű�� ���� link�� ����ִ� �ּҸ� �ִ´�.
		middle->link = trail;
		// middle�� ����Ű�� ���� link�� trail�� ����ִ� �ּҸ� �ִ´�.
	}

	h->first = middle; // h�� ����Ű�� ���� first�� middle�� ����ִ� �ּҸ� �ִ´�.

	return 0;
}

void printList(headNode *h)
{
	int i = 0;
	listNode *p;
	// �޸��� Stack ������ p ����

	printf("\n---PRINT\n");

	if (h == NULL) // h�� ����Ű�� ���� NULL�̶��
	{
		printf("Nothing to print....\n"); // ����� ���� ���ٴ� ���� ���
		return;
	}

	p = h->first; // p�� h�� ����Ű�� ���� first�� ����ִ� �ּҸ� �ִ´�.

	while (p != NULL) // p�� ����Ű�� ���� NULL�� �ƴ� ������ �ݺ�
	{
		printf("[ [%d]=%d ] ", i, p->key); // p�� ����Ű�� ���� key ���
		p = p->link;					   // p�� p�� ����Ű�� ���� link�� ����ִ� �ּҸ� �ִ´�.
		i++;							   // i�� 1�� ������Ų��.
	}

	printf("  items = %d\n", i); // �� ��° ������� ���
}