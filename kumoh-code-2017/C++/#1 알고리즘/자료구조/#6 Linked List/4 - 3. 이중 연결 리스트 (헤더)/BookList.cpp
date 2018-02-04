#include "BookList.h"
#include "OperatorHandler.h"
#include "IoHandler.h"

Book* BookList::findBook()
{
	IoHandler ioh;
	string book_no = ioh.getString("도서명을 입력하세요 : ");
	
	for (OperatorHandler curNode = getFirst(); curNode != head; ++curNode)
	{
		if (curNode->book_no == book_no)
		{
			return curNode.getLink();
		}
	}
	ioh.putString("not found book!");
	return NULL;
}

void BookList::insertBook(Book* b)
{
	if (head->rightLink == nullptr);
	{
		head->rightLink = b;
		return;
	}
	if (b->book_no > head->leftLink->book_no)
	{
		b->leftLink = head->leftLink;
		b->rightLink = head;
		head->leftLink->rightLink = b;
		head->leftLink = b;
		return;
	}
	else if (b->book_no < head->rightLink->book_no)
	{
		b->leftLink = head;
		b->rightLink = head->rightLink;
		head->rightLink->leftLink = b;
		head->rightLink = b;
		return;
	}
	else
	{
		for (OperatorHandler curNode = head; ;++curNode)
		{
			if (b->book_no < curNode->book_no)
			{
				b->rightLink = curNode.getLink();
				b->leftLink = curNode->leftLink;
				curNode->leftLink->rightLink = b;
				curNode->leftLink = b;
				break;
			}
		}
	}
}

void BookList::deleteBook(string book_no)
{
	IoHandler ioh;

	for (OperatorHandler curNode = head; curNode != head; ++curNode)
	{
		if (curNode->book_no == book_no)
		{
			curNode->leftLink->rightLink = curNode->rightLink;
			curNode->rightLink->leftLink = curNode->leftLink;
			delete curNode.getLink();
			return;
		}
	}
	ioh.putString("not found book!");
}

void BookList::displayBook()
{
	for (OperatorHandler curNode = getFirst(); curNode != head; ++curNode)
	{
		cout << curNode->book_no << " [" << curNode->name << "] " << endl;
	}
}

void BookList::displayReverseBook()
{
	for (OperatorHandler lastNode = getLast(); lastNode != head; --lastNode)
	{
		cout << lastNode->book_no << " [" << lastNode->name << "] " << endl;
	}
}

void BookList::displayFindBook(Book* book_no)
{
	if (book_no != NULL)
	{
		for (OperatorHandler curNode = book_no; curNode != head; --curNode)
		{
			cout << curNode->book_no << " [" << curNode->name << "] " << endl;
		}
	}
}

void BookList::displayReverseFindBook(Book* book_no)
{
	for (OperatorHandler curNode = book_no; curNode != head; ++curNode)
	{
		cout << curNode->book_no << " [" << curNode->name << "] " << endl;
	}
}