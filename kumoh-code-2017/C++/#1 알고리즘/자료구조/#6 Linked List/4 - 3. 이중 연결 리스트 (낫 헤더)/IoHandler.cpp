#include "IoHandler.h"

int IoHandler::getMenu()
{
	int menu;

	cout << "원하는 기능을 선택하세요 : ";

	cin >> menu;
	if (menu >= INSERT && menu <= EXIT)
	{
		return menu;
	}
	cout << endl << "Invalid Selection!! Retry!!";
}

void IoHandler::putMenu()
{
	cout << "==========================================" << endl;
	cout << "(1) 새 도서 입력" << endl;
	cout << "(2) 도서 삭제" << endl;
	cout << "(3) 도서명 순으로 전체 출력" << endl;
	cout << "(4) 도서명 역순으로 전체 출력" << endl;
	cout << "(5) 특정 도서명부터 전체 출력" << endl;
	cout << "(6) 특정 도서명부터 첫도서명까지 역순 출력" << endl;
	cout << "(7) 파일에 저장하고 종료" << endl;
	cout << "==========================================" << endl;
}

Book* IoHandler::getBook()
{
	string book_no;
	string name;
	string book_text;

	cout << "도서번호와 도서명을 입력하세요 : ";
	cin.ignore();	// 입력 버퍼에 있는 모든 내용을 추출해서 버림
	getline(cin, book_text);

	book_text = book_text.substr(book_text.find_first_not_of(' '), book_text.length());		// 공백부터 전체 문자열의 길이만큼 읽어들임

	book_no = book_text.substr(0, book_text.find_first_of(' '));	// 0부터 공백까지 읽어들임
	name = book_text.substr(book_text.find_first_of(' ') + 1, book_text.length());	// 먼저 찾은 공백부터 길이만큼 읽어들임

	name = name.substr(name.find_first_not_of(' '), book_text.length());	// 공백부터 해당 문자열의 길이만큼 읽어들임	
	name = name.substr(0, name.find_last_not_of(' ') + 1);	// 다시 0부터 공백까지 읽어들임

	Book* b = new Book(book_no, name);	// 새로운 노드

	return b;
}

int IoHandler::getInteger(string msg)
{
	int value;

	cout << msg;
	cin >> value;

	return value;
}

string IoHandler::getString(string msg)
{
	string value;

	cout << msg;
	cin >> value;

	return value;
}