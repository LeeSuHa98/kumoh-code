package part1;

public class ComparisonSnum
{
	public void compareSnum(Student s1, Student s2)
	{
		if(s1.getSnum() > s2.getSnum())
		{
			System.out.println(s2.getSname() + "����" + s1.getSname() + "�� �й��� �������ϴ�.");
			System.out.println(s1.getSname() + "����" + s2.getSname() + "�� �й��� �������ϴ�.");
		}
	}
}