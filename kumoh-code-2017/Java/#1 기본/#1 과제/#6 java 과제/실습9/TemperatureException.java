public class TemperatureException extends Exception
{
	private int temperature; // 예외에 대한 추가 정보
	
	TemperatureException()
	{
		super("제어 불가");
	}
	TemperatureException(String msg)
	{
		super(msg);
	}
	
	void setTemperature(int t){temperature = t;}
	int getTemperature(){return temperature;}
} // TemperatureException
