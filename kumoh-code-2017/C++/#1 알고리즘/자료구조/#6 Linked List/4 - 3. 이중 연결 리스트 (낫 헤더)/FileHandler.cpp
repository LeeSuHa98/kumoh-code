#include "FileHandler.h"
#include "OperatorHandler.h"

void FileHandler::loadBookList(string fname, BookList& b_list)
{
	//open file
	ifstream fin;
	fin.open(fname, ios_base::in);
	if (!fin)
	{
		cerr << "\n" << "can't open file!!";
		return;
	}

	// read data from file
	while (!fin.eof()) // read data
	{
		string book_no;
		string name;
		string book_text;

		getline(fin, book_text);

		if (book_text == "") break;

		if (fin.fail()) break;

		book_text = book_text.substr(book_text.find_first_not_of(' '), book_text.length());		// 공백부터 전체 문자열의 길이만큼 읽어들임

		book_no = book_text.substr(0, book_text.find_first_of(' '));	// 0부터 공백까지 읽어들임
		name = book_text.substr(book_text.find_first_of(' ') + 1, book_text.length());	// 먼저 찾은 공백부터 길이만큼 읽어들임

		name = name.substr(name.find_first_not_of(' '), book_text.length());	// 공백부터 해당 문자열의 길이만큼 읽어들임	
		name = name.substr(0, name.find_last_not_of(' ') + 1);	// 다시 0부터 공백까지 읽어들임

		Book* b = new Book(book_no, name);	// 새로운 노드

		b_list.insertBook(b);
	}

	// close file
	fin.close();
}

void FileHandler::saveBookList(string fname, BookList& b_list)
{
	// open file
	ofstream fout;
	fout.open(fname, ios_base::out);
	if (!fout.is_open())
	{
		cerr << "\n" << "can't open file!!";
		exit(1);
	}

	// save data into file
	for (OperatorHandler curNode = b_list.getFirst(); curNode != b_list.getHead(); ++curNode)
	{
		fout << curNode->getBookNo() << " " << curNode->getName() << endl;
	}
	// close file
	fout.close();
}