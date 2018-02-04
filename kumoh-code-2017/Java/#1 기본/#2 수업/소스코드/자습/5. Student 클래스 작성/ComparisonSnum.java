package part1;

public class ComparisonSnum
{
	public void compareSnum(Student s1, Student s2)
	{
		if(s1.getSnum() > s2.getSnum())
		{
			System.out.println(s2.getSname() + "보다" + s1.getSname() + "의 학번이 더높습니다.");
			System.out.println(s1.getSname() + "보다" + s2.getSname() + "의 학번이 더높습니다.");
		}
	}
}