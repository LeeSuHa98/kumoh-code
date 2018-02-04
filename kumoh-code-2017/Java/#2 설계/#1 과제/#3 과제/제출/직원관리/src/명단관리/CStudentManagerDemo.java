package ��ܰ���;

public class CStudentManagerDemo 
{
	public static void main(String[] args) 
	{
		try {
//			Student studentObj = new Student("�̼���", 2, "������", "�湫��");
//			studentObj.studentShow();
//			studentObj.changeAddress("�����");
//			studentObj.studentShow();
			
			Under underObj = new Under("15670428", "�к�", "�̼���", 2, "������", "�湫��", 3.8, "����");
			underObj.show(); 
			underObj.changeAddress("�����");
			underObj.changeCircle("AIT"); // underObj.changeCircle("");��
			//�ٲپ�������Ŀ��ܹ߻�Ȯ�ο�
//			underObj.changeCircle("");
			underObj.show();

			Graduate graduateObj = new Graduate("16000001", "���п�", "����", 1, "���³�", "Ȳ�ص�", 3.5, "AI");
			graduateObj.show();
			graduateObj.changeAddress("�����");
			graduateObj.changeMajor("PL"); //  graduateObj.changeMajor("");�� 
			// �ٲپ�������Ŀ��ܹ߻�Ȯ�ο�
//			graduateObj.changeMajor("");
			graduateObj.show();

			IndustryGraduate industryGraduateObj = new IndustryGraduate("15000001", "���п�", "ȫ�浿", 1, "���ο�", "���̽�", 4.0, "AI", "�Ｚ", "�ű��", "å��");

			industryGraduateObj.show();
			industryGraduateObj.changeAddress("�����");
			industryGraduateObj.changeMajor("PL");
			industryGraduateObj.changePosition("�̻�");
			//industryGraduateObj.changePosition("");��
			//�ٲپ�������Ŀ��ܹ߻�Ȯ�ο�
//			industryGraduateObj.changePosition("");
			industryGraduateObj.show();
			
			CStudentManager csm = new CStudentManager();
			
			csm.loadStudentFile("student.csv");
			csm.printStudent();
			csm.insertStudent("20091003", "���п�", "������", 2, "���ؿ�", "���׽�", 4.1, "����ó��");
			csm.insertStudent("20091004", "���п�", "�̸�ȯ", 2, "�躴��", "�ȵ���", 4.05);
			csm.insertStudent("20100003", "�к�", "���뼮", 2, "�輱��", "�뱸��", 3.8);
			csm.insertStudent("20100019", "�к�", "Ƽ�Ĵ�", 2, "�躴��", "����Ư����", 4.35, "��Ʋ��");
			System.out.println("- Print Students ----------------------------------------------");
			csm.printStudent();
			System.out.println("- Sort By GPA ---------------------------------------------");
			csm.sortByGPA();
			csm.printStudent();
			System.out.println("- Search By Advisor ------------------------------------------");
			csm.searchByAdvisor("���ؿ�");
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
			System.out.println("������ȣ: " + e.getCode());
			System.out.println("��������: " + e.getDescription());
		}
	}
}
