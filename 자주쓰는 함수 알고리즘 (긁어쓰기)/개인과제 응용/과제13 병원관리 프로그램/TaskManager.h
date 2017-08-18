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
	// 환자 상세 내역(신상자료, 병실 이동 내역, 담당 의료인 변경 내역, 검사기록)
	void displayDetailsOfPatient(PatientList& p_list, RoomChangeHistory& rc_history, StaffAssignHistory& sa_history, CheckSheetList& cs_list);
	// 가용 병실 목록
	void displayListOfAvailableRooms(RoomList& r_list);
	// 병실별 환자 명단
	void displayListOfPatientsInRoom(PatientList& p_list, RoomList& r_list);
	// 의료인별 담당 환자 명단
	void displayListOfPatientsByStaff(PatientList& p_list, StaffList& s_list);
	// 의료인(직원) 배정
	void assignListOfStaff(StaffList& s_list);
	// 주치의 배정
	void assignListOfDoctorsByStaff(PatientList& p_list, StaffList& s_list, StaffAssignHistory& sa_history);
	// 담당 간호사 배정
	void assignListOfNurseByStaff(PatientList& p_list, StaffList& s_list, StaffAssignHistory& sa_history);
public:
	// 입원
	void checkIn(PatientList& p_list);
	// 퇴원
	void checkOut(PatientList& p_list);
	// 병실이동
	void changeRoom(RoomChangeHistory& rc_history, PatientList& p_list, RoomList& r_list);
	// 의료인(직원, 의사, 간호사) 배정
	void assignStaff(PatientList& p_list, StaffList& s_list, StaffAssignHistory& sa_history);
	// 검사기록 등재
	void registerCheckSheet(PatientList& p_list, CheckSheetList& cs_list, StaffList& s_list);
	// 자료 조회
	void processQuery(PatientList& p_list, RoomList& r_list, RoomChangeHistory& rc_history, StaffList& s_list, StaffAssignHistory& sa_history, CheckSheetList& cs_list);
};