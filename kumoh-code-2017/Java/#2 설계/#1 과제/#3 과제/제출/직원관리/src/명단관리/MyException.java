package ��ܰ���;

public class MyException extends Exception
{
	private int code;
	private String description;
	
	public MyException() {}
	public MyException(int code, String description)
	{
		this.code = code;
		this.description = description;
	} 
	
	public int getCode() {return code;}
	
	public String getDescription() {return description;}
}
