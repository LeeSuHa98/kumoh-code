public class TemperatureException extends Exception
{
	private int temperature; // ���ܿ� ���� �߰� ����
	
	TemperatureException()
	{
		super("���� �Ұ�");
	}
	TemperatureException(String msg)
	{
		super(msg);
	}
	
	void setTemperature(int t){temperature = t;}
	int getTemperature(){return temperature;}
} // TemperatureException
