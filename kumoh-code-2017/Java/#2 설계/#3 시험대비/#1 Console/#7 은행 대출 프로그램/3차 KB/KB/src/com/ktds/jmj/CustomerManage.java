package com.ktds.jmj;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

public class CustomerManage {
	
	private List<CustomerVO> customerList;
	private CustomerVO customer;
	private KBstar kb;
	private static Date curDate;
	
	public CustomerManage() {
		this.customerList = new ArrayList<CustomerVO>();
		this.kb = new KBstar();
	}

	public List<CustomerVO> getCustomerList() {
		return customerList;
	}

	public void setCustomerList(List<CustomerVO> customerList) {
		this.customerList = customerList;
	}
	
//대출시작(가입)
	/**
	 * 가입
	 * @param name
	 * @param phoneNumber
	 * @param money
	 * @param dambo
	 */
	public void signUp(String name, String phoneNumber, int money, String dambo) {
		curDate = new Date();
		Calendar now = Calendar.getInstance();
		long dateTime = now.getTimeInMillis();
		customer = new CustomerVO();
		
		customer.setName(name);
		customer.setPhoneNumber(phoneNumber);
		//customer.setMoney(money);
		customer.setDambo(dambo);
		customer.setLoanTime(curDate);
		customer.setMillisTime(dateTime);
		customer.setLoanMoney(money);
		
		this.addNewCustomerInfo(customer);
		System.out.println("빌린 시간 : " + customer.getLoanTime());
	}
	
	
	/**
	 * Create
	 * @param customer
	 */
	public void addNewCustomerInfo(CustomerVO customer) {
		this.customerList.add(customer);
	}
	
	/**
	 * Read
	 * @param name
	 * @return
	 */
	public boolean getCustomerByName( String name ) {
		//이름으로 사람을 검색함
		for ( CustomerVO customer : this.customerList ) {
			if ( customer.getName().equals(name) ){
				this.customer = customer;
				return true;
			}
		}
		return false;
	}
	

	/**
	 * Delete
	 * @param name
	 * @return
	 */
	public boolean deleteCustomerByName(String name){
		for ( CustomerVO customer : this.customerList ) {
			if (customer.getName().equals(name)){
				this.customer = customer;
				return true;
			}
		}
		return false;
	}
	
	/**
	 * 파산
	 * @param customer
	 */
	public void failLife(CustomerVO customer, int money){
		if ( money == 0 ) { // 돈이 0이면 파산시켜줌
			System.out.println("당신의 담보 " + customer.getDambo() + "는 내가 가져간다." );// 담보 뺏기
			this.customerList.remove(customer); // 기록 삭제
			System.out.println("정보삭제는 해줄게");
		}
		else {//가진돈이 있으면 파산 안시켜줌
			System.out.println("돈이 남았으니 파산할 수 없어.");
		}
	}
	
	/**
	 * 해당고객정보가져오기
	 * @param name
	 * @return
	 */
	public CustomerVO getInfo( String name ) {
		for ( CustomerVO customer : this.customerList ) {
			if ( customer.getName().equals(name)){
				this.customer = customer;
				return customer;
			}
		}
		return new CustomerVO();
	}
	
	
	/**
	 * 갚아야할 돈 계산
	 * @param customer
	 * @return
	 */
	public int totalLoan (CustomerVO customer){
		Calendar when = Calendar.getInstance();
		long time = when.getTimeInMillis();
		long result = ((time - customer.getMillisTime()) / 1000);
		int sc = (int)Math.round((double)result);
		double down = Math.floor(sc/5); // 소수점 내림
		double pow = Math.pow((1+kb.RATE),down);
		int totalLoan = (int)(customer.getLoanMoney() * pow);
		
		return totalLoan;
	}
	
	/**
	 * 정보 출력
	 * @param customer
	 */
	public void printInfo(CustomerVO customer){
		System.out.println("이름 : " + customer.getName());
		System.out.println("전화번호 : " + customer.getPhoneNumber());
		System.out.println("대출금액 : " + customer.getLoanMoney());
		System.out.println("갚은 금액 :" + customer.getRepayMoney());
		System.out.println("담보 : " + customer.getDambo());
		System.out.println("대출시간 : " + customer.getLoanTime());
	}
	

}
