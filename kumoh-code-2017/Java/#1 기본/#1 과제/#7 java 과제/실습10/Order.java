import java.io.*;

public class Order implements Serializable
{
	private String title;
	private float price;
	private int unit;
	
	public Order(String title, float price, int unit)
	{
		this.title = title;
		this.price = price;
		this.unit = unit;
	}
	
	public String getTitle(){return title;}
	public float getPrice(){return price;}
	public int getUnit(){return unit;}
}
