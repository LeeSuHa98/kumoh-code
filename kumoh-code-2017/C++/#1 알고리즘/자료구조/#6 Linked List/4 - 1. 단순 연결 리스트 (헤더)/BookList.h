#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum menus {INSERT = 1, DELETE, DISPLAY, EXIT};

class BookList;

class Book
{
	friend class BookList;
private:
	string book_no;	// ������ȣ
	string name;	// ������
	Book* link;	// ���� ��� ��ũ
public:
	Book() { book_no = ""; name = ""; link = nullptr; }
	Book(string book_no, string name)
	{
		this->book_no = book_no;
		this->name = name;
		link = nullptr;
		
	}
	~Book() {}

	string getBookNo() { return book_no; }
	string getName() { return name; }
	Book* getLink() { return link; }
};

class BookList
{
private:
	Book* head;	// ���
public:
	BookList() { head = new Book(); }	// first�� 0���� �ʱ�ȭ
	~BookList()	// �Ҹ���
	{
		Book* pNode = head;	//	����

		while (1)
		{
			if (pNode->link == nullptr)
			{
				break;
			}
			Book* tmp = pNode->link;	// ������ �ӽð���
			pNode->link = tmp->link;	// ���� ���� �̵�
			delete tmp;	// ���� ����
		}
	}
	
	Book* getFirst() { return head->link; }
	// ü������ ����
	void insertBook(Book* b);
	void deleteBook(string book_no);
	void displayBook();
};