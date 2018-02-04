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
	Book* first;	// 헤더
public:
	BookList() { first = nullptr; }	// first를 0으로 초기화
	~BookList()	// 소멸자
	{
		while (1)
		{
			if (first == nullptr)
			{
				break;
			}
			Book* tmp = first;	// 해제할 임시 공간
			first = first->link;	// 다음 노드로 이동
			delete tmp;	// 동적 해제
		}
	}
	
	Book* getFirst() { return first; }
	// 체인조작 연산
	void insertBook(Book* b);
	void deleteBook(string book_no);
	void displayBook();
};