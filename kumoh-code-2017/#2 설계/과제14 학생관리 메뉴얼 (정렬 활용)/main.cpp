#include "common.h"
#include "Student.h"
#include "StudentList.h"
#include "FileHandler.h"

int main()
{
	// ��ü ����
	StudentList s_list;
	FileHandler fh;

	while (1)
	{
		cout << "---------- �л����� �޴�                 ----------" << endl;
		cout << "---------- 1. �����Է�(����, ����, ����) ----------" << endl;
		cout << "---------- 2. ���Ϸ� ����                ----------" << endl;
		cout << "---------- 3. ���Ϸκ��� �б�            ----------" << endl;
		cout << "---------- 4. ���                       ----------" << endl;
		cout << "---------- 5. ����(�й� ��, ��������)    ----------" << endl;
		cout << "---------- 6. ����(���� ��, ��������)    ----------" << endl;
		cout << "---------- 7. �˻�(�й�)                 ----------" << endl;
		cout << "---------- 8. ��ü ���                  ----------" << endl;
		cout << "---------- 9. ����                       ----------" << endl;
		cout << "���� : ";

		int select;
		cin >> select;

		switch (select)
		{	// ��ü�� Method ȣ��
		case 1:	// ���� �Է�
			s_list.registerStudentRecord();
			break;
		case 2:	// ���Ϸ� ����
			fh.saveStudent("Student.txt", s_list);
			break;
		case 3:	// ���Ϸκ��� �б�
			fh.loadStudent("Student.txt", s_list);
			break;
		case 4:	// ���
			s_list.averageStudentRecord();
			break;
		case 5:	// ����(�й� ��)
			s_list.sortByStudentRecordWithId();
			break;
		case 6:	// ����(���� ��)
			s_list.sortByStudentRecordWithGrade();
			break;
		case 7:	// �˻�(�й�)
			s_list.searchByStudentId();
			break;
		case 8:	// ��ü ���
			s_list.allDisplayStudent();
			break;
		case 9:	// ����
			exit(1);
			break;
		}
	}

	system("pause");
	return 0;
}