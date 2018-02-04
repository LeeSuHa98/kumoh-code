public class Student { // 학생은 기본 데이터 입력은 생성자로 각 변수는 get함수를 가짐
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

class StudentList// 학생 리스트 count를 통해 현재 채워져있는 값을 알수있다. 
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