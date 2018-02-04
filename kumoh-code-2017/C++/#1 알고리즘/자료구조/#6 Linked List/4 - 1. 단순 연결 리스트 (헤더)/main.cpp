#include "BookList.h"
#include "IoHandler.h"
#include "FileHandler.h"
#include "TaskManager.h"

int main(int argc, char argv[])
{
	BookList b_list;
	IoHandler ioh;
	FileHandler fh;
	TaskManager tm;

	//load from file
	fh.loadBookList("book.txt", b_list);
	//fh.loadBookList(argv[0], b_list);

	ioh.putMenu();

	while (1)
	{
		int menu = ioh.getMenu();
		//if (menu == EXIT) break;

		switch (menu)
		{
		case INSERT:
			// 새 도서 입력
			tm.registerBook(b_list);
			break;
		case DELETE:
			// 도서 삭제
			tm.unregisterBook(b_list);
			break;
		case DISPLAY:
			// 도서명 순으로 전체 출력
			tm.printBook(b_list);
			break;
		case EXIT:
			// 파일에 저장하고 종료
			fh.saveBookList("book.txt", b_list);
			//fh.saveBookList(argv[0], b_list);
			exit(1);
		}
	}

}