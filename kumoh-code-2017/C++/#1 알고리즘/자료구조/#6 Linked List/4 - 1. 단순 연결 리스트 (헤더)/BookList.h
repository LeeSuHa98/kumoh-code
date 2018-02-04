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
	string book_no;	// 도서번호
	string name;	// 도서명
	Book* link;	// 현재 노드 링크
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
	Book* head;	// 헤더
public:
	BookList() { head = new Book(); }	// first를 0으로 초기화
	~BookList()	// 소멸자
	{
		Book* pNode = head;	//	시작

		while (1)
		{
			if (pNode->link == nullptr)
			{
				break;
			}
			Book* tmp = pNode->link;	// 해제할 임시공간
			pNode->link = tmp->link;	// 다음 노드로 이동
			delete tmp;	// 동적 해제
		}
	}
	
	Book* getFirst() { return head->link; }
	// 체인조작 연산
	void insertBook(Book* b);
	void deleteBook(string book_no);
	void displayBook();
};