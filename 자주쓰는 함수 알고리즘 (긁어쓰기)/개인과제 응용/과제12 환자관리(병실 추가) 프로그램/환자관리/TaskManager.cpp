#include "TaskManager.h"

void TaskManager::displayDetailsOfPatient(PatientList& p_list, RoomHistoryList& rh_list)
{
	// 조회 대상 환자의 id를 입력 받는다.
	ioHandler ioh;
	string p_id = ioh.getPatientId(p_list, "\n조회대상 환자번호 : ");

	// 신상자료
	Patient p = p_list.searchPatient(p_id);
	ioh.putPatient(p);

	// 병실이동 내역
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

	ioh.putString("", "병실별 환자 명단");
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


	// 해당 환자의 병실을 찾음
	Room& r = r_list.searchRoom(p.room_no);

	if (r_list.isFull(r)) // 병실의 인원이 꽉찼는지 검사
	{
		cout << "Room is full. Can not insert!" << endl;
		return;
	}

	if (!r_list.isSex(p,r)) // 병실의 성별이 맞는지 검사
	{
		cout << "Gender is mismatch. Can not insert!" << endl;
		return;
	}

	p_list.insertPatient(p);
	// 해당 병실의 현재 인원을 증가
	r.p_count++;

	int index = r_list.findRoom(r);
	r_list.updateRoom(index, r);
}

void TaskManager::checkOut(PatientList& p_list, RoomList& r_list)
{
	ioHandler ioh;
	string p_id = ioh.getPatientId(p_list, "\n퇴원할 환자번호 : ");	// get valid patient id
	Patient p = p_list.searchPatient(p_id);

	p_list.deletePatient(p);				// delete existing patient	
	p.leaving_date = ioh.getCurrentDate();	// update leaving_date
	p.leaving_time = ioh.getCurrentTime();	// update leaving_time
	p_list.insertPatient(p);				// insert updated patient

	// 해당 환자의 병실을 찾음
	Room r = r_list.searchRoom(p.room_no);
	// 해당 병실의 현재 인원을 감소
	r.p_count--;

	int index = r_list.findRoom(r);
	r_list.updateRoom(index, r);
}

void TaskManager::changeRoom(PatientList& p_list, RoomList& r_list)
{
	ioHandler ioh;
	string p_id = ioh.getPatientId(p_list, "\n이동할 환자번호 : ");
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
	case 1:				// 환자 상세 내역(신상자료, 병실이동, 의료인 변경, 검사기록)
		displayDetailsOfPatient(p_list, rh_list);
		break;
	case 2:				// 전체 환자 명단
		p_list.showPatientList();
		break;
	case 3:				// 가용 병실 목록
		displayAvailableOfRoomList(r_list);
		break;
	case 4:				// 병실별 환자 명단
		displayPatientListByRoom(p_list, r_list);
		break;
	}
}