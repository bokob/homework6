#include <stdio.h>
#include <stdlib.h>

typedef struct Node // 구조체 Node 선언
{
	int key;		   // int형 변수 key
	struct Node *link; // 구조체 Node에 대한 포인터 link
} listNode;			   // 선언한 구조체 Node를 listNode라 정의한다.

typedef struct Head // 구조체 Head 선언
{
	struct Node *first; // 구조체 Node에 대한 포인터 first
} headNode;				// 선언한 구조체 Head를 headNode라 정의한다.

headNode *initialize(headNode *h);	   // h가 가리키는 연결리스트 초기화하는 함수
int freeList(headNode *h);			   // h로부터 접근할 수 있는 노드들 해제하는 함수
int insertFirst(headNode *h, int key); //  연결리스트 맨 앞에 입력받은 key를 지닌 노드 추가하는 함수
int insertNode(headNode *h, int key);  // 노드들 중에서 입력한 key보다 큰 값을 가지는 노드 바로 앞에 삽입하는 함수
int insertLast(headNode *h, int key);  // 연결리스트의 맨 뒤에 입력받은 key를 지닌 노드 추가하는 함수

int deleteFirst(headNode *h);		  // 연결리스트의 맨 앞에 있는 노드 삭제
int deleteNode(headNode *h, int key); // 입력받은 key를 지닌 노드 삭제
int deleteLast(headNode *h);		  // 연결리스트의 맨 뒤에 있는 노드 삭제
int invertList(headNode *h);		  // 연결리스트를 역순으로 연결

void printList(headNode *h); // 연결리스트 출력

