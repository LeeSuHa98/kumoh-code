package ��ܰ���;

public class Main 
{
	public static void main(String[] args) 
	{
		try {
			Student studentObj = new Student("�̼���", 2, "������", "�湫��");
			studentObj.show();
			studentObj.changeAddress("�����");
			studentObj.show();
			
			Under underObj = new Under("�к�", "�̼���", 2, "������", "�湫��", "����");
			underObj.show(); 
			underObj.changeAddress("�����");
			underObj.changeCircle("AIT"); // underObj.changeCircle("");��
			//�ٲپ�������Ŀ��ܹ߻�Ȯ�ο�
//			underObj.changeCircle("");
			underObj.show();

			Graduate graduateObj = new Graduate("���п�", "����", 1, "���³�", "Ȳ�ص�", "AI");
			graduateObj.show();
			graduateObj.changeAddress("�����");
			graduateObj.changeMajor("PL"); //  graduateObj.changeMajor("");�� 
			// �ٲپ�������Ŀ��ܹ߻�Ȯ�ο�
//			graduateObj.changeMajor("");
			graduateObj.show();

			IndustryGraduate industryGraduateObj = new IndustryGraduate("���п�", "ȫ�浿", 1, "���ο�", "���̽�", "AI", "�Ｚ", "�ű��", "å��");

			industryGraduateObj.show();
			industryGraduateObj.changeAddress("�����");
			industryGraduateObj.changeMajor("PL");
			industryGraduateObj.changePosition("�̻�");
			//industryGraduateObj.changePosition("");��
			//�ٲپ�������Ŀ��ܹ߻�Ȯ�ο�
//			industryGraduateObj.changePosition("");
			industryGraduateObj.show();
		}
		catch (MyException e) 
		{
			System.out.println("������ȣ: " + e.getCode());
			System.out.println("��������: " + e.getDescription());
		}
	}
}
