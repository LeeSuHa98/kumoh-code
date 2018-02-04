package com.ktds.jmj;

import java.util.Calendar;
import java.util.InputMismatchException;
import java.util.Scanner;

public class KBprogram {
	
	private int choice; // 메뉴선택
	private KBstar kb;
	private CustomerVO customer;
	private CustomerManage manage;
	private ScannerManage scan;
	private boolean result;
	
	public KBprogram() {
		this.kb = new KBstar();
		this.customer = new CustomerVO();
		this.manage = new CustomerManage();
		this.scan = new ScannerManage();
	}
	
	public int getChoice() {
		return choice;
	}

	public void setChoice() { // choice 에 대한 InputMismatchException예외처리
		while(true){
			try{
				this.choice = scan.inputScannerInt();
				break;
			}
			catch(InputMismatchException ime){
				System.out.println("1,2,3,4,5 중에 입력해주세요.");
			}
		}
	}

	public void startProgram() {
		int choice = 0;
		kb.setTotalMoney(1000000000); // 초기 은행 돈 10억으로 설정
		while ( true ) {
			System.out.println("========KB 국민은행 대출========");
			System.out.println("1.대출");
			System.out.println("2.돈갚기");
			System.out.println("3.대출내역보기");
			System.out.println("4.파산신청");
			System.out.println("5.종료");
			System.out.println("==============================="); // 메뉴
			
			this.setChoice();
			choice = this.getChoice(); // choice 입력받고 예외처리
			
			if ( choice == 1 ) {
				while(true){
					System.out.println("이름, 번호, 빌리고 싶은 돈, 담보를 입력하세요.(최대 대출 가능액: 1억)");
					String name = scan.inputScanner();
					if(scan.checkScanner("^[가-힣a-zA-Z]*$", name)){ //이름에 대한 체크
						System.out.println("재입력");
					}
					else{
						if ( this.checkName(name) ){
							String phoneNumber = scan.inputScanner();
							int money = scan.inputScannerInt();// 예외처리해야해
							this.checkInputMoney(name, phoneNumber, money);
							kb.printBankInfo(); // 대출 후 은행 돈 출력
							break;
						}
						else {
							System.out.println("새로운 정보로 가입해주세요.");
						}
					}//else
				}//while
			}//if
			else if ( choice == 2 ) { // 돈갚기
				while (true) {
					System.out.println("이름을 입력해주세요.");
					String searchName = scan.inputScanner();
					if(scan.checkScanner("^[가-힣a-zA-Z]*$", searchName)){ //searchName  체크
					}
					else{
						if ( this.returnMoney(searchName) ){
							break;
						}
						else {
							System.out.println(searchName + "의 고객 정보가 없습니다.");
							break;
						}//else					
					}//else
				}//while
			}//else if
			else if ( choice == 3 ) { // 대출내역 확인
				while(true){
					System.out.println("이름을 입력해주세요.");
					String searchName = scan.inputScanner();
					if ( scan.checkScanner("^[가-힣a-zA-Z]*$", searchName) ){// searchName 체크
					}
					else {
						this.searchMyInfo(searchName);
						kb.printBankInfo(); // 은행정보 출력
						break;
					}
				}
			}
			else if ( choice == 4 ) { // 파산신청
				while (true) {
					System.out.println("이름을 입력하세요.");
					String deleteName = scan.inputScanner();
					if ( scan.checkScanner("^[가-힣a-zA-Z]*$", deleteName) ){ // deleteName 체크
					}
					else{ 
						this.bankruptcy(deleteName);
						kb.printBankInfo();//은행정보 출력
						break;
					}//if
				}//while
			}//else if
			else if ( choice == 5){//프로그램 종료
				System.exit(0);
			}
		}//while
	}
	
	/**
	 * 돈빌리기
	 */
	public void loanMoney( int money ) {
		int out = kb.getTotalMoney() - money; // 은행돈에서 빌린돈 빼
		kb.setTotalMoney(out); // 그돈을 은행 총금액에 넣어
		System.out.println(money + "원의 돈을 빌렸습니다.");
	}
	
	/**
	 * 돈 갚기
	 */
	public void repayMoney (CustomerVO customer, int money ){
		customer.setRepayMoney(money); // 고객이 갚은 돈 쌓기
		kb.setTotalMoney(kb.getTotalMoney() + money); // 은행에 갚은 돈 만큼 총금액에 추가
		System.out.println(money + "만큼의 돈을 갚았습니다.");
	}
	
