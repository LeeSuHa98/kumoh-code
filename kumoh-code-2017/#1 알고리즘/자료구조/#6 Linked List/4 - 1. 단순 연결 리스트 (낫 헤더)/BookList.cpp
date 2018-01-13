#include "BookList.h"

void BookList::insertBook(Book* b)
{
	Book* curNode = first;	// ���� ����� ������ ���
	Book* preNode = nullptr; // ���� ��尡 �������

	if (first == nullptr)	// ����� ������� ��
	{
		first = b;	// ����� ���ο� ��� ����
	}
	else
	{
		// �������� ��带 �о����
		for (; curNode; preNode = curNode, curNode = curNode->link)
		{
			if (curNode->link == nullptr)	// ���� ��尡 ����Ű�� ���� ��� ������
			{
				curNode->link = b;	// ����
				break;
			}
			if (b->name < curNode->name)	// ���ο� ��尡 ���� ��尡 ����Ű�� �ͺ��� ������
			{
				b->link = curNode;	// ���ο� ��尡 ����Ű�� ���� ������
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
	Book* curNode = first;	// ���� ����� ������ ���
	Book* preNode = nullptr; // ���� ��尡 �������
	
	if (first == nullptr)	// ����� ������� ��
	{
		cout << "list is null!";
	}
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
			if (preNode == nullptr)	// ����� ó���� ������
			{
				if (curNode->link == nullptr)	// ��尡 �Ѱ�
				{
					Book* tempFirst = curNode->link;	// ���� ��尡 ����Ű�� ��
					delete curNode;	// ���� ��� ���� ���� (����)
					first = tempFirst;
					break;
				}
				else // ��尡 �ټ�
				{
					preNode = curNode;	// ���� ���� ���� ���
					first = curNode->link;	// ����� ���� ��尡 ����Ű�� ��
					delete preNode;	// ���� ��� ���� ���� (����)
					break;
				}
			}
			else if (curNode->link == nullptr)	// ����� ���� ������
			{
				preNode->link = nullptr;	// ���� ��尡 ����Ű�� ���� ���
				delete curNode;	// ���� ��� ���� ���� (����)
				break;
			}
			else // �߰� ��� ��ġ
			{
				preNode->link = curNode->link;	// ���� ��尡 ����Ű�� ���� ���� ��尡 ����Ű�� ��
				delete curNode;	// ���� ��� ���� ���� (����)
				break;
			}
		}
	}
}

void BookList::displayBook()
{
	Book* curNode = first;	// ���� ���� ����� ����Ű�� ��

	if (first == nullptr)
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