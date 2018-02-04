#include "BookList.h"

void BookList::insertBook(Book* b)
{
	Book* curNode = first;	// 현재 노드의 시작은 헤더
	Book* preNode = nullptr; // 이전 노드가 비어있음

	if (first == nullptr)	// 헤더가 비어있을 때
	{
		first = b;	// 헤더에 새로운 노드 삽입
	}
	else
	{
		// 차순으로 노드를 읽어들임
		for (; curNode; preNode = curNode, curNode = curNode->link)
		{
			if (curNode->link == nullptr)	// 현재 노드가 가르키는 곳이 비어 있으면
			{
				curNode->link = b;	// 삽입
				break;
			}
			if (b->name < curNode->name)	// 새로운 노드가 현재 노드가 가르키는 것보다 작으면
			{
				b->link = curNode;	// 새로운 노드가 가르키는 곳이 현재노드
				if (first == curNode)
				{
					first = b;
				}
				else
				{
					preNode->link = b;
				}
				break;
			}
		}
	}
}

void BookList::deleteBook(string book_no)
{
	Book* curNode = first;	// 현재 노드의 시작은 헤더
	Book* preNode = nullptr; // 이전 노드가 비어있음
	
	if (first == nullptr)	// 헤더가 비어있을 때
	{
		cout << "list is null!";
	}
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
			if (preNode == nullptr)	// 노드의 처음과 같으면
			{
				if (curNode->link == nullptr)	// 노드가 한개
				{
					Book* tempFirst = curNode->link;	// 현재 노드가 가르키는 것
					delete curNode;	// 현재 노드 동적 해제 (삭제)
					first = tempFirst;
					break;
				}
				else // 노드가 다수
				{
					preNode = curNode;	// 이전 노드는 현재 노드
					first = curNode->link;	// 헤더는 현재 노드가 가르키는 곳
					delete preNode;	// 이전 노드 동적 해제 (삭제)
					break;
				}
			}
			else if (curNode->link == nullptr)	// 노드의 끝과 같으면
			{
				preNode->link = nullptr;	// 이전 노드가 가르키는 곳을 비움
				delete curNode;	// 현재 노드 동적 해제 (삭제)
				break;
			}
			else // 중간 노드 일치
			{
				preNode->link = curNode->link;	// 이전 노드가 가르키는 곳은 현재 노드가 가르키는 곳
				delete curNode;	// 현재 노드 동적 해제 (삭제)
				break;
			}
		}
	}
}

void BookList::displayBook()
{
	Book* curNode = first;	// 현재 노드는 헤더가 가르키는 곳

	if (first == nullptr)
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