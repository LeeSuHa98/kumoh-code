public class Student { // �л��� �⺻ ������ �Է��� �����ڷ� �� ������ get�Լ��� ����
	String name;
	int sNum;
	String jbun;
	String address;
	
	Student(String name,int sNum, String jbun, String address)
	{
		this.name = name;
		this.sNum = sNum;
		this.jbun = jbun;
		this.address = address;
	}
	
	String getName(){return name;}
	int getSnum(){return sNum;}
	String getJbun(){return jbun;}
	String getAddress(){return address;}
	
}

class StudentList// �л� ����Ʈ count�� ���� ���� ä�����ִ� ���� �˼��ִ�. 
{
	private Student[] sList = new Student[100];
	private int count = 0;
	
	StudentList(){}
	
	int getCount(){return count;}
	void insertStd(Student s)
	{
		sList[count++] = s;
	}
	Student getStudents(int index)
	{
		return sList[index];
	}
	
	

}