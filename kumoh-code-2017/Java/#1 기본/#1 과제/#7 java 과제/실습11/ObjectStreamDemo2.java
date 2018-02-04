import java.io.*;

public class ObjectStreamDemo2
{
	public static void main(String[] args) throws ClassNotFoundException, IOException
	{
		Order[] orders = {
		new Order("10���� ����", 10.0f, 10),
		new Order("��ũ���׽�����", 20.0f, 100),
		new Order("���", 30.0f, 1000)
		};
		
		ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("orders.txt"));
		out.writeObject(orders); // �迭�� ��ü�̹Ƿ� �� ���� writeObject()�� ��
		out.close();
		
		float total = 0.0f;
		Order[] ords;
		ObjectInputStream in = new ObjectInputStream(new FileInputStream("orders.txt"));
		ords = (Order[])in.readObject(); // �� ���� readObject()�� ����, Ÿ�� ��ȯ �ʼ�
		for(Order o : ords)
		{
			System.out.format("You ordered %d unit of %s at $%.1f%n", o.getUnit(), o.getTitle(), o.getPrice());
			total += o.getUnit() * o.getPrice();
		}
		System.out.format("Total: %.2f$", total);
		in.close();
	} // end of main()
} // end of class DataStream2
