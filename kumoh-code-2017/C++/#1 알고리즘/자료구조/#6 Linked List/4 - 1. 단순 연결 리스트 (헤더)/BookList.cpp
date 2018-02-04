#include "BookList.h"

void BookList::insertBook(Book* b)
{
	Book* preNode = head;	// ���� ����� ������ ���
	Book* curNode = preNode->link;	// ���� ���� ���� ��尡 ����Ű�� ��

	if (head->link == nullptr)	// ����� ����Ű�� ���� ��� ������
	{	
		head->link = b;	// ����� ����Ű�� ���� ����
		return;
	}
	// �������� ��带 �о����
	for (; curNode; preNode = curNode, curNode = preNode->link)
	{
		if (b->name < curNode->name)	// ���ο� ��尡 ���� ��尡 ����Ű�� �ͺ��� ������
		{
			b->link = curNode;	// ���ο� ��尡 ����Ű�� ���� ������ ����
			preNode->link = b;	// ���� ��尡 ����Ű�� ���� ���ο� ��� ����
			return;
		}
	}
	
	preNode->link = b;	// ���� ��忡 ���ο� ��� ����
}

void BookList::deleteBook(string book_no)
{
	Book* preNode = head;	// ���� ����� ������ ���
	Book* curNode = preNode->link;	// ���� ���� ���� ��尡 ����Ű�� ��
	// �������� ��带 �о����
	for (; curNode; preNode = curNode, curNode = curNode->link)
	{
		if (curNode == nullptr)	// ���� ��尡 ��� ������
		{
			cout << "not found book!" << endl;
			break;
		}
		if (curNode->book_no == book_no)	// ���� ��尡 ����Ű�� �Ͱ� ���ο� ����� ���� ������
		{
			if (curNode->link == nullptr)	// ���� ��尡 ����Ű�� ���� ��� ������
			{
				preNode->link = nullptr;	// ���� ��尡 ����Ű�� ���� ��� (���� ���)
				delete curNode;	// ���� ��� ���� ���� (����)
			}
			else
			{
				preNode->link = curNode->link;	// ���� ��尡 ����Ű�� ���� ���� ��尡 ����Ű�� ���� �ȴ�
				delete curNode;	// ���� ��� ���� ���� (����)
			}
			break;
		}
	}
}

void BookList::displayBook()
{
	Book* curNode = head->link;	// ���� ���� ����� ����Ű�� ��

	if (head == nullptr)
	{
		cout << "list is null!";
		return;
	}
	do
	{
		cout << curNode->name << " [" << curNode->book_no << "] " << endl;

		curNode = curNode->link;	// ���� ���� ���� ��尡 ����Ű�� ���� �ȴ�
	} while (curNode != nullptr);
}