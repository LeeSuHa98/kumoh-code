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
	string book_no;	// 도서번호
	string name;	// 도서명
	Book* leftLink;	// 현재 노드 왼쪽 링크
	Book* rightLink; // 현재 노드 오른쪽 링크
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
	Book* head;	// 헤더
public:
	BookList() { head = new Book(); }	// first를 0으로 초기화
	~BookList()
	{}
	Book* getHead() { return head; }
	Book* getFirst() { return head->rightLink; }
	Book* getLast() { return head->leftLink;}
	// 체인조작 연산
	Book* findBook();	// 특정 도서명 검색
	void insertBook(Book* b);	// 삽입
	void deleteBook(Book* book_no);	// 삭제
	void displayBook();	// 전체 출력
	void displayReverseBook();	// 역순 출력
	void displayFindBook(Book* book_no);	// 특정 도서명부터 출력
	void displayReverseFindBook(Book* book_no);	// 특정 도서명부터 첫 도서명까지 역순 출력
};