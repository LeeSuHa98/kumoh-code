#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum menus { INSERT = 1, DELETE, DISPLAY, DISPLAY_REVERSE, DISPLAY_FIND, DISPLAY_RVERSE_FIND, EXIT };

class BookList;

class Book
{
	friend class BookList;
	friend class OperatorHandler;
private:
	string book_no;	// ������ȣ
	string name;	// ������
	Book* leftLink;	// ���� ��� ���� ��ũ
	Book* rightLink; // ���� ��� ������ ��ũ
public:
	Book() { book_no = ""; name = ""; leftLink = rightLink = nullptr; }
	Book(string book_no, string name)
	{
		this->book_no = book_no;
		this->name = name;
		leftLink = rightLink = nullptr;
	}
	~Book() {}

	string getBookNo() { return book_no; }
	string getName() { return name; }
	Book* getLeftLink() { return leftLink; }
	Book* getRightLink() { return rightLink; }
};

class BookList
{
private:
	Book* head;	// ���
public:
	BookList() { head = new Book(); }	// first�� 0���� �ʱ�ȭ
	~BookList()
	{}
	Book* getHead() { return head; }
	Book* getFirst() { return head->rightLink; }
	Book* getLast() { return head->leftLink;}
	// ü������ ����
	Book* findBook();	// Ư�� ������ �˻�
	void insertBook(Book* b);	// ����
	void deleteBook(Book* book_no);	// ����
	void displayBook();	// ��ü ���
	void displayReverseBook();	// ���� ���
	void displayFindBook(Book* book_no);	// Ư�� ��������� ���
	void displayReverseFindBook(Book* book_no);	// Ư�� ��������� ù ��������� ���� ���
};