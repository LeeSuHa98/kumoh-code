#include "TaskManager.h"
#include "ioHandler.h"

void TaskManager::displayDetailsOfPatient(PatientList& p_list, RoomChangeHistory& rc_history, StaffAssignHistory& sa_history, CheckSheetList& cs_list)
{
	// ��ȸ ��� ȯ���� id�� �Է� �޴´�.
	ioHandler ioh;
	string p_id = ioh.getPatientId(p_list, "��ȸ��� ȯ�ڹ�ȣ : ");

	// �Ż��ڷ�
	Patient p = p_list.searchPatient(p_id);
	ioh.putPatient(p);

	// ���� �̵� ����
	RoomChangeHistory rch = rc_history.searchRoomHistoryForPatient(p);
	rch.showRoomChangeHistory();

	// ��� �Ƿ��� ���� ����
	StaffAssignHistory sah = sa_history.searchStaffHistoryForPatient(p);
	sah.showStaffAssignHistory();

	// �˻���
	CheckSheetList csl = cs_list.searchCheckSheetForPatient(p);
	csl.showCheckSheetList();
}

void TaskManager::displayListOfAvailableRooms(RoomList& r_list)
{
	ioHandler ioh;
	int r_no = ioh.getRoomNo(r_list);
	RoomList rl = r_list.searchAvailableRooms();
	rl.showRoomList();
}

void TaskManager::displayListOfPatientsInRoom(PatientList& p_list, RoomList& r_list)
{
	ioHandler ioh;
	int r_no = ioh.getRoomNo(r_list);
	PatientList pl = p_list.searchPatientsInRoom(r_no);
	pl.showPatientList();
}

void TaskManager::assignListOfStaff(StaffList& s_list)
{
	ioHandler ioh;
	Staff s = ioh.getStaff(s_list);
	s_list.insertStaff(s);
}

void TaskManager::displayListOfPatientsByStaff(PatientList& p_list, StaffList& s_list)
{
	ioHandler ioh;
	string s_id = ioh.getStaffId(s_list, "");
	PatientList pl = p_list.searchPatientInStaff(s_id);
	pl.showPatientList();
}

void TaskManager::assignListOfDoctorsByStaff(PatientList& p_list, StaffList& s_list, StaffAssignHistory& sa_history)
{
	ioHandler ioh;

	StaffAssign sa = ioh.getDoctorAssign(p_list, s_list);
	sa_history.insertStaffAssign(sa);	// insert updated staff

	Patient p = p_list.searchPatient(sa.patient_id);
	p_list.deletePatient(p);	// delete existing patient
	p.doctor_assigned = sa.after_staff;	// update doctor_assigned
}

void TaskManager::assignListOfNurseByStaff(PatientList& p_list, StaffList& s_list, StaffAssignHistory& sa_history)
{
	ioHandler ioh;

	StaffAssign sa = ioh.getNurseAssign(p_list, s_list);
	sa_history.insertStaffAssign(sa);	// insert updated staff

	Patient p = p_list.searchPatient(sa.patient_id);
	p_list.deletePatient(p);	// delete existing patient
	p.nurse_assigned = sa.after_staff;	// update nurse_assigned
}

void TaskManager::checkIn(PatientList& p_list)
{
	ioHandler ioh;
	Patient p = ioh.getPatient(p_list);
	p_list.insertPatient(p);
}

void TaskManager::checkOut(PatientList& p_list)
{
	ioHandler ioh;
	string p_id = ioh.getPatientId(p_list, "����� ȯ�ڹ�ȣ : ");	// get valid patient id

	Patient p = p_list.searchPatient(p_id);
	ioh.putPatient(p);				// display information for patient to leave

	p_list.deletePatient(p);				// delete existing patient
	p.leaving_date = ioh.getCurrentDate();	// update leaving_date
	p.leaving_time = ioh.getCurrentTime();	// update leaving_time
	p_list.insertPatient(p);				// insert updated patient
}

void TaskManager::changeRoom(RoomChangeHistory& rc_history, PatientList& p_list, RoomList& r_list)
{
	ioHandler ioh;
	RoomChange rc = ioh.getRoomChange(p_list, r_list);
	rc_history.insertRoomChange(rc);

	Patient p = p_list.searchPatient(rc.patient_id);
	p_list.deletePatient(p);				// delete existing patient			
	p.room_no = rc.after_room;				// update room no
	p_list.insertPatient(p);				// insert updated patient
}

void TaskManager::assignStaff(PatientList& p_list, StaffList& s_list, StaffAssignHistory& sa_history)
{
	ioHandler ioh;
	int sa_menu = ioh.getStaffAssignMenu();

	switch (sa_menu)
	{
	case 1:				// �Ƿ���(����) ����
		assignListOfStaff(s_list);
	case 2:				// ��ġ�� ����
		assignListOfDoctorsByStaff(p_list, s_list, sa_history);
		break;
	case 3:				// ��� ��ȣ�� ����
		assignListOfNurseByStaff(p_list, s_list, sa_history);
		break;
	}
}

void TaskManager::registerCheckSheet(PatientList& p_list, CheckSheetList& cs_list, StaffList& s_list)
{
	ioHandler ioh;
	CheckSheet cs;
	cs = ioh.getCheckSheet(p_list, s_list, cs_list);
	cs_list.insertCheckSheet(cs);
}

void TaskManager::processQuery(PatientList& p_list, RoomList& r_list, RoomChangeHistory& rc_history, StaffList& s_list, StaffAssignHistory& sa_history, CheckSheetList& cs_list)
{
	ioHandler ioh;
	int q_menu = ioh.getQueryMenu();

	switch (q_menu) 
	{
	case 1:				// ȯ�� �� ����(�Ż��ڷ�, �����̵�)
		displayDetailsOfPatient(p_list, rc_history, sa_history, cs_list);
		break;
	case 2:				// ��ü ȯ�� ���
		p_list.showPatientList();
		break;
	case 3:				// ���� ���� ���
		displayListOfAvailableRooms(r_list);
		break;
	case 4:				// ���Ǻ� ȯ�� ���
		displayListOfPatientsInRoom(p_list, r_list);
		break;
	case 5:				// �Ƿ��κ� ��� ȯ�� ���
		displayListOfPatientsByStaff(p_list, s_list);
	}
}