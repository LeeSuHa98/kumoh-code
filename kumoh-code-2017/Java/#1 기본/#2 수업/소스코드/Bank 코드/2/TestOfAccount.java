import java.util.*;

public class TestOfAccount
{
    static void MenuViewer()
    {
        System.out.println("1. 계좌 개설");
        System.out.println("2. 예금주 정보 조회");
        System.out.println("3. 잔고 조회");
        System.out.println("4. 입금");
        System.out.println("5. 출금");
        System.out.println("6. 조회");
        System.out.println("7. 계좌 이체");
        System.out.println("8. 종료");
        System.out.print("입력하세요 : ");
    }
    public static void main(String[] args)
    {
        MinusAccount storeMemory = new MinusAccount();
        Scanner scan = new Scanner(System.in);
        int choice,choiceinfo;
        long findAccountNumber,wantMoney,sendAccountNumber;
        boolean Stop = true;
        
        while(Stop)
        {
            MenuViewer();
            choice = scan.nextInt();
            switch(choice)
            {
                case 1 :
                    storeMemory.CreateAccountNumber();
                    break;
                    
                case 2:
                    System.out.print("계좌번호 입력 : ");
                    findAccountNumber = scan.nextLong();
                    storeMemory.FindData(findAccountNumber);
                    break;
                    
                case 3:
                    System.out.print("계좌번호 입력 : ");
                    findAccountNumber = scan.nextLong();
                    storeMemory.getMoney(findAccountNumber);
                    break;
                    
                case 4 :
                    System.out.print("계좌번호 입력 : ");
                    findAccountNumber = scan.nextLong();
                    System.out.print("입금하실 금액 : ");
                    wantMoney = scan.nextLong();
                    storeMemory.Deposit(findAccountNumber, wantMoney);
                    break;
                    
                case 5:
                    System.out.print("계좌번호 입력 : ");
                    findAccountNumber = scan.nextLong();
                    System.out.print("입금하실 금액 : ");
                    wantMoney = scan.nextLong();
                    storeMemory.Withdraw(findAccountNumber, wantMoney);
                    break;
                            
                case 6:
                    System.out.print("계좌번호 입력 : ");
                    findAccountNumber = scan.nextLong();
                    System.out.print("입금이면 1을 출금이면 2를 입력하세요.");
                    choiceinfo = scan.nextInt();
                    
                    if(choiceinfo == 1)
                        storeMemory.DepositInformation(findAccountNumber);
                    else if(choiceinfo == 2)
                        storeMemory.WithdrawInformation(findAccountNumber);
                    else
                        System.out.println("잘못 입력하셨습니다.");
                    
                    break;
                case 7:
                    System.out.print("계좌번호 입력 : ");
                    findAccountNumber = scan.nextLong();
                    System.out.print("보내실 계좌번호 입력 : ");
                    sendAccountNumber = scan.nextLong();
                    System.out.print("보내실 금액을 입력하세요 : ");
                    wantMoney = scan.nextLong();
                    storeMemory.SendMoney(findAccountNumber, sendAccountNumber, wantMoney);
                    break;
                case 8:
                    System.out.println("종료되었습니다.");
                    Stop = false;
             }
        }
    }
}