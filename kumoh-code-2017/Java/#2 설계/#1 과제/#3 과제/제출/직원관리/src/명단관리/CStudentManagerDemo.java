package 명단관리;

public class CStudentManagerDemo 
{
	public static void main(String[] args) 
	{
		try {
//			Student studentObj = new Student("이순신", 2, "김현수", "충무시");
//			studentObj.studentShow();
//			studentObj.changeAddress("서울시");
//			studentObj.studentShow();
			
			Under underObj = new Under("15670428", "학부", "이순신", 2, "김현수", "충무시", 3.8, "석향");
			underObj.show(); 
			underObj.changeAddress("서울시");
			underObj.changeCircle("AIT"); // underObj.changeCircle("");로
			//바꾸어실행한후예외발생확인요
//			underObj.changeCircle("");
			underObj.show();

			Graduate graduateObj = new Graduate("16000001", "대학원", "장길산", 1, "김태남", "황해도", 3.5, "AI");
			graduateObj.show();
			graduateObj.changeAddress("서울시");
			graduateObj.changeMajor("PL"); //  graduateObj.changeMajor("");로 
			// 바꾸어실행한후예외발생확인요
//			graduateObj.changeMajor("");
			graduateObj.show();

			IndustryGraduate industryGraduateObj = new IndustryGraduate("15000001", "대학원", "홍길동", 1, "박인용", "구미시", 4.0, "AI", "삼성", "신기술", "책임");

			industryGraduateObj.show();
			industryGraduateObj.changeAddress("서울시");
			industryGraduateObj.changeMajor("PL");
			industryGraduateObj.changePosition("이사");
			//industryGraduateObj.changePosition("");로
			//바꾸어실행한후예외발생확인요
//			industryGraduateObj.changePosition("");
			industryGraduateObj.show();
			
			CStudentManager csm = new CStudentManager();
			
			csm.loadStudentFile("student.csv");
			csm.printStudent();
			csm.insertStudent("20091003", "대학원", "조현우", 2, "이해연", "포항시", 4.1, "영상처리");
			csm.insertStudent("20091004", "대학원", "이명환", 2, "김병만", "안동시", 4.05);
			csm.insertStudent("20100003", "학부", "오대석", 2, "김선명", "대구시", 3.8);
			csm.insertStudent("20100019", "학부", "티파니", 2, "김병만", "서울특별시", 4.35, "셈틀꾼");
			System.out.println("- Print Students ----------------------------------------------");
			csm.printStudent();
			System.out.println("- Sort By GPA ---------------------------------------------");
			csm.sortByGPA();
			csm.printStudent();
			System.out.println("- Search By Advisor ------------------------------------------");
			csm.searchByAdvisor("이해연");
			csm.deleteStudent("20100002");
			csm.deleteStudent("20100019");
			csm.saveStudentFile("student_modify1.csv");
			csm.clearAll();
			System.out.println("---------------------------------------------------------");
			csm.loadStudentFile("student_modify1.csv");
			csm.printStudent();
		}
		catch (MyException e) 
		{
			System.out.println("오류번호: " + e.getCode());
			System.out.println("오류내용: " + e.getDescription());
		}
	}
}
