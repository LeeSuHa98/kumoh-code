package practice;

@SuppressWarnings("serial")
public class MyException extends Exception{
	private int check;
	MyException(String num){
		if(num == "1") {
			check = 1;
		}
		else if(num == "2") {
			check = 2;
		}
	
	}
	public void message() {
		if(check == 1) {
			 System.out.println("�̹� ����� �¼��Դϴ�. ����Ұ�");
		}
		else if(check == 2) {
			System.out.println("�̹� ���ڸ��Դϴ�. ������� �Ұ�");
		}
		
	}
}
