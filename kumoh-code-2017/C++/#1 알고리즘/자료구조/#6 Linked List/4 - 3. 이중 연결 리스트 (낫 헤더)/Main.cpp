#include "BookList.h"
#include "IoHandler.h"
#include "FileHandler.h"
#include "TaskManager.h"

//안돌아가는 코드입니다. 공부가 부족하여 설계만 열심히 하였습니다

int main(int argc, char argv[])
{
	BookList b_list;
	IoHandler ioh;
	FileHandler fh;
	TaskManager tm;

	//load from file
	fh.loadBookList("book.txt", b_list);	// Error
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
		case DISPLAY_REVERSE:
			// 도서명 역순으로 전체 출력
			tm.printReverseBook(b_list);
			break;
		case DISPLAY_FIND:
			// 특정 도서명부터 전체 출력
			tm.printFindBook(b_list);
			break;
		case DISPLAY_RVERSE_FIND:
			// 특정 도서명부터 첫 도서명까지 역순 출력
			tm.printReverseFindBook(b_list);
			break;
		case EXIT:
			// 파일에 저장하고 종료
			fh.saveBookList("book.txt", b_list);
			//fh.saveBookList(argv[0], b_list);
			exit(1);
		}
	}
}