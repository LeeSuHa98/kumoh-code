public class Bicycle
{
	private int speed; // �ӵ�
	private boolean state; // ����
	
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
	public void speedUp(int index) // ���ӿ���
	{
		if(state == true)
		{
			speed += index;
		}
	}
	public void speedDown(int index) // ���ӿ���
	{
		if(state == true)
		{
			speed -= index;
		}
	}
	public void speedEqual(int index) // ��ӿ���
	{
		if(state == true)
		{
			speed = index;
		}
	}
}
