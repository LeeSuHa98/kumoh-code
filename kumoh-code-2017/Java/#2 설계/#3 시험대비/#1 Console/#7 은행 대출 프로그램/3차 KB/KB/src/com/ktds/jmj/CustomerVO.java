package com.ktds.jmj;

import java.util.Date;

public class CustomerVO {

	private String name;
	private String phoneNumber;
	private int loanMoney; // 빌린돈
	private String dambo; // 담보
	private Date loanTime; //출력용 시간
	private long millisTime; // 계산용 시간
	private int repayMoney;//갚은돈
	
	public long getMillisTime() {
		return millisTime;
	}
	public void setMillisTime(long millisTime) {
		this.millisTime = millisTime;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getPhoneNumber() {
		return phoneNumber;
	}
	public void setPhoneNumber(String phoneNumber) {
		this.phoneNumber = phoneNumber;
	}

	public Date getLoanTime() {
		return loanTime;
	}
	public void setLoanTime(Date loanTime) {
		this.loanTime = loanTime;
	}
	public int getLoanMoney() {
		return loanMoney;
	}
	public void setLoanMoney(int loanMoney) {
		this.loanMoney = loanMoney;
	}
	public String getDambo() {
		return dambo;
	}
	public void setDambo(String dambo) {
		this.dambo = dambo;
	}
	public int getRepayMoney() {
		return repayMoney;
	}
	public void setRepayMoney(int repayMoney) {
		this.repayMoney = this.repayMoney + repayMoney; // 갚을때 마다 쌓아간다.
	}

}
