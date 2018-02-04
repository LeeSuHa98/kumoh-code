package 수업;

public class ClassX implements Cloneable
{
	private Account a;
	int x;
	char c;
	
	public void classX(int x, char c)
	{
		this.x = x;
		this.c = c;
	}
	protected Object clone() throws CloneNotSupportedException
	{
		try
		{
			ClassX x = (ClassX)super.clone();
			x.a = (Account)a.clone();
			return x;
		}
		catch(CloneNotSupportedException e)
		{
			e.printStackTrace();
		}
		return null;
	}
}
