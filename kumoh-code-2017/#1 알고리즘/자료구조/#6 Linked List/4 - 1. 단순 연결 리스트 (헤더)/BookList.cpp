#include "BookList.h"

void BookList::insertBook(Book* b)
{
	Book* preNode = head;	// 이전 노드의 시작은 헤더
	Book* curNode = preNode->link;	// 현재 노드는 이전 노드가 가르키는 곳

	if (head->link == nullptr)	// 헤더가 가르키는 곳이 비어 있으면
	{	
		head->link = b;	// 헤더가 가르키는 곳에 삽입
		return;
	}
	// 차순으로 노드를 읽어들임
	for (; curNode; preNode = curNode, curNode = preNode->link)
	{
		if (b->name < curNode->name)	// 새로운 노드가 현재 노드가 가르키는 것보다 작으면
		{
			b->link = curNode;	// 새로운 노드가 가르키는 곳에 현재노드 삽입
			preNode->link = b;	// 이전 노드가 가르키는 곳에 새로운 노드 삽입
			return;
		}
	}
	
	preNode->link = b;	// 이전 노드에 새로운 노드 삽입
}

void BookList::deleteBook(string book_no)
{
	Book* preNode = head;	// 이전 노드의 시작은 헤더
	Book* curNode = preNode->link;	// 현재 노드는 이전 노드가 가르키는 곳
	// 차순으로 노드를 읽어들임
	for (; curNode; preNode = curNode, curNode = curNode->link)
	{
		if (curNode == nullptr)	// 현재 노드가 비어 있으면
		{
			cout << "not found book!" << endl;
			break;
		}
		if (curNode->book_no == book_no)	// 현재 노드가 가르키는 것과 새로운 노드의 값이 같으면
		{
			if (curNode->link == nullptr)	// 현재 노드가 가르키는 곳이 비어 있으면
			{
				preNode->link = nullptr;	// 이전 노드가 가르키는 곳을 비움 (현재 노드)
				delete curNode;	// 현재 노드 동적 해제 (삭제)
			}
			else
			{
				preNode->link = curNode->link;	// 이전 노드가 가르키는 곳이 현재 노드가 가르키는 곳이 된다
				delete curNode;	// 현재 노드 동적 해제 (삭제)
			}
			break;
		}
	}
}

void BookList::displayBook()
{
	Book* curNode = head->link;	// 현재 노드는 헤더가 가르키는 곳

	if (head == nullptr)
	{
		cout << "list is null!";
		return;
	}
	do
	{
		cout << curNode->name << " [" << curNode->book_no << "] " << endl;

		curNode = curNode->link;	// 현재 노드는 현재 노드가 가르키는 곳이 된다
	} while (curNode != nullptr);
}