	/**
	 * 은행돈 0원인지 확인
	 */
	public void checkMoney(){ // 은행에 남은돈 확인
		if ( kb.getTotalMoney() == 0 ) {
			System.exit(0); // 은행돈이 0원이면 종료
		}
	}
	
	public void checkInputMoney( String name, String phoneNumber, int money ) { // inputMoney를 체크하는 메소드
		if (money > kb.MAX_LOAN){ // 1억 이상 빌리면 재입력
			System.out.println("1억 까지만 빌릴 수 있습니다.");
		}
		else if(money > kb.getTotalMoney()) { // 은행에 있는 돈보다 대출하려는 돈이 크면
			System.out.println("은행에 돈이 모자릅니다.");
		}
		else {
			String dambo = scan.inputScanner();
			if(scan.checkScanner("^[가-힣a-zA-Z]*$", dambo)){ // 담보에 대한 체크
				System.out.println("재입력");
			}
			else{
				manage.signUp(name, phoneNumber, money, dambo); // 가입 (대출 진행)
				this.loanMoney(money); // 돈 대출
				this.checkMoney(); // 은행에 있는 돈이 0원인지 확인
			}
		}
	}
	
	/**
	 * 이름을 받아 파산하는 메소드
	 * @param deleteName
	 */
	public void bankruptcy(String deleteName) { // 파산하는 메소드
		if ( this.result = manage.deleteCustomerByName(deleteName) ){ //존재하면
			System.out.println("가진 재산이 얼마니?");
			int asset = scan.inputScannerInt(); // 가진 재산 받기 예외처리 해야하는데.....
			manage.failLife(manage.getInfo(deleteName), asset); // 파산메소드로 ㄱ.ㄱ
		}
		else{ //이름이 존재하지않으면
			System.out.println(deleteName+"의 정보가 없습니다.\n");
		}//else
	}
	
	/**
	 * 이름을 입력하여 대출 내역을 확인
	 * @param searchName
	 */
	public void searchMyInfo(String searchName) { // 내가 빌린 돈의 정보를 찾는다.
		if ( this.result = manage.getCustomerByName(searchName)) { 
			manage.printInfo(manage.getInfo(searchName));//해당하는 정보 출력
			System.out.println("");
		}
		else { 
			System.out.println(searchName + "의 고객 정보가 없습니다.");
		}
	}
	
	/**
	 * 빌린 돈을 갚는 메소드
	 * @param searchName
	 * @return
	 */
	public boolean returnMoney( String searchName) { // 돈 갚을 때 
		if (this.result = manage.getCustomerByName(searchName) ){
		manage.printInfo(manage.getInfo(searchName)); // 찾은정보 출력
		int totalLoan = manage.totalLoan(manage.getInfo(searchName)) - manage.getInfo(searchName).getRepayMoney(); //갚아야할 돈 계산
		System.out.println("");					
		kb.printBankInfo();//은행 정보 출력
		System.out.println("지금 까지 갚은돈" + manage.getInfo(searchName).getRepayMoney()); 
		System.out.println("갚아야할 돈은 " + totalLoan + "입니다."); // 
		while(true){
			System.out.println("얼마를 갚을 건가요?");
			int money = scan.inputScannerInt();
				if ( money > totalLoan){ //갚아야할 돈보다 많으면
					System.out.println("그렇게 많이 안줘도 되는데...;;");
				}
				else if ( money == totalLoan){
					System.out.println("돈을 전부 갚으셨습니다.");
					this.repayMoney(manage.getInfo(searchName), money); //돈갚음
					manage.getCustomerList().remove(manage.getInfo(searchName)); //다갚았으니 정보삭제
					System.out.println("정보가 삭제되었습니다.\n");
					break;
				}
				else {
					this.repayMoney(manage.getInfo(searchName), money); // 돈갚음
					kb.printBankInfo();
					System.out.println("");
					break;
				}
				
			}
		return true;
		}
		else{
			return false;
		}
	}
	
	/**
	 * 이미 존재하는 고객인지 체크
	 * @param searchName 입력받은 이름
	 * @return
	 */
	public boolean checkName ( String searchName ){ 
		if ( this.result = manage.getCustomerByName(searchName)) { 
			System.out.println("이미 존재하는 고객입니다.");
			return false;
		}
		else { 
			return true;
		}
		
	}
	
}
