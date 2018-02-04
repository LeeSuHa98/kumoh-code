package 명단관리;

public interface Employee
{
	public abstract void changePosition(String position) throws MyException;
	public abstract void show();
}
