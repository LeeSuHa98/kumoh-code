
import java.util.*;

public class MinusAccount extends Account
{
    private char credit;
    
    void CreateAccountNumber()
    {
        String name,address,birthday,phoneNumber;
        int year,month,day,hour,min,sec;
        System.out.print("�̸� �Է� : ");
        name = scan.nextLine();
        System.out.print("�ּ� �Է� : ");
        address = scan.nextLine();
        System.out.print("���� �Է� : ");
        birthday = scan.nextLine();
        System.out.print("��ȭ��ȣ �Է� ex)051)501-5043 : ");
        phoneNumber = scan.nextLine();
        year = cal.get(Calendar.YEAR);
        month = cal.get(Calendar.MONDAY)+1;
        day = cal.get(Calendar.DATE);
	hour = cal.get(Calendar.HOUR_OF_DAY);
	min = cal.get(Calendar.MINUTE);
	sec = cal.get(Calendar.SECOND);	
        storeUser[userIndex++] = new Customer(name, address, birthday, phoneNumber, year, month, 
day,lastAccountNumber,hour,min,sec);
        tranInfo.add(new Transaction(lastAccountNumber++));
        tranIndex++;
        credit = 'C';
    }
    
    void Withdraw(long findAccountNumber,long wantMoney)
    {
        int wantIndex,creditMoney=0;
        
        wantIndex = FindAccoutNumber(findAccountNumber);
        
        switch(credit)
        {
            case 'A' :
                creditMoney = 1000000;
                break; 
            case 'B' :
                creditMoney = 500000;
                break;
            case 'C' :
                creditMoney = 100000;
                break;
        }
        
        if(wantIndex != -1)
        {
            if(storeUser[wantIndex].money + creditMoney < wantMoney)     System.out.println("��� ���� �Է��� �ٽ��ϼ���.");
            else 
            {
                storeUser[wantIndex].money -= wantMoney;
                System.out.println("��� ����");
                tranInfo.get(wantIndex).AddWithdrawInformation(wantMoney);
            }
        }
        else System.out.println("�����͸� ã�� �� �����ϴ�.");
    }
    void SendMoney(long findAccountNumber,long sendAccountNumber,long wantMoney)
    {
        int findIndex,sendIndex;
        findIndex = FindAccoutNumber(findAccountNumber);
        sendIndex = FindAccoutNumber(sendAccountNumber);
        if(findIndex == -1 || sendIndex == -1)
        {
            if(findIndex == -1) System.out.println("�ش� ���¹�ȣ ã�� �� �����ϴ�.");
            else if(sendIndex == -1) System.out.println("�������� ���¹�ȣ�� ã�� �� �����ϴ�.");
        }
        else
        {
            if(storeUser[findIndex].money < wantMoney)  System.out.println("�ش� �ݾ����δ� ���� ��ü�� �Ұ����մϴ�.");
            else
            {
                storeUser[sendIndex].money += wantMoney;
                tranInfo.get(sendIndex).AddDepositInformation(wantMoney);
                storeUser[findIndex].money -= wantMoney;
                tranInfo.get(findIndex).AddWithdrawInformation(wantMoney);
            }
        }
    }
}
