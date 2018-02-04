
import java.util.*;

public class MinusAccount extends Account
{
    private char credit;
    
    void CreateAccountNumber()
    {
        String name,address,birthday,phoneNumber;
        int year,month,day,hour,min,sec;
        System.out.print("이름 입력 : ");
        name = scan.nextLine();
        System.out.print("주소 입력 : ");
        address = scan.nextLine();
        System.out.print("생일 입력 : ");
        birthday = scan.nextLine();
        System.out.print("전화번호 입력 ex)051)501-5043 : ");
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
            if(storeUser[wantIndex].money + creditMoney < wantMoney)     System.out.println("출금 실패 입력을 다시하세요.");
            else 
            {
                storeUser[wantIndex].money -= wantMoney;
                System.out.println("출금 성공");
                tranInfo.get(wantIndex).AddWithdrawInformation(wantMoney);
            }
        }
        else System.out.println("데이터를 찾을 수 없습니다.");
    }
    void SendMoney(long findAccountNumber,long sendAccountNumber,long wantMoney)
    {
        int findIndex,sendIndex;
        findIndex = FindAccoutNumber(findAccountNumber);
        sendIndex = FindAccoutNumber(sendAccountNumber);
        if(findIndex == -1 || sendIndex == -1)
        {
            if(findIndex == -1) System.out.println("해당 계좌번호 찾을 수 없습니다.");
            else if(sendIndex == -1) System.out.println("보내려는 계좌번호를 찾을 수 없습니다.");
        }
        else
        {
            if(storeUser[findIndex].money < wantMoney)  System.out.println("해당 금액으로는 계좌 이체가 불가능합니다.");
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
