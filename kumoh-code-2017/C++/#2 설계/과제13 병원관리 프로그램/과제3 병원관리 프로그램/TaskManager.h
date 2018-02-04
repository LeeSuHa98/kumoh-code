#pragma once
#include "PatientList.h"
#include "RoomList.h"
#include "RoomChangeHistory.h"
#include "StaffList.h"
#include "StaffAssignHistory.h"
#include "CheckSheetList.h"

class TaskManager
{
private:
	// ȯ�� �� ����(�Ż��ڷ�, ���� �̵� ����, ��� �Ƿ��� ���� ����, �˻���)
	void displayDetailsOfPatient(PatientList& p_list, RoomChangeHistory& rc_history, StaffAssignHistory& sa_history, CheckSheetList& cs_list);
	// ���� ���� ���
	void displayListOfAvailableRooms(RoomList& r_list);
	// ���Ǻ� ȯ�� ���
	void displayListOfPatientsInRoom(PatientList& p_list, RoomList& r_list);
	// �Ƿ��κ� ��� ȯ�� ���
	void displayListOfPatientsByStaff(PatientList& p_list, StaffList& s_list);
	// �Ƿ���(����) ����
	void assignListOfStaff(StaffList& s_list);
	// ��ġ�� ����
	void assignListOfDoctorsByStaff(PatientList& p_list, StaffList& s_list, StaffAssignHistory& sa_history);
	// ��� ��ȣ�� ����
	void assignListOfNurseByStaff(PatientList& p_list, StaffList& s_list, StaffAssignHistory& sa_history);
public:
	// �Կ�
	void checkIn(PatientList& p_list);
	// ���
	void checkOut(PatientList& p_list);
	// �����̵�
	void changeRoom(RoomChangeHistory& rc_history, PatientList& p_list, RoomList& r_list);
	// �Ƿ���(����, �ǻ�, ��ȣ��) ����
	void assignStaff(PatientList& p_list, StaffList& s_list, StaffAssignHistory& sa_history);
	// �˻��� ����
	void registerCheckSheet(PatientList& p_list, CheckSheetList& cs_list, StaffList& s_list);
	// �ڷ� ��ȸ
	void processQuery(PatientList& p_list, RoomList& r_list, RoomChangeHistory& rc_history, StaffList& s_list, StaffAssignHistory& sa_history, CheckSheetList& cs_list);
};