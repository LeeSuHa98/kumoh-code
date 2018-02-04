package 학생관리;

public class Student
{
	private int id; // 학번
	private String name; // 이름
	private int age; // 나이
	private String phone; // 전화번호
	
	public Student(int id, String name, int age, String phone)
	{
		this.id = id;
		this.name = name;
		this.age = age;
		this.phone = phone;
	}
	
	public int getId(){return id;}
	public String getName(){return name;}
	public int getAge(){return age;}
	public String getPhone(){return phone;}
}
