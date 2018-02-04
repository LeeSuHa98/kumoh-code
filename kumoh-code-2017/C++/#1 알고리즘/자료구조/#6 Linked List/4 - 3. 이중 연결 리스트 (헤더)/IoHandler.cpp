#include "IoHandler.h"

int IoHandler::getMenu()
{
	int menu;

	cout << "���ϴ� ����� �����ϼ��� : ";

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
	cout << "(1) �� ���� �Է�" << endl;
	cout << "(2) ���� ����" << endl;
	cout << "(3) ������ ������ ��ü ���" << endl;
	cout << "(4) ������ �������� ��ü ���" << endl;
	cout << "(5) Ư�� ��������� ��ü ���" << endl;
	cout << "(6) Ư�� ��������� ù��������� ���� ���" << endl;
	cout << "(7) ���Ͽ� �����ϰ� ����" << endl;
	cout << "==========================================" << endl;
}

Book* IoHandler::getBook()
{
	string book_no;
	string name;
	string book_text;

	cout << "������ȣ�� �������� �Է��ϼ��� : ";
	cin.ignore();	// �Է� ���ۿ� �ִ� ��� ������ �����ؼ� ����
	getline(cin, book_text);

	book_text = book_text.substr(book_text.find_first_not_of(' '), book_text.length());		// ������� ��ü ���ڿ��� ���̸�ŭ �о����

	book_no = book_text.substr(0, book_text.find_first_of(' '));	// 0���� ������� �о����
	name = book_text.substr(book_text.find_first_of(' ') + 1, book_text.length());	// ���� ã�� ������� ���̸�ŭ �о����

	name = name.substr(name.find_first_not_of(' '), book_text.length());	// ������� �ش� ���ڿ��� ���̸�ŭ �о����	
	name = name.substr(0, name.find_last_not_of(' ') + 1);	// �ٽ� 0���� ������� �о����

	Book* b = new Book(book_no, name);	// ���ο� ���

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