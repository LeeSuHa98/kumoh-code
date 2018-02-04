#include "BookList.h"
#include "IoHandler.h"
#include "FileHandler.h"
#include "TaskManager.h"

//�ȵ��ư��� �ڵ��Դϴ�. ���ΰ� �����Ͽ� ���踸 ������ �Ͽ����ϴ�

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
			// �� ���� �Է�
			tm.registerBook(b_list);
			break;
		case DELETE:
			// ���� ����
			tm.unregisterBook(b_list);
			break;
		case DISPLAY:
			// ������ ������ ��ü ���
			tm.printBook(b_list);
			break;
		case DISPLAY_REVERSE:
			// ������ �������� ��ü ���
			tm.printReverseBook(b_list);
			break;
		case DISPLAY_FIND:
			// Ư�� ��������� ��ü ���
			tm.printFindBook(b_list);
			break;
		case DISPLAY_RVERSE_FIND:
			// Ư�� ��������� ù ��������� ���� ���
			tm.printReverseFindBook(b_list);
			break;
		case EXIT:
			// ���Ͽ� �����ϰ� ����
			fh.saveBookList("book.txt", b_list);
			//fh.saveBookList(argv[0], b_list);
			exit(1);
		}
	}
}