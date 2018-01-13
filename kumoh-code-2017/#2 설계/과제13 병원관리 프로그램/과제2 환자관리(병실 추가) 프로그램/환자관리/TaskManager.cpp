#include "TaskManager.h"

void TaskManager::displayDetailsOfPatient(PatientList& p_list, RoomHistoryList& rh_list)
{
	// ��ȸ ��� ȯ���� id�� �Է� �޴´�.
	ioHandler ioh;
	string p_id = ioh.getPatientId(p_list, "\n��ȸ��� ȯ�ڹ�ȣ : ");

	// �Ż��ڷ�
	Patient p = p_list.searchPatient(p_id);
	ioh.putPatient(p);

	// �����̵� ����
	RoomHistory rh = rh_list.searchRoomHistory(p_id);
	ioh.putRoomHistory(rh);
}

void TaskManager::displayAvailableOfRoomList(RoomList& r_list)
{
	ioHandler ioh;
	for (int i = 0; i < MAX_ROOMS; i++)
	{
		if (r_list.getRoomList(i).capacity > r_list.getRoomList(i).p_count)
		{
			ioh.putRoom(r_list.getRoomList(i));
			ioh.putNewLine();
		}
	}
}

void TaskManager::displayPatientListByRoom(PatientList& p_list, RoomList& r_list)
{
	ioHandler ioh;

	ioh.putString("", "���Ǻ� ȯ�� ���");
	ioh.putNewLine();
	for (int i = 0; i < r_list.getCount(); i++)
	{
		cout << endl << r_list.getRoomList(i).room_no;
		ioh.putNewLine();
		for (int j = 0; j < p_list.getCount(); j++)
		{
			if (p_list.getPatientList(j).room_no == r_list.getRoomList(i).room_no)
			{
				cout << p_list.getPatientList(j).name;
				ioh.putNewLine();
			}
		}
	}
}

void TaskManager::checkIn(PatientList& p_list, RoomList& r_list)
{
	ioHandler ioh;
	Patient p = ioh.getPatient(p_list);


	// �ش� ȯ���� ������ ã��
	Room& r = r_list.searchRoom(p.room_no);

	if (r_list.isFull(r)) // ������ �ο��� ��á���� �˻�
	{
		cout << "Room is full. Can not insert!" << endl;
		return;
	}

	if (!r_list.isSex(p,r)) // ������ ������ �´��� �˻�
	{
		cout << "Gender is mismatch. Can not insert!" << endl;
		return;
	}

	p_list.insertPatient(p);
	// �ش� ������ ���� �ο��� ����
	r.p_count++;

	int index = r_list.findRoom(r);
	r_list.updateRoom(index, r);
}

void TaskManager::checkOut(PatientList& p_list, RoomList& r_list)
{
	ioHandler ioh;
	string p_id = ioh.getPatientId(p_list, "\n����� ȯ�ڹ�ȣ : ");	// get valid patient id
	Patient p = p_list.searchPatient(p_id);

	p_list.deletePatient(p);				// delete existing patient	
	p.leaving_date = ioh.getCurrentDate();	// update leaving_date
	p.leaving_time = ioh.getCurrentTime();	// update leaving_time
	p_list.insertPatient(p);				// insert updated patient

	// �ش� ȯ���� ������ ã��
	Room r = r_list.searchRoom(p.room_no);
	// �ش� ������ ���� �ο��� ����
	r.p_count--;

	int index = r_list.findRoom(r);
	r_list.updateRoom(index, r);
}

void TaskManager::changeRoom(PatientList& p_list, RoomList& r_list)
{
	ioHandler ioh;
	string p_id = ioh.getPatientId(p_list, "\n�̵��� ȯ�ڹ�ȣ : ");
	Patient p = p_list.searchPatient(p_id);

	p_list.deletePatient(p);
	ioh.getRoomHistory(p);
	p.room_no = ioh.getRoomNo(r_list);
	p_list.insertPatient(p);
}

void TaskManager::processQuery(PatientList& p_list, RoomList& r_list, RoomHistoryList& rh_list)
{
	ioHandler ioh;
	int q_menu = ioh.getQueryMenu();

	switch (q_menu) 
	{
	case 1:				// ȯ�� �� ����(�Ż��ڷ�, �����̵�, �Ƿ��� ����, �˻���)
		displayDetailsOfPatient(p_list, rh_list);
		break;
	case 2:				// ��ü ȯ�� ���
		p_list.showPatientList();
		break;
	case 3:				// ���� ���� ���
		displayAvailableOfRoomList(r_list);
		break;
	case 4:				// ���Ǻ� ȯ�� ���
		displayPatientListByRoom(p_list, r_list);
		break;
	}
}