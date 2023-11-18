#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int LTDataType;

typedef struct LinkNode
{
    LTDataType data;
    struct LinkNode* prev;
    struct LinkNode* next;
}LNode;

void ListPrint(LNode* phead)//´òÓ¡
{
	LNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


LNode* CreatLNode(LTDataType x)
{
    LNode* NewNode = (LNode*)malloc(sizeof(LNode));
    NewNode->data = x;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
}

LNode* ListInit()
{
    LNode* phead = CreatLNode(-1);
    phead->next = phead;
    phead->prev = phead;
    return phead;
}

void ListPushBack(LNode* phead,LTDataType x)//Î²²å
{
	//assert(phead);
	LNode* tail = phead->prev;
	LNode* NewNode = CreatLNode(x);
	tail->next = NewNode;
	NewNode->prev = tail;
	NewNode->next = phead;
	phead->prev = NewNode;
	//ListInsert(phead, x);
}

void ListPushHead(LNode* phead, LTDataType x)  //Í·²å·¨
{
    LNode* front = phead->next;
    LNode* NewNode = CreatLNode(x);
    phead->next = NewNode;
    NewNode->prev = phead;
    NewNode->next = front;
    front->prev = NewNode;
}

void ListPushFront(LNode* phead)//Í·É¾
{
	assert(phead);
	LNode* first = phead->next;
	LNode* second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;
}

void ListDelateBack(LNode* phead)//Î²É¾
{
	assert(phead);
	LNode* tail = phead->prev;
	LNode* tailPrev = tail->prev;
	free(tail);
	tailPrev->next = phead;
	phead->prev = tailPrev;
}

int ListSize(LNode* phead)
{
	assert(phead);
	int size = 0;
	LNode* cur = phead->next;
	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}
	return size;
}




int main()
{
    LNode *L;
    int size;
    L = ListInit();
    ListPushBack(L,1);
    ListPushBack(L,2);
    ListPrint(L);
    size = ListSize(L);
    printf("%d ",size);

    system("pause");
}




