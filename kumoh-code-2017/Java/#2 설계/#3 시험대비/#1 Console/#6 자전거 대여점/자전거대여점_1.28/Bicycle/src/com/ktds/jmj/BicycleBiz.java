package com.ktds.jmj;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class BicycleBiz {
	
	private List<CustomerVO> customerList;
	private CustomerVO customer;
	private BicycleVO high;
	private BicycleVO mid;
	private BicycleVO low;
	private Scanner input;
	private static Date curDate;
	private int choice; // 메뉴
	private int choiceBicycle; // 자전거선택
	private boolean result;
	
	public BicycleBiz() {
		this.customerList = new ArrayList<CustomerVO>();
		this.input = new Scanner(System.in);
		this.high = new BicycleVO("고급형", 5000, 2);
		this.mid = new BicycleVO("중급형", 3000, 5);
		this.low = new BicycleVO("보급형", 1000, 15);
	}

	public List<CustomerVO> getCustomerList() {
		return customerList;
	}

	public void setCustomerList(List<CustomerVO> customerList) {
		this.customerList = customerList;
	}

	public int getChoice() {
		return choice;
	}

	public void setChoice() { // 메뉴 choice 에 대한 InputMismatchException예외처리
		while(true){
			try{
				this.choice = this.inputScannerInt();
				break;
			}
			catch(InputMismatchException ime){
				System.out.println("1,2 중에 입력해주세요.");
			}
		}
	}
	
	public int getChoiceBicycle() {
		return choiceBicycle;
	}

	public void setChoiceBicycle() { // 자전거 선택 choice 에 대한 예외 처리
		while(true){
			try{
				this.choiceBicycle = this.inputScannerInt();
				break;
			}
			catch(InputMismatchException ime){
				System.out.println("1,2,3 중에 입력해주세요.");
			}
		}
	}

	public int inputScannerInt(){
		input = new Scanner(System.in);
		return input.nextInt();
	}
	
	public void startProgram() {
		int choice = 0;
		
		while ( true ) {
			this.customer = new CustomerVO();
			//customer.bicycleList = new ArrayList<String>();
			System.out.println("=====자전거 대여 프로그램 입니다.=====");
			System.out.println("1. 대여");
			System.out.println("2. 반납");
			System.out.println("3. 종료");
			System.out.println("===================================");
			
			this.setChoice();
			choice = this.getChoice();
			
			if ( choice == 1 ) { // 대여
				int choiceBicycle = 0;				
				while(true){
					System.out.println("빌릴 자전거를 선택하세요.");
					System.out.println("1. 보급");
					System.out.println("2. 중급");
					System.out.println("3. 고급");
					System.out.println("자전거 보유 현황");
					low.currentCount(); // 자전거 정보 출력
					mid.currentCount();
					high.currentCount();
				
					this.setChoiceBicycle(); 
					choiceBicycle = this.getChoiceBicycle();
					
					if ( choiceBicycle == 1 ) { //보급형선택했을 때 
						rent(low);
						this.addNewCustomerInfo(customer);
						break;
					}
					else if ( choiceBicycle == 2 ){
						rent(mid);
						this.addNewCustomerInfo(customer);
						break;
					}
					else if (choiceBicycle == 3){
						rent(high);
						this.addNewCustomerInfo(customer);
						break;
					}
					else{
						System.out.println("다시입력해주세요.");//if
					}
				}//while
			}
			else if ( choice == 2 ) { // 반납
				while(true) {
					System.out.println("반납할 이름을 입력하세요.");
					String deleteName = input.next();
					if ( checkScanner("^[가-힣a-zA-Z]*$", deleteName) ){
					}
					else{ 
						if (this.result = this.deleteCustomerByName(deleteName) ){ //존재하면
							Calendar cal = Calendar.getInstance();
							long time = cal.getTimeInMillis() + 1800000; //테스트용
							//long time = cal.getTimeInMillis();
							this.checkCount(getInfo(deleteName), high, time);
							this.checkCount(getInfo(deleteName), mid, time);
							this.checkCount(getInfo(deleteName), low, time);// 어떤 자전거 빌렸었는지 검사 해서 반납
							this.customerList.remove(getInfo(deleteName)); // 고객 정보 삭제
							System.out.println(deleteName + "님의 정보가 삭제되었습니다.\n");
							break;
						}
						else{ //이름이 존재하지않으면
							System.out.println(deleteName+"의 정보가 없습니다.\n");
							break;
						}//else
					}//else
				}//while
			}//else if
			else if ( choice == 3 ) {
				System.exit(0);
			}
		}//while
	}
	
	private void rent(BicycleVO type){
		curDate = new Date();
		Calendar now = Calendar.getInstance();
		customer.setRentTime(now.getTimeInMillis());
		if ( type.checkCount() ){ // 남은 수 확인
			System.out.println("자전거가 0대에요.");
		}
		else{ // 자전거가 남아 있다면
			System.out.println("이름과 가진 돈을 입력하세요."); // 고객 정보 등록
			String name = input.next();
			customer.setName(name);
			int money = input.nextInt();
			customer.setMoney(money);
			customer.setType(type.getType());
			type.rent(); // 보급형의 count를 1 줄인다.
			System.out.println(name + ": " + type.getType() + "자전거를 한대 대여하셨습니다.");
			System.out.println("대여한 시간 : " + curDate); // 대여한 시간 출력
		}		
	}
	
	public void checkCount ( CustomerVO customer , BicycleVO type, long time) { //  반납 계산 메소드
		if ( customer.getType() == type.getType()){ // 고객이 고급형을 가지고 있다면
			type.back(); // 고급형 자전거 count 1 증가 (반납했으므로)
			long result = (time - customer.getRentTime()) / 1000;
			int minute = (int)Math.round((double)result / 60); //시간으로 돈계산
			System.out.println("이용시간(분) : " + minute);
			if ( minute < 10) { // 10분보다 적으면 돈 안내도 된다고
				System.out.println("이용하신 시간이 10분 미만입니다. 돈 안내도댐");
				System.out.println("반납되었습니다. 고객님의 잔액 : " + customer.getMoney());
			}
			else {
				int cost = (minute / 10) * type.getCost(); // 10분당 돈 계산
				System.out.println("금액 :" + cost);
				customer.setMoney(customer.getMoney() - cost);
				System.out.println("반납되었습니다. 고객님의 잔액 : " + customer.getMoney());
			}
		}
		else{
		}
	}
	
	public boolean deleteCustomerByName( String name ) {
		for ( CustomerVO customer : this.customerList ) {
			if( customer.getName().equals(name) ) {
				return true;
			}
		}
		return false;
	}
	
	public CustomerVO getInfo( String name ) {
		for ( CustomerVO customer : this.customerList ) {
			if ( customer.getName().equals(name) ){
				this.customer = customer;
				return customer;
			}
		}
		return new CustomerVO();
	}
	
	public boolean checkScanner( String checkScan, String whatString ) {
		if ( !whatString.matches(checkScan) ) {
			System.out.println("재입력");
			return true;
		}
		else {
			return false;
		}
	}
	
	public void addNewCustomerInfo(CustomerVO customer){
		this.customerList.add(customer);
	}

}
