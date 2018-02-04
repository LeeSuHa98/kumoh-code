package part1;

public class Student
{
	private	String sName;
	private int sNum;
	public Student(String name, int num)
	{
			sName = name;
			sNum = num;
	}

	public int getSnum(){return sNum;}
	public String getSname(){return sName;}

	public void printInfo()
	{
		System.out.println("학번 : " + sNum);
		System.out.println("이름 : " + sName);
		System.out.println();
	}
};