int main()
{
	char command;			   // 명령어를 입력받을 char형 변수 command
	int key;				   // int형 변수 key
	headNode *headnode = NULL; // 메모리의 Stack 영역에 headnode를 만들고 Null을 가리키도록 한다.

	int flag = 0; // initialize() 함수를 사용하고 다른 함수를 사용했을 때 판단할 변수

	printf("[------------------- [복무창] [2021040021] -------------------]\n");

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
		scanf(" %c", &command); // 명령어를 입력받는다.

		switch (command)
		{
		case 'z':
		case 'Z':							 // z 또는 Z 입력 받은 경우
			headnode = initialize(headnode); // headnode를 초기화한다.
			flag=1;							 // initialize() 함수를 사용했다
			break;
		case 'p':
		case 'P':				 // p 또는 P를 입력 받은 경우
			printList(headnode); // 연결리스트 출력
			break;
		case 'i':
		case 'I': // i 또는 I를 입력 받은 경우
			if(flag == 0)		// initialize() 함수를 사용하지 않았으면
			{
				printf("Please initialize.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key); // key 입력
			insertNode(headnode, key);
			// 노드들 중에서 입력한 key보다 큰 값을 가지는 노드 바로 앞에 삽입
			break;
		case 'd':
		case 'D': // d 또는 D 입력 받은 경우
			if(flag == 0)		// initialize() 함수를 사용하지 않았으면
			{
				printf("Please initialize.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);		   // key 입력
			deleteNode(headnode, key); // 입력받은 key를 지닌 노드 삭제
			break;
		case 'n':
		case 'N': // n 또는 N 입력 받으 경우
			if(flag == 0)		// initialize() 함수를 사용하지 않았으면
			{
				printf("Please initialize.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);		   // key 입력
			insertLast(headnode, key); // 연결리스트의 맨 뒤에 입력받은 key를 지닌 노드 삽입
			break;
		case 'e':
		case 'E':				  // e 또는 E 입력 받은 경우
			if(flag == 0)		// initialize() 함수를 사용하지 않았으면
			{
				printf("Please initialize.\n");
				break;
			}
			deleteLast(headnode); // 연결리스트의 맨 뒤의 노드 삭제
			break;
		case 'f':
		case 'F': // f 또는 F 입력 받은 경우
			if(flag == 0)		// initialize() 함수를 사용하지 않았으면
			{
				printf("Please initialize.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);			// key 입력
			insertFirst(headnode, key); // 연결리스트의 맨 앞에 입력받은 key를 지닌 노드 삽입
			break;
		case 't':
		case 'T':				   // t 또는 T 입력 받은 경우
			if(flag == 0)		// initialize() 함수를 사용하지 않았으면
			{
				printf("Please initialize.\n");
				break;
			}
			deleteFirst(headnode); // 연결리스트의 맨 앞에 있는 노드 삭제
			break;
		case 'r':
		case 'R':				  // r 또는 R 입력 받은 경우
			if(flag == 0)		// initialize() 함수를 사용하지 않았으면
			{
				printf("Please initialize.\n");
				break;
			}
			invertList(headnode); // 연결리스트를 역순으로 연결
			break;
		case 'q':
		case 'Q':				// q 또는 Q 입력 받은 경우
			freeList(headnode); // 연결리스틀르 해제한다.
			break;
		default:													   // 그 외의 명령어를 입력받은 경우
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); // 집중하라는 문구 출력
			break;
		}

	} while (command != 'q' && command != 'Q'); // q 또는 Q가 입력받지 않을 때까지 반복

	return 1;
}

headNode *initialize(headNode *h)
{
	if (h != NULL)	 // h에 NULL이 들어있지 않다면
		freeList(h); // freeList를 호출하여 해제한다.

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode *temp = (headNode *)malloc(sizeof(headNode));
	// 메모리의 Heap 영역에 headNode 만큼의 크기를 갖는 공간을 만들고
	// 그곳의 주소를 temp에 할당한다.
	temp->first = NULL; // temp가 가리키는 곳의 first에 NULL을 넣는다.

	return temp; // temp를 반환한다.
}

int freeList(headNode *h)
{
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode *p = h->first;
	// 메모리의 Stack 영역에 p를 만들고
	// h가 가리키는 곳의 first에 들어있는 주소를 p에 넣는다.

	listNode *prev = NULL;
	// 메모리의 Stack 영역에 prev를 만들고
	// prev에 NULL을 넣는다.
	while (p != NULL)
	{
		prev = p;	 // prev애 p에 들어있는 주소를 넣는다.
		p = p->link; // p에 p가 가리키는 곳의  link에 들어있는 주소를 넣는다.
		free(prev);	 // prev를 해제한다.
	}
	free(h); // h를 해제한다.

	return 0;
}

/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode *h, int key)
{

	listNode *node = (listNode *)malloc(sizeof(listNode));
	// 메모리의 Heap 영역에 listNode 만큼의 크기를 갖는 공간을 만들고
	// 그곳의 주소를 메모리의 Stack 영역의 node에 할당한다.

	node->key = key; // node가 가리키는 곳의 key에 입력받은 key를 넣는다.

	node->link = h->first;
	// h가 가리키는 곳의 first에 들어있는 주소를 node가 가리키는 곳의 link에 넣는다.
	h->first = node; // h가 가리키는 곳의 first에 node에 들어있는 주소를 넣는다.

	return 0;
}

/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode *h, int key)
{

	listNode *node = (listNode *)malloc(sizeof(listNode));
	// 메모리의 Heap 영역에 listNode 만큼의 크기를 갖는 공간을 만들고
	// 그곳의 주소를 Stack 영역의 node에 할당한다.
	node->key = key;   // node가 가리키는 곳의 key에 입력받은 key의 값을 넣는다.
	node->link = NULL; // node가 가리키는 곳의 link에 NULL을 넣는다.

	if (h->first == NULL)
	// h가 가리키는 곳의 first가 가리키는 곳이 NULL이라면
	{
		h->first = node;
		// h가 가리키는 곳의 first에 node가 가리키는 곳의 주소를 넣는다.
		return 0;
	}

	listNode *n = h->first;
	// 메모리의 Stack 영역에 n을 만들고,
	// h가 가리키는 곳의 first가 가리키는 곳의 주소를 n에 넣는다.
	listNode *trail = h->first;
	// 메모리의 Stack 영역에 trail을 만들고,
	// h가 가리키는 곳의 first가 가리키는 곳의 주소를 trail에 넣는다.

	while (n != NULL) // n이 아무것도 가리키기 않을 때까지 반복
	{
		if (n->key >= key)
		// n이 가리키는 곳의 key가 입력받은 key보다 크거나 같다면
		{
			if (n == h->first)
			// n이 가리키는 곳이 h가 가리키는 곳의 firstr가 가리키는 곳이라면
			{
				h->first = node; // h가 가리키는 곳의 first에 node에 들어있는 주소를 넣는다.
				node->link = n;	 // node가 가리키는 곳의 link에 n에 들어있는 주소를 넣는다.
			}
			else // n이 가리키는 곳이 h가 가리키는 곳의 first가 아니라면
			{
				node->link = n;		// node가 가리키는 곳의 link에 n에 들어있는 주소를 넣는다.
				trail->link = node; // trail이 가리키는 곳의 link에 node에 들어있는 주소를 넣는다.
			}
			return 0;
		}

		//	n이 가리키는 곳의 key가 입력받은 key보다 작은 경우 실행되는 부분

		trail = n;	 // trail에 n에 들어있는 주소를 넣는다.
		n = n->link; // n에 n이 가리키는 곳의 link에 들어있는 주소를 넣는다.
	}

	// n이 아무것도 가리키지 않을 때 실행되는 부분

	trail->link = node; // trail이 가리키는 곳의 link에 node에 들어있는 주소를 넣는다.
	return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode *h, int key)
{
	listNode *node = (listNode *)malloc(sizeof(listNode));
	// 메모리의 Heap 영역에 listNode 만큼의 크기를 갖는 공간을 만들고
	// 그곳의 주소를 메모리의 Stack 영역의 node에 할당한다.
	node->key = key;   // node가 가리키는 곳의 key에 입력받은 key를 넣는다.
	node->link = NULL; // node가 가리키는 곳의 link에 NULL을 넣는다.

	if (h->first == NULL)
	// h가 가리키는 곳의 first가 가리키는 곳이 NULL이라면
	{
		h->first = node;
		// h가 가리키는 곳의 first에 node가 가리키고 있는 곳의 주소를 넣는다.
		return 0;
	}

	listNode *n = h->first;
	// 메모리의 Stack 영역에 n을 만들고
	// h가 가리키는 곳의 first가 가리키는 곳의 주소를 n에 넣는다.
	while (n->link != NULL)
	// n이 가리키는 곳의 link가 가리키는 곳이 NULL이 아닐 때까지 반복
	{
		n = n->link; // n에 n이 가리키는 곳의 link가 가리키는 곳의 주소를 넣는다.
	}
	n->link = node; // n이 가리키는 곳의 link에 node가 가리키는 곳의 주소를 넣는다.

	return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode *h)
{
	if (h->first == NULL) // h가 가리키는 곳의 first가 가리키는 곳이 NULL이라면
	{
		printf("nothing to delete.\n"); // 삭제할 것이 없다는 문구 출력
		return 0;
	}
	listNode *n = h->first;
	// 메모리의 Stack 영역에 n을 만들고,
	// h가 가리키는 곳의 first가 가리키는 곳의 주소를 n에 넣는다.

	h->first = n->link;
	// n이 가리키는 곳의 link에 들어있는 주소를 h가 가리키는 곳의 first에 넣는다.

	free(n); // n을 해제한다.

	return 0;
}

/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode *h, int key)
{

	if (h->first == NULL) // h가 가리키는 곳의 first가 가리키는 곳이 NULL이라면
	{
		printf("nothing to delete\n"); // 삭제할 것이 없다고 출력
		return 0;
	}

	listNode *n = h->first;
	// 메모리의 Stack 영역에 n을 만들고
	// h가 가리키는 곳의 first가 가리키는 곳의 주소를 n에 넣는다.
	listNode *trail = NULL;
	// 메모리의 Stack 영역에 trail을 만들고
	// trail에 NULL을 넣는다.

	while (n != NULL) // n이 가리키는 곳이 NULL이 아닐 때까지 반복
	{
		if (n->key == key) // n이 가리키는 곳의 key가 입력받은 key와 같다면
		{
			if (n == h->first)
			// n이 가리키는 곳과 h가 가리키는 곳의 first가 가리키는 곳이 같다면
			{
				h->first = n->link;
				// h가 가리키는 곳의 first에 n이 가리키는 곳의 link에 들어있는 주소를 넣는다.
			}
			else
			// n이 가리키는 곳과 h가 가리키는 곳의 first가 가리키는 곳이 같지 않다면
			{
				trail->link = n->link;
				// trail이 가리키는 곳의 link에 n이 가리키는 곳의 link애 들어있는 주소를 넣는다.
			}
			free(n); // n을 해제한다.
			return 0;
		}
		trail = n;	 // trail에 n에 들어있는 주소를 넣는다.
		n = n->link; // n에 n이 가리키는 곳의 link가 가리키는 곳의 주소를 넣는다.
	}

	// 삭제할 노드를 못찾은 경우
	printf("cannot find the node for key = %d\n", key);
	return 0;
}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode *h)
{

	if (h->first == NULL) // h가 가리키는 곳의 first가 가리키는 곳이 NULL이라면
	{
		printf("nothing to delete.\n"); // 삭제할 노드가 없다는 문구 출력
		return 0;
	}

	listNode *n = h->first;
	// 메모리의 Stack 영역에 n을 만들고,
	// h가 가리키는 곳의 first가 가리키는 곳의 주소를 n에 넣는다.
	listNode *trail = NULL;
	// 메모리의 Stack 영역에 trail을 만들고 NULL을 넣는다.

	if (n->link == NULL) // n이 가리키는 곳의 link에 NULL이 들어있다면
	{
		h->first = NULL; // h가 가리키는 곳의 first에 NULL을 넣는다.
		free(n);		 // n을 해제한다.
		return 0;
	}

	while (n->link != NULL)
	// n이 가리키는 곳의 link가 NULL을 가리키지 않을 때까지 반복
	{
		trail = n;	 // trail에 n에 들어있는 주소를 넣는다.
		n = n->link; // n에 n이 가리키는 곳의 link에 들어있는 주소를 넣는다.
	}

	trail->link = NULL; // trail이 가리키는 곳의 link에 NULL을 넣는다.
	free(n);			// n을 해제한다.

	return 0;
}

/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode *h)
{
	if (h->first == NULL) // h가 가리키는 곳의 first가 가리키는 곳이 NULL이라면
	{
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->first;
	// 메모리의 Stack 영역에 n을 만들고,
	// h가 가리키는 곳의 first가 가리키는 곳의 주소를 n에 넣는다.
	listNode *trail = NULL;
	listNode *middle = NULL;

	while (n != NULL) // n이 가리키는 곳이 NULL이 아닐 때까지 반복
	{
		trail = middle; // trail에 middle에 들어있는 주소를 넣는다.
		middle = n;		// middle에 n에 들어있는 주소를 넣는다.
		n = n->link;	// n에 n이 가리키는 곳의 link에 들어있는 주소를 넣는다.
		middle->link = trail;
		// middle이 가리키는 곳의 link에 trail에 들어있는 주소를 넣는다.
	}

	h->first = middle; // h가 가리키는 곳의 first에 middle에 들어있는 주소를 넣는다.

	return 0;
}

void printList(headNode *h)
{
	int i = 0;
	listNode *p;
	// 메모리의 Stack 영역에 p 생성

	printf("\n---PRINT\n");

	if (h == NULL) // h가 가리키는 곳이 NULL이라면
	{
		printf("Nothing to print....\n"); // 출력할 것이 없다는 문구 출력
		return;
	}

	p = h->first; // p에 h가 가리키는 곳의 first에 들어있는 주소를 넣는다.

	while (p != NULL) // p가 가리키는 곳이 NULL이 아닐 때까지 반복
	{
		printf("[ [%d]=%d ] ", i, p->key); // p가 가리키는 곳의 key 출력
		p = p->link;					   // p에 p가 가리키는 곳의 link에 들어있는 주소를 넣는다.
		i++;							   // i를 1씩 증가시킨다.
	}

	printf("  items = %d\n", i); // 몇 번째 노드인지 출력
}