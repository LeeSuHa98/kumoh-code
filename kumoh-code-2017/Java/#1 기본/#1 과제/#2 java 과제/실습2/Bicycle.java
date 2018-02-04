public class Bicycle
{
	private int speed; // 加档
	private boolean state; // 惑怕
	
	public Bicycle()
	{
		speed = 0;
		state = false;
	}
	public int getSpeed(){return speed;}
	
	public void stateBicycle()
	{
		if(state == true)
		{
			state = false;
		}
		else
		{
			state = true;
		}
	}
	public void speedUp(int index) // 啊加款青
	{
		if(state == true)
		{
			speed += index;
		}
	}
	public void speedDown(int index) // 皑加款青
	{
		if(state == true)
		{
			speed -= index;
		}
	}
	public void speedEqual(int index) // 殿加款青
	{
		if(state == true)
		{
			speed = index;
		}
	}
}
