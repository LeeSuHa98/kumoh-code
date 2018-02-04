package com.ktds.jmj;

public class KBstar { // 국민은행...
	
	public static final int MAX_LOAN = 100000000; // 최대 대출 가능한돈
	public static final double RATE = 0.1; // 이율
	private int totalMoney; // 은행에 있는 돈
	
	
	public int getTotalMoney() {
		return totalMoney;
	}
	public void setTotalMoney(int totalMoney) {
		this.totalMoney = totalMoney;
	}

	public void printBankInfo() {// 은행 정보 출력
		System.out.println("은행돈 : " + this.getTotalMoney()); // 은행 정보 출력
	}

